
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

        //x1 += vx1 * dt;
       // y1 += vy1 * dt;

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

       // x2 += vx2 * dt;
        //y2 += vy2 * dt;

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

            float Dx = x1 - x2;
      	float Dy = y1 - y2;
      	float d = sqrt(Dx*Dx+Dy*Dy); if (d == 0) d = 0.01;
      	float s = Dx/d; // sin
      	float e = Dy/d; // cos
      	if (d < r1+r2){
      		float Vn1 = dx2*s + dy2*e;
      		float Vn2 = dx1*s + dy1*e;
      		float dt = (r2+r1-d)/(Vn1-Vn2);
      		if (dt > 0.6) dt = 0.6;
      		if (dt < -0.6) dt = -0.6;
      		x1-=dx1*dt;
      		y1-=dy1*dt;
      		x2-=dx2*dt;
      		y2-=dy2*dt;
      		Dx = x1 - x2;
      		Dy = y1 - y2;
      		d = sqrt(Dx*Dx+Dy*Dy); if (d == 0) d = 0.01;
      		s = Dx/d; // sin
      		e = Dy/d; // cos
      		Vn1 = dx2*s + dy2*e;
      		Vn2 = dx1*s + dy1*e;
      		float Vt1 = -dx2*e+dy2*s;
      		float Vt2 = -dx1*e+dy1*s;


      		float o = Vn2;
      		Vn2 = Vn1;
      		Vn1 = o;


      		dx1 = Vn2*s-Vt2*e;
      		dy1 = Vn2*e+Vt2*s;
      		dx2 = Vn1*s-Vt1*e;
      		dy2 = Vn1*e+Vt1*s;
      		x1+=dx1*dt;
      		y1+=dy1*dt;
      		x2+=dx2*dt;
      		y2+=dy2*dt;
      	}



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
