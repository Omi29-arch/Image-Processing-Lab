#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>

float xStart, xEnd, yStart, yEnd;

void display(void)
{
    float dy, dx, step, x, y;

    x = xStart;
    y = yStart;
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();

    if(xStart == xEnd){
        while(y <= yEnd){
            y = y + 1;
            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();
        }
    }

    glFlush();
}

void init(void)
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); //multiply the current matrix by identity matrix
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

int main(int argc, char** argv)
{
    printf("Input xStart, yStart, xEnd, yEnd : \n");
    scanf("%f %f %f %f", &xStart, &yStart, &xEnd, &yEnd);

    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RED);
    glutCreateWindow("Direct Line Drawing Algorithm");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
