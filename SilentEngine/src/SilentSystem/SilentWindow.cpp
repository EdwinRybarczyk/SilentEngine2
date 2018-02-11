#include <SDL2/SDL.h>
#include "SilentWindow.hpp"
#include <GL/gl.h>
#define VULKAN_ENABLED 1
#define OPENGL_ENABLED 1
#define SOFTWARE_RENDERING 0


using namespace SilentSystem;

namespace SilentSystem
{
    SDL_Window* window = NULL;
    SDL_GLContext glContext;

    SilentWindow::SilentWindow()
    {

    }

    SilentWindow::~SilentWindow()
    {
        this->windowOpen = false;
        SDL_GL_DeleteContext(glContext);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    void SilentWindow::createWindow()
    {
        if(this->api == OpenGL)
        {
            
            //Initialise SDL
            if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
            {
                printf("Couldn't initialise SDL!\n");
                exit(1);
            }

            //Create SDL window
            window = SDL_CreateWindow(
                (const char*)this->title.data(),
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                this->width,
                this->height,
                SDL_WINDOW_OPENGL
            );

            //Require minimum OpenGL 2
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

            //Set double buffering
            if(this->doubleBuffering)
            {
                SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
            }

            glContext = SDL_GL_CreateContext(window);
            this->windowOpen = true;
            glClearColor(0.25, 0, 0.5, 0);

        }

        else if(this->api == Vulkan)
        {

        }

        else if(this->api == Software)
        {

        }

        else
        {
            printf("Invalid API selected\n");
            exit(1);
        }
    }

    void SilentWindow::updateWindow()
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                this->~SilentWindow();
            }
        }
        glClear(GL_COLOR_BUFFER_BIT);
        SDL_GL_SwapWindow(window);
        SDL_Delay(1);
    }
}


