//
// Created by Alien on 03/09/2026.
//

#include "game.h"

#include <SDL3/SDL_events.h>

namespace bliss
{
    GameClass::GameClass(const WindowClass& p_WindowClassHandle, RendererClass& p_RendererClassHandle)
        : m_WindowClassHandle(p_WindowClassHandle)
        , m_RendererClassHandle(p_RendererClassHandle)
    {

    }

    void GameClass::HandleEvents()
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_EVENT_QUIT:
                {
                    m_IsRunning = false;
                } break;

                default:
                {
                } break;
            }
        }
    }

    void GameClass::Update()
    {

    }

    void GameClass::Draw()
    {
        m_RendererClassHandle.SetDrawColor(20, 20, 20, 255);
        m_RendererClassHandle.Begin();
        m_RendererClassHandle.End();
    }

    void GameClass::Run()
    {
        while (m_IsRunning)
        {
            HandleEvents();
            Update();
            Draw();
        }
    }
} // bliss