#pragma once

#include "window.hpp"
#include "renderer.hpp"

namespace bliss
{
    class GameContext
    {
    public:
        GameContext(Window& p_WindowClass, Renderer& p_RendererClass);
        ~GameContext();

    private:
        bool m_IsRunning { true };
        double m_DeltaTime { 0.0 };

    private:
        void HandleEvents();
        void Update();
        void Draw();

    public:
        void Run();
    };
}