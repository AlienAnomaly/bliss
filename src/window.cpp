#include "window.hpp"

#include <stdexcept>

namespace bliss
{
    Window::Window(const std::string& p_Title, int p_Width, int p_Height)
    {
        if (!SDL_Init(SDL_INIT_VIDEO))
            throw std::runtime_error("Failed to initialize SDL. Error: " + std::string(SDL_GetError()));

        m_Window = std::unique_ptr<SDL_Window, WindowDeleter>(
            SDL_CreateWindow(
                p_Title.c_str(),
                p_Width,
                p_Height,
                SDL_WINDOW_RESIZABLE
            )
        );

        if (!m_Window)
            throw std::runtime_error("Failed to initialize SDL window. Error: " + std::string(SDL_GetError()));
    }

    Window::~Window()
    {
        SDL_Quit();
    }

    SDL_Window& Window::GetWindow() const
    {
        return *m_Window;
    }
}