#include "renderer.hpp"

#include <stdexcept>

#include <SDL3_image/SDL_image.h>

namespace bliss
{
    Renderer::Renderer(SDL_Window& p_WindowClass)
    {
        m_RendererHandle = std::unique_ptr<SDL_Renderer, RendererDeleter>(
            SDL_CreateRenderer(
                &p_WindowClass,
                nullptr
            )
        );

        if(!m_RendererHandle)
        {
            throw std::runtime_error("Failed to create renderer. Error: " + 
                std::string(SDL_GetError()));
        }
    }

    void Renderer::Begin()
    {
        SDL_RenderClear(m_RendererHandle.get());
    }

    void Renderer::End()
    {
        for (const auto& texture : m_MainTextureContainer)  
        {
            SDL_RenderTexture(m_RendererHandle.get(), texture.get(), NULL, NULL);
        }
    }

    SDL_Renderer& Renderer::GetRendererHandle() const
    {
        return *m_RendererHandle;
    }

    SDL_Texture& Renderer::QueueTexture(const std::string& p_AssetPath)
    {
        std::shared_ptr<SDL_Texture> texture(
            IMG_LoadTexture(m_RendererHandle.get(), p_AssetPath.c_str()),
            SDL_DestroyTexture
        );

        m_TempTextureContainer.push_back(texture);

        return *texture;
    }

    void Renderer::UpdateTextureQueue()
    {
        for (const auto& texture : m_TempTextureContainer)
        {
            m_MainTextureContainer.push_back(texture);
        }

        m_TempTextureContainer.clear();
    }
}