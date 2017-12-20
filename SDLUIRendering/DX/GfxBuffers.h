#pragma once

#include "..\Types\DataStructs.h"
#include "GfxDevice.h"
#include "GfxTexture.h"

class GfxBuffers
{
public:
    GfxBuffers();
    ~GfxBuffers();
    void Initialize(std::weak_ptr<GfxDevice> gfxdevice, int width, int height);

    std::shared_ptr<GfxTexture> GetNextBuffer();

    void Present();

    void Clear(UITypes::Vector4 color);

private:
    Microsoft::WRL::ComPtr<IDXGISwapChain1> swapChain;
    Microsoft::WRL::ComPtr<ID3D11Device> d3dDevice;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext> d3dImmediateContext;
    Microsoft::WRL::ComPtr<IDXGIDevice> dxgiDevice;
    Microsoft::WRL::ComPtr<IDXGIFactory2> dxgiFactory;
    Microsoft::WRL::ComPtr<IDXGIAdapter> dxgiAdapter;

    Microsoft::WRL::ComPtr<ID3D11RenderTargetView> renderTargetView;

    Microsoft::WRL::ComPtr<ID3D11Texture2D> depthStencilBuffer;
    Microsoft::WRL::ComPtr<ID3D11DepthStencilView> depthStencilView;

    std::weak_ptr<GfxDevice> gfxDevice;

    int width; int height;
};