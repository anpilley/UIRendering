
#include "..\stdafx.h"
#include "GfxModel.h"


using namespace Microsoft::WRL;
using namespace DirectX;

GfxModel::GfxModel()
{

}

GfxModel::~GfxModel()
{
    
}

void GfxModel::Initialize(std::weak_ptr<GfxDevice> device)
{
    std::shared_ptr<GfxDevice> gfxDevice = device.lock();
    if (gfxDevice)
    {
        SimpleVertex vertices[] =
        {
            XMFLOAT3(0.0f, 0.5f, 0.5f),
            XMFLOAT3(0.5f, -0.5f, 0.5f),
            XMFLOAT3(-0.5f, -0.5f, 0.5f),
        };
        D3D11_BUFFER_DESC bd;
        ZeroMemory(&bd, sizeof(bd));
        bd.Usage = D3D11_USAGE_DEFAULT;
        bd.ByteWidth = sizeof(SimpleVertex) * 3;
        bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
        bd.CPUAccessFlags = 0;
        D3D11_SUBRESOURCE_DATA InitData;
        ZeroMemory(&InitData, sizeof(InitData));
        InitData.pSysMem = vertices;

        this->d3dDevice = gfxDevice->GetDevice();
        this->immediateContext = gfxDevice->GetImmediateContext();

        this->d3dDevice->CreateBuffer(&bd, &InitData, &this->vertexBuffer);

        UINT stride = sizeof(SimpleVertex);
        UINT offset = 0;

        this->immediateContext->IASetVertexBuffers(0, 1, this->vertexBuffer.GetAddressOf(), &stride, &offset);

        this->immediateContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    }
}

void GfxModel::Draw(std::shared_ptr<GfxVertexShader> vs, std::shared_ptr<GfxPixelShader> ps)
{
    if (this->immediateContext)
    {
        this->immediateContext->VSSetShader(vs->GetVS(), nullptr, 0);
        this->immediateContext->PSSetShader(ps->GetPS(), nullptr, 0);
        this->immediateContext->Draw(3, 0); // abstract out the vertex count
    }
}