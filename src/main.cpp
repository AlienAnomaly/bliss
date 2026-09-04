#include <iostream>

#include "window.h"
#include "renderer.h"
#include "game.h"

#include "level.h"

int main()
{
    try
    {
        bliss::LevelClass level("Level-1", "../levels/level-1.json");

        const bliss::WindowClass window("Game Window", 800, 600);
        bliss::RendererClass renderer(window);

        bliss::GameClass game(window, renderer);
        game.Run();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}