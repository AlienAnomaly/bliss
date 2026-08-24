#include "window.hpp"
#include "renderer.hpp"

#include <iostream>

int main()
{  
    try
    {
        bliss::Window window("Game Window", 800, 600);
        bliss::Renderer renderer(window.GetWindow());
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}