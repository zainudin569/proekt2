
#include "TXLib.h"

void MoveBall();
void DrowBall(int x, int y, int vx, int vy, COLLORREF Color, COLLORREF FillColor);

int main()
    {
    txCreateWindow (800, 600);

    MoveBall();

    return 0;
    }

void MoveBall()
    {
     int x1 = 100,  y1 = 100,
        vx1 =   5, vy1 =   3,
         r1 =  20;

     int x2 = 100,  y2 = 100,
        vx2 =   5, vy2 =   3,
         r2 =  20;

     int x3 = 100,  y3 = 100,
        vx3 =   5, vy3 =   3,
         r3 =  20;

     int dt = 1;

     while (!txGetAsyncKeyState (VK_ESCAPE))
        {

        DrowBall(x1, y1, vx1, vy1, TX_LIGHTBLUE , TX_BLUE);
        DrowBall(x2, y2, vx2, vy2, TX_LIGHTRED  , TX_RED);
        DrowBall(x2, y2, vx2, vy2, TX_LIGHTGREEN, TX_GREEN);

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

void DrowBall(int x, int y, int vx, int vy, COLLORREF Color, COLLORREF FillColor)
    {
    txSetColor (Color, 2);
    txSetFillColor (FillColor);

    txCircle (x, y, r);
    txLine (x, y, x + vx*5, y + vy*5);
    txCircle (x + vx*5, y + vy*5, 3);
    }
