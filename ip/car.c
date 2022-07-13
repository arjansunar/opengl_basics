#include <GL/glut.h>
#include <math.h>

#define width 500
#define height 500

// initialization 
void init(){
	gluOrtho2D(0, width, 0, height);
}

// drawing circle 
void DrawCircleWithSpokes(float cx, float cy, float r) {
    glBegin(GL_LINE_LOOP);
    float x,y;
    for (int ii = 0; ii < 1000; ii++)   {
      x= cx + r * cos(ii);
      y= cy + r * sin(ii);
        glVertex2f(x,y);//output vertex 
    }
    glEnd();
	// drawing tire spokes
    for (int ii = 0; ii <= 360; ii+= 36)   {
		x= cx + r * cos(ii);
      	y= cy + r * sin(ii);
		glBegin(GL_LINE_LOOP);
			glVertex2f(cx,cy);
			glVertex2f(x,y);
		glEnd();
	}
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(4.0);
	// car frame
	glBegin(GL_LINE_LOOP);
		glVertex2i(100, 100);
		glVertex2i(100, 160);
		glVertex2i(150, 160);
		glVertex2i(200, 200);
		glVertex2i(400, 200);
		glVertex2i(450, 160);
		glVertex2i(450, 100);
	glEnd();
	glLineWidth(1.0);

	// front tire 
	DrawCircleWithSpokes(200,100,25);
	// back tire 9
	DrawCircleWithSpokes(380,100,25);

	// mid line 
	glBegin(GL_LINE_LOOP);
		glVertex2i(300, 100);
		glVertex2i(300, 200);
	glEnd();
	
	// horizontal mid line 
	glBegin(GL_LINE_LOOP);
		glVertex2i(150, 158);
		glVertex2i(450, 158);
	glEnd();
	
	// front triangle vertical line
	glBegin(GL_LINE_LOOP);
		glVertex2i(200, 200);
		glVertex2i(200, 160);
	glEnd();
	// back triangle vertical line 
	glBegin(GL_LINE_LOOP);
		glVertex2i(400, 200);
		glVertex2i(400, 160);
	glEnd();

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);// Use single display buffer.
	glutInitWindowSize(width,height);	// Set window size.
	glutInitWindowPosition(500, 300);
	glutCreateWindow("Arjan Gahatraj Sunar's 2D Car Development Individual Project");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}