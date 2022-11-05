#include<bits/stdc++.h>
#include <GL/glut.h>
#include<stdlib.h>
#include <time.h>

#define maxWD 400
#define maxHT 400

int xa, ya, xb, yb, xc, yc, xd, yd, sx, sy;

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock())
        ;
}

void myInit(void)
{
    glColor3f(0.0, 0.0, 1.0);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-400, maxWD, -400, maxHT);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}


void scale_rec(int sx, int sy)
{
    glColor3f(1.0, 0.0, 0.0);

    xa-=sx;
    xb +=sx;
    xc -=sx;
    xd +=sx;

    ya+=sx;
    yb +=sy;
    yc -=sy;
    yd -=sy;

    glBegin(GL_LINE_LOOP);
    glVertex2i(xa,  ya);
    glVertex2i(xb, yb);
    glVertex2i(xd,yd);
    glVertex2i(xc, yc);

    glEnd();
}

void draw_rec()
{
    glBegin(GL_LINES);

    glVertex2i(0, -400);
    glVertex2i(0, 400);

    glEnd();
    glFlush();

    glBegin(GL_LINES);

    glVertex2i(400, 0);
    glVertex2i(-400, 0);

    glEnd();
    glFlush();

    glBegin(GL_LINE_LOOP);
    glVertex2i(xa,  ya);
    glVertex2i(xb, yb);
    glVertex2i(xd,yd);
    glVertex2i(xc, yc);

    glEnd();
    glFlush();
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    draw_rec();

    delay(1000); //2 sec por por rectangle draw korbe

    scale_rec(sx, sy);
    glFlush();
}

int main(int argc, char** argv)
{
    printf("Input Rectange Point serially :  \n");
    scanf("%d %d %d %d %d %d %d %d", &xa, &ya, &xb, &yb, &xc, &yc, &xd, &yd);

    printf("Scalling point sx and sy : \n");
    scanf("%d %d", &sx, &sy);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(2 * maxWD, 2 * maxHT);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Rectangle Scalling");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
}

/*
input
15 60
60 60
15 15
60 15
15 15
 */
