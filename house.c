/*
* Compiler parameters:
* -framework GLUT
* -framework OpenGL
*/

#if defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// Displays a window with a square inside.

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	// Draw a square
	glBegin(GL_LINE_LOOP);
		glVertex2i(20, 30);
		glVertex2i(270, 30);
		glVertex2i(270, 150);
		glVertex2i(20, 150);
	glEnd();
	// draw a door
	glBegin(GL_LINE_LOOP);
		glVertex2i(100, 30);
		glVertex2i(170, 30);
		glVertex2i(170, 100);
		glVertex2i(100, 100);
	glEnd();

	// draw side wall
	glBegin(GL_LINE_LOOP);
		glVertex2i(270, 30);
		glVertex2i(470, 50);
		glVertex2i(470, 300);
		glVertex2i(270, 150);
	glEnd();


	// draw roof
	glBegin(GL_LINE_LOOP);
		glVertex2i(270, 150);
		glVertex2i(470, 300);
		glVertex2i(200, 300);
		glVertex2i(20, 150);
	glEnd();
	
	glFlush();
}

int main(int argc, char** argv)
{
	double width= 500;
	double height= 500;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);	// Use single display buffer.
	glutInitWindowSize(width,height);	// Set window size.
	glutInitWindowPosition(500, 100);
	glutCreateWindow("Hello world");
	gluOrtho2D(0, width, 0, height);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}