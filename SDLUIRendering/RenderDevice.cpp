
#include "stdafx.h"
#include "Types\RenderTypes.h"
#include "DX\GfxDevice.h"
#include "RenderDevice.h"

std::weak_ptr<GfxDevice> GRenderDevice::graphicsDevice;


GRenderDevice::GRenderDevice()
{

}

std::weak_ptr<GfxDevice> GRenderDevice::GetDevice()
{
    return graphicsDevice;
}

void GRenderDevice::SetDevice(std::weak_ptr<GfxDevice> device)
{
    graphicsDevice = device;
}