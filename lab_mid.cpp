#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <math.h>

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */

void display() {

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	// Draw a Red 1x1 Square centered at origin
	glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f); // Red
	glVertex2f(-0.9f, -0.7f);
	glVertex2f(-0.9f, 0.7f);
	glVertex2f(0.9f, 0.7f);
	glVertex2f(0.9f, -0.7f);    // x, y

	glEnd();

	glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 1.0f, 0.0f); // green

	glVertex2f(-0.9f, -0.7f);
	glVertex2f(-0.4f, 0.7f);
	glVertex2f(0.1f, -0.7f);    // x, y

	glEnd();


	// make a right arrow
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.5f, 0.0f); // Red

	glVertex2f(-0.2f, 0.3f);
	glVertex2f(-0.2f, 0.5f);
	glVertex2f(0.1f, 0.5f);
	glVertex2f(0.1f, 0.3f);

	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.5f, 0.0f); // Red

	glVertex2f(0.1f, 0.2f);
	glVertex2f(0.1f, 0.6f);
	glVertex2f(0.2f, 0.4f);

	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f); // yellow

	glVertex2f(0.2f, -0.5f);
	glVertex2f(0.3f, 0.5f);
	glVertex2f(0.7f, 0.5f);
	glVertex2f(0.8f, -0.5f);

	glEnd();


	// circle
    glMatrixMode(GL_POLYGON);
    glTranslatef(0.5f,0.0f,0.0f);
    //glColor3f(1.0f, 0.5f, 0.0f); // Red
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
    {
        glColor3f(1.0f, 0.0f, 0.0f); // Red
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();




	glFlush();  // Render now


}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(1000, 600);// Set the window's initial width & height
	glutCreateWindow("OpenGL Setup Test");
	//gluOrtho2D(-0.1,0.7,-0.1,0.3); // Create a window with the given title
	//glutInitWindowSize(500, 500);// Set the window's initial width & height
	glutDisplayFunc(display);// Register display callback handler for window re-paint
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}
