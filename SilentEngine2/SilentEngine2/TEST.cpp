
#include "SilentWindow.h"

int main() {
    using namespace Silent;

    SilentWindow* window = new SilentWindow();

    bool running = true;

    window->InitializeDisplay();
    window->OpenDisplay();

    while (running) {
        window->UpdateDisplay();
    }

    window->CloseDisplay();
	return 0;
}