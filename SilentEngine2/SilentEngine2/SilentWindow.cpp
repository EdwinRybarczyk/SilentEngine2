#include <glew.h>
#include <SDL.h>
#include "SilentWindow.h"
#include "PSilentWindow.h"

Silent::SilentWindow::SilentWindow()
{
}

void Silent::SilentWindow::InitializeDisplay()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        exit(1);
    }

    if (GLEW_OK != glewInit())
    {
        exit(1);
    }

    window = new Pwindow();
}

void Silent::SilentWindow::OpenDisplay(char * title, int Width, int Height, int PositionX, int PositionY, bool FullScreen)
{
    
    if (PositionX == NULL && PositionY == NULL) {
        PositionX = window->centered;
        PositionY = window->centered;
    }


    if (FullScreen) {
        window->window = SDL_CreateWindow(
            title,
            PositionX,
            PositionY,
            Width,
            Height,
            SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN
        );
    }
    if (!FullScreen) {
        window->window = SDL_CreateWindow(
            title,
            PositionX,
            PositionY,
            Width,
            Height,
            SDL_WINDOW_OPENGL 
        );
        glClearColor(0, 0, 1, 1);
    }
}

void Silent::SilentWindow::UpdateDisplay()
{
    SDL_GL_SwapWindow(window->window);
    SDL_UpdateWindowSurface(window->window);

}

void Silent::SilentWindow::CloseDisplay()
{
    SDL_DestroyWindow(window->window);
}
