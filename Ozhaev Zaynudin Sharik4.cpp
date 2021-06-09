
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
    float x1 = 800/4;
    float y1 = 600/2;
    float x2 = 800/4*3;
    float y2 = 600/2;
    float r1 = 20;
    float r2 = 50;
    float vx1 = rand() % 10;
    float vy1 = rand() % 10;
    float vx2 = rand() % 10;
    float vy2 = rand() % 10;
    float dt = 1;

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

        float Dx = x1 - x2;
      	float Dy = y1 - y2;
      	float d = sqrt(Dx*Dx+Dy*Dy); if (d == 0) d = 0.01;
      	float s = Dx/d; // sin
      	float e = Dy/d; // cos
      	if (d < r1+r2){
      		float Vn1 = vx2*s + vy2*e;
      		float Vn2 = vx1*s + vy1*e;
      		float dt = (r2+r1-d)/(Vn1-Vn2);
      		if (dt > 0.6) dt = 0.6;
      		if (dt < -0.6) dt = -0.6;
      		x1-=vx1*dt;
      		y1-=vy1*dt;
      		x2-=vx2*dt;
      		y2-=vy2*dt;
      		Dx = x1 - x2;
      		Dy = y1 - y2;
      		d = sqrt(Dx*Dx+Dy*Dy); if (d == 0) d = 0.01;
      		s = Dx/d; // sin
      		e = Dy/d; // cos
      		Vn1 = vx2*s + vy2*e;
      		Vn2 = vx1*s + vy1*e;
      		float Vt1 = -vx2*e+vy2*s;
      		float Vt2 = -vx1*e+vy1*s;


      		float o = Vn2;
      		Vn2 = Vn1;
      		Vn1 = o;


      		vx1 = Vn2*s-Vt2*e;
      		vy1 = Vn2*e+Vt2*s;
      		vx2 = Vn1*s-Vt1*e;
      		vy2 = Vn1*e+Vt1*s;
      		x1+=vx1*dt;
      		y1+=vy1*dt;
      		x2+=vx2*dt;
      		y2+=vy2*dt;
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
