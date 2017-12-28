#include "..\stdafx.h"
#include "GfxBuffers.h"
#include "GfxTexture.h"

using namespace Microsoft::WRL;

GfxBuffers::GfxBuffers():
    width(0),
    height(0)
{

}

GfxBuffers::~GfxBuffers()
{
    
}

void GfxBuffers::Initialize(std::weak_ptr<GfxDevice> gfxdevice, int width, int height)
{
    this->gfxDevice = gfxdevice;
    this->width = width;
    this->height = height;
    ID3D11RenderTargetView* view;

    if (auto spGfxDevice = this->gfxDevice.lock())
    {
        this->d3dDevice = spGfxDevice->GetDevice();
        this->d3dImmediateContext = spGfxDevice->GetImmediateContext();

        if (this->d3dDevice)
        {
            RECT rc;
            GetClientRect(spGfxDevice->GetHWND(), &rc);
            UINT width = rc.right - rc.left;
            UINT height = rc.bottom - rc.top;

            // get the dxgi device
            ThrowIfFailed(this->d3dDevice.As<IDXGIDevice>(&this->dxgiDevice));
            
            // get the dxgi adapter
            ThrowIfFailed(this->dxgiDevice->GetParent(__uuidof(IDXGIAdapter), &this->dxgiAdapter));

            // get the dxgi factory
            ThrowIfFailed(this->dxgiAdapter->GetParent(__uuidof(IDXGIFactory2), &this->dxgiFactory));

            // 11.1+
            DXGI_SWAP_CHAIN_DESC1 desc;
            ZeroMemory(&desc, sizeof(desc));
            desc.Width = width;
            desc.Height = height;
            desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
            desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
            desc.BufferCount = 1;
            desc.SampleDesc.Count = 1;
            desc.SampleDesc.Quality = 0;

            ThrowIfFailed(this->dxgiFactory->CreateSwapChainForHwnd(
                this->d3dDevice.Get(),
                spGfxDevice->GetHWND(),
                &desc,
                NULL, // windowed,
                NULL,
                &this->swapChain));

            this->dxgiFactory->MakeWindowAssociation(spGfxDevice->GetHWND(), DXGI_MWA_NO_ALT_ENTER);

            ComPtr<ID3D11Texture2D> texture2d;
            ThrowIfFailed(this->swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), &texture2d));

            //std::shared_ptr<GfxTexture> texture = std::make_shared<GfxTexture>();
            //texture->Initialize(texture2d.Get());

            // Bind to the render target
            ThrowIfFailed(this->d3dDevice->CreateRenderTargetView(texture2d.Get(), nullptr, &view));

            // Create Depth stencil buffer
            D3D11_TEXTURE2D_DESC descDepth;
            ZeroMemory(&descDepth, sizeof(descDepth));
            descDepth.Width = width;
            descDepth.Height = height;
            descDepth.MipLevels = 1;
            descDepth.ArraySize = 1;
            descDepth.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
            descDepth.SampleDesc.Count = 1;
            descDepth.SampleDesc.Quality = 0;
            descDepth.Usage = D3D11_USAGE_DEFAULT;
            descDepth.BindFlags = D3D11_BIND_DEPTH_STENCIL;

            descDepth.CPUAccessFlags = 0;
            descDepth.MiscFlags = 0;
            ThrowIfFailed(this->d3dDevice->CreateTexture2D(&descDepth, nullptr, &depthStencilBuffer));

            // Create depth stencil settings
            D3D11_DEPTH_STENCIL_DESC descState;
            ZeroMemory(&descState, sizeof(D3D11_DEPTH_STENCIL_DESC));
            descState.DepthEnable = true;
            descState.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
            descState.DepthFunc = D3D11_COMPARISON_LESS;

            descState.StencilEnable = false;
            descState.StencilReadMask = 0xFF;
            descState.StencilWriteMask = 0xFF;
            
            descState.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
            descState.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
            descState.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
            descState.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

            descState.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
            descState.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
            descState.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
            descState.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

            ThrowIfFailed(this->d3dDevice->CreateDepthStencilState(&descState, &depthState));

            // create depth stencil view
            D3D11_DEPTH_STENCIL_VIEW_DESC descDSView;
            ZeroMemory(&descDSView, sizeof(descDSView));
            descDSView.Format = descDepth.Format;
            descDSView.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
            descDSView.Texture2D.MipSlice = 0;
            ThrowIfFailed(this->d3dDevice->CreateDepthStencilView(depthStencilBuffer.Get() , &descDSView, &depthStencilView));

            this->d3dImmediateContext->OMSetDepthStencilState(depthState.Get(), 1);

            this->d3dImmediateContext->OMSetRenderTargets(1, &view, depthStencilView.Get());

            this->renderTargetView = view;

            D3D11_VIEWPORT vp;
            ZeroMemory(&vp, sizeof(vp));
            vp.Width = (float)width;
            vp.Height = (float)height;
            vp.MinDepth = 0.f;
            vp.MaxDepth = 1.f;
            vp.TopLeftX = 0;
            vp.TopLeftY = 0;
            this->d3dImmediateContext->RSSetViewports(1, &vp);

            view->Release();
        }
    }
}

std::shared_ptr<GfxTexture> GfxBuffers::GetNextBuffer()
{
    ComPtr<ID3D11Texture2D> texture2d;

    std::shared_ptr<GfxTexture> texture = std::make_shared<GfxTexture>();

    if (!this->swapChain)
    {
        return nullptr;
    }

    ThrowIfFailed(this->swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), &texture2d));

    texture->Initialize(texture2d.Get());

    return std::move(texture);
}

void GfxBuffers::Present()
{
    this->swapChain->Present(0, 0);
}

void GfxBuffers::Clear(UITypes::Vector4 color)
{
    FLOAT c[4] = { color.x, color.y, color.z, color.a };
    this->d3dImmediateContext->ClearRenderTargetView(this->renderTargetView.Get(), c);

    this->d3dImmediateContext->ClearDepthStencilView(this->depthStencilView.Get(), D3D11_CLEAR_DEPTH, 1.0f, 0);

}