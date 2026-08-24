#pragma once

#include <string>
#include <memory>

#include <SDL3/SDL.h>

namespace bliss
{
    struct WindowDeleter
    {
        void operator()(SDL_Window* window) const
        {   
            SDL_DestroyWindow(window);
        }
    };

    class Window
    {
    public:
        Window(const std::string& p_Title, int p_Width, int p_Height);
        ~Window();

    private:
        std::unique_ptr<SDL_Window, WindowDeleter> m_Window { nullptr };

    public:
        SDL_Window& GetWindow() const;
    };
}