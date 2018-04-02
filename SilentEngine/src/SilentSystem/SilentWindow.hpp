#ifndef SILENT_WINDOW
#define SILENT_WINDOW
#include <iostream>
namespace SilentSystem
{
    enum renderingAPI
    {
        OpenGL,
        Vulkan,
        Software
    };

    class SilentWindow
    {
        //window properties
        public:
        std::string title;
        unsigned int width;
        unsigned int height;
        renderingAPI api;
        bool doubleBuffering;
        bool windowOpen;


        private:

        public:
        SilentWindow();
        ~SilentWindow();
        void createWindow();
        void updateWindow();


    };


}
#endif