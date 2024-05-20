#include "../inc/init.hpp"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int nCmdShow) {
    // Pass window arguments
    WIN_ARGS w_args = WIN_ARGS(hInst, hPrevInst, args, nCmdShow);
    
    // Creates Window object
    WindowManager gui_initialize = WindowManager();

    // Set window to 800x600 resolution
    WIN_SETTINGS.width = 800;
    WIN_SETTINGS.height = 600;
    WIN_SETTINGS.winTitle = L"Project Euler Solver";
    WIN_SETTINGS.className = L"ProjectEulerWin";

    // Register window
    if ( !gui_initialize.register_window(w_args, WIN_SETTINGS))
        return -1;
    
    // Create window
    gui_initialize.create_window(w_args, WIN_SETTINGS);

    // Initialize GUI interface
    gui_initialize.gui_loop();
    return 0;
}