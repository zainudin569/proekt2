
#include "TXLib.h"
const int W = 1100;
const int H = 720;

void MoveBall();

int main()
    {
    txCreateWindow (W, H);

    MoveBall();

    return 0;
    }

void MoveBall()
    {
    srand(time(NULL));
    float x1 = rand() % W;
    float y1 = rand() % H;
    float x2 = rand() % W;
    float y2 = rand() % H;
    float r1 = 15 + rand() % 35;
    float r2 = 15 + rand() % 35;
    float vx1 = rand() % 10;
    float vy1 = rand() % 10;
    float vx2 = rand() % 10;
    float vy2 = rand() % 10;
    float dt = 1;

    while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        txSetFillColor (TX_BLACK);
        txClear ();

        txSetColor (TX_LIGHTGREEN, 2);
        txSetFillColor (TX_GREEN);

        txCircle (x1, y1, r1);

        x1 += vx1 * dt;
        y1 += vy1 * dt;

        if (x1 > W - r1)
            {
             vx1 = -vx1;
             x1 = W - r1;
            }

        if (y1 > H - r1)
            {
             vy1 = -vy1;
             y1 = H - r1;
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
    //------------------------------------------------------------
        txSetColor (TX_LIGHTRED, 2);
        txSetFillColor (TX_RED);

        txCircle (x2, y2, r2);

        x2 += vx2 * dt;
        y2 += vy2 * dt;

        if (x2 > W - r2)
            {
             vx2 = -vx2;
             x2 = W - r2;
            }

        if (y2 > H - r2)
            {
             vy2 = -vy2;
             y2 = H - r2;
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

        float Dx = x1 - x2; // ??????? ????????????
      	float Dy = y1 - y2; // ??????? ????????????
      	float d = sqrt(Dx*Dx + Dy*Dy); if (d == 0) d = 0.01; //??????????
      	float sin = Dx/d; // sin ???? ????????????
      	float cos = Dy/d; // cos ???? ????????????

      	if (d < r1 + r2) //???????? ????????????
            {
      		float Vn1 = vx2*sin + vy2*cos; //??????? ??????? ????????? ???1
      		float Vn2 = vx1*sin + vy1*cos; //??????? ??????? ????????? ???2
            float Vt1 = -vx2*cos + vy2*sin; //??????? ??????? ????????? ???1
      		float Vt2 = -vx1*cos + vy1*sin; //??????? ??????? ????????? ???2

      		float o = Vn2; //?????? ??????? vn1 ? vn2
      		Vn2 = Vn1;
      		Vn1 = o;

      		vx1 = Vn2*sin - Vt2*cos; //???????? ??????? ??????? ????????? ???1
      		vy1 = Vn2*cos + Vt2*sin; //???????? ??????? ??????? ????????? ???1
      		vx2 = Vn1*sin - Vt1*cos; //???????? ??????? ??????? ????????? ???2
      		vy2 = Vn1*cos + Vt1*sin; //???????? ??????? ??????? ????????? ???2

      		x1 = x1 + vx1*dt;
      		y1 = y1 + vy1*dt;
      		x2 = x2 + vx2*dt;
      		y2 = y2 + vy2*dt;
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
