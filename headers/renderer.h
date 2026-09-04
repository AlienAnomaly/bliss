//
// Created by Alien on 03/09/2026.
//

#ifndef BLISS_RENDERER_H
#define BLISS_RENDERER_H

#include "window.h"

namespace bliss
{
    struct RendererDeleter
    {
        void operator()(SDL_Renderer* renderer) const
        {
            SDL_DestroyRenderer(renderer);
        }
    };

    class RendererClass
    {
    public:
        RendererClass(const WindowClass& p_WindowClassHandle);
        ~RendererClass() = default;

    private:
        std::unique_ptr<SDL_Renderer, RendererDeleter> m_RendererHandle {nullptr};

    public:
        SDL_Renderer& GetRendererHandle() const;

        void SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) const;

        void Begin();

        // rendering stuff here...

        void End();
    };
} // bliss

#endif //BLISS_RENDERER_H
