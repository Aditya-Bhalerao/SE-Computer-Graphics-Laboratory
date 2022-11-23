// Write C++ program to draw the following pattern. Use DDA and Bresenham‘s Line
// drawing algorithm.

#include <iostream>
#include <graphics.h>

using namespace std;

// *****DDA Algorithm Definition*****
void DDAAlgorithm(int a1, int b1, int a2, int b2)
{
    int dx = a2 - a1;
    int dy = b2 - b1;
    int steps = dx > dy ? dx : dy;
    float aInc = dx / (float) steps;
    float bInc = dy / (float) steps;
    float a = a1;
    float b = b1;
    for (int i = 0; i <= steps; i++)
    {
        putpixel(a, b, WHITE);
        a += aInc;
        b += bInc;
    }
}
// Display Function to Display All 8 Parts of Circle
void DisplayCircle(int ac, int bc, int a, int b)
{
    putpixel(ac + a, bc + b, BLUE);
    putpixel(ac - a, bc + b, BLUE);
    putpixel(ac + a, bc - b, BLUE);
    putpixel(ac - a, bc - b, BLUE);
    putpixel(ac + b, bc + a, BLUE);
    putpixel(ac - b, bc + a, BLUE);
    putpixel(ac + b, bc - a, BLUE);
    putpixel(ac - b, bc - a, BLUE);
}
//*****Bresenham's Circle Drawing Algorithm Definition*****
void BresenhamsCircle(int a1, int b1, int r)
{
    int a = 0, b = r;
    int d = 3 - 2 * r;
//    DisplayCircle(a1, b1, a, b);
    while (a <= b)
    {
        a++;
        if (d > 0)
        {
            b--;
            d = d + 4 * (a - b) + 10;
        }
        else
        {
            d = d + 4 * a + 6;
        }
        DisplayCircle(a1, b1, a, b);
    }
}
int main()
{
    initwindow(900, 900, "Pattern_1.cpp");
    BresenhamsCircle(450, 480, 57);
    BresenhamsCircle(450, 480, 57 / 2);
    DDAAlgorithm(402, 450, 498, 450);
    DDAAlgorithm(402, 450, 450, 536);
    DDAAlgorithm(450, 536, 498, 450);
    getch();
    closegraph();
    return 0;
}
