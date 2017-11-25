#pragma once

#include "GfxShader.h"

class GfxPixelShader : public GfxShader
{
public:
    GfxPixelShader();
    ~GfxPixelShader();

    virtual void Initialize(std::weak_ptr<GfxDevice> device, LPCWSTR filename, LPCSTR name, LPCSTR shaderModel) override;

    ID3D11PixelShader* GetPS();
protected:
};