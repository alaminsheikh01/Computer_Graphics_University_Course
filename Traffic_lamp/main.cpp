#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include <math.h>

void box()
{
glColor3f(1.0f,0.0f,0.0f);
glBegin(GL_POLYGON);
glVertex2f(-0.10f,0.0f);
glVertex2f(0.10f,0.0f);
glVertex2f(0.10f,0.5f);
glVertex2f(-0.10f,0.5f);
glEnd();
}

void trinangle()
{
glColor3f(1.0f,1.0f,0.0f);
glBegin(GL_TRIANGLES);
glVertex2f(0.5f,0.0f);
glVertex2f(0.8f,0.0f);
glVertex2f(0.5f,0.2f);
glEnd();
}

void display() {
glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // Set background color to black and opaque
//glClearColor()
glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

//function calling
box();
//trinangle();

glFlush(); // Render now
}
/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
glutInit(&argc, argv); // Initialize GLUT
glutInitWindowSize(800, 600);// Set the window's initial width & height
glutCreateWindow("OpenGL Setup Test");
//gluOrtho2D(-0.1,0.7,-0.1,0.3); // Create a window with the given title
glutInitWindowSize(500, 700);// Set the window's initial width & height
glutDisplayFunc(display);// Register display callback handler for window re-paint
glutMainLoop(); // Enter the event-processing loop
return 0;
}
