#include <GL/glew.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>
#include <vulkan/vulkan.h>
#include "SilentWindow.hpp"
#define VULKAN_ENABLED 1
#define OPENGL_ENABLED 1
#define SOFTWARE_RENDERING 0

using namespace SilentSystem;

namespace SilentSystem
{
    SDL_Window* window = NULL;
    //opengl
    SDL_GLContext glContext;

    //vulkan
    VkInstance instance;

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
        //Initialise SDL
        if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
        {
            printf("Couldn't initialise SDL!\n");
            exit(1);
        }

        if(this->api == OpenGL)
        {
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
            //SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

            //Set double buffering
            if(this->doubleBuffering)
            {
                SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
            }

            glContext = SDL_GL_CreateContext(window);
            this->windowOpen = true;
            glClearColor(0.25, 0, 0.5, 0);

            if(glewInit() != GLEW_OK)
            {
                printf("Couldn't initialise OpenGL\n");
            }
            glewExperimental = GL_TRUE;

        }

        else if(this->api == Vulkan)
        {
            //Create SDL window
            window = SDL_CreateWindow(
                (const char*)this->title.data(),
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                this->width,
                this->height,
                SDL_WINDOW_SHOWN
            );

/*
            VkApplicationInfo appInfo = {};
            appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
            appInfo.pApplicationName = this->title.data();
            appInfo.applicationVersion = VK_MAKE_VERSION(1,0,0);
            appInfo.pEngineName = "Silent Game Engine";
            appInfo.engineVersion = VK_MAKE_VERSION(1,0,0);
            appInfo.apiVersion = VK_API_VERSION_1_0;

            VkInstanceCreateInfo createInfo = {};
            createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
            createInfo.pApplicationInfo = &appInfo;*/
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
        //glClear(GL_COLOR_BUFFER_BIT);
        SDL_GL_SwapWindow(window);
        SDL_Delay(1);
    }
}


