#include "..\stdafx.h"
#include "..\Types\RenderTypes.h"
#include "GfxDevice.h"
#include "GfxDataBuffer.h"

using namespace Microsoft::WRL;

GfxDataBuffer::GfxDataBuffer() :
    size(0)
{

}

GfxDataBuffer::~GfxDataBuffer()
{

}

void GfxDataBuffer::Initialize(UINT32 size, ComPtr<ID3D11Buffer> buffer)
{
    this->size = size;
    this->dxBuffer = buffer;
}