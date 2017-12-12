
#include "..\stdafx.h"
#include "GfxModel.h"
#include "../RenderDevice.h"

using namespace Microsoft::WRL;
using namespace DirectX;

GfxModel::GfxModel() :
    vertexCount(0)
{

}

GfxModel::~GfxModel()
{

}

void GfxModel::Initialize(const UITypes::VArray<SimpleVertex> & vertices, const UITypes::VArray<UINT16>& indexes)
{
    // Get default device
    std::weak_ptr<GfxDevice> gfxDevice = GRenderDevice::GetDevice();


    this->Initialize(gfxDevice, vertices, indexes);
}

void GfxModel::Initialize(std::weak_ptr<GfxDevice> device, const UITypes::VArray<SimpleVertex> & vertices, const UITypes::VArray<UINT16>& indexes)
{
    this->gfxDevice = device;
    this->vertexCount = indexes.Size();
    std::shared_ptr<GfxDevice> gfxDevice = device.lock();
    if (gfxDevice)
    {
        // vertex data
        D3D11_BUFFER_DESC bd;
        ZeroMemory(&bd, sizeof(bd));
        bd.Usage = D3D11_USAGE_DEFAULT;
        bd.ByteWidth = sizeof(SimpleVertex) * vertices.Size();
        bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
        bd.CPUAccessFlags = 0;
        D3D11_SUBRESOURCE_DATA InitData;
        ZeroMemory(&InitData, sizeof(InitData));
        InitData.pSysMem = vertices.GetRaw();   

        this->d3dDevice = gfxDevice->GetDevice();
        this->immediateContext = gfxDevice->GetImmediateContext();

        ThrowIfFailed(this->d3dDevice->CreateBuffer(&bd, &InitData, &this->vertexBuffer));

        // index data
        bd.Usage = D3D11_USAGE_DEFAULT;
        bd.ByteWidth = sizeof(UINT16) * indexes.Size();
        bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
        bd.CPUAccessFlags = 0;
        InitData.pSysMem = indexes.GetRaw();
        
        ThrowIfFailed(this->d3dDevice->CreateBuffer(&bd, &InitData, &this->indexBuffer));
    }
}

void GfxModel::Draw(std::shared_ptr<GfxVertexShader> vs, std::shared_ptr<GfxPixelShader> ps)
{
    if (this->immediateContext)
    {
        // Update the constant buffer containing the world/view/projection matrixes.
        std::shared_ptr<GfxDevice> device = this->gfxDevice.lock(); // doing this per object seems like it'll give me lock contention. fix.
        if (device)
        {
            UINT stride = sizeof(SimpleVertex);
            UINT offset = 0;

            this->immediateContext->IASetVertexBuffers(0, 1, this->vertexBuffer.GetAddressOf(), &stride, &offset);

            this->immediateContext->IASetIndexBuffer(this->indexBuffer.Get(), DXGI_FORMAT_R16_UINT, 0);

            // better off doing this before rendering groups of items?
            this->immediateContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

            this->immediateContext->VSSetShader(vs->GetVS(), nullptr, 0);
            ID3D11Buffer * cb = device->GetConstantBuffer();
            this->immediateContext->VSSetConstantBuffers(0, 1, &cb);

            this->immediateContext->PSSetShader(ps->GetPS(), nullptr, 0);
            this->immediateContext->DrawIndexed(this->vertexCount, 0, 0); 
        }
    }
}