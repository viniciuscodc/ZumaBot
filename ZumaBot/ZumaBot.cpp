// ZumaBot.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

int main()
{
    bool gameStart{};
    while (true) {
        LPCWSTR window_title = L"Zuma Deluxe 1.1.0.0";
        HWND hWnd = FindWindow(NULL, window_title);

        if (hWnd != NULL && !gameStart) {
            hWnd = FindWindow(NULL, window_title);
            std::cout << "Game Started" << std::endl;
            gameStart = true;
            RECT rect = {};
            GetClientRect(hWnd, &rect);
            std::cout << "bottom: " << rect.bottom << " | " << "right: " << rect.right << std::endl;
        }

        Sleep(10);
        if (GetAsyncKeyState(VK_NUMPAD1)) {
            //HDC hDC = GetDC(hwnd);
            POINT p;
            GetCursorPos(&p);
            ScreenToClient(hWnd, &p);
            std::cout << "x position: " << p.x << " | " << "y position: " << p.y << std::endl;
            Sleep(1000);
        }
        if (GetAsyncKeyState(VK_NUMPAD2)) {
            HDC hDC = GetDC(hWnd);
            POINT p;
            GetCursorPos(&p);
            ScreenToClient(hWnd, &p);
            COLORREF color = GetPixel(hDC, p.x, p.y);
            ReleaseDC(hWnd, hDC);
            std::cout << "Red: " << (int)GetRValue(color) << " | Green: " << (int)GetGValue(color) 
                << "| Blue: " << (int)GetBValue(color) << std::endl;
            Sleep(1000);
        }
        if (GetAsyncKeyState(VK_NUMPAD3)) {
            Sleep(1000);
        }
        if (GetAsyncKeyState(VK_NUMPAD4)) {
            return 0;
        }

    }
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
