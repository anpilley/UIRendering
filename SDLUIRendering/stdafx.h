#pragma once

#define _WIN32_WINNT 0x0A00
#define WIN32_LEAN_AND_MEAN 1
#include <sdkddkver.h>
#include <Windows.h>

#include <stdio.h>
#include <string>
#include <exception>
#include <memory>

// SDL
#include <SDL.h>
#include <SDL_syswm.h>

// DX
#include <d3d11.h>
#include <DXGI1_2.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>

inline void ThrowIfFailed(HRESULT hr)
{
    if (FAILED(hr))
    {
        // Set a breakpoint on this line to catch DirectX API errors
        throw std::exception();
    }
}



// ComPtr
#include <wrl/client.h>


