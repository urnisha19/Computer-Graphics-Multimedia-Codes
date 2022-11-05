#include <GL\glut.h>
#include <iostream>
#include <windows.h>
using namespace std;

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0); //Clear background color (R,G,B,Alpha)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 400.0, 0.0, 400.0); //Specify the display area
}

void house(void)
{
    glClear(GL_COLOR_BUFFER_BIT); //Clear the screen buffer
    glPointSize(4.0);

    //Create the polygon(house)
    glColor3f(1.0f, 1.5f, 1.5f); //Color of Rectangular part of house
    glBegin(GL_POLYGON);
    glVertex2i(40, 40);
    glVertex2i(320, 40);

    glVertex2i(40, 200);
    glVertex2i(320, 200);

    glVertex2i(40, 200);
    glVertex2i(40, 40);

    glVertex2i(320, 200);
    glVertex2i(320, 40);
    glEnd();

    //Create the polygon(window)
    glColor3f(0.8f, 0.5f, 0.5f); //Window color
    glBegin(GL_POLYGON);
    glVertex2i(220, 60);
    glVertex2i(300, 60);

    glVertex2i(220, 150);
    glVertex2i(300, 150);

    glVertex2i(220, 60);
    glVertex2i(220, 150);

    glVertex2i(300, 150);
    glVertex2i(300, 60);
    glEnd();

    //Create the polygon(door)
    glColor3f(0.8f, 0.5f, 0.5f); //Door color
    glBegin(GL_POLYGON);
    glVertex2i(130, 40);
    glVertex2i(130, 160);

    glVertex2i(130, 160);
    glVertex2i(180, 160);

    glVertex2i(180, 100);
    glVertex2i(180, 40);

    glVertex2i(120, 40);
    glVertex2i(170, 40);
    glEnd();

    //Create triangle(House top part)
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2i(10, 200);
    glVertex2i(340, 200);

    glVertex2i(200, 390);

    glVertex2i(10, 200);
    glVertex2i(200, 390);
    glEnd();

    glFlush();  // Sends all output to display
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); //Initialize the init function
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Sets the display mode and and specify the color scheme
    glutInitWindowSize(1200, 740); //Specify the window size
    glutInitWindowPosition(0, 0); //Sets the starting position for the window
    glutCreateWindow("House"); //Creates the window and sets the title
    glutDisplayFunc(house);
    init(); //Additional initializations
    glutMainLoop(); //Go into a loop until event occurs
    return 0;
}
