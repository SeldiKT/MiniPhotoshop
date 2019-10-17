//Code Blocks: Project Build Options Linker settings Othoer linker options: add -lgdi32
#define _WIN32_WINNT 0x0500
#include "windows.h"
#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.14
int main(){
    HWND myconsole = GetConsoleWindow();
    HDC mydc = GetDC(myconsole);
    int pixel =0;
    COLORREF COLOR= RGB(255,255,255);

    //Draw pixels
    for(double i = 0; i < PI * 4; i += 0.05)
    {
        SetPixel(mydc,pixel,(int)(50+25*cos(i)),COLOR);
        pixel+=1;
    }

    ReleaseDC(myconsole, mydc);
    cin.ignore();
    return 0;
}
