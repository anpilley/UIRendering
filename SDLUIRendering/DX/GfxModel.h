#pragma once

#include "..\Types\DataStructs.h"
#include "..\Types\VArray.h"
#include "GfxDevice.h"
#include "GfxVertexShader.h"
#include "GfxPixelShader.h"

class GfxModel
{
public:
    GfxModel();
    ~GfxModel();

    virtual void Initialize(const UITypes::VArray<SimpleVertex> & vertices, const UITypes::VArray<UINT32>& indexes);
    virtual void Initialize(std::weak_ptr<GfxDevice> device, const UITypes::VArray<SimpleVertex> & vertices, const UITypes::VArray<UINT32>& indexes);

    virtual void Draw(std::shared_ptr<GfxVertexShader> vs, std::shared_ptr<GfxPixelShader> ps);

private:
    std::shared_ptr<SimpleVertex> vertices;
    Microsoft::WRL::ComPtr<ID3D11Device> d3dDevice;

    Microsoft::WRL::ComPtr<ID3D11DeviceContext> immediateContext;
    Microsoft::WRL::ComPtr<ID3D11Buffer> vertexBuffer;
    Microsoft::WRL::ComPtr<ID3D11Buffer> indexBuffer;



};