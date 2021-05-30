
#include "TXLib.h"

void MpveBall();

int main()
    {
    txCreateWindow (800, 600);

    MpveBall();

    return 0;
    }

void MpveBall()
    {
     int x  = 100, y  = 100,
         vx =   5, vy =   3,
         r = 20;

     int dt = 1;

     int x2  = 150, y2  = 110,
         vx2 =   3, vy2 =   4,
         r2 = 30;

     int dt2 = 1;
     txSetColor (TX_LIGHTGREEN, 2);
     txSetFillColor (TX_GREEN);

     while (!txGetAsyncKeyState (VK_ESCAPE))
        {

        txCircle (x, y, r);

        x += vx * dt;
        y += vy * dt;

        if (x > 800 - r)
            {
             vx = -vx;
             x = 800 - r;
            }

        if (y > 600 - r)
            {
             vy = -vy;
             y = 600 - r;
            }

        if (x < 0 + r)
            {
             vx = -vx;
             x = 0 + r;
            }

        if (y < 0 + r)
            {
             vy = -vy;
             y = 0 + r;
            }
    //________________________________________________________________
        txSetColor (TX_LIGHTYELLOW, 2);
        txSetFillColor (TX_YELLOW);

        txCircle (x2, y2, r2);

        x2 += vx2 * dt2;
        y2 += vy2 * dt2;

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
