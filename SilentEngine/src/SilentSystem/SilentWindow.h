#include <iostream>
#ifndef SILENT_WINDOW
#define SILENT_WINDOW
namespace SilentSystem
{
    class SilentWindow
    {
        private:
        int width;
        int height;
        const char* title;
        char renderingAPI;

        public:
        SilentWindow(int width = 1280,int height = 720,
            const char* title = "Silent Game Engine",
            char renderingAPI = 0
        );
        ~SilentWindow();


    };


}

#endif //SILENT_WINDOW