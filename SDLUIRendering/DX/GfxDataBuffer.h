#pragma once

class GfxDataBuffer
{
public:
    GfxDataBuffer();
    ~GfxDataBuffer();

    void Initialize(UINT32 size, Microsoft::WRL::ComPtr<ID3D11Buffer> buffer);

private:
    Microsoft::WRL::ComPtr<ID3D11Buffer> dxBuffer;
    UINT32 size;
};