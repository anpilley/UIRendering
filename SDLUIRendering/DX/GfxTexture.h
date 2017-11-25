#pragma once

class GfxTexture
{
public:
    GfxTexture();
    ~GfxTexture();

    void Initialize(ID3D11Texture2D * backBuffer);

//    ID3D11Texture2D* GetRawBuffer();
    //void Clear(Vector4 color);
private:
    Microsoft::WRL::ComPtr<ID3D11Texture2D> texture;
    
};