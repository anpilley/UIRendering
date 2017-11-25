#include "..\stdafx.h"
#include "GfxPixelShader.h"

using namespace Microsoft::WRL;

GfxPixelShader::GfxPixelShader()
{

}

GfxPixelShader::~GfxPixelShader()
{

}

void GfxPixelShader::Initialize(std::weak_ptr<GfxDevice> device, LPCWSTR filename, LPCSTR name, LPCSTR shaderModel)
{
    GfxShader::Initialize(device, filename, name, shaderModel);

    if (this->shaderBlob && this->d3dDevice)
    {
        ComPtr<ID3D11PixelShader> pixelShader;
        ThrowIfFailed(this->d3dDevice->CreatePixelShader(
            this->shaderBlob->GetBufferPointer(),
            this->shaderBlob->GetBufferSize(),
            nullptr,
            &pixelShader
        ));

        this->shader = pixelShader;
    }
}

ID3D11PixelShader * GfxPixelShader::GetPS()
{
    if (this->shader)
    {
        ComPtr<ID3D11PixelShader> ps;
        this->shader.As(&ps);

        if (ps)
        {
            return ps.Get();
        }
    }

    ThrowIfFailed(E_FAIL);
    return nullptr;
}
