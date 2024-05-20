#include "../inc/init.hpp"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int nCmdShow) {
    // Pass window arguments
    WIN_ARGS w_args = WIN_ARGS(hInst, hPrevInst, args, nCmdShow);
    
    // Creates Window object
    InitProcess gui_initialize = InitProcess();

    // Set window to 1280x720 resolution
    WIN_SETTINGS.width = 1280;
    WIN_SETTINGS.height = 720;
    WIN_SETTINGS.winTitle = L"DreamScape Modpack Manager";
    WIN_SETTINGS.className = L"DreamScapeManager";

    // Register window
    if ( !gui_initialize.register_window(w_args, WIN_SETTINGS))
        return -1;
    
    // Create window
    gui_initialize.create_window(w_args, WIN_SETTINGS);

    // Initialize GUI interface
    gui_initialize.gui_loop();
    return 0;
}