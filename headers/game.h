//
// Created by Alien on 03/09/2026.
//

#ifndef BLISS_GAME_H
#define BLISS_GAME_H

#include "window.h"
#include "renderer.h"

namespace bliss
{
    class GameClass
    {
    public:
        GameClass(const WindowClass& p_WindowClassHandle, RendererClass& p_RendererClassHandle);
        ~GameClass() = default;

    private:
    // members
        const WindowClass& m_WindowClassHandle;
        RendererClass& m_RendererClassHandle;

        bool m_IsRunning {true};
        double m_DeltaTime {0.0};

    // functions:
        void HandleEvents();
        void Update();
        void Draw();

    public:
        void Run();
        [[nodiscard]] const double& GetDeltaTime() const;
    };
} // bliss

#endif //BLISS_GAME_H
