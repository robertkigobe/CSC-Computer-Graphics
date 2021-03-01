/*
 Problem 1: Basic drawing (max number of points is 50)
 Make a drawing which includes:
 
*/
//  Created by Robert Kigobe on 28/02/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GLUT/glut.h>


//1a coordinates
int t1 [] = {10,100};
int t2 [] = {100,10};
int t6 [] = {100,200};
int t3 [] = {110,10};
int t4 [] = {200,100};
int t5 [] = {110,200};

//separator coordinates
int x = 210;
int m = 1;
int c = 0;

//rectangle coordinates
int vertex1 [] = {220,10};
int vertex2 [] = {420,100};

//polygon coordinates
int p1 [] = {220,150};
int p2 [] = {280,110};
int p3 [] = {360,110};
int p4 [] = {420,150};
int p5 [] = {360,200};
int p6 [] = {280,200};

//Patter to be used in a mask
GLubyte fillPattern []={
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x01, 0xf0,
    0x00, 0x00, 0x07, 0xf0, 0x0f, 0x00, 0x1f, 0xe0,
    0x1f, 0x80, 0x1f, 0xc0, 0x0f, 0xc0, 0x3f, 0x80,
    0x07, 0xe0, 0x7e, 0x00, 0x03, 0xf0, 0xff, 0x80,
    0x03, 0xf5, 0xff, 0xe0, 0x07, 0xfd, 0xff, 0xf8,
    0x1f, 0xfc, 0xff, 0xe8, 0xff, 0xe3, 0xbf, 0x70,
    0xde, 0x80, 0xb7, 0x00, 0x71, 0x10, 0x4a, 0x80,
    0x03, 0x10, 0x4e, 0x40, 0x02, 0x88, 0x8c, 0x20,
    0x05, 0x05, 0x04, 0x40, 0x02, 0x82, 0x14, 0x40,
    0x02, 0x40, 0x10, 0x80, 0x02, 0x64, 0x1a, 0x80,
    0x00, 0x92, 0x29, 0x00, 0x00, 0xb0, 0x48, 0x00,
    0x00, 0xc8, 0x90, 0x00, 0x00, 0x85, 0x10, 0x00,
    0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, };

void init(void)
{
    
    // specifying a 2D world coordinate reference frame
    
    glClearColor(0.0, 0.0, 0.0, 1.0); // Set display-window color to black.
    glMatrixMode(GL_PROJECTION); // Set projection parameters.
    gluOrtho2D (0.0, 900.0, 0.0, 600.0); //set projection parameters
}

//a) At least 2 geometric figures filled with solid colors;
void problem_1 (){
    
    glClear(GL_COLOR_BUFFER_BIT);//clear display window
    glColor3f(0.0,0.4,0.2); //set line segment color to green
    
    //draw some two traingles
    glBegin(GL_TRIANGLES);
        glVertex2iv(t1);
    glColor3f(1.0,0.0,0.0);
        glVertex2iv(t2);
        glVertex2iv(t6);
        glVertex2iv(t3);
    glColor3f(0.0,0.0,1.0);
    glVertex2iv(t4);
        glVertex2iv(t5);
       
    glEnd();
    
    //draw a line separator between 1a,1b
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
        
        glLineStipple(1,0x00FF);
        glLineWidth(4.0); //add the width attribute
        glColor3f(0.0,0.0,1.0);
        glVertex2i (210,0);
        glColor3f(1.0,0.0,0.0);
        glVertex2i (210,500);
    
        glEnd();
    glDisable(GL_LINE_STIPPLE);
    
    //b) At least 2 more filled with more than one color (color interpolation).
    
    glColor3f(0.66, 0.31, 0.13);
    glRectiv(vertex1,vertex2);
    
    //First Rectangle with two diffrent color
    
        glBegin(GL_POLYGON);
            glColor3f(1.0,0.0,0.0);
            glVertex2iv(p1);
            glColor3f(1.0,1.0,0.0);
            glVertex2iv(p2);
            glColor3f(0.0,1.0,1.0);
            glVertex2iv(p3);
            glColor3f(0.0,0.0,1.0);
            glVertex2iv(p4);
            glColor3f(1.0,0.0,1.0);
            glVertex2iv(p5);
            glColor3f(0.0,1.0,0.0);
            glVertex2iv(p6);
    
        glEnd();

    int i;
    int lineAmount = 100; //# of triangles used to draw circle
    int radius = 100;
    int center_x = 320;
    int center_y = 320;

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2 * 3.141592;

    glBegin(GL_LINE_LOOP);
        for(i = 0; i <= lineAmount;i++) {
            glColor3f(0.8,1.0,0.4);
            glVertex2f(
                center_x + (radius * cos(i *  twicePi / lineAmount)),
                center_y + (radius* sin(i * twicePi / lineAmount))
            );
        }
    glEnd();
    
    
    
    
    //draw a line separator between 1b,1c
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
        
        glLineStipple(1,0x0101); //add stipple on line
        glLineWidth(3.0); //add the width attribute
        glColor3f(0.0,1.0,1.0);
        glVertex2i (430,0);
        glColor3f(1.0,1.0,0.0);
        glVertex2i (430,500);
    
        glEnd();
    glDisable(GL_LINE_STIPPLE);
    
    // c) At least 3 more filled with given masks.
    
    //glShadeModel(GL_SMOOTH);// used to fill interpolation of colors
    glPolygonStipple (fillPattern);
    glEnable(GL_POLYGON_STIPPLE);
    glBegin(GL_POLYGON);
        glColor3f(1.0,0.0,0.0);
        glVertex2i (440,10);
        glColor3f(0.0,1.0,0.0);
        glVertex2i (880,10);
        glColor3f(0.0,0.0,1.0);
        glVertex2i (660,400);
    glEnd();
    glDisable(GL_POLYGON_STIPPLE);
    glFlush(); //process all Open gl functions as quickly as possible

    
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Initialize GLUT.

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode.

    glutInitWindowPosition(50, 100); // Set top-left display-window position.

    glutInitWindowSize(900, 600); // Set display-window width and height.
    glutCreateWindow("Problem 1a"); // Create display window.

    init(); // Execute initialization procedure.

    glutDisplayFunc(problem_1); // Send graphics to display window.

    glutMainLoop(); // Display everything and wait.
    return 1;
}
