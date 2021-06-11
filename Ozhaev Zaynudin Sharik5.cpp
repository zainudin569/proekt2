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
void CollisionBall(Ball* ball_1, Ball* ball_2, int dt);
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
                 1 + rand() % 9, 1 + rand() % 9,
                 15 + rand() % 35,
                 RGB(50 + rand() % 200, 50 + rand() % 200, 50 + rand() % 200),
                 RGB(50 + rand() % 200, 50 + rand() % 200, 50 + rand() % 200) };

    Ball ball2 = { rand() % W,  rand() % H,
                 1 + rand() % 9, 1 + rand() % 9,
                 15 + rand() % 35,
                 RGB(50 + rand() % 200, 50 + rand() % 200, 50 + rand() % 200),
                 RGB(50 + rand() % 200, 50 + rand() % 200, 50 + rand() % 200) };

    Ball ball3 = { rand() % W,  rand() % H,
                 1 + rand() % 9, 1 + rand() % 9,
                 15 + rand() % 35,
                 RGB(50 + rand() % 200, 50 + rand() % 200, 50 + rand() % 200),
                 RGB(50 + rand() % 200, 50 + rand() % 200, 50 + rand() % 200) };

    Ball ball4 = { rand() % W,  rand() % H,
                 1 + rand() % 9, 1 + rand() % 9,
                 15 + rand() % 35,
                 RGB(50 + rand() % 200, 50 + rand() % 200, 50 + rand() % 200),
                 RGB(50 + rand() % 200, 50 + rand() % 200, 50 + rand() % 200) };

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


        CollisionBall(&ball1, &ball2, dt);
        CollisionBall(&ball1, &ball3, dt);
        CollisionBall(&ball1, &ball4, dt);

        CollisionBall(&ball2, &ball1, dt);
        CollisionBall(&ball2, &ball3, dt);
        CollisionBall(&ball2, &ball4, dt);

        CollisionBall(&ball3, &ball1, dt);
        CollisionBall(&ball3, &ball2, dt);
        CollisionBall(&ball3, &ball4, dt);

        CollisionBall(&ball4, &ball1, dt);
        CollisionBall(&ball4, &ball2, dt);
        CollisionBall(&ball4, &ball3, dt);

        /*int bilo_li_ono = bilo_stolknov (x1, y1, x2, y2, r1, r2);
        if (bilo_li_ono)
            {
            Bam_balls (x1, y1, &vx1, &vy1, x2, y2, &vx2, &vy2);
            }
        Ball_Control (&vx1, &vy1);
        */
        ControlBall(&ball1);

        txSleep (1);
        }
    }

//---------------------------------------------------------------------------------

