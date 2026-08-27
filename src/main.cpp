#include "window.hpp"
#include "renderer.hpp"
#include "game.hpp"

#include <iostream>

int main()
{  
    try
    {
        bliss::Window window("Game Window", 800, 600);
        bliss::Renderer renderer(window.GetWindow());
        bliss::GameContext game(window, renderer);
        
        game.Run();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}