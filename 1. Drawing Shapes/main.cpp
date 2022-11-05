#include<windows.h>
#include <GL/glut.h>
#include<math.h>
#define PI 3.1416

//Draw Points
void displayPoints(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 1.0, 0.0);
    glBegin(GL_POINTS);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();
    glFlush();
}

//Draw Lines
void displayLines(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glColor3f (0.0, 0.0, 1.0);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glEnd();
    glutSwapBuffers();
}

//Draw Linestrip
void displayLinestrip()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_STRIP);
    //glBegin(GL_LINE_LOOP);
    glColor3f (1.0, 0.0, 0.0);
    glVertex2f(-0.75f, 0.75f);
    glVertex2f(-0.25f, 0.25f);
    glVertex2f(0.25f, 0.25f);
    glVertex2f(0.75f, 0.75f);
    glEnd();
    glutSwapBuffers();
}

//Draw Triangle
void displayTriangle(void)
{
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-0.25f, 0.25f, 0.0); //vertex 1
    glVertex3f(-0.5f, -0.25f, 0.0); //vertex 2
    glVertex3f(0.5f, -0.25f, 0.0); //vertex 3
    glEnd();
    glFlush();
}

//Draw Circle
void displayCircle(void)
{
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    GLint circle_points = 1000;
    glBegin(GL_LINE_LOOP);
    for(int i =0; i< circle_points; i++)
    {
        double angle = 2*PI*i/circle_points;
        glVertex2f(0.5*cos(angle), 0.5*sin(angle));
    }
    glEnd();
    glFlush();
}

//Draw Quads
void displayQuads(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.25f, 0.25f);
    glVertex2f(-0.25f, -0.25f);
    glVertex2f(-0.75f, -0.25f);
    glVertex2f(-0.75f, 0.25f);
    glEnd();
    glFlush();
}

//Draw Polygon
void displayPolygon(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(-0.25f, 0.25f); //v1
    glVertex2f(0.25f, 0.25f); //v2
    glVertex2f(0.75f, 0.0f); //v3
    glVertex2f(0.25f, -0.25f); //v4
    glVertex2f(-0.25f, -0.25f); //v5
    glVertex2f(-0.75f, 0.0f); //v6
    glEnd();
    glFlush();
}

//Draw Color Quads
void displayColorQuads(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f); //yellow
    glVertex2f(-0.25f, 0.25f);
    glColor3f(0.0f, 1.0f, 0.0f); //green
    glVertex2f(-0.25f, -0.25f);
    glColor3f(0.0f, 1.0f, 1.0f); //cyan
    glVertex2f(-0.75f, -0.25f);
    glColor3f(1.0f, 0.0f, 1.0f); //magenta
    glVertex2f(-0.75f, 0.25f);
    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("New Window says hi!");
    //glutDisplayFunc(displayPoints);
    //glutDisplayFunc(displayLinestrip);
    //glutDisplayFunc(displayTriangle);
    glutDisplayFunc(displayQuads);
    //glutDisplayFunc(displayPolygon);
    //glutDisplayFunc(displayColorQuads);
    glutMainLoop();
    return 0;
}