void DrowBall(Ball ball)
    {
    txSetColor ((ball .Color), 2);
    txSetFillColor (ball .FillColor);

    txCircle (ball .x, ball .y, ball .r);
    txLine (ball .x, ball .y, ball .x + ball .vx*5, ball .y + ball .vy*5);
    txCircle (ball .x + ball .vx*5, ball .y + ball .vy*5, 3);
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
            (*ball) .FillColor = TX_RED;
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
            (*ball) .Color     = RGB((*ball) .x,   (*ball) .y,   150);
            (*ball) .FillColor = RGB((*ball) .x/2, (*ball) .y/2, 150);
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
        }

    if ((*ball) .y  > H - (*ball) .r)
        {
        (*ball) .vy =   - (*ball) .vy;
        (*ball) .y  = H - (*ball) .r;
        }

    if ((*ball) .x <  0 + (*ball) .r)
        {
        (*ball) .vx =   - (*ball) .vx;
        (*ball) .x  = 0 + (*ball) .r;
        }

    if ((*ball) .y <   0 + (*ball) .r)
        {
        (*ball) .vy =   - (*ball) .vy;
        (*ball) .y  = 0 + (*ball) .r;
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

void CollisionBall (Ball* ball_1, Ball* ball_2, int dt)
{
    int Dx = (*ball_1) .x - (*ball_2) .x; // стороны треугольника
    int Dy = (*ball_1) .y - (*ball_2) .y; // стороны треугольника
    double d = sqrt(Dx*Dx + Dy*Dy); if (d == 0) d = 0.01; //гипотенуза
    //printf ("Coordin do(): x  = %d and y  = %d\n", (*ball_1) .x, (*ball_2) .x);
    //printf ("Coordin do(): Dx  = %d\n", Dx);
    //printf ("Coordin do(): Dy  = %d\n", Dy);
    //printf ("Coordin do(): d  = %f\n", d);
    //txSleep (5000);
    double sin = Dx/d; // sin угла треугольника
    double cos = Dy/d; // cos угла треугольника

    if (d < (*ball_1) .r + (*ball_2) .r) //проверка столкновения
        {
        double Vn1 = (*ball_2) .vx*sin + (*ball_2) .vy*cos; //поворот системы координат шар1
        double Vn2 = (*ball_1) .vx*sin + (*ball_1) .vy*cos; //поворот системы координат шар2

        /*
        double Vt = ((*ball_1) .r + (*ball_2) .r - d)/(Vn1 - Vn2); // удаление залипания

        if (Vt > 0.6) Vt = 0.6;
        if (Vt < -0.6) Vt = -0.6;

        printf ("Coordin do(): r1  = %d, r2= %d, vt  = %f\n", (*ball_1) .r, (*ball_2) .r, Vt);
        //printf ("Coordin do(): vn1  = %d and vn2  = %d\n", Vn1, Vn2);
        //printf ("Coordin do(): x  = %d and y  = %d\n", (*ball_1) .x, (*ball_1) .y);
        //printf ("Coordin do(): x  = %d and y  = %d\n", (*ball_2) .x, (*ball_2) .y);

        (*ball_1) .x = ROUND((*ball_1) .x - (*ball_1) .vx*Vt);
        (*ball_1) .y = ROUND((*ball_1) .x - (*ball_1) .vy*Vt);
        (*ball_2) .x = ROUND((*ball_2) .x - (*ball_2) .vx*Vt);
        (*ball_2) .y = ROUND((*ball_2) .x - (*ball_2) .vy*Vt);

        printf ("Coordin pos(): x  = %d and y  = %d\n", (*ball_1) .x, (*ball_1) .y);
        printf ("Coordin pos(): x  = %d and y  = %d\n", (*ball_2) .x, (*ball_2) .y);

        //txSleep (5000);

        Dx = (*ball_1) .x - (*ball_2) .x;
        Dy = (*ball_1) .y - (*ball_2) .y;
        d = sqrt(Dx*Dx + Dy*Dy); if (d == 0) d = 0.01;
        sin = Dx/d; // sin
        cos = Dy/d; // cos
        Vn1 = (*ball_2) .vx*sin + (*ball_2) .vy*cos; //поворот системы координат шар1
        Vn2 = (*ball_1) .vx*sin + (*ball_1) .vy*cos; //поворот системы координат шар2
        */
        double Vt1 = -(*ball_2) .vx*cos + (*ball_2) .vy*sin; //поворот системы координат шар1
        double Vt2 = -(*ball_1) .vx*cos + (*ball_1) .vy*sin; //поворот системы координат шар2

        double o = Vn2; //меняем местами vn1 и vn2
        Vn2 = Vn1;
        Vn1 = o;

        (*ball_1) .vx = ROUND(Vn2*sin - Vt2*cos); //обратный поворот системы координат шар1
        (*ball_1) .vy = ROUND(Vn2*cos + Vt2*sin); //обратный поворот системы координат шар1
        (*ball_2) .vx = ROUND(Vn1*sin - Vt1*cos); //обратный поворот системы координат шар2
        (*ball_2) .vy = ROUND(Vn1*cos + Vt1*sin); //обратный поворот системы координат шар2

        (*ball_1) .x = (*ball_1) .x + (*ball_1) .vx*dt;
        (*ball_1) .y = (*ball_1) .y + (*ball_1) .vy*dt;
        (*ball_2) .x = (*ball_2) .x + (*ball_2) .vx*dt;
        (*ball_2) .y = (*ball_2) .y + (*ball_2) .vy*dt;
        //txSleep (5000);
        }

}
