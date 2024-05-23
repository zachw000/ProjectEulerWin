#pragma once

// STD Includes
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <math.h>
#include <windows.h>

typedef struct WIN_ARGS {
    HINSTANCE hInst;
    HINSTANCE hPrevInst;
    LPSTR args;
    int nCmdShow;

    WIN_ARGS() {
        hInst = NULL;
        hPrevInst = NULL;
        args = NULL;
        nCmdShow = NULL;
    }

    WIN_ARGS(HINSTANCE instH, HINSTANCE prevInstH, LPSTR argv, int cmdShowN) {
        hInst = instH;
        hPrevInst = prevInstH;
        args = argv;
        nCmdShow = cmdShowN;
    }
    
} WIN_ARGS;

class WindowManager {
public:
    struct WIN_SETTINGS {
        int xpos = WindowManager::DEFAULT_XY;
        int ypos = WindowManager::DEFAULT_XY;
        int width = WindowManager::DEFAULT_DIM_X;
        int height = WindowManager::DEFAULT_DIM_Y;
        LPCWSTR className = L"DefaultWin";
        LPCWSTR winTitle = L"Default Window";
    } WIN_SETTINGS;

    WindowManager() {
        tkns = {""};
        wc = nullptr;
        hInst = NULL;
        hPrevInst = NULL;
        args = NULL;
        className = L"";
        winTitle = L"";
        nCmdShow = NULL;
        msg = { 0 };
    }

    WindowManager(WNDCLASSW *window, HINSTANCE instH, HINSTANCE prevInstH, LPSTR argv, LPCWSTR class_name, LPCWSTR win_title)
    : wc(window), hInst(instH), args(argv), className(class_name), winTitle(win_title) {
        msg = { 0 };
    }

    ~WindowManager() {
        wc = nullptr;
        hInst = NULL;
        hPrevInst = NULL;
        args = NULL;
        className = L"";
        winTitle = L"";
        nCmdShow = NULL;
        msg = { 0 };
    }

    bool register_window(WIN_ARGS wa) {
        hInst = wa.hInst;
        hPrevInst = wa.hPrevInst;
        args = wa.args;
        className = WIN_SETTINGS.className;
        winTitle = WIN_SETTINGS.winTitle;
        nCmdShow = wa.nCmdShow;

        return startWin();
    }

    bool register_window(HINSTANCE instH, HINSTANCE prevInstH, LPSTR argv, LPCWSTR class_name, LPCWSTR win_title, int cmdShowN) {
        hInst = instH;
        hPrevInst = prevInstH;
        args = argv;
        className = class_name;
        winTitle = win_title;
        nCmdShow = cmdShowN;

        return startWin();
    }

    void create_window(int posx, int posy, int wx, int hy, HWND parentH, HMENU menuH, HINSTANCE instH, LPVOID lp) {
        CreateWindowW(className, winTitle, WS_OVERLAPPEDWINDOW | WS_VISIBLE, posx, posy, wx, hy, parentH, menuH, instH, lp);
    }

    void create_window(WIN_ARGS wa) {
        CreateWindowW(className, winTitle, WS_OVERLAPPEDWINDOW | WS_VISIBLE, WIN_SETTINGS.xpos, WIN_SETTINGS.ypos, WIN_SETTINGS.width, WIN_SETTINGS.height, NULL, NULL, NULL, NULL);
    }

    /// @brief Initializes loop for running GUI application.
    /// @return int exit_code
    int gui_loop() {
        while ( GetMessageW(&msg, NULL, NULL, NULL) ) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        return 0;
    }

    // Define default constants
    const static int DEFAULT_XY =  100;
    const static int DEFAULT_DIM_X = 800;
    const static int DEFAULT_DIM_Y = 600;
private:
    void init_cmd_loop() {
        // TODO: Implement
    }

    void process_args(int prblm, std::vector<std::string>& tkn_in) {
        for (const std::string &token : tkn_in) {
            init_cmd_loop();
        }
    }

    bool startWin() {
        WNDCLASSW wcw;
        wcw = {0};
        wc = &wcw;

        wc->hbrBackground = (HBRUSH)COLOR_WINDOW;
        wc->hCursor = LoadCursor(NULL, IDC_ARROW);
        wc->hInstance = hInst;
        wc->lpszClassName = className;
        wc->lpfnWndProc = this->WindowProc;

        return RegisterClassW(wc);
    }

    MSG msg;
    std::vector<std::string> tkns;
    WNDCLASSW *wc;
    HINSTANCE hInst;
    HINSTANCE hPrevInst;
    LPSTR args;
    LPCWSTR className;
    LPCWSTR winTitle;

    int nCmdShow;
protected:
    static LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
        switch (msg)
        {
            case WM_DESTROY:
                PostQuitMessage(0);
                break;
            default:
                return DefWindowProcW(hWnd, msg, wp, lp);
        }
        return NULL;
    }
};