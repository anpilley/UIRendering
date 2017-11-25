#pragma once

#include "GfxShader.h"

class GfxVertexShader : public GfxShader
{
public:
    GfxVertexShader();
    ~GfxVertexShader();

    virtual void Initialize(std::weak_ptr<GfxDevice> device, LPCWSTR filename, LPCSTR name, LPCSTR shaderModel) override;

    ID3D11VertexShader* GetVS();

protected:
    Microsoft::WRL::ComPtr<ID3D11InputLayout> inputLayout;
};