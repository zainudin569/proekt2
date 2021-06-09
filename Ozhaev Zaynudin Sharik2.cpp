
#include "TXLib.h"

void MoveBall();

int main()
    {
    txCreateWindow (800, 600);

    MoveBall();

    return 0;
    }

void MoveBall()
    {
    int x1  = 100, y1  = 100,
        vx1 =   5, vy1 =   3,
        r1 = 20;

    int dt = 1;

    int x2  = 150, y2  = 110,
        vx2 =   3, vy2 =   4,
        r2 = 30;

    txSetColor (TX_LIGHTGREEN, 2);
    txSetFillColor (TX_GREEN);

    while (!txGetAsyncKeyState (VK_ESCAPE))
        {

        txCircle (x1, y1, r1);

        x1 += vx1 * dt;
        y1 += vy1 * dt;

        if (x1 > 800 - r1)
            {
             vx1 = -vx1;
             x1 = 800 - r1;
            }

        if (y1 > 600 - r1)
            {
             vy1 = -vy1;
             y1 = 600 - r1;
            }

        if (x1 < 0 + r1)
            {
             vx1 = -vx1;
             x1 = 0 + r1;
            }

        if (y1 < 0 + r1)
            {
             vy1 = -vy1;
             y1 = 0 + r1;
            }
    //________________________________________________________________
        txSetColor (TX_LIGHTRED, 2);
        txSetFillColor (TX_RED);

        txCircle (x2, y2, r2);

        x2 += vx2 * dt;
        y2 += vy2 * dt;

        if (x2 > 800 - r2)
            {
             vx2 = -vx2;
             x2 = 800 - r2;
            }

        if (y2 > 600 - r2)
            {
             vy2 = -vy2;
             y2 = 600 - r2;
            }

        if (x2 < 0 + r2)
            {
             vx2 = -vx2;
             x2 = 0 + r2;
            }

        if (y2 < 0 + r2)
            {
             vy2 = -vy2;
             y2 = 0 + r2;
            }

        if (txGetAsyncKeyState (VK_RIGHT)) vx++;
        if (txGetAsyncKeyState (VK_LEFT))  vx--;
        if (txGetAsyncKeyState (VK_UP))    vy--;
        if (txGetAsyncKeyState (VK_DOWN))  vy++;

        if (txGetAsyncKeyState (VK_SPACE)) vy = vx = 0;

        if (txGetAsyncKeyState (VK_F1))
            {
            txSetColor (TX_LIGHTRED, 2);
            txSetFillColor (TX_RED);
            }
        if (txGetAsyncKeyState (VK_F2))
            {
            txSetColor (TX_LIGHTBLUE, 2);
            txSetFillColor (TX_BLUE);
            }
        if (txGetAsyncKeyState (VK_F3))
            {
            txSetColor (TX_LIGHTGREEN, 2);
            txSetFillColor (TX_GREEN);
            }
        if (txGetAsyncKeyState (VK_F4))
            {
            txSetColor     (RGB(x,   y,   150), 2);
            txSetFillColor (RGB(x/2, y/2, 150));
            }
        txSleep (1);
        }
    }
