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
        const double freq = static_cast<double>(SDL_GetPerformanceFrequency());
        Uint64 lastCounter = SDL_GetPerformanceCounter();

        constexpr double desiredFrameTime = 1.0 / 60.0;
        constexpr double maxDeltaTime = 0.05;

        while (m_IsRunning)
        {
            HandleEvents();
            Update();
            Draw();

            Uint64 currentCounter = SDL_GetPerformanceCounter();
            double frameTime = static_cast<double>(currentCounter - lastCounter) / freq;

            if (frameTime < desiredFrameTime)
            {
                const auto delayTimeMs = static_cast<double>(desiredFrameTime - frameTime) * 1000.0;

                if (delayTimeMs > 0.0)
                    SDL_Delay(static_cast<Uint32>(delayTimeMs));

                frameTime = desiredFrameTime;
            }

            if (frameTime > maxDeltaTime)
                frameTime = maxDeltaTime;

            m_DeltaTime = frameTime;
            lastCounter = SDL_GetPerformanceCounter();
        }
    }

    const double& GameClass::GetDeltaTime() const
    {
        return m_DeltaTime;
    }
} // bliss