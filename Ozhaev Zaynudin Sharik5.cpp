#include "TXLib.h"
const int W = 1100;
const int H = 720;

void MoveBall();
void DrowBall(int x, int y, int vx, int vy,int r, COLORREF Color, COLORREF FillColor);
void PhysicsBall(int* x, int* y, int* vx, int* vy, int dt, int r);
void Physics2Ball(int*  x1, int*  y1, int*  x2, int*  y2,
                  int* vx1, int* vy1, int* vx2, int* vy2,
                  int*  r1, int* r2, int dt);
void ControlBall(int x, int y, int* vx, int* vy);

//---------------------------------------------------------------------------------

int main()
    {
    txCreateWindow (W, H);

    MoveBall();

    return 0;
    }

//---------------------------------------------------------------------------------

void MoveBall()
    {
    srand(time(NULL));
      int  x1 = rand() % W,   y1 = rand() % H,
          vx1 = rand() % 10, vy1 = rand() % 10,
           r1 = 15 + rand() % 35;

      int x2 = rand() % W,   y2 = rand() % H,
         vx2 = rand() % 10, vy2 = rand() % 10,
          r2 = 15 + rand() % 35;

      int x3 = rand() % W,   y3 = rand() % H,
         vx3 = rand() % 10, vy3 = rand() % 10,
          r3 = 15 + rand() % 35;

      int x4 = rand() % W,   y4 = rand() % H,
         vx4 = rand() % 10, vy4 = rand() % 10,
          r4 = 15 + rand() % 35;

    int dt = 1;

    while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        txSetFillColor (TX_BLACK);
        txClear ();

        DrowBall(x1, y1, vx1, vy1, r1, TX_LIGHTBLUE , TX_BLUE );
        DrowBall(x2, y2, vx2, vy2, r2, TX_LIGHTRED  , TX_RED  );
        //DrowBall(x3, y3, vx3, vy3, r3, TX_LIGHTGREEN, TX_GREEN);
       // DrowBall(x4, y4, vx4, vy4, r4, TX_PINK      , TX_BROWN);

        PhysicsBall(&x1, &y1, &vx1, &vy1, dt, r1);
        PhysicsBall(&x2, &y2, &vx2, &vy2, dt, r2);
       // PhysicsBall(&x3, &y3, &vx3, &vy3, dt, r3);
        //PhysicsBall(&x4, &y4, &vx4, &vy4, dt, r4);

        Physics2Ball( &x1,  &y1,  &x2,  &y2,
                     &vx1, &vy1, &vx2, &vy2,
                      &r1, &r2, dt);

        ControlBall(x1, y1, &vx1, &vy1);

        txSleep (1);
        }
    }

//---------------------------------------------------------------------------------

void DrowBall(int x, int y, int vx, int vy, int r, COLORREF Color, COLORREF FillColor)
    {
    txSetColor (Color, 2);
    txSetFillColor (FillColor);

    txCircle (x, y, r);
    txLine (x, y, x + vx*5, y + vy*5);
    txCircle (x + vx*5, y + vy*5, 3);
    }

//---------------------------------------------------------------------------------

void ControlBall(int x, int y, int* vx, int* vy)
        {
        if (txGetAsyncKeyState (VK_RIGHT)) ++*vx;
        if (txGetAsyncKeyState (VK_LEFT))  --*vx;
        if (txGetAsyncKeyState (VK_UP))    --*vy;
        if (txGetAsyncKeyState (VK_DOWN))  ++*vy;

        if (txGetAsyncKeyState (VK_SPACE)) *vy = *vx = 0;

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
        }

//---------------------------------------------------------------------------------

void PhysicsBall(int* x, int* y, int* vx, int* vy, int dt, int r)
    {
    *x += *vx * dt;
    *y += *vy * dt;

    if (*x > W - r)
        {
         *vx =   - *vx;
          *x = W - r;
        }

    if (*y > H - r)
        {
         *vy =   - *vy;
          *y = H - r;
        }

    if (*x <   0 + r)
        {
         *vx = - *vx;
          *x = 0 + r;
        }

    if (*y <   0 + r)
        {
         *vy = - *vy;
          *y = 0 + r;
        }
    }

//---------------------------------------------------------------------------------

void Physics2Ball(int*  x1, int*  y1, int*  x2, int*  y2,
                  int* vx1, int* vy1, int* vx2, int* vy2,
                  int*  r1, int* r2, int dt)
    {
    float Dx = x1 - x2; // стороны треугольника
    float Dy = y1 - y2; // стороны треугольника
    float d = sqrt(Dx*Dx + Dy*Dy); if (d == 0) d = 0.01; //гипотенуза
    float sin = Dx/d; // sin угла треугольника
    float cos = Dy/d; // cos угла треугольника

    if (d < *r1 + *r2) //проверка столкновения
        {
        float Vn1 = *vx2*sin + *vy2*cos; //поворот системы координат шар1
        float Vn2 = *vx1*sin + *vy1*cos; //поворот системы координат шар2
        float Vt1 = -*vx2*cos + *vy2*sin; //поворот системы координат шар1
        float Vt2 = -*vx1*cos + *vy1*sin; //поворот системы координат шар2

        float o = Vn2; //меняем местами vn1 и vn2
        Vn2 = Vn1;
        Vn1 = o;

        *vx1 = Vn2*sin - Vt2*cos; //обратный поворот системы координат шар1
        *vy1 = Vn2*cos + Vt2*sin; //обратный поворот системы координат шар1
        *vx2 = Vn1*sin - Vt1*cos; //обратный поворот системы координат шар2
        *vy2 = Vn1*cos + Vt1*sin; //обратный поворот системы координат шар2

        *x1 = *x1 + *vx1*dt;
        *y1 = *y1 + *vy1*dt;
        *x2 = *x2 + *vx2*dt;
        *y2 = *y2 + *vy2*dt;
        }
    }
