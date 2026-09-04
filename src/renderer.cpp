//
// Created by Alien on 03/09/2026.
//

#include "renderer.h"

namespace bliss
{
    RendererClass::RendererClass(const WindowClass& p_WindowClassHandle)
    {
        m_RendererHandle = std::unique_ptr<SDL_Renderer, RendererDeleter>(
            SDL_CreateRenderer(
                &p_WindowClassHandle.GetWindowHandle(),
                nullptr
            )
        );

        if (!m_RendererHandle)
            throw std::runtime_error("Failed to create renderer. Error: " + std::string(SDL_GetError()));
    }

    SDL_Renderer& RendererClass::GetRendererHandle() const
    {
        return *m_RendererHandle;
    }

    void RendererClass::SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) const
    {
        SDL_SetRenderDrawColor(m_RendererHandle.get(), r, g, b, a);
    }

    void RendererClass::Begin()
    {
        SDL_RenderClear(m_RendererHandle.get());
    }

    void RendererClass::End()
    {
        SDL_RenderPresent(m_RendererHandle.get());
    }
} // bliss