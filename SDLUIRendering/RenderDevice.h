#pragma once

#include "DX\GfxDevice.h"
#include "DX\GfxDataBuffer.h"

class GRenderDevice
{
public:
    static void SetDevice(std::weak_ptr<GfxDevice> device);
    static void SetConstantBuffer(std::weak_ptr<GfxDataBuffer> buffer);


    static std::weak_ptr<GfxDevice> GetDevice();
    static std::weak_ptr<GfxDataBuffer> GetConstantBuffer();

private:
    GRenderDevice();

    static std::weak_ptr<GfxDataBuffer> constantBuffer;
    static std::weak_ptr<GfxDevice> graphicsDevice;
};