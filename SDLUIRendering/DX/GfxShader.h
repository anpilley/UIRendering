#pragma once

#include "DataStructs.h"
#include "GfxDevice.h"

// abstract shader class
class GfxShader
{
public:
    GfxShader();
    ~GfxShader();

    virtual void Initialize(std::weak_ptr<GfxDevice> device, LPCWSTR filename, LPCSTR name, LPCSTR shaderModel);

protected:
    std::weak_ptr<GfxDevice> gfxDevice;
    Microsoft::WRL::ComPtr<ID3D11Device> d3dDevice;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext> immediateContext;
    Microsoft::WRL::ComPtr<ID3DBlob> shaderBlob;
    Microsoft::WRL::ComPtr<ID3D11DeviceChild> shader;
    std::string name;
    std::string shaderModel;
    std::wstring filename;

};