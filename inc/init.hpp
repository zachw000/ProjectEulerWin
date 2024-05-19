#pragma once
#ifndef INIT
#define INIT
// STD Includes
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <math.h>
#include <windows.h>

class InitProcess {
public:
    InitProcess() {
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

    InitProcess(WNDCLASSW *window, HINSTANCE instH, HINSTANCE prevInstH, LPSTR argv, LPCWSTR class_name, LPCWSTR win_title) {
        wc = window;
        hInst = instH;
        args = argv;
        className = class_name;
        winTitle = win_title;
        msg = { 0 };
    }

    ~InitProcess() {
        wc = nullptr;
        hInst = NULL;
        hPrevInst = NULL;
        args = NULL;
        className = L"";
        winTitle = L"";
        nCmdShow = NULL;
        msg = { 0 };
    }

    bool register_window(HINSTANCE instH, HINSTANCE prevInstH, LPSTR argv, LPCWSTR class_name, LPCWSTR win_title, int nCmdShow) {
        hInst = instH;
        hPrevInst = prevInstH;
        args = argv;
        className = class_name;
        winTitle = win_title;

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

    void create_window(int posx, int posy, int wx, int hy, HWND parentH, HMENU menuH, HINSTANCE instH, LPVOID lp) {
        CreateWindowW(className, winTitle, WS_OVERLAPPEDWINDOW | WS_VISIBLE, posx, posy, wx, hy, parentH, menuH, instH, lp);
    }

    int gui_loop() {
        while ( GetMessageW(&msg, NULL, NULL, NULL) ) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        return 0;
    }

private:
    void init_cmd_loop() {
        // TODO: Implement
    }

    void process_args(int prblm, std::vector<std::string>& tkn_in) {
        for (const std::string &token : tkn_in) {
            init_cmd_loop();
        }
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
#endif