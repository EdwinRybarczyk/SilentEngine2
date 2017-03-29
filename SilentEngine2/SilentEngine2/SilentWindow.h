#pragma once
#include <iostream>

namespace Silent{

    class Pwindow;
	class SilentWindow 
    {
    public:
        SilentWindow();

        void InitializeDisplay();
		void OpenDisplay(
            char* title = "Silent Game Engine",

            int Width = 600,
            int Height = 400,

            int PositionX = NULL,
            int PositionY = NULL,

            bool FullScreen = false
        );

		void UpdateDisplay();
		void CloseDisplay();

    private:
        Pwindow* window;   

	};


}