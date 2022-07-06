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
	glBegin(GL_POLYGON);
	    glVertex2i(5,0);
        glVertex2i(5,5);
        glVertex2i(5,12);
        glVertex2i(5,15);
        glVertex2i(10,12);
        glVertex2i(10,8);
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
	gluOrtho2D(-width*scale /2, width/2 *scale, -height*scale /2, height/2 *scale);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}