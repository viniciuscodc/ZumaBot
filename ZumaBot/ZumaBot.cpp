// ZumaBot.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

int main()
{
    int width = 0;
    int height = 0;
    bool gameStart{};

    while (true) {
        LPCWSTR window_title = L"Zuma Deluxe 1.1.0.0";
        HWND hWnd = FindWindow(NULL, window_title);
        
        if (hWnd != NULL && !gameStart) {
            std::cout << "Game Started" << std::endl;

            hWnd = FindWindow(NULL, window_title);

            RECT rect = {};
            GetClientRect(hWnd, &rect);

            width = rect.right;
            height = rect.bottom;

            std::cout << "bottom: " << height << " | " << "right: " << width << std::endl;
            
            gameStart = true;
        }

        Sleep(10);
        if (GetAsyncKeyState(VK_NUMPAD1)) {
            //HDC hDC = GetDC(hwnd);
            POINT p;
            GetCursorPos(&p);
            //ScreenToClient(hWnd, &p);
            std::cout << "x position: " << p.x << " | " << "y position: " << p.y << std::endl;
            Sleep(1000);
        }

        if (GetAsyncKeyState(VK_NUMPAD2) && gameStart) {
            HDC hDC = GetDC(hWnd);
            COLORREF color;
            COLORREF baseColor = 8142474;

            printf("Botao pressionado");
            
            for (int x = 0; x < height; x++)
            {
                for (int y = 0; y < width; y++)
                {
                    color = GetPixel(hDC, x, y);
                    if (color == baseColor) {
                        printf("Encontrado x: %d | %d:",x,y);
                        return 0;
                    }
                }
            }

            ReleaseDC(hWnd, hDC);
            Sleep(1000);
        }

        if (GetAsyncKeyState(VK_NUMPAD3)) {
            HDC hDC = GetDC(hWnd);
            POINT p;
            GetCursorPos(&p);
            ScreenToClient(hWnd, &p);
            COLORREF color = GetPixel(hDC, p.x, p.y);
            ReleaseDC(hWnd, hDC);

            std::cout << "Color: " << color;
            /*
            std::cout << "Red: " << (int)GetRValue(color) << " | Green: " << (int)GetGValue(color)
                << "| Blue: " << (int)GetBValue(color) << std::endl;
            */

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
