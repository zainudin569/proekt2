#include "TXLib.h"
const int W = 1100;
const int H = 720;

struct Ball
    {
    int  x, y , vx, vy;

    int r;

    COLORREF Color;
    COLORREF FillColor;
    };

//---------------------------------------------------------------------------------

void MoveBall();
void DrowBall(Ball ball);
void PhysicsBall(Ball* ball, int dt);
void Physics2Ball(int*  x1, int*  y1, int*  x2, int*  y2,
                  int* vx1, int* vy1, int* vx2, int* vy2,
                  int*  r1, int* r2, int dt);
void ControlBall(Ball* ball);

//void bilo_stolknov (double xA, double yA, double xB, double yB, double rA, double rB)
//double Distansce (double x1, double y1, double x2, double y2);

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

    Ball ball1 = { rand() % W,  rand() % H,
                  rand() % 10, rand() % 10,
                  15 + rand() % 35,
                  TX_LIGHTBLUE, TX_BLUE };

    Ball ball2 = { rand() % W,  rand() % H,
                  rand() % 10, rand() % 10,
                  15 + rand() % 35,
                  TX_LIGHTRED, TX_RED };

    Ball ball3 = { rand() % W,  rand() % H,
                  rand() % 10, rand() % 10,
                  15 + rand() % 35,
                  TX_LIGHTGREEN, TX_GREEN };

    Ball ball4 = { rand() % W,  rand() % H,
                  rand() % 10, rand() % 10,
                  15 + rand() % 35,
                  TX_PINK , TX_BROWN };

    int dt = 1;

    while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        txSetFillColor (TX_BLACK);
        txClear ();

        DrowBall(ball1);
        DrowBall(ball2);
        DrowBall(ball3);
        DrowBall(ball4);

        //printf ("In CraziBall(): x  = %d and y  = %d\n", x2, y2);
        //printf ("In CraziBall(): vx = %d and vy = %d\n", vx2, vy2);

        PhysicsBall(&ball1, dt);
        PhysicsBall(&ball2, dt);
        PhysicsBall(&ball3, dt);
        PhysicsBall(&ball4, dt);

        /*Physics2Ball( &x1,  &y1,  &x2,  &y2,
                     &vx1, &vy1, &vx2, &vy2,
                      &r1, &r2, dt);*/
        /*int bilo_li_ono = bilo_stolknov (x1, y1, x2, y2, r1, r2);
        if (bilo_li_ono)
            {
            Bam_balls (x1, y1, &vx1, &vy1, x2, y2, &vx2, &vy2);
            }
        Ball_Control (&vx1, &vy1);
        */
        //ControlBall(x1, y1, &vx1, &vy1);

        txSleep (1);
        }
    }

//---------------------------------------------------------------------------------

void DrowBall(Ball ball)
    {
    txSetColor ((ball .Color), 2);
    txSetFillColor (ball .FillColor);

    txCircle (ball .x, ball .y, ball .r);
    //txLine (x, y, x + vx*5, y + vy*5);
    //txCircle (x + vx*5, y + vy*5, 3);
    }

//---------------------------------------------------------------------------------

void ControlBall(Ball* ball)
        {
        if (txGetAsyncKeyState (VK_RIGHT)) ++(*ball) .vx;
        if (txGetAsyncKeyState (VK_LEFT))  --(*ball) .vx;
        if (txGetAsyncKeyState (VK_UP))    --(*ball) .vy;
        if (txGetAsyncKeyState (VK_DOWN))  ++(*ball) .vy;

        if (txGetAsyncKeyState (VK_SPACE)) (*ball) .vy = (*ball) .vx = 0;

        if (txGetAsyncKeyState (VK_F1))
            {
            (*ball) .Color = TX_LIGHTRED;
            (*ball) .SetFillColor = TX_RED;
            }
        if (txGetAsyncKeyState (VK_F2))
            {
            (*ball) .Color = TX_LIGHTBLUE;
            (*ball) .FillColor = TX_BLUE;
            }
        if (txGetAsyncKeyState (VK_F3))
            {
            (*ball) .Color = TX_LIGHTGREEN;
            (*ball) .FillColor = TX_GREEN;
            }
        if (txGetAsyncKeyState (VK_F4))
            {
            (*ball) .Color     = RGB(*ball .x,   *ball .y,   150);
            (*ball) .FillColor = RGB(*ball .x/2, *ball .y/2, 150);
            }
        }

//---------------------------------------------------------------------------------

void PhysicsBall(Ball* ball, int dt)
    {
    (*ball) .x += (*ball) .vx * dt;
    (*ball) .y += (*ball) .vy * dt;

    if ((*ball) .x  > W - (*ball) .r)
        {
        (*ball) .vx =   - (*ball) .vx;
        (*ball) .x  = W - (*ball) .r;
        return;
        }

    if ((*ball) .y  > H - (*ball) .r)
        {
        (*ball) .vy =   - (*ball) .vy;
        (*ball) .y  = H - (*ball) .r;
        return;
        }

    if ((*ball) .x <  0 + (*ball) .r)
        {
        (*ball) .vx =   - (*ball) .vx;
        (*ball) .x  = 0 + (*ball) .r;
        return;
        }

    if ((*ball) .y <   0 + (*ball) .r)
        {
        (*ball) .vy =   - (*ball) .vy;
        (*ball) .y  = 0 + (*ball) .r;
        return;
        }
    }

//---------------------------------------------------------------------------------

/*void bilo_stolknov (double xA, double yA, double xB, double yB, double rA, double rB)
    {
    return (Distansce (xA, yA, xB, yB) <= r1 + r2);
    }

//---------------------------------------------------------------------------------

double Distansce (double x1, double y1, double x2, double y2);
    {
    double answer= sqrt((x1 - x2) * (x1 - x2) + (y1 - y2)* (y1 - y2));

    printf ("In Distance(): answer = %lg\n ", answer;

    return answer;
    }

viod Bam_balls (int* x, int* y, int* vx, int* vy);
    {
    *vx = -(*xv);
    *x = *x - r;
    *vy = -(*xy);
    *y = *y - r;
    }

    */

//---------------------------------------------------------------------------------

void Physics2Ball(int*  x1, int*  y1, int*  x2, int*  y2,
                  int* vx1, int* vy1, int* vx2, int* vy2,
                  int*  r1, int* r2, int dt)
{
    float Dx = *x1 - *x2; // стороны треугольника
    float Dy = *y1 - *y2; // стороны треугольника
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
