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
		glVertex2i(10, 10);
		glVertex2i(50, 10);
		glVertex2i(50, 20);
		glVertex2i(10, 20);
	glEnd();
	// draw a smaller square
	glBegin(GL_LINE_LOOP);
		glVertex2i(15, 20);
		glVertex2i(35, 20);
		glVertex2i(35, 30);
		glVertex2i(15, 30);
	glEnd();

	// draw flag stand
	glBegin(GL_LINE_LOOP);
		glVertex2i(25, 30);
		glVertex2i(25, 50);
	glEnd();


	// draw lower triangle
	glBegin(GL_LINE_LOOP);
		glVertex2i(25, 50);
		glVertex2i(65, 50);
		glVertex2i(25, 70);
	glEnd();
    // draw upper triangle
	glBegin(GL_LINE_LOOP);
		glVertex2i(25, 70);
		glVertex2i(55, 70);
		glVertex2i(25, 90);
	glEnd();
	
	glFlush();
}

int main(int argc, char** argv)
{
    double scale = 0.25;
	double width= 500;
	double height= 500;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);	// Use single display buffer.
	glutInitWindowSize(width,height);	// Set window size.
	glutInitWindowPosition(500, 100);
	glutCreateWindow("Hello world");
	gluOrtho2D(0, width * scale, 0, height*scale);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}