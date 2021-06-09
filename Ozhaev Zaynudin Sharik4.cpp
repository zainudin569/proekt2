
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
    int x1 = rand() % W;
    int y1 = rand() % H;
    int x2 = rand() % W;
    int y2 = rand() % H;
    int r1 = 15 + rand() % 35;
    int r2 = 15 + rand() % 35;
    int vx1 = rand() % 10;
    int vy1 = rand() % 10;
    int vx2 = rand() % 10;
    int vy2 = rand() % 10;
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

        float Dx = x1 - x2; // стороны треугольника
      	float Dy = y1 - y2; // стороны треугольника
      	double d = sqrt(Dx*Dx + Dy*Dy); if (d == 0) d = 0.01; //гипотенуза
      	float s = Dx/d; // sin угла треугольника
      	float e = Dy/d; // cos угла треугольника

      	if (d < r1 + r2) //проверка столкновения
            {
      		float Vn1 = vx2*s + vy2*e; //поворот системы координат шар1
      		float Vn2 = vx1*s + vy1*e; //поворот системы координат шар2
      		float Vt1 = -vx2*e + vy2*s; //поворот системы координат шар1
      		float Vt2 = -vx1*e + vy1*s; //поворот системы координат шар2

      		float o = Vn2; //меняем местами vn1 и vn2
      		Vn2 = Vn1;
      		Vn1 = o;

      		vx1 = Vn2*s - Vt2*e; //обратный поворот системы координат шар1
      		vy1 = Vn2*e + Vt2*s; //обратный поворот системы координат шар1
      		vx2 = Vn1*s - Vt1*e; //обратный поворот системы координат шар2
      		vy2 = Vn1*e + Vt1*s; //обратный поворот системы координат шар2

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
