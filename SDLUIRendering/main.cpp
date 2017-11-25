#include "stdafx.h"

#include "DX\DataStructs.h"

#include "DX\GfxDevice.h"
#include "DX\GfxBuffers.h"
#include "DX\GfxTexture.h"
#include "DX\GfxVertexShader.h"
#include "DX\GfxPixelShader.h"
#include "DX\GfxModel.h"


int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
    SDL_Window* window = NULL;
    HWND hWnd = NULL;
    std::shared_ptr<GfxDevice> device;
    std::shared_ptr<GfxBuffers> swapChain;
    std::shared_ptr<GfxVertexShader> vertexShader;
    std::shared_ptr<GfxPixelShader> pixelShader;
    std::shared_ptr<GfxModel> model;

    SDL_Event winEvent;
    SDL_SysWMinfo wmInfo;
    SDL_Init(SDL_INIT_EVERYTHING);

    int width = 1280;
    int height = 720;

    window = SDL_CreateWindow("UIRendering", 100, 100, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    // get the HWND
    SDL_VERSION(&wmInfo.version);
    if (!SDL_GetWindowWMInfo(window, &wmInfo))
    {
        printf("failed to get window info: %s\n", SDL_GetError());
        return 1;
    }
    hWnd = wmInfo.info.win.window;
    
    // Init Dx
    device = std::make_shared<GfxDevice>();
    device->Initialize(hWnd);

    swapChain = std::make_shared<GfxBuffers>();
    swapChain->Initialize(device, width, height);

    vertexShader = std::make_shared<GfxVertexShader>();
    vertexShader->Initialize(device, L"Shaders\\Shaders.fx", "VS", "vs_4_0");

    pixelShader = std::make_shared<GfxPixelShader>();
    pixelShader->Initialize(device, L"Shaders\\Shaders.fx", "PS", "ps_4_0");

    model = std::make_shared<GfxModel>();
    model->Initialize(device);

    while (1) {
        SDL_PollEvent(&winEvent);
        if (winEvent.type == SDL_QUIT) {
            break;
        }

        // rendering loop here.
        // get next buffer from swapchain
        
        Vector4 color(0.392156899f, 0.584313750f, 0.929411829f, 1.000000000f);
        swapChain->Clear(color);
        model->Draw(vertexShader, pixelShader);


        swapChain->Present();
    }

    SDL_Quit();

    return 0;
}