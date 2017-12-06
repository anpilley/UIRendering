
#include "..\stdafx.h"
#include "GfxVertexShader.h"

using namespace Microsoft::WRL;

GfxVertexShader::GfxVertexShader()
{

}

GfxVertexShader::~GfxVertexShader()
{

}

void GfxVertexShader::Initialize(std::weak_ptr<GfxDevice> device, LPCWSTR filename, LPCSTR name, LPCSTR shaderModel)
{
    GfxShader::Initialize(device, filename, name, shaderModel);

    if (this->shaderBlob && this->d3dDevice)
    {
        ComPtr<ID3D11VertexShader> vertexShader;
        ThrowIfFailed(this->d3dDevice->CreateVertexShader(
            this->shaderBlob->GetBufferPointer(),
            this->shaderBlob->GetBufferSize(),
            nullptr,
            &vertexShader
        ));

        this->shader = vertexShader;

        D3D11_INPUT_ELEMENT_DESC layout[] =
        {
            { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
            { "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0},
        };
        UINT numElements = ARRAYSIZE(layout);

        ThrowIfFailed(this->d3dDevice->CreateInputLayout(
            layout,
            numElements,
            this->shaderBlob->GetBufferPointer(),
            this->shaderBlob->GetBufferSize(),
            &this->inputLayout
        ));

        // this might be something you want to do just prior to loading in data?
        this->immediateContext->IASetInputLayout(this->inputLayout.Get());
    }
    else
    {
        ThrowIfFailed(E_FAIL);
    }

}

ID3D11VertexShader * GfxVertexShader::GetVS()
{
    if (this->shader)
    {
        ComPtr<ID3D11VertexShader> vs;
        this->shader.As(&vs);

        if (vs)
        {
            return vs.Get();
        }
    }

    ThrowIfFailed(E_FAIL);
    return nullptr;
}
