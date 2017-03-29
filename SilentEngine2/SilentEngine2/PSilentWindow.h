#pragma once
#include <SDL.h>

namespace Silent {

    class Pwindow {
    public:
        SDL_Window* window;

        int centered = SDL_WINDOWPOS_CENTERED;
    };

}