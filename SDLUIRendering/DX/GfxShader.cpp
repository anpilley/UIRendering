#include "..\stdafx.h"
#include "GfxShader.h"

using namespace Microsoft::WRL;

GfxShader::GfxShader()
{
    
}

GfxShader::~GfxShader()
{

}

void GfxShader::Initialize(std::weak_ptr<GfxDevice> device, LPCWSTR filename, LPCSTR name, LPCSTR shaderModel)
{
    this->name = std::string(name);
    this->filename = std::wstring(filename);
    this->shaderModel = std::string(shaderModel);
    this->gfxDevice = device;
    HRESULT hr = S_OK;

    std::shared_ptr<GfxDevice> gfxDevice = device.lock();
    if (gfxDevice)
    {
        this->d3dDevice = gfxDevice->GetDevice();
        this->immediateContext = gfxDevice->GetImmediateContext();
    }

    DWORD dwShaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;

    // debug
    dwShaderFlags |= D3DCOMPILE_DEBUG;
    dwShaderFlags |= D3DCOMPILE_SKIP_OPTIMIZATION;

    ComPtr<ID3DBlob> errorBlob;
    hr = D3DCompileFromFile(
        this->filename.c_str(),
        nullptr,
        nullptr,
        this->name.c_str(),
        this->shaderModel.c_str(),
        dwShaderFlags,
        0,
        &this->shaderBlob,
        &errorBlob);
    if (FAILED(hr))
    {
        // couldn't compilethe shader. get details from the error blob.
        ThrowIfFailed(hr);
    }
}