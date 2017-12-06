
#include "stdafx.h"
#include "DX\GfxDevice.h"
#include "RenderDevice.h"

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