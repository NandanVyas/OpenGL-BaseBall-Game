//#include <bits/stdc++.h>
//#include <GL/freeglut.h>
//#include <GL/gl.h>
#include <math.h>
#include <time.h>
#include<GL/glut.h>
#include<windows.h>
#include <iostream>

#define PI 3.14159265359
using namespace std;
void text(int x, int y, char* string)
{
    glColor3f(1, 1, 1);
    glRasterPos2f(x, y);
    int len, i;
    len = (int)strlen(string);
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
    }
}
float xone, yone, xtwo, ytwo;
// void parametric_linesegment (float xone, float yone, float xtwo, float ytwo);
void second_step(void);
void hit();
void midcircle(float h, float k, float r)
{
    int a = 0, b = r;
    int pk = 1 - r;
    while (a <= b)
    {
        glVertex2d(a + h, b + k);      // 2
        glVertex2d(b + h, a + k);      //1
        glVertex2d(-a + h, b + k);      // 3
        glVertex2d(-b + h, a + k);      // 4
        glVertex2d(-b + h, -a + k);      //5
        glVertex2d(-a + h, -b + k);      //6
        glVertex2d(a + h, -b + k);      // 7
        glVertex2d(b + h, -a + k);      // 8
        if (pk < 0)
        {
            b = b;
            pk = pk + 2 * a + 1;
        }
        else
        {
            b = b - 1;
            pk = pk + 2 * a + 5 - 2 * b;
        }
        a++;
    }
}

void drawball(int h, int k, int r)
{
    glColor3f(255, 255, 255);
    glBegin(GL_POINTS);
    for (int i = 1; i <= r; i++)
    {
        midcircle(h, k, i);
    }
    glBegin(GL_POLYGON);
    glColor3ub(255, 0, 0);
    glVertex2i(h - 6.4, k + 11.25);
    glVertex2i(h - 6.6, k + 11.25);
    glVertex2i(h - 6.6, k - 11.25);
    glVertex2i(h - 6.4, k - 11.25);
    

    glBegin(GL_POLYGON);
    glColor3ub(255, 0, 0);
    glVertex2i(h + 6.4, k + 11.25);
    glVertex2i(h + 6.6, k + 11.25);
    glVertex2i(h + 6.6, k - 11.25);
    glVertex2i(h + 6.4, k - 11.25);
    glEnd();
}

