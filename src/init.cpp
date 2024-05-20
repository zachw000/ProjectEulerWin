#include "../inc/init.hpp"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int nCmdShow) {
    // Pass window arguments
    WIN_ARGS wa = WIN_ARGS(hInst, hPrevInst, args, nCmdShow);
    
    // Creates Window object
    InitProcess loop_initialize = InitProcess();

    // Set window to 1280x720 resolution
    WIN_SETTINGS.width = 1280;
    WIN_SETTINGS.height = 720;

    // Register window
    if (!loop_initialize.register_window(wa, WIN_SETTINGS))
        return -1;
    
    // Create window
    loop_initialize.create_window(wa, WIN_SETTINGS);

    // Initialize GUI interface
    loop_initialize.gui_loop();
    return 0;
}