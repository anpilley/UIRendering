#include "..\stdafx.h"

#include "DataStructs.h"

#include "GfxBuffers.h"
#include "GfxTexture.h"

GfxTexture::GfxTexture()
{

}

GfxTexture::~GfxTexture()
{

}

void GfxTexture::Initialize(ID3D11Texture2D * backBuffer)
{
    this->texture = backBuffer;

    // get details about the texture
    D3D11_TEXTURE2D_DESC desc;
    this->texture->GetDesc(&desc);
}
//
//void GfxTexture::Clear(Vector4 color)
//{
//
//}