void fillellipse(int cx, int cy, int a, int b)
{
    glBegin(GL_POLYGON);
    // glColor3ub(0,141,204);
    for (float i = 0; i <= 360; i += 1)
    {
        float angle = i * PI / 180.0;
        // if (cy+b*sin(angle) < cy+30)
        // {
        //     glColor3ub(0,141,204);
        // }
        // else
        {
            glColor3ub(232, 190, 172);
        }
        glVertex2f(cx + a * cos(angle), cy + b * sin(angle));
    }
    glEnd();
}
void batsman(int x, int y, int flag)
{
    //head
    fillellipse(x - 5, y + 400, 35, 50);

    //body
    glBegin(GL_POLYGON);
    glColor3ub(0, 255, 0);
    glVertex2i(x + 20, y + 200);
    glVertex2i(x + 70, y + 200);
    glVertex2i(x + 20, y + 350);
    glVertex2i(x - 30, y + 350);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glPointSize(5);
    glVertex2i(x + 20, y + 200);
    glVertex2i(x + 70, y + 200);
    glVertex2i(x + 20, y + 350);
    glVertex2i(x - 30, y + 350);
    glEnd();
    // hand in shirt
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2i(x - 20, y + 330);
    glVertex2i(x - 20, y + 280);
    glVertex2i(x + 10, y + 280);
    glVertex2i(x + 10, y + 330);;
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(0, 0, 0);
    glVertex2i(x - 20, y + 330);
    glVertex2i(x - 20, y + 280);
    glVertex2i(x + 10, y + 280);
    glVertex2i(x + 10, y + 330);
    glEnd();
    // hand
    glBegin(GL_POLYGON);
    glColor3ub(232, 190, 172);
    
    glVertex2i(x - 17, y + 280);
    glVertex2i(x + 7, y + 280);
    glVertex2i(x + 7, y + 260);
    glVertex2i(x - 17, y + 260);
    glEnd();
    if (flag == 0)
    {
        glBegin(GL_POLYGON);
        glVertex2i(x - 17, y + 260);
        glVertex2i(x + 7, y + 260);
        glVertex2i(x - 30, y + 200);
        glVertex2i(x - 30, y + 223);
        glEnd();
        glBegin(GL_LINE_LOOP);
        glColor3f(0, 0, 0);
        glPointSize(5);
        glVertex2i(x - 17, y + 280);
        glVertex2i(x + 7, y + 280);
        glVertex2i(x + 7, y + 260);
        glVertex2i(x - 30, y + 200);
        glVertex2i(x - 30, y + 223);
        glVertex2i(x - 17, y + 260);
        glEnd();

    }
    else
    {
        glBegin(GL_POLYGON);
        glVertex2i(x - 17, y + 260);
        glVertex2i(x + 7, y + 260);
        glVertex2i(x + 24, y + 200);
        glVertex2i(x + 24, y + 223);
        glEnd();
        glBegin(GL_LINE_LOOP);
        glColor3f(0, 0, 0);
        glPointSize(5);
        glVertex2i(x - 17, y + 280);
        glVertex2i(x + 7, y + 280);
        glVertex2i(x + 7, y + 260); 
        glVertex2i(x + 24, y + 223);
        glVertex2i(x + 24, y + 200);
        glVertex2i(x - 17, y + 260);
        glEnd();
    }
    if (flag == 0)
    {
        //bat handle
        glBegin(GL_POLYGON);
        glColor3f(0, 0, 0);
        glVertex2i(x - 30, y + 188);
        glVertex2i(x - 20, y + 198);
        glVertex2i(x - 55, y + 238);
        glVertex2i(x - 65, y + 228);
        glEnd();
    }
    else
    {
        //bat handle
        glBegin(GL_POLYGON);
        glColor3f(0, 0, 0);
        glVertex2i(x -11, y + 188);
        glVertex2i(x - 11, y + 198);
        glVertex2i(x +24, y + 238);
        glVertex2i(x +34, y + 228);
        glEnd();
    }
    //gloves
    if (flag == 0)
    {
        glBegin(GL_POLYGON);
        glColor3ub(255, 255, 255);
        glVertex2i(x - 30, y + 200);
        glVertex2i(x - 30, y + 225);
        glVertex2i(x - 50, y + 225);
        glVertex2i(x - 50, y + 200);
        glEnd();
        glBegin(GL_LINE_LOOP);
        glColor3f(0, 0, 0);
        glVertex2i(x - 30, y + 200);
        glVertex2i(x - 30, y + 225);
        glVertex2i(x - 50, y + 225);
        glVertex2i(x - 50, y + 200);
        glEnd();
    }
    else
    {
        glBegin(GL_POLYGON);
        glColor3ub(255, 255, 255);
        glVertex2i(x +24, y + 200);
        glVertex2i(x +24, y + 225);
        glVertex2i(x +4, y + 225);
        glVertex2i(x +4, y + 200);
        glEnd();
        glBegin(GL_LINE_LOOP);
        glColor3f(0, 0, 0);
        glVertex2i(x + 24, y + 200);
        glVertex2i(x + 24, y + 225);
        glVertex2i(x + 4, y + 225);
        glVertex2i(x + 4, y + 200);
        glEnd();
    }
    // legs
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2i(x - 20, y + 150);
    glVertex2i(x + 20, y + 140);
    glVertex2i(x + 60, y + 200);
    glVertex2i(x + 20, y + 200);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glPointSize(5);
    glVertex2i(x - 20, y + 150);
    glVertex2i(x + 20, y + 140);
    glVertex2i(x + 60, y + 200);
    glVertex2i(x + 20, y + 200);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2i(x - 10, y + 150);
    glVertex2i(x + 30, y + 140);
    glVertex2i(x + 70, y + 200);
    glVertex2i(x + 30, y + 200);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex2i(x - 10, y + 150);
    glVertex2i(x + 30, y + 140);
    glVertex2i(x + 70, y + 200);
    glVertex2i(x + 30, y + 200);
    glEnd();
    //shoes
    glBegin(GL_POLYGON);
    glColor3ub(0, 255, 0);
    glVertex2i(x - 42, y);
    glVertex2i(x - 45, y + 6);
    glVertex2i(x - 45, y + 12);
    glVertex2i(x - 42, y + 18);
    glVertex2i(x + 2, y + 30);
    glVertex2i(x + 5, y + 30);
    glVertex2i(x + 5, y + 6);
    glVertex2i(x + 2, y);
    glEnd();
    glPointSize(3);
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex2i(x - 42, y);
    glVertex2i(x - 45, y + 6);
    glVertex2i(x - 45, y + 12);
    glVertex2i(x - 42, y + 18);
    glVertex2i(x + 2, y + 30);
    glVertex2i(x + 5, y + 30);
    glVertex2i(x + 5, y + 6);
    glVertex2i(x + 2, y);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(0, 255, 0);
    glVertex2i(x - 22, y);
    glVertex2i(x - 25, y + 6);
    glVertex2i(x - 25, y + 12);
    glVertex2i(x - 22, y + 18);
    glVertex2i(x + 22, y + 30);
    glVertex2i(x + 25, y + 30);
    glVertex2i(x + 25, y + 6);
    glVertex2i(x + 22, y);
    glEnd();
    glPointSize(3);
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex2i(x - 22, y);
    glVertex2i(x - 25, y + 6);
    glVertex2i(x - 25, y + 12);
    glVertex2i(x - 22, y + 18);
    glVertex2i(x + 22, y + 30);
    glVertex2i(x + 25, y + 30);
    glVertex2i(x + 25, y + 6);
    glVertex2i(x + 22, y);
    glEnd();
    //pads
    glBegin(GL_POLYGON);
    glColor3ub(1, 1, 1);
    glVertex2i(x - 30, y + 20);
    glVertex2i(x - 30, y + 140);
    glVertex2i(x - 20, y + 150);
    glVertex2i(x - 10, y + 160);
    glVertex2i(x, y + 160);
    glVertex2i(x + 10, y + 150);
    glVertex2i(x + 20, y + 140);
    glVertex2i(x + 20, y + 20);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glPointSize(5);
    glVertex2i(x - 30, y + 20);
    glVertex2i(x - 30, y + 140);
    glVertex2i(x - 20, y + 150);
    glVertex2i(x - 10, y + 160);
    glVertex2i(x, y + 160);
    glVertex2i(x + 10, y + 150);
    glVertex2i(x + 20, y + 140);
    glVertex2i(x + 20, y + 20);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(1, 1, 1);
    glVertex2i(x - 20, y + 20);
    glVertex2i(x - 20, y + 140);
    glVertex2i(x - 10, y + 150);
    glVertex2i(x, y + 160);
    glVertex2i(x + 10, y + 160);
    glVertex2i(x + 20, y + 150);
    glVertex2i(x + 30, y + 140);
    glVertex2i(x + 30, y + 20);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glPointSize(5);
    glVertex2i(x - 20, y + 20);
    glVertex2i(x - 20, y + 140);
    glVertex2i(x - 10, y + 150);
    glVertex2i(x, y + 160);
    glVertex2i(x + 10, y + 160);
    glVertex2i(x + 20, y + 150);
    glVertex2i(x + 30, y + 140);
    glVertex2i(x + 30, y + 20);
    glEnd();
    //bat
    if (flag == 0)
    {
        glBegin(GL_POLYGON);
        glColor3ub(150, 75, 0);
        glVertex2i(x - 55, y + 237);
        glVertex2i(x - 55, y + 213);
        glVertex2i(x - 140, y + 300);
        glVertex2i(x - 123, y + 318);
        glEnd();
        /*
        glBegin(GL_LINE_LOOP);
        glPointSize(3);
        // glColor3ub(186, 140, 99);
        glColor3f(0, 0, 0);
        glVertex2i(x - 45, y + 248);
        glVertex2i(x - 75, y + 218);
        glVertex2i(x - 153, y + 297);
        glVertex2i(x - 123, y + 327);
        glEnd();
        */

    }
    else
    {
        /*
        glBegin(GL_POLYGON);
        glColor3ub(150,75,0);
        glVertex2i(x - 35, y + 175);
        glVertex2i(x - 45, y + 175);
        glVertex2i(x - 47, y + 25);
        glVertex2i(x - 27, y + 25);
        glEnd();
        */
        glBegin(GL_POLYGON);
        glColor3ub(150, 75, 0);
        glVertex2i(x +19, y + 237);
        glVertex2i(x +19, y + 213);
        glVertex2i(x + 104, y + 300);
        glVertex2i(x + 87, y + 318);
        glEnd();
        /*
        glBegin(GL_LINE_LOOP);
        glPointSize(3);
        glColor3ub(186, 140, 99);
        glColor3f(0, 0, 0);
        glVertex2i(x - 25, y + 175);
        glVertex2i(x - 55, y + 175);
        glVertex2i(x - 55, y + 25);
        glVertex2i(x - 25, y + 25);
        glEnd();
        */
    }

}
void pitch()
{
    //pitch
    glBegin(GL_POLYGON);
    // glColor3f(196.0/256.0,164.0/256.0,132.0/256.0);
    glColor3ub(205, 133, 63);
    glVertex2i(0, 0);
    glVertex2i(900, 1500);
    glVertex2i(1000, 1500);
    glVertex2i(1900, 0);
    glEnd();

    glBegin(GL_LINE_LOOP); //non fill circle
    glColor3ub(205, 133, 63);
    for (int ii = 0; ii < 50; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(50);//get the current angle

        float x = 50 * cosf(theta);//calculate the x component
        float y = 50 * sinf(theta);//calculate the y component

        glVertex2f(x + 950, y + 1500);//output vertex

    }
    glEnd();



    glBegin(GL_POLYGON);
    // glColor3f(196.0/256.0,164.0/256.0,132.0/256.0);
    glColor3ub(0, 100, 0);
    glVertex2i(100, 0);
    glVertex2i(930, 1400);
    glVertex2i(970, 1400);
    glVertex2i(1800, 0);
    glEnd();





    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(205, 133, 63);
    GLfloat twicePi = 2.0f * PI;
    glVertex2f(950, 1500); // center of circle
    for (int i = 0; i <= 100; i++) {
        glVertex2f(
            950 + (150 * cos(i * twicePi / 100)),
            1500 + (150 * sin(i * twicePi / 100))
        );
    }
    glEnd();
    /* above code
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();*/

}
int startangle;
int endangle;
float i;
int mid;
float speed;
int cx, cy, a, b;
int x, y, flag;
float ballposition;
float side = -1;
int temp;
int running = 0;
int score = 0;
float u = 0;
int started = 0;
int runcount = 0;
int ballcount = 0;
void info();
void scoreboard()
{
    //black background
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2i(1550, 1530);
    glVertex2i(1750, 1530);
    glVertex2i(1750, 1800);
    glVertex2i(1550, 1800);
    glEnd();
    char str[100] = "RUNS   ";
    char str1[100];
    sprintf_s(str1, "%d", runcount);
    strcat_s(str, str1);
    text(1590, 1700, str);
    char str2[100] = "BALLS  ";
    char str3[100];
    sprintf_s(str3, "%d", ballcount);
    strcat_s(str2, str3);
    text(1590, 1600, str2);
}
void scoreinfo()
{
    if (score == 0)
    {
        char str[100] = "Strike !!!";
        text(950, 1000, str);
    }
    else if (score == 1)
    {
        char str[100] = "Advance by one base";
        text(950, 1000, str);
    }
    else if (score == 2)
    {
        char str[100] = "Advance by two ";
        text(950, 1000, str);
    }
    else if (score == 3)
    {
        char str[100] = "Advance by three";
        text(950, 1000, str);
    }
    else if (score == 4)
    {
        char str[100] = "Score is four !!!!";
        text(950, 1000, str);
    }
    else if (score == 6)
    {
        char str[100] = "Home Run !!!! ";
        text(950, 1000, str);
    }
}
void loop(int val)
{
    if (startangle < endangle)
    {
        float angle = i * PI / 180.0;
        // glVertex2f(cx + a*cos(angle),cy + b*sin(angle));
        glClear(GL_COLOR_BUFFER_BIT);
        pitch();
        scoreboard();
        if (running == 3)
        {
            scoreinfo();
        }
        info();
        batsman(x, y, flag);
        // x=cx+a*cos(angle);
        drawball(cx + a * cos(angle), cy + b * sin(angle), 13);
        ballposition = cy + b * sin(angle);
        glFlush();
        // glutPostRedisplay();
        i += speed;
        if (i <= endangle)
        {
            glutTimerFunc(50, loop, 0);
        }
        else if (running == 1)
        {
            second_step();
        }
        else if (running == 2)
        {
            // parametric_linesegment(500,1000,950+temp,1550);
            hit();
        }
    }
    else
    {
        float angle = i * PI / 180.0;
        // glVertex2f(cx + a*cos(angle),cy + b*sin(angle));
        glClear(GL_COLOR_BUFFER_BIT);
        pitch();
        scoreboard();
        if (running == 3)
        {
            scoreinfo();
        }
        info();
        batsman(x, y, flag);
        drawball(cx + a * cos(angle), cy + b * sin(angle), 13);
        ballposition = cy + b * 0.5;
        // x=cx+a*cos(angle);
        glFlush();
        glutPostRedisplay();
        i -= speed;
        if (i >= endangle)
        {
            glutTimerFunc(50, loop, 0);
        }
        else if (running == 1)
        {
            second_step();
        }
        else if (running == 2)
        {
            // parametric_linesegment(500,1000,950+temp,1550);
            hit();
        }
    }
}
void loop1(int val)
{
    if (u <= 1)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        pitch();
        scoreboard();
        if (running == 3)
        {
            scoreinfo();
        }
        info();
        batsman(x, y, flag);
        drawball(xone + u * (xtwo - xone), yone + u * (ytwo - yone), 13);
        ballposition = yone + u * (ytwo - yone);
        // x=cx+a*cos(angle);
        glFlush();
        u += 0.02;
        glutTimerFunc(50, loop1, 0);
    }
}


