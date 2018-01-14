#include <SDL2/SDL.h>
#include "SilentWindow.h"
#include <GL/gl.h>
#define VULKAN_ENABLED 1
#define OPENGL_ENABLED 1
#define SOFTWARE_RENDERING 0


using namespace SilentSystem;

SilentWindow::SilentWindow(
    int width,
    int height,
    const char* title,
    char renderingAPI
)
{
    //Initialise window properties
    this->width = width;
    this->height = height;
    this->title = title;
    this->renderingAPI = renderingAPI;

}


