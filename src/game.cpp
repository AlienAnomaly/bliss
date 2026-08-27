#include "game.hpp"

namespace bliss
{
    GameContext::GameContext(Window& p_WindowClass, Renderer& p_RendererClass)
    {

    }

    GameContext::~GameContext()
    {

    }

    void GameContext::HandleEvents()
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {   
            switch (event.type)
            {
                case SDL_EVENT_QUIT:
                    m_IsRunning = false;
                    break;
            }
        }
    }

    void GameContext::Update()
    {

    }

    void GameContext::Draw()
    {
        
    }
    
    void GameContext::Run()
    {
        while (m_IsRunning)
        {   
            HandleEvents();
            Update();
            Draw();
        }
    }
}