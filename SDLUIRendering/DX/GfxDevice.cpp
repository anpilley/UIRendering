#include "..\stdafx.h"
#include "..\Types\RenderTypes.h"
#include "GfxDevice.h"

using namespace UITypes;

GfxDevice::GfxDevice()
    : hWnd(NULL),
    d3d11_1(false)
{

}

GfxDevice::~GfxDevice()
{
    if (!this->d3dDevice)
    {
        // ensure we're in a good state when shutting down.
        this->d3dImmediateContext->Flush();
        this->d3dImmediateContext.Reset();
        this->d3dDevice.Reset();
    }
}

void GfxDevice::Initialize(HWND hWnd)
{
    this->hWnd = hWnd;
    // check if the hWnd looks valid
    D3D_FEATURE_LEVEL features[2] = { D3D_FEATURE_LEVEL_11_1 , D3D_FEATURE_LEVEL_11_0 };
    D3D_FEATURE_LEVEL featureSupported;

    // enumerate adapters?
    ThrowIfFailed(D3D11CreateDevice(
        NULL,
        D3D_DRIVER_TYPE_HARDWARE,
        NULL, // no software renderer
        D3D11_CREATE_DEVICE_DEBUG,// | D3D11_CREATE_DEVICE_DEBUGGABLE, // debug/debug shaders
        features,
        2,
        D3D11_SDK_VERSION,
        &this->d3dDevice,
        &featureSupported,
        &this->d3dImmediateContext
    ));

    if (featureSupported == D3D_FEATURE_LEVEL_11_1)
    {
        d3d11_1 = true;
    }
}

void GfxDevice::SetupConstantBuffer()
{
    D3D11_BUFFER_DESC bd;
    ZeroMemory(&bd, sizeof(bd));

    bd.Usage = D3D11_USAGE_DEFAULT;
    bd.ByteWidth = sizeof(DXConstantBuffer);
    bd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
    bd.CPUAccessFlags = 0;
    ThrowIfFailed(d3dDevice->CreateBuffer(&bd, nullptr, &d3dConstantBuffer));
}

DirectX::XMMATRIX ToDX(Matrix4x4 mat)
{
    return DirectX::XMMATRIX(mat.m11, mat.m12, mat.m13, mat.m14,
        mat.m21, mat.m22, mat.m23, mat.m24,
        mat.m31, mat.m32, mat.m33, mat.m34,
        mat.m41, mat.m42, mat.m43, mat.m44);
}

void GfxDevice::UpdateConstantBuffer(Matrix4x4 world, Matrix4x4 view, Matrix4x4 projection)
{
    DXConstantBuffer cb;
    cb.mWorld = DirectX::XMMatrixTranspose(ToDX(world));
    cb.mView = DirectX::XMMatrixTranspose(ToDX(view));
    cb.mProjection = DirectX::XMMatrixTranspose(ToDX(projection));

    //DirectX::XMMATRIX model = DirectX::XMMatrixTranspose(DirectX::XMMatrixIdentity());

    //// Initialize the view matrix
    //DirectX::XMVECTOR Eye = DirectX::XMVectorSet(0.0f, 1.0f, -5.0f, 0.0f);
    //DirectX::XMVECTOR At = DirectX::XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
    //DirectX::XMVECTOR Up = DirectX::XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
    //DirectX::XMMATRIX lview = DirectX::XMMatrixLookAtLH(Eye, At, Up);
    //lview = DirectX::XMMatrixTranspose(lview);

    //// Initialize the projection matrix
    //DirectX::XMMATRIX proj = DirectX::XMMatrixTranspose(DirectX::XMMatrixPerspectiveFovLH(DirectX::XM_PIDIV2, 1280 / (FLOAT)720, 0.01f, 100.0f));



    /*cb.mWorld = DirectX::XMMatrixTranspose(model);
    cb.mView = DirectX::XMMatrixTranspose(lview);
    cb.mProjection = DirectX::XMMatrixTranspose(proj);*/

    this->d3dImmediateContext->UpdateSubresource(this->d3dConstantBuffer.Get(), 0, nullptr, &cb, 0, 0);
}