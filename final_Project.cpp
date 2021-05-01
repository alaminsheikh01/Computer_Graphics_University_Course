#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <GL/gl.h>
using namespace std;

//Initializes 3D rendering
void initRendering()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    //glEnable(GL_BLEND);
}

void handleResize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float _cameraAngle = 0.0;

float x = 0;
float sun = 0.0;

static int cl = 0;


void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
    glLoadIdentity(); //Reset the drawing perspectivew
    glTranslatef(0.0, 0.0, -7.0); //Move forward 5 units

    glPushMatrix();


        glScalef(1.03, 1, 0);
        glPushMatrix();


        ///Goal Post Border Line

        glPushMatrix();

        glColor3ub(255, 255, 255);

        glBegin(GL_LINE_LOOP);

        glVertex2f(-3.58, -.58);
        glVertex2f(-4.199, -1.79);
        glVertex2f(2.76, -1.79);
        glVertex2f(2.17, -.58);
        glEnd();

        ///Middle Line
        glBegin(GL_LINES);

        glVertex2f(-0.7, -.58);
        glVertex2f(-0.7, -1.79);
        glEnd();

        glPopMatrix();

        ///Field middle circle
        glPushMatrix();
        glTranslatef(-0.7, -1.1, 0.0);
        glRotatef(40, -1.0, 0.0, 0.0);
        glPushMatrix();
        glColor3ub(255, 255, 255);
        //glPointSize(2);
        glBegin(GL_LINES);

        for (int i = 0; i < 200; i++)
        {
            float pi = 3.1416;
            float A = (i * 2 * pi) / 100;
            float r = 0.28;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x, y);
        }
        glEnd();

        glBegin(GL_POLYGON);

        for (int i = 0; i < 200; i++)
        {
            float pi = 3.1416;
            float A = (i * 2 * pi) / 100;
            float r = 0.05;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x, y);
        }
        glEnd();

        glPopMatrix();
        glPopMatrix();

        ///Goal Post Line Border END



        ///Goal Post

        //Goal Post 1111


        glPushMatrix();
        glScalef(0.9, 0.9, 0);
        glTranslatef(2.75, -1.4, 0.0);
        glPushMatrix();
        glColor3ub(255, 255, 255);
        glBegin(GL_POLYGON);
        glVertex3f(0.05, 0.01, 0);
        glVertex3f(0.05, 0.5, 0);
        glVertex3f(0.0, 0.5, 0);
        glVertex3f(0.0, 0.01, 0);
        glEnd();

        glColor3ub(255, 255, 255);
        glBegin(GL_POLYGON);
        glVertex3f(0.05, 0.5, 0);
        glVertex3f(-0.15, 0.85, 0);
        glVertex3f(-0.2, 0.85, 0);
        glVertex3f(0.0, 0.5, 0);
        glEnd();

        glColor3ub(255, 255, 255);
        glBegin(GL_POLYGON);
        glVertex3f(-0.15, 0.4, 0);
        glVertex3f(-0.15, 0.85, 0);
        glVertex3f(-0.2, 0.85, 0);
        glVertex3f(-0.2, 0.4, 0);
        glEnd();

        glPopMatrix();
        glPopMatrix();


        //Goal Post 2222

        glPushMatrix();

        glScalef(0.9, 0.9, 0);
        glTranslatef(-3.93, -1.4, 0.0);
        glPushMatrix();
        glColor3ub(255, 255, 255);
        glBegin(GL_POLYGON);
        glVertex3f(-0.45, 0.01, 0);
        glVertex3f(-0.45, 0.5, 0);
        glVertex3f(-0.4, 0.5, 0);
        glVertex3f(-0.4, 0.01, 0);
        glEnd();

        glColor3ub(255, 255, 255);
        glBegin(GL_POLYGON);
        glVertex3f(-0.2, 0.85, 0);
        glVertex3f(-0.25, 0.85, 0);
        glVertex3f(-0.45, 0.5, 0);
        glVertex3f(-0.4, 0.5, 0);
        glEnd();

        glColor3ub(255, 255, 255);
        glBegin(GL_POLYGON);
        glVertex3f(-0.2, 0.4, 0);
        glVertex3f(-0.2, 0.85, 0);
        glVertex3f(-0.25, 0.85, 0);
        glVertex3f(-0.25, 0.4, 0);
        glEnd();

        glPopMatrix();
        glPopMatrix();

        ///Goal Post End



        ///TREE-1


        glPushMatrix();  /// TREE-1(from left) Main portion lower  ///////////glTranslatef(.8, .9, 0);
        glTranslatef(-3.9, -.25, 0);
        glRotatef(-90, 1, 0, 0);
        glColor3ub(0, 255, 0);
        glutSolidCone(.3, .6, 15, 20);
        glPopMatrix();


        glPushMatrix();  /// TREE-1(from left) Main portion upper  ///////////
        glTranslatef(-3.9, 0, 0);
        glRotatef(-90, 1, 0, 0);
        glColor3ub(0, 255, 0);
        glutSolidCone(.3, .6, 15, 15);
        glPopMatrix();

        glPushMatrix();  /// TREE-1(from left) lower portion  ///////////
        glTranslatef(-2, -.7, 0);
        glColor3ub(139, 69, 19);
        glBegin(GL_POLYGON);
        glVertex3f(-1.95, 0.6, 0);
        glVertex3f(-1.95, 0.15, 0);
        glVertex3f(-1.85, 0.15, 0);
        glVertex3f(-1.85, 0.6, 0);
        glEnd();
        glPopMatrix();

        /// TREE-2
        glPushMatrix();
        glTranslatef(1.5, 0, 0);



        glPushMatrix();  /// TREE-2(from left) Main portion lower  ///////////
        glTranslatef(-3.9, -.25, 0);
        glRotatef(-90, 1, 0, 0);
        glColor3ub(0, 255, 0);
        glutSolidCone(.3, .6, 15, 15);
        glPopMatrix();


        glPushMatrix();  /// TREE-2(from left) Main portion upper  ///////////
        glTranslatef(-3.9, 0, 0);
        glRotatef(-90, 1, 0, 0);
        glColor3ub(0, 255, 0);
        glutSolidCone(.3, .6, 15, 15);
        glPopMatrix();

        glPushMatrix();  /// TREE-2(from left) lower portion  ///////////
        glTranslatef(-2, -.7, 0);
        glColor3ub(139, 69, 19);
        glBegin(GL_POLYGON);
        glVertex3f(-1.95, 0.6, 0);
        glVertex3f(-1.95, 0.15, 0);
        glVertex3f(-1.85, 0.15, 0);
        glVertex3f(-1.85, 0.6, 0);
        glEnd();
        glPopMatrix();

        glPopMatrix();



        /// TREE-3
        glPushMatrix();
        glTranslatef(2.5, 0, 0);



        glPushMatrix();  /// TREE-3(from left) Main portion lower  ///////////
        glTranslatef(-3.9, -.25, 0);
        glRotatef(-90, 1, 0, 0);
        glColor3ub(0, 255, 0);
        glutSolidCone(.3, .6, 15, 15);
        glPopMatrix();

        glPushMatrix();  /// TREE-3(from left) Main portion upper  ///////////
        glTranslatef(-3.9, 0, 0);
        glRotatef(-90, 1, 0, 0);
        glColor3ub(0, 255, 0);
        glutSolidCone(.3, .6, 15, 15);
        glPopMatrix();

        glPushMatrix();  /// TREE-3(from left) lower portion  ///////////
        glTranslatef(-2, -.7, 0);
        glColor3ub(139, 69, 19);

        glBegin(GL_POLYGON);
        glVertex3f(-1.95, 0.6, 0);
        glVertex3f(-1.95, 0.15, 0);
        glVertex3f(-1.85, 0.15, 0);
        glVertex3f(-1.85, 0.6, 0);
        glEnd();
        glPopMatrix();

        glPopMatrix();

        /// TREE-4
        glPushMatrix();
        glTranslatef(6, 0, 0);



        glPushMatrix();  /// TREE-4(from left) Main portion lower  ///////////
        glTranslatef(-3.9, -.25, 0);
        glRotatef(-90, 1, 0, 0);
        glColor3ub(0, 255, 0);
        glutSolidCone(.3, .6, 15, 15);
        glPopMatrix();


        glPushMatrix();  /// TREE-4(from left) Main portion upper  ///////////
        glTranslatef(-3.9, 0, 0);
        glRotatef(-90, 1, 0, 0);
        glColor3ub(0, 255, 0);
        glutSolidCone(.3, .6, 15, 15);
        glPopMatrix();

        glPushMatrix();  /// TREE-4(from left) lower portion  ///////////
        glTranslatef(-2, -.7, 0);
        glColor3ub(139, 69, 19);
        glBegin(GL_POLYGON);
        glVertex3f(-1.95, 0.6, 0);
        glVertex3f(-1.95, 0.15, 0);
        glVertex3f(-1.85, 0.15, 0);
        glVertex3f(-1.85, 0.6, 0);
        glEnd();
        glPopMatrix();

        glPopMatrix();



        ///window design starts from here

        glPushMatrix();
        glTranslatef(-4.57, -.07, 0);
        glBegin(GL_POLYGON);    /// inside Window of Annex-2 From Left-1
        glColor3ub(0, 0, 0);
        glVertex2f(.2, .2);
        glVertex2f(.2, 0);
        glVertex2f(0, 0);
        glVertex2f(0, .2);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-4.33, -.07, 0);
        glBegin(GL_POLYGON);    /// inside Window of Annex-2 From Left-1
        glColor3ub(0, 0, 0);
        glVertex2f(.2, .2);
        glVertex2f(.2, 0);
        glVertex2f(0, 0);
        glVertex2f(0, .2);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-4.57, .16, 0);
        glBegin(GL_POLYGON);    /// inside Window of Annex-2 From Left-1
        glColor3ub(0, 0, 0);
        glVertex2f(.2, .2);
        glVertex2f(.2, 0);
        glVertex2f(0, 0);
        glVertex2f(0, .2);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-4.33, .16, 0);
        glBegin(GL_POLYGON);    /// inside Window of Annex-2 From Left-1
        glColor3ub(0, 0, 0);
        glVertex2f(.2, .2);
        glVertex2f(.2, 0);
        glVertex2f(0, 0);
        glVertex2f(0, .2);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-4.6, -.1, 0);
        glBegin(GL_POLYGON);    /// Window of Annex-2 From Left-1
        glColor3ub(255, 255, 224);
        glVertex2f(.5, .5);
        glVertex2f(.5, 0);
        glVertex2f(0, 0);
        glVertex2f(0, .5);
        glEnd();
        glPopMatrix();

        ///
        glPushMatrix();
        glTranslatef(-3.37, -.07, 0);
        glBegin(GL_POLYGON);    /// inside Window of Annex-2 From Left-2
        glColor3ub(0, 0, 0);
        glVertex2f(.2, .2);
        glVertex2f(.2, 0);
        glVertex2f(0, 0);
        glVertex2f(0, .2);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-3.13, -.07, 0);
        glBegin(GL_POLYGON);    /// inside Window of Annex-2 From Left-2
        glColor3ub(0, 0, 0);
        glVertex2f(.2, .2);
        glVertex2f(.2, 0);
        glVertex2f(0, 0);
        glVertex2f(0, .2);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-3.37, .16, 0);
        glBegin(GL_POLYGON);    /// inside Window of Annex-2 From Left-2
        glColor3ub(0, 0, 0);
        glVertex2f(.2, .2);
        glVertex2f(.2, 0);
        glVertex2f(0, 0);
        glVertex2f(0, .2);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-3.13, .16, 0);
        glBegin(GL_POLYGON);    /// inside Window of Annex-2 From Left-2
        glColor3ub(0, 0, 0);
        glVertex2f(.2, .2);
        glVertex2f(.2, 0);
        glVertex2f(0, 0);
        glVertex2f(0, .2);
        glEnd();
        glPopMatrix();
        ///

        glPushMatrix();
        glTranslatef(-3.4, -.1, 0);
        glBegin(GL_POLYGON);    /// Window of Annex-2 From Left-2
        glColor3ub(255, 255, 224);
        glVertex2f(.5, .5);
        glVertex2f(.5, 0);
        glVertex2f(0, 0);
        glVertex2f(0, .5);
        glEnd();
        glPopMatrix();

        ///
        glPushMatrix();
        glTranslatef(-2.17, -.07, 0);
        glBegin(GL_POLYGON);    /// inside Window of Annex-2 From Left-3
        glColor3ub(0, 0, 0);
        glVertex2f(.2, .2);
        glVertex2f(.2, 0);
        glVertex2f(0, 0);
        glVertex2f(0, .2);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-1.94, -.07, 0);
        glBegin(GL_POLYGON);    /// inside Window of Annex-2 From Left-3
        glColor3ub(0, 0, 0);
        glVertex2f(.2, .2);
        glVertex2f(.2, 0);
        glVertex2f(0, 0);
        glVertex2f(0, .2);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-2.17, .16, 0);
        glBegin(GL_POLYGON);    /// inside Window of Annex-2 From Left-3
        glColor3ub(0, 0, 0);
        glVertex2f(.2, .2);
        glVertex2f(.2, 0);
        glVertex2f(0, 0);
        glVertex2f(0, .2);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-1.94, .16, 0);
        glBegin(GL_POLYGON);    /// inside Window of Annex-2 From Left-3
        glColor3ub(0, 0, 0);
        glVertex2f(.2, .2);
        glVertex2f(.2, 0);
        glVertex2f(0, 0);
        glVertex2f(0, .2);
        glEnd();
        glPopMatrix();
        ///

        glPushMatrix();
        glTranslatef(-2.2, -.1, 0);
        glBegin(GL_POLYGON);    /// Window of Annex-2 From Left-3
        glColor3ub(255, 255, 224);

        glVertex2f(.5, .5);
        glVertex2f(.5, 0);
        glVertex2f(0, 0);
        glVertex2f(0, .5);
        glEnd();
        glPopMatrix();


        glPushMatrix();
        glTranslatef(1.53, -.07, 0);
        glBegin(GL_POLYGON);    /// inside Window of Annex-2 From Left-4
        glColor3ub(0, 0, 0);
        glVertex2f(.2, .2);
        glVertex2f(.2, 0);
        glVertex2f(0, 0);
        glVertex2f(0, .2);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(1.77, -.07, 0);
        glBegin(GL_POLYGON);    /// inside Window of Annex-2 From Left-4
        glColor3ub(0, 0, 0);
        glVertex2f(.2, .2);
        glVertex2f(.2, 0);
        glVertex2f(0, 0);
        glVertex2f(0, .2);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(1.53, .16, 0);
        glBegin(GL_POLYGON);    /// inside Window of Annex-2 From Left-4
        glColor3ub(0, 0, 0);
        glVertex2f(.2, .2);
        glVertex2f(.2, 0);
        glVertex2f(0, 0);
        glVertex2f(0, .2);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(1.77, .16, 0);
        glBegin(GL_POLYGON);    /// inside Window of Annex-2 From Left-4
        glColor3ub(0, 0, 0);
        glVertex2f(.2, .2);
        glVertex2f(.2, 0);
        glVertex2f(0, 0);
        glVertex2f(0, .2);
        glEnd();
        glPopMatrix();
        ///
        glPushMatrix();
        glTranslatef(1.5, -.1, 0);
        glBegin(GL_POLYGON);    /// Window of Annex-2 From Left-4
        glColor3ub(255, 255, 255);

        glVertex2f(.5, .5);
        glVertex2f(.5, 0);
        glVertex2f(0, 0);
        glVertex2f(0, .5);
        glEnd();
        glPopMatrix();

        ///
        glPushMatrix();
        glTranslatef(2.73, -.07, 0);
        glBegin(GL_POLYGON);    /// inside Window of Annex-2 From Left-5
        glColor3ub(0, 0, 0);
        glVertex2f(.2, .2);
        glVertex2f(.2, 0);
        glVertex2f(0, 0);
        glVertex2f(0, .2);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(2.97, -.07, 0);
        glBegin(GL_POLYGON);    /// inside Window of Annex-2 From Left-5
        glColor3ub(0, 0, 0);
        glVertex2f(.2, .2);
        glVertex2f(.2, 0);
        glVertex2f(0, 0);
        glVertex2f(0, .2);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(2.73, .16, 0);
        glBegin(GL_POLYGON);    /// inside Window of Annex-2 From Left-5
        glColor3ub(0, 0, 0);
        glVertex2f(.2, .2);
        glVertex2f(.2, 0);
        glVertex2f(0, 0);
        glVertex2f(0, .2);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(2.97, .16, 0);
        glBegin(GL_POLYGON);    /// inside Window of Annex-2 From Left-5
        glColor3ub(0, 0, 0);
        glVertex2f(.2, .2);
        glVertex2f(.2, 0);
        glVertex2f(0, 0);
        glVertex2f(0, .2);
        glEnd();
        glPopMatrix();
        ///

        glPushMatrix();
        glTranslatef(2.7, -.1, 0);
        glBegin(GL_POLYGON);    /// Window of Annex-2 From Left-5
        glColor3ub(255, 255, 224);

        glVertex2f(.5, .5);
        glVertex2f(.5, 0);
        glVertex2f(0, 0);
        glVertex2f(0, .5);
        glEnd();
        glPopMatrix();

        ///
        glPushMatrix();
        glTranslatef(3.93, -.07, 0);
        glBegin(GL_POLYGON);    /// inside Window of Annex-2 From Left-6
        glColor3ub(0, 0, 0);
        glVertex2f(.2, .2);
        glVertex2f(.2, 0);
        glVertex2f(0, 0);
        glVertex2f(0, .2);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(4.17, -.07, 0);
        glBegin(GL_POLYGON);    /// inside Window of Annex-2 From Left-6
        glColor3ub(0, 0, 0);
        glVertex2f(.2, .2);
        glVertex2f(.2, 0);
        glVertex2f(0, 0);
        glVertex2f(0, .2);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(3.93, .16, 0);
        glBegin(GL_POLYGON);    /// inside Window of Annex-2 From Left-6
        glColor3ub(0, 0, 0);
        glVertex2f(.2, .2);
        glVertex2f(.2, 0);
        glVertex2f(0, 0);
        glVertex2f(0, .2);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(4.17, .16, 0);
        glBegin(GL_POLYGON);    /// inside Window of Annex-2 From Left-6
        glColor3ub(0, 0, 0);
        glVertex2f(.2, .2);
        glVertex2f(.2, 0);
        glVertex2f(0, 0);
        glVertex2f(0, .2);
        glEnd();
        glPopMatrix();
        ///

        glPushMatrix();
        glTranslatef(3.9, -.1, 0);
        glBegin(GL_POLYGON);    /// Window of Annex-2 From Left-6
        glColor3ub(255, 255, 224);

        glVertex2f(.5, .5);
        glVertex2f(.5, 0);
        glVertex2f(0, 0);
        glVertex2f(0, .5);
        glEnd();
        glPopMatrix();

        glBegin(GL_POLYGON);   /// Red portion of Annex-2
        glColor3f(.7, 0, 0);
        glVertex2f(-5, -.2);
        glVertex2f(5, -.2);
        glVertex2f(5, .55);
        glVertex2f(-5, .55);
        glEnd();

        glBegin(GL_POLYGON); /// white portion of Annex-2
        glColor3f(1, 1, 1);

        glVertex2f(5, .5);
        glVertex2f(5, .6);
        glVertex2f(-5, .6);
        glVertex2f(-5, .5);
        glEnd();


        /// Field color start

        glBegin(GL_POLYGON);   /// Field Street
        glColor3ub(84, 84, 84);
        glVertex2f(-5, -.2);
        glVertex2f(-5, -.4);
        glVertex2f(5, -.4);
        glVertex2f(5, -.2);
        glEnd();

        glBegin(GL_POLYGON);   /// Field Street Triangle
        glColor3ub(19,198, 37);
        glVertex2f(-5, -.2);
        glVertex2f(-4.7, -.4);
        glVertex2f(-5, -.6);
        glEnd();

        glBegin(GL_POLYGON);   /// Field Lower
      //  glColor3f(0,.6,0);
        glVertex2f(-5, -.4);
        glVertex2f(-5, -2);
        glVertex2f(3.6, -2);
        glVertex2f(2.5, -.4);
        glEnd();

        glBegin(GL_POLYGON);   /// Tennis Court / Pool
        glColor3ub(0, 255, 0);
        glColor3ub(0, 0, 255);
        glVertex2f(3.6, -2);
        glVertex2f(5, -2);
        glVertex2f(5, -.4);
        glVertex2f(2.5, -.4);
        glEnd();


        /// Field color end

        /// Cloud start

        glPushMatrix();   ///  Cloud A  ///////////////
        glTranslatef(x, 0, 0);
        glTranslatef(2, -.3, 0);
        if (cl % 2 == 1)
        {
            glScalef(1.5, 1.3, 0);
        }
        else
        {
            glScalef(1, 1.2, 0);
        }

        glPushMatrix();    /// Cloud-A-1
        glTranslatef(-3, 2, 0.0);
        glColor3f(1.0, 1.0, 1);
        glBegin(GL_POLYGON);
        for (int i = 0; i < 400; i++)
        {
            float pi = 3.1416;
            float A = (i * 2 * pi) / 100;
            float r = .19;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x, y);
        }
        glEnd();
        glPopMatrix();

        glPushMatrix();    /// Cloud-A-2
        glTranslatef(-2.75, 2.15, 0.0);
        glColor3f(1.0, 1.0, 1);
        glBegin(GL_POLYGON);
        for (int i = 0; i < 400; i++)
        {
            float pi = 3.1416;
            float A = (i * 2 * pi) / 100;
            float r = .19;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x, y);
        }
        glEnd();
        glPopMatrix();

        glPushMatrix();    /// Cloud-A-3
        glTranslatef(-2.5, 2.15, 0.0);
        glColor3f(1.0, 1.0, 1);
        glBegin(GL_POLYGON);
        for (int i = 0; i < 400; i++)
        {
            float pi = 3.1416;
            float A = (i * 2 * pi) / 100;
            float r = .19;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x, y);
        }
        glEnd();
        glPopMatrix();

        glPushMatrix();    /// Cloud-A-4
        glTranslatef(-2.75, 1.9, 0.0);
        glColor3f(1.0, 1.0, 1);
        glBegin(GL_POLYGON);
        for (int i = 0; i < 400; i++)
        {
            float pi = 3.1416;
            float A = (i * 2 * pi) / 100;
            float r = .19;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x, y);
        }
        glEnd();
        glPopMatrix();

        glPushMatrix();    /// Cloud-A-5
        glTranslatef(-2.5, 1.9, 0.0);
        glColor3f(1.0, 1.0, 1);
        glBegin(GL_POLYGON);
        for (int i = 0; i < 400; i++)
        {
            float pi = 3.1416;
            float A = (i * 2 * pi) / 100;
            float r = .19;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x, y);
        }
        glEnd();
        glPopMatrix();

        glPushMatrix();    /// Cloud-A-6
        glTranslatef(-2.25, 2, 0.0);
        glColor3f(1.0, 1.0, 1);
        glBegin(GL_POLYGON);
        for (int i = 0; i < 400; i++)
        {
            float pi = 3.1416;
            float A = (i * 2 * pi) / 100;
            float r = .19;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x, y);
        }
        glEnd();
        glPopMatrix();

        glPopMatrix();

        glPushMatrix();   ///  Cloud B  ///////////////
        glTranslatef(x, -.3, 0);
        //glScalef(1,1.2,0);

        glPushMatrix();    /// Cloud-B-1
        glTranslatef(-3, 2, 0.0);
        glColor3f(1.0, 1.0, 1);
        glBegin(GL_POLYGON);
        for (int i = 0; i < 400; i++)
        {
            float pi = 3.1416;
            float A = (i * 2 * pi) / 100;
            float r = .19;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x, y);
        }
        glEnd();
        glPopMatrix();

        glPushMatrix();    /// Cloud-B-2
        glTranslatef(-2.75, 2.15, 0.0);
        glColor3f(1.0, 1.0, 1);
        glBegin(GL_POLYGON);
        for (int i = 0; i < 400; i++)
        {
            float pi = 3.1416;
            float A = (i * 2 * pi) / 100;
            float r = .19;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x, y);
        }
        glEnd();
        glPopMatrix();

        glPushMatrix();    /// Cloud-B-3
        glTranslatef(-2.5, 2.15, 0.0);
        glColor3f(1.0, 1.0, 1);
        glBegin(GL_POLYGON);
        for (int i = 0; i < 400; i++)
        {
            float pi = 3.1416;
            float A = (i * 2 * pi) / 100;
            float r = .19;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x, y);
        }
        glEnd();
        glPopMatrix();

        glPushMatrix();    /// Cloud-B-4
        glTranslatef(-2.75, 1.9, 0.0);
        glColor3f(1.0, 1.0, 1);
        glBegin(GL_POLYGON);
        for (int i = 0; i < 400; i++)
        {
            float pi = 3.1416;
            float A = (i * 2 * pi) / 100;
            float r = .19;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x, y);
        }
        glEnd();
        glPopMatrix();

        glPushMatrix();    /// Cloud-B-5
        glTranslatef(-2.5, 1.9, 0.0);
        glColor3f(1.0, 1.0, 1);
        glBegin(GL_POLYGON);
        for (int i = 0; i < 400; i++)
        {
            float pi = 3.1416;
            float A = (i * 2 * pi) / 100;
            float r = .19;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x, y);
        }
        glEnd();
        glPopMatrix();

        glPushMatrix();    /// Cloud-B-6
        glTranslatef(-2.25, 2, 0.0);
        glColor3f(1.0, 1.0, 1);
        glBegin(GL_POLYGON);
        for (int i = 0; i < 400; i++)
        {
            float pi = 3.1416;
            float A = (i * 2 * pi) / 100;
            float r = .19;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x, y);
        }
        glEnd();
        glPopMatrix();

        glPopMatrix();

        glPushMatrix();  /// Sun
        glTranslatef(sun, 0, 0);
        glPushMatrix();
        glTranslatef(-4.5, 2.5, 0.0);
        glColor3f(1.0, 1.0, 0);
        glBegin(GL_POLYGON);
        for (int i = 0; i < 400; i++)
        {
            float pi = 3.1416;
            float A = (i * 2 * pi) / 100;
            float r = .35;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x, y);
        }
        glEnd();
        glPopMatrix();
        glPopMatrix();

        glBegin(GL_POLYGON);   /// Sky
        glColor3ub(135, 206, 250);
        glVertex2f(-5, -.2);
        glVertex2f(5, -.2);
        glVertex2f(5, 3);
        glVertex2f(-5, 3);
        glEnd();

        glPopMatrix();

    glPopMatrix();


    glFlush();
    glLoadIdentity();
}


int main(int argc, char** argv)
{
    //Initialize GLUT
    glutInit(&argc, argv);
    glutInitWindowSize(1120, 650);

    glutCreateWindow("AIUB");
    initRendering();

    glutDisplayFunc(display);

    glutReshapeFunc(handleResize);
    glutMainLoop();
    return 0;
}

