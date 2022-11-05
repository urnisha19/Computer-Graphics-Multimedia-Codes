#include <iostream>
#include <cmath>
#include<stdio.h>
#include <iostream>
#include <cmath>
#include<stdio.h>
#include<bits/stdc++.h>
#include <GL/glut.h>
#include<stdlib.h>
#include <time.h>

#define PI 3.14159265

using namespace std;

struct pointset {

    double x, y, z = 1;

};

pointset points[4], translated_points[4], rotated_points[4], scaled_points[4], mirrored_x_points[4], mirrored_y_points[4];
double n, tx, ty, theta, sx, sy;

void dda(double x1, double y1, double x2, double y2) {

    double dx, dy, _count, increment_x, increment_y, x, y;

    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dy) > abs(dx))
        _count = abs(dy) * 100;
    else
        _count = abs(dx) * 100;

    increment_x = dx / _count;
    increment_y = dy / _count;

    x = x1;
    y = y1;

    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    glFlush();


    for (double i = 1; i <= _count; i++) {
        x += increment_x;
        y += increment_y;

        glBegin(GL_POINTS);
        glVertex2f(x, y);
        glEnd();
    }

    glFlush();
    glutSwapBuffers();
}

void draw_polygon() {

    for (int i = 0; i < 4; i++) {
        if (i + 1 == 4)
            dda(points[i].x, points[i].y, points[0].x, points[0].y);
        else
            dda(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
    }
}

void mirror() {
    double mirrored_matrix_x[3][1], mirrored_matrix_y[3][1];

    double mirroring_matrix_x[3][3] = {
            {1, 0,  0},
            {0, -1, 0},
            {0, 0,  1}
    };

    double mirroring_matrix_y[3][3] = {
            {-1, 0, 0},
            {0,  1, 0},
            {0,  0, 1}
    };

    for (int p = 0; p < 4; p++) {

        memset(mirrored_matrix_x, 0, sizeof(mirrored_matrix_x));
        memset(mirrored_matrix_y, 0, sizeof(mirrored_matrix_y));

        double point_matrix[3][1] = {
                {points[p].x},
                {points[p].y},
                {points[p].z}
        };

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 1; j++)
                for (int k = 0; k < 3; k++) {
                    mirrored_matrix_x[i][j] += mirroring_matrix_x[i][k] * point_matrix[k][j];
                    mirrored_matrix_y[i][j] += mirroring_matrix_y[i][k] * point_matrix[k][j];
                }

        mirrored_x_points[p].x = mirrored_matrix_x[0][0];
        mirrored_x_points[p].y = mirrored_matrix_x[1][0];
        mirrored_x_points[p].z = mirrored_matrix_x[2][0];

        mirrored_y_points[p].x = mirrored_matrix_y[0][0];
        mirrored_y_points[p].y = mirrored_matrix_y[1][0];
        mirrored_y_points[p].z = mirrored_matrix_y[2][0];
    }

    for (int i = 0; i < 4; i++) {
        if (i + 1 == 4) {
            dda(mirrored_x_points[i].x, mirrored_x_points[i].y, mirrored_x_points[0].x, mirrored_x_points[0].y);
            dda(mirrored_y_points[i].x, mirrored_y_points[i].y, mirrored_y_points[0].x, mirrored_y_points[0].y);
        } else {
            dda(mirrored_x_points[i].x, mirrored_x_points[i].y, mirrored_x_points[i + 1].x, mirrored_x_points[i + 1].y);
            dda(mirrored_y_points[i].x, mirrored_y_points[i].y, mirrored_y_points[i + 1].x, mirrored_y_points[i + 1].y);
        }
    }
}

void display() {
    glColor3f(1.0, 1.0, 0.0);
    dda(-500, 0, 500, 0);
    dda(0, -500, 0, 500);

    glPointSize(1.5);
    glColor3f(1.0, 1.0, 1.0);
    draw_polygon();
    glEnd();
    glFlush();

    glPointSize(2.0);
    glColor3f(1.0, 0.0, 0.0);

    mirror();

    glEnd();
    glFlush();
}

int main(int argc, char **argv) {

    cout << "Enter the coordinates: " << endl;
    int x, y;

    for (int i = 0; i < 4; i++) {
        cin >> x >> y;
        points[i].x = x;
        points[i].y = y;
    }

    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(450, 100);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glutCreateWindow("Drawing a polygon and mirroring");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500, 500, -500, 500);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
/*
input
20 20
100 20
100 100
20 100
*/
