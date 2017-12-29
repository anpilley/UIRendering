#pragma once

// forward decl
class GfxDataBuffer;

struct DXConstantBuffer
{
    DirectX::XMMATRIX mWorld;
    DirectX::XMMATRIX mView;
    DirectX::XMMATRIX mProjection;
    DirectX::XMFLOAT4 vLightDir[2];
    DirectX::XMFLOAT4 vLightColor[2];
    DirectX::XMFLOAT4 vOutputColor;
};

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

    void SetupConstantBuffer();
    void UpdateConstantBuffer(
        UITypes::Matrix4x4 world,
        UITypes::Matrix4x4 view,
        UITypes::Matrix4x4 projection,
        UITypes::Vector4 lightDir[2],
        UITypes::Vector4 lightColor[2],
        UITypes::Vector4 ambientColor
    );
    ID3D11Buffer* GetConstantBuffer() { return d3dConstantBuffer.Get(); };

private:
    HWND hWnd;
    Microsoft::WRL::ComPtr<ID3D11Device> d3dDevice;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext> d3dImmediateContext;
    Microsoft::WRL::ComPtr<ID3D11Buffer> d3dConstantBuffer;
    D3D_FEATURE_LEVEL featureLevel;

    bool d3d11_1;
};