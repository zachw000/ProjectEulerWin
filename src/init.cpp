#include "../inc/init.hpp"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int nCmdShow) {
    // Pass window arguments
    WIN_ARGS w_args = WIN_ARGS(hInst, hPrevInst, args, nCmdShow);
    
    // Creates Window object
    WindowManager gui_initialize = WindowManager();

    // Set window to 800x600 resolution
    gui_initialize.WIN_SETTINGS.width = 1536;
    gui_initialize.WIN_SETTINGS.height = 864;
    gui_initialize.WIN_SETTINGS.winTitle = L"Project Euler Solver";
    gui_initialize.WIN_SETTINGS.className = L"ProjectEulerWin";

    // Register window
    if ( !gui_initialize.register_window(w_args))
        return -1;
    
    // Create window
    gui_initialize.create_window(w_args);

    // Initialize GUI interface
    gui_initialize.gui_loop();
    return 0;
}