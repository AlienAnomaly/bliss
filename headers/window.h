//
// Created by Alien on 03/09/2026.
//

#ifndef BLISS_WINDOW_H
#define BLISS_WINDOW_H

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

    class WindowClass
    {
    public:
        WindowClass(const std::string& p_Title, int p_Width, int p_Height);
        ~WindowClass();

    private:
        std::unique_ptr<SDL_Window, WindowDeleter> m_WindowHandle {nullptr};

    public:
        SDL_Window& GetWindowHandle() const;
    };
}

#endif //BLISS_WINDOW_H
