#include "..\stdafx.h"
#include "GfxDevice.h"


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