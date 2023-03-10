/*

#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <conio.h>
#include <stdlib.h>
// center of the circle = (320, 240)
int xc = 320, yc = 240;
void plot_point(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(xc+x, yc+y);
    glVertex2i(xc+x, yc-y);
    glVertex2i(xc+y, yc+x);
    glVertex2i(xc+y, yc-x);
    glVertex2i(xc-x, yc-y);
    glVertex2i(xc-y, yc-x);
    glVertex2i(xc-x, yc+y);
    glVertex2i(xc-y, yc+x);
    glEnd();

}
//function for draw a circle using bresenham's
//circle drawing algorithm
void bresenham_circle(int r)
{

    int x=0, y=r;
    float pk=(5.0/4.0)-r;

    /*plot the points */
    /*plot the first point*/
   /* plot_point(x,y);
    int k;
    /*find all vertices till x=y */
    /*while(x < y)
    {
        x = x+1;
        if(pk < 0)
            pk = pk + 2*x+1;
        else
        {
            y = y - 1;
            pk = pk + 2*(x - y) +1;
        }
        plot_point(x,y);
    }
    glFlush();
}/*
//function to draw two concentric circles
void concentric_circles(void)
{
    /* clear buffers to preset values */
    /*glClear(GL_COLOR_BUFFER_BIT);
    int radius1 = 100, radius2 = 200;
    bresenham_circle(radius1);
}

void Init()
{
    /* set clear color to white */
    /*glClearColor(1.0,1.0,1.0,0);
    /*set fill color to black */
    /*glColor3f(0.0,0.0,0.0);
    /* glViewPort(0, 0, 640, 480); */
    /* glMatrixMode(GL_PROJECTION);*/
    /* gl LoadIdentify(); */
    /*glOrtho2D(0, 640,0, 480);
}/*
int main(int argc, char **argv)
{
    gluInit(&argc,argv);
    gluInitDisplayMode(GLUT_SINGLE | GLUT_RED);

    glutInitWindowPosition(0,0);
    glutInitWindowSize(640,480);

    glutCreateWindow("Bresenham_circle");

    Init();

    glutDisplayFunc(concentric_circles);

    glutMainLoop();
    return 0;
}

*/

#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int pntx1, pnty1, r;

void plot(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x+pntx1, y+pnty1);
    glEnd();
}
void myInit(void)

{
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0f,0.0f,0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,640.0,0.0,480.0);
}
void midPointCircle()
{
    int x = 0;
    int y = r;
    float decision = 5/4 -r;
    plot(x,y);
    while(y > x)
    {
        if(decision < 0)
        {
            x++;
            decision += 2*x + 1;
        }
        else{
            y--;
            x++;
            decision += 2*(x-y)+1;
        }
        plot(x,y);
        plot(x,-y);
        plot(-x,y);
        plot(-x,-y);
        plot(y,x);
        plot(-y,x);
        plot(y,-x);
        plot(-y,-x);

    }
}
void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    glPointSize(1.0);
    midPointCircle();
    glFlush();
}

main(int argc, char **argv)
{
    cout << "Enter the coordinate of the center.\n\n"<<endl;

    cout << "x-coordinate: ";cin >> pntx1;
    cout << "y-coordinate: ";cin >> pnty1;

    cout << "\nEnter radius :";cin >> r;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RED);

    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,150);
    glutCreateWindow("Circle Drawing Algorithm");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();

}











