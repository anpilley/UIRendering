#pragma once

#include "DX\GfxDevice.h"

class GRenderDevice
{
public:
    static void SetDevice(std::weak_ptr<GfxDevice> device);

    static std::weak_ptr<GfxDevice> GetDevice();

private:
    GRenderDevice();

    static std::weak_ptr<GfxDevice> graphicsDevice;
};