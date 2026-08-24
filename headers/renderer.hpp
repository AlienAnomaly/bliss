#pragma once

#include <memory>
#include <string>
#include <vector>

#include <SDL3/SDL.h>

namespace bliss
{
    struct RendererDeleter
    {
        void operator()(SDL_Renderer* renderer) const
        {
            SDL_DestroyRenderer(renderer);
        }
    };

    struct TextureDeleter
    {
        void operator()(SDL_Texture* texture) const
        {   
            SDL_DestroyTexture(texture);
        }
    };

    class Renderer
    {
    public:
        Renderer(SDL_Window& p_WindowClass);
        ~Renderer() = default;

    private:
        std::unique_ptr<SDL_Renderer, RendererDeleter> m_RendererHandle { nullptr };
        std::vector<std::shared_ptr<SDL_Texture>> m_TempTextureContainer;
        std::vector<std::shared_ptr<SDL_Texture>> m_MainTextureContainer;

    public:
        void Begin();
        void End();
        SDL_Texture& QueueTexture(const std::string& p_AssetPath);
        void UpdateTextureQueue();
        
        SDL_Renderer& GetRendererHandle() const;
    };
}