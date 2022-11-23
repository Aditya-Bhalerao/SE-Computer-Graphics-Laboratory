// Write C++ program to draw the following pattern. Use DDA and Bresenham‘s drawing
// algorithm.

#include <iostream>
#include <graphics.h>
#include <dos.h>

int Sign(int a)
{
    if (a < 0) return -1;
    else if (a > 0) return 1;
    else return 0;
}
// Bresenham's Line Drawing Algorithm Definition
void Bresenhamsline(int a1, int b1, int a2, int b2, int color)
{
    int dx, dy, p, a, b, i = 1;
    dx = a2 - a1;
    dy = b2 - b1;
    a = a1;
    b = b1;
    p = 2 * dy - dx;
    while (i <= dx)
    {
        while (p >= 0)
        {
            b++;
            p = p - 2 * dx;
            delay(2);
        }
        a++;
        p = p + 2 * dy;
        putpixel(a, b, color);
        i++;
    }
}
// DDA Line Algorithm Definition
void DDALine(int a1, int b1, int a2, int b2, int color)
{
    int a, b, len, i;
    float dx, dy;
    if (a1 == a2 && b1 == b2) putpixel(a1, b1, color);
    else
    {
        dx = a2 - a1;
        dy = b2 - b1;
        if (dx > dy) len = dx;
        else
            len = dy;
        dx = (a2 - a1) / len;
        dy = (b2 - b1) / len;
        a = a1 + 0.5 * Sign(dx);
        b = b1 + 0.5 * Sign(dy);
        i = 1;
        while (i < len)
        {
            putpixel(a, b, color);
            a = a + dx;
            b = b + dy;
            i++;
            delay(2);
        }
    }
}
int main()
{
    int ch, col, a1, a2, b1, b2;
    initwindow(1000, 600, "Pattern_2.cpp");
    DDALine(350, 350, 350, 500, 2); // Left Vertical
    DDALine(350, 350, 650, 350, 4); // Up Horizontal
    DDALine(650, 350, 650, 500, 6); // Right Vertical
    DDALine(350, 500, 650, 500, 7); // Down Horizontal
    DDALine(500, 350, 350, 425, 9); // Diamond Up Left
    Bresenhamsline(350, 425, 500, 500, 12); // Diamond Left, Down
    DDALine(650, 425, 500, 500, 14); // Diamond Down, Right
    Bresenhamsline(500, 350, 650, 425, 3); // Diamond Right, Up
    DDALine(575, 387, 575, 463, 4); // In Right
    DDALine(425, 387, 575, 387, 5); // In Up
    DDALine(425, 387, 425, 463, 6); // In Left
    DDALine(425, 463, 575, 463, 2); // In Down
    getch();
    closegraph();
    return 0;
}