void hit()
{
    runcount += score;
    ballcount++;
    running = 3;
    flag = 1;
    if (side == -1)
    {
        // ParametricEllipseAlgo(950+temp-400,1500,400,50,0,180,speed,950+temp+40,1500,1);
        if (score == 0)
        {
            glClear(GL_COLOR_BUFFER_BIT);
            pitch();
            scoreboard();
            if (running == 3)
            {
                if (running == 3)
                {
                    scoreinfo();
                }
            }
            info();
            batsman(x, y, flag);
            drawball(950 + temp, 1450, 13);
            ballposition = 1500;
            // x=cx+a*cos(angle);
            glFlush();
        }
        else if (score < 4)
        {
            // parametric_linesegment(950+temp,1550,500,1000);
            xone = 950 + temp;
            yone = 1500;
            xtwo = 700 - (score * 150);
            ytwo = rand() % 500 + 500;
            u = 0;
            loop1(0);
        }
        else if (score == 4)
        {
            xone = 950 + temp;
            yone = 1500;
            xtwo = 0;
            ytwo = rand() % 500 + 500;
            u = 0;
            loop1(0);
        }
        else if (score == 6)
        {
            cx = 950 + temp;
            cy = 0;
            a = 950 + temp + rand() % 400;
            b = 1550;
            startangle = 90;
            endangle = 180;
            i = startangle;
            x = 950 + temp + 40;
            y = 1500;
            glutTimerFunc(50, loop, 0);
        }
    }
    else if (side == 1)
    {
        // ParametricEllipseAlgo(950+temp+400,1500,400,50,180,0,speed,950+temp+40,1500,1);
        if (score == 0)
        {
            glClear(GL_COLOR_BUFFER_BIT);
            pitch();
            scoreboard();
            if (running == 3)
            {
                scoreinfo();
            }
            info();
            batsman(x, y, flag);
            drawball(950 + temp, 1450, 13);
            ballposition = 1500;
            // x=cx+a*cos(angle);
            glFlush();
        }
        else if (score < 4)
        {
            // parametric_linesegment(950+temp,1550,500,1000);
            xone = 950 + temp;
            yone = 1500;
            xtwo = 1300 + (score * 150);
            ytwo = rand() % 500 + 500;
            u = 0;
            loop1(0);
        }
        else if (score == 4)
        {
            xone = 950 + temp;
            yone = 1500;
            xtwo = 2000;
            ytwo = rand() % 500 + 500;
            u = 0;
            loop1(0);
        }
        else if (score == 6)
        {
            cx = 950 + temp;
            cy = 0;
            a = 2000 - (950 + temp) + rand() % 400;
            b = 1550;
            startangle = 90;
            endangle = 0;
            i = startangle;
            x = 950 + temp + 40;
            y = 1500;
            glutTimerFunc(50, loop, 0);
        }
    }
}

