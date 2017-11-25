#pragma once


class GfxDevice
{
public:
    GfxDevice();
    ~GfxDevice();

    void Initialize(HWND hWnd);

    ID3D11Device* GetDevice() { return d3dDevice.Get(); };
    ID3D11DeviceContext* GetImmediateContext() { return d3dImmediateContext.Get(); };
    HWND GetHWND() {
        return this->hWnd;
    };

private:
    HWND hWnd;
    Microsoft::WRL::ComPtr<ID3D11Device> d3dDevice;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext> d3dImmediateContext;
    D3D_FEATURE_LEVEL featureLevel;

    bool d3d11_1;
};