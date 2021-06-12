#include "TXLib.h"
const int W = 1070;
const int H = 650;
struct Ball;

void MoveBall();
void DrowBall(Ball ball);
void PhysicsBall(Ball* ball, int dt);
void CollisionBall(Ball* ball_1, Ball* ball_2, int* score1);
void ControlBall(Ball* ball, int* F4_Col);
void ScoreDraw (int score1, int score2);

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

struct Ball
    {
    int  x, y , vx, vy;

    int r;

    COLORREF Color;
    COLORREF FillColor;
    };

//---------------------------------------------------------------------------------

void MoveBall()
    {
    //srand(time(NULL));

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
    int F4_Col = 0;
    int score1 = 0, score2 = 0;

    HDC Fon  = txLoadImage ("images\\Fon.bmp");

    while (!txGetAsyncKeyState (VK_ESCAPE))
        {

        txBegin ();
        txSetFillColor (TX_BLACK);
        txClear ();

        txBitBlt  (txDC(), 0, 50, 0, 0, Fon);

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


        CollisionBall(&ball1, &ball2, &score1); //�������� ������������
        CollisionBall(&ball1, &ball3, &score1);
        CollisionBall(&ball1, &ball4, &score1);

        CollisionBall(&ball2, &ball3, &score2);
        CollisionBall(&ball2, &ball4, &score2);

        CollisionBall(&ball3, &ball4, &score2);



        /*int bilo_li_ono = bilo_stolknov (x1, y1, x2, y2, r1, r2);
        if (bilo_li_ono)
            {
            Bam_balls (x1, y1, &vx1, &vy1, x2, y2, &vx2, &vy2);
            }
        Ball_Control (&vx1, &vy1);
        */
        ControlBall(&ball1, &F4_Col);

        ScoreDraw (score1, score2);

        txEnd ();
        txSleep (1);
        }

    txDeleteDC(Fon);
    }

//---------------------------------------------------------------------------------

void DrowBall(Ball ball)
    {
    txSetColor ((ball .Color), 2);
    txSetFillColor (ball .FillColor);

    txCircle (ball .x, ball .y, ball .r);
    //txLine (ball .x, ball .y, ball .x + ball .vx*5, ball .y + ball .vy*5);
    //txCircle (ball .x + ball .vx*5, ball .y + ball .vy*5, 3);
    }

//---------------------------------------------------------------------------------

void ControlBall(Ball* ball, int* F4_Col)
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
            *F4_Col = 0;
            }

        if (txGetAsyncKeyState (VK_F2))
            {
            (*ball) .Color = TX_LIGHTBLUE;
            (*ball) .FillColor = TX_BLUE;
            *F4_Col = 0;
            }

        if (txGetAsyncKeyState (VK_F3))
            {
            (*ball) .Color = TX_LIGHTGREEN;
            (*ball) .FillColor = TX_GREEN;
            *F4_Col = 0;
            }

        if (txGetAsyncKeyState (VK_F4))
            {
            *F4_Col = 1;
            }

        if (*F4_Col == 1)
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

    if ((*ball) .x  < 0 + (*ball) .r)
        {
        (*ball) .vx =   - (*ball) .vx;
        (*ball) .x  = 0 + (*ball) .r;
        }

    if ((*ball) .y  < 50 + (*ball) .r)
        {
        (*ball) .vy =   - (*ball) .vy;
        (*ball) .y  = 50 + (*ball) .r;
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

void CollisionBall (Ball* ball_1, Ball* ball_2, int* score)
{
    int Dx = (*ball_1) .x - (*ball_2) .x; // ������� ������������
    int Dy = (*ball_1) .y - (*ball_2) .y; // ������� ������������
    double d = sqrt(Dx*Dx + Dy*Dy); if (d == 0) d = 0.01; //����������
    double sin = Dx/d; // sin ���� ������������
    double cos = Dy/d; // cos ���� ������������

    if (d < (*ball_1) .r + (*ball_2) .r) //�������� ������������
        {
        txPlaySound ("sounds/Zvuk_Ball.wav");

        ++(*score);

        double Vn1 = (*ball_2) .vx*sin + (*ball_2) .vy*cos; //������� ������� ��������� ���1
        double Vn2 = (*ball_1) .vx*sin + (*ball_1) .vy*cos; //������� ������� ��������� ���2

        if ((Vn1 - Vn2) == 0) Vn1 = Vn1 + 0.01;

        double dt = ((*ball_1) .r + (*ball_2) .r - d)/(Vn1 - Vn2); // �������� ���������

        if (dt >  1)  dt = 1;   // ����������� �� dt, ���� ��� �� ���������� ������
        if (dt < -1) dt = -1;

        (*ball_1) .x = ROUND((*ball_1) .x - (*ball_1) .vx*dt);
        (*ball_1) .y = ROUND((*ball_1) .y - (*ball_1) .vy*dt);
        (*ball_2) .x = ROUND((*ball_2) .x - (*ball_2) .vx*dt);
        (*ball_2) .y = ROUND((*ball_2) .y - (*ball_2) .vy*dt);

        Dx = (*ball_1) .x - (*ball_2) .x;
        Dy = (*ball_1) .y - (*ball_2) .y;
        d = sqrt(Dx*Dx + Dy*Dy); if (d == 0) d = 0.01;
        sin = Dx/d; // sin
        cos = Dy/d; // cos
        Vn1 = (*ball_2) .vx*sin + (*ball_2) .vy*cos;
        Vn2 = (*ball_1) .vx*sin + (*ball_1) .vy*cos;

        double Vt1 = -(*ball_2) .vx*cos + (*ball_2) .vy*sin; //������� ������� ��������� ���1
        double Vt2 = -(*ball_1) .vx*cos + (*ball_1) .vy*sin; //������� ������� ��������� ���2

        double o = Vn2; //������ ������� vn1 � vn2
        Vn2 = Vn1;
        Vn1 = o;

        (*ball_1) .vx = ROUND(Vn2*sin - Vt2*cos); //�������� ������� ������� ��������� ���1
        (*ball_1) .vy = ROUND(Vn2*cos + Vt2*sin); //�������� ������� ������� ��������� ���1
        (*ball_2) .vx = ROUND(Vn1*sin - Vt1*cos); //�������� ������� ������� ��������� ���2
        (*ball_2) .vy = ROUND(Vn1*cos + Vt1*sin); //�������� ������� ������� ��������� ���2

        (*ball_1) .x = ROUND((*ball_1) .x + (*ball_1) .vx*dt);
        (*ball_1) .y = ROUND((*ball_1) .y + (*ball_1) .vy*dt);
        (*ball_2) .x = ROUND((*ball_2) .x + (*ball_2) .vx*dt);
        (*ball_2) .y = ROUND((*ball_2) .y + (*ball_2) .vy*dt);
        //printf (" dt  = %f\n", dt);
        //txSleep (3000);
        }
}

//---------------------------------------------------------------------------------

void ScoreDraw (int score1, int score2)
    {
    txSelectFont ("TimesNewRoman", 50);
    char str[12] = "";
    sprintf (str, "%d : %d", score1, score2);

    int textSizeX = txGetTextExtentX ("------"),
        textSizeY = txGetTextExtentY ("------");

    txSetFillColor (TX_BLACK);
    txRectangle (W/2 - textSizeX, 2,
                 W/2 + textSizeX, textSizeY);
    txSetColor ((TX_GREEN), 2);
    txSetTextAlign (TA_CENTER);
    txTextOut (txGetExtentX() / 2, 2, str);


    }