void myInit()
{
    // 71,162,13
    glClearColor(71.0 / 256.0, 162.0 / 256.0, 13.0 / 256.0, 0.0);
    // glClearColor(0.0,1.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 2000.0, 0.0, 2000.0);
}

void second_step()
{
    running = 2;
    temp = (rand() % 100);
    if (rand() % 2)
    {
        temp = -temp;
        // ParametricEllipseAlgo(950+temp,mid,-temp,1550-mid,0,90,speed,950+temp+40,1500,0);
        cx = 950 + temp;
        cy = mid;
        a = -temp;
        b = 1550 - mid;
        startangle = 0;
        endangle = 90;
        i = startangle;
        x = 950 + temp + 40;
        y = 1500;
        flag = 0;
        glutTimerFunc(50, loop, 0);
    }
    else
    {
        // ParametricEllipseAlgo(950+temp,mid,temp,1550-mid,180,90,speed,950+temp+40,1500,0);
        cx = 950 + temp;
        cy = mid;
        a = temp;
        b = 1550 - mid;
        startangle = 180;
        endangle = 90;
        i = startangle;
        x = 950 + temp + 40;
        y = 1500;
        flag = 0;
        glutTimerFunc(50, loop, 0);
    }
}
void baseball()
{
    started = 1;
    score = 0;
    // cout<<"side is "<<side<<endl;
    srand(time(NULL));
    glClear(GL_COLOR_BUFFER_BIT);
    mid = rand() % 600 + 800;
    speed = ((rand() % 10) + 1);
    // ParametricEllipseAlgo(950,0,250,mid,0,90,speed,1040,1500,0);
    cx = 950;
    cy = 0;
    a = 250;
    b = mid;
    startangle = 0;
    endangle = 90;
    i = startangle;
    x = 1040;
    y = 1500;
    flag = 0;
    ballposition = 0;
    // glutTimerFunc(100,loop,0);
    running = 1;
    loop(0);
}

