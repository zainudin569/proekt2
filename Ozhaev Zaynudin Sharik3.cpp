
#include "TXLib.h"

void MoveBall();
void DrowBall(int x, int y, int vx, int vy,int r, COLORREF Color, COLORREF FillColor);
void PhysicsBall(int* x, int* y, int* vx, int* vy, int dt, int r);

int main()
    {
    txCreateWindow (800, 600);

    MoveBall();

    return 0;
    }

void MoveBall()
    {
     int x1 = 100,  y1 = 100,
        vx1 =   2, vy1 =   3,
         r1 =  10;

     int x2 = 150,  y2 = 110,
        vx2 =   7, vy2 =   2,
         r2 =  25;

     int x3 = 100,  y3 = 150,
        vx3 =   5, vy3 =   3,
         r3 =  15;

     int dt = 1;

     while (!txGetAsyncKeyState (VK_ESCAPE))
        {

        DrowBall(x1, y1, vx1, vy1, r1, TX_LIGHTBLUE , TX_BLUE);
        DrowBall(x2, y2, vx2, vy2, r2, TX_LIGHTRED  , TX_RED);
        DrowBall(x3, y3, vx3, vy3, r3, TX_LIGHTGREEN, TX_GREEN);

        PhysicsBall(&x1, &y1, &vx1, &vy1, dt, r1);
        PhysicsBall(&x2, &y2, &vx2, &vy2, dt, r2);
        PhysicsBall(&x3, &y3, &vx3, &vy3, dt, r3);

        if (txGetAsyncKeyState (VK_RIGHT)) vx1++;
        if (txGetAsyncKeyState (VK_LEFT))  vx1--;
        if (txGetAsyncKeyState (VK_UP))    vy1--;
        if (txGetAsyncKeyState (VK_DOWN))  vy1++;

        if (txGetAsyncKeyState (VK_SPACE)) vy1 = vx1 = 0;

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
            txSetColor     (RGB(x1,   y1,   150), 2);
            txSetFillColor (RGB(x1/2, y1/2, 150));
            }
        txSleep (1);
        }
    }

void DrowBall(int x, int y, int vx, int vy, int r, COLORREF Color, COLORREF FillColor)
    {
    txSetColor (Color, 2);
    txSetFillColor (FillColor);

    txCircle (x, y, r);
    txLine (x, y, x + vx*5, y + vy*5);
    txCircle (x + vx*5, y + vy*5, 3);
    }

void PhysicsBall(int* x, int* y, int* vx, int* vy, int dt, int r)
    {
    *x += *vx * dt;
    *y += *vy * dt;

    if (*x > 800 - r)
        {
         *vx = -*vx;
         *x = 800 - r;
        }

    if (*y > 600 - r)
        {
         *vy = -*vy;
         *y = 600 - r;
        }

    if (*x < 0 + r)
        {
         *vx = -*vx;
         *x = 0 + r;
        }

    if (*y < 0 + r)
        {
         *vy = -*vy;
         *y = 0 + r;
        }
    }
