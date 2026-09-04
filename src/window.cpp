//
// Created by Alien on 03/09/2026.
//

#include "window.h"

namespace bliss
{
    WindowClass::WindowClass(const std::string& p_Title, int p_Width, int p_Height)
    {
        if (!SDL_Init(SDL_INIT_VIDEO))
            throw std::runtime_error("Could not initialize SDL. Error: " + std::string(SDL_GetError()));

        m_WindowHandle = std::unique_ptr<SDL_Window, WindowDeleter>(
            SDL_CreateWindow(
                p_Title.c_str(),
                p_Width,
                p_Height,
                SDL_WINDOW_RESIZABLE
            )
        );

        if (!m_WindowHandle)
            throw std::runtime_error("Could not create window. Error: " + std::string(SDL_GetError()));
    }

    WindowClass::~WindowClass()
    {
        SDL_Quit();
    }

    SDL_Window& WindowClass::GetWindowHandle() const
    {
        return *m_WindowHandle;
    }
} // bliss