void arrow(int key, int p, int q)
{
    if (key == GLUT_KEY_LEFT)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        baseball();
        side = -1;
    }
    else if (key == GLUT_KEY_RIGHT)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        baseball();
        side = 1;
    }
}
void info()
{
    char str1[100] = "Instructions";
    text(200, 1100, str1);
    char str2[100] = "Press left arrow to hit left side";
    text(100, 1000, str2);
    char str3[100] = "Press right arrow to hit right side";
    text(100, 900, str3);
    char str4[100] = "Press space bar to hit the ball";
    text(100, 800, str4);
    // glFlush();
    // glFlush();
}
void intro()
{
    if (started != 1)
    {
        // baseball();
        baseball();
    }
}
void keyboard(unsigned char key, int p, int q)
{
    switch (key)
    {
    case ' ':
        if (ballposition < 1000)
        {
            score = 0;
        }
        else if (ballposition < 1100)
        {
            score = 1;
        }
        else if (ballposition < 1200)
        {
            score = 2;
        }
        else if (ballposition < 1300)
        {
            score = 3;
        }
        else if (ballposition < 1400)
        {
            score = 4;
        }
        else if (ballposition < 1550)
        {
            score = 6;
        }
        break;
    default:
        break;
    }
}
int main(int aGc, char** aGv)
{
    glutInit(&aGc, aGv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));
    // glutInitWindowSize(1500,800);
    glutInitWindowPosition(200, 0);
    glutCreateWindow("baseball");
    glutSpecialFunc(arrow);
    glutKeyboardFunc(keyboard);
    myInit();
    glutDisplayFunc(intro);
    glutMainLoop();
    return 0;
}
