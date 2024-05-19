#include "../inc/init.hpp"

const struct WIN_SETTINGS {
    int xpos = 100;
    int ypos = 100;
    int width = 800;
    int height = 600;
    LPCWSTR className = L"ProjectEulerWin";
    LPCWSTR winTitle = L"Project Euler Solver";
} WIN_SETTINGS;


int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int nCmdShow) {
    // Creates Window object
    InitProcess loop_initialize = InitProcess();

    // Register and create window
    if (!loop_initialize.register_window(hInst, hPrevInst, args, WIN_SETTINGS.className,
         WIN_SETTINGS.winTitle, NULL)) 
        return -1;

    loop_initialize.create_window(WIN_SETTINGS.xpos, WIN_SETTINGS.ypos, 
        WIN_SETTINGS.width, WIN_SETTINGS.height, NULL, NULL, NULL, NULL);

    // Initialize GUI interface
    loop_initialize.gui_loop();
    return 0;
}