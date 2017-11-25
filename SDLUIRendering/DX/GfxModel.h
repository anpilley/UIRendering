#pragma once

#include "DataStructs.h"
#include "GfxDevice.h"
#include "GfxVertexShader.h"
#include "GfxPixelShader.h"

class GfxModel
{
public:
    GfxModel();
    ~GfxModel();

    virtual void Initialize(std::weak_ptr<GfxDevice> device);

    virtual void Draw(std::shared_ptr<GfxVertexShader> vs, std::shared_ptr<GfxPixelShader> ps);

private:
    std::shared_ptr<SimpleVertex> vertices;
    Microsoft::WRL::ComPtr<ID3D11Device> d3dDevice;

    Microsoft::WRL::ComPtr<ID3D11DeviceContext> immediateContext;
    Microsoft::WRL::ComPtr<ID3D11Buffer> vertexBuffer;



};