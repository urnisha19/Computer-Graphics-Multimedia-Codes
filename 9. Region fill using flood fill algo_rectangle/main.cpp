#include<windows.h>
#include <GL/glut.h>

int ww = 500, wh = 500;
float initialColor[3] = {1.0,0.0,0.0};//RED
float colorToFill[3] = {0.0,1.0,1.0};//Cyan

void init()
{
    glViewport(0,0,ww,wh);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,(GLdouble)ww,0.0,(GLdouble)wh);
    glMatrixMode(GL_MODELVIEW);
}

void floodfillAlgo(int x,int y,float oldcolor[3],float newcolor[3])
{
    float color[3];
    //Get Pixel
    glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,color);

    if(color[0]==oldcolor[0] && (color[1])==oldcolor[1] && (color[2])==oldcolor[2])
    {
        //Set Pixel
        glBegin(GL_POINTS);
        glColor3fv(newcolor);
        glVertex2i(x,y);
        glEnd();
        glFlush();

        //Recursion for 4 connected
        floodfillAlgo(x+1,y,oldcolor,newcolor);
        floodfillAlgo(x-1,y,oldcolor,newcolor);
        floodfillAlgo(x,y+1,oldcolor,newcolor);
        floodfillAlgo(x,y-1,oldcolor,newcolor);
    }
}

void drawRectangle(int x1, int y1, int x2, int y2)
{
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(x1, y1);
    glVertex2i(x1, y2);
    glVertex2i(x2, y2);
    glVertex2i(x2, y1);
    glEnd();
    glFlush();
}


void display()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    drawRectangle(150,250,300,400);
    glFlush();
}

void mousePosition(int btn, int state, int x, int y)   //Mouse function to get the start point
{
    if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        int xi = x;
        int yi = (wh-y);
        floodfillAlgo(xi,yi,initialColor,colorToFill);
    }
}

int main(int argc, char** argv)   //main function
{
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(ww,wh);
    glutCreateWindow("Flood-Fill-Rectangle");
    glutDisplayFunc(display);
    init();
    glutMouseFunc(mousePosition);
    glutMainLoop();
    return 0;
}
