#include "SilentSystem/SilentWindow.hpp"
#include "SilentRenderer/SilentRenderer.hpp"
using namespace SilentSystem;
using namespace SilentEntities;
using namespace SilentRenderingEngine;
int main()
{
    SilentWindow window;
    window.api = OpenGL;
    window.doubleBuffering = true;
    window.width = 600;
    window.height = 400;
    window.title = "Sample Window";
    window.createWindow();

    SilentRenderer renderer;

    SilentEntity sampleEntity = loadOBJModel("src/untitled2.obj");
    sampleEntity.load();
    while(window.windowOpen)
    {
        renderer.prepare();
        renderer.renderEntity(sampleEntity);
        window.updateWindow();
    }
    return 0;
}