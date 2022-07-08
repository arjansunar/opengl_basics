/*
* Compiler parameters:
* -framework GLUT
* -framework OpenGL
*/
#include <math.h>

#if defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// drawing circle 
void DrawCircle(float cx, float cy, float r) {
    glBegin(GL_POLYGON);
    float x,y;
    for (int ii = 0; ii < 1000; ii++)   {
      x= cx + r * cos(ii);
      y= cy + r * sin(ii);
        glVertex2f(x,y);//output vertex 
    }
    glEnd();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	// Draw a fan
	glColor3d(0.5,0,0);
	glBegin(GL_POLYGON);
		glVertex2i(50, 20);
		glVertex2i(70, 120);
		glVertex2i(100, 120);
		glVertex2i(120, 20);
	glEnd();

    // diagonal
	glColor3d(0.5,0.8,0);
    glBegin(GL_POLYGON);
		glVertex2i(30, 80);
		glVertex2i(20, 90);
		glVertex2i(60, 130);
		glVertex2i(70, 120);
	glEnd();

     // diagonal
	glColor3d(0,.9,0);
    glBegin(GL_POLYGON);
		glVertex2i(140, 60);
		glVertex2i(90, 110);
		glVertex2i(100, 120);
		glVertex2i(150, 70);
	glEnd();

    // circle
	glColor3d(0.6,0.8,0);
    DrawCircle(85, 135,15);

    // diagonal
	glColor3d(0.6,0.8,0.9);
    glBegin(GL_POLYGON);
		glVertex2i(70, 150);
		glVertex2i(30, 190);
		glVertex2i(40, 200);
		glVertex2i(80, 160);	
	glEnd();

    // diagonal
	glColor3ub(255,0,0);
    glBegin(GL_POLYGON);
		glVertex2i(110, 140);
		glVertex2i(100, 150);
		glVertex2i(140, 190);
		glVertex2i(150, 180);
	glEnd();

	glFlush();
}

int main(int argc, char** argv)
{
    double scale = 0.5;
	double width= 500;
	double height= 500;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);	// Use single display buffer.
	glutInitWindowSize(width,height);	// Set window size.
	glutInitWindowPosition(500, 100);
	glutCreateWindow("fan");
	gluOrtho2D(0, width * scale, 0, height*scale);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
