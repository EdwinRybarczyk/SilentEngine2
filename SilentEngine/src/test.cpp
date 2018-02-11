#include "SilentSystem/SilentWindow.hpp"
using namespace SilentSystem;
int main()
{
    SilentWindow window;
    window.api = OpenGL;
    window.doubleBuffering = true;
    window.width = 600;
    window.height = 400;
    window.title = "Sample Window";
    window.createWindow();

    while(window.windowOpen)
    {
        window.updateWindow();
    }
    return 0;
}