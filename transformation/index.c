#include <GL/glut.h>
#include <math.h>

#define width 500
#define height 500

// initialization 
void init(){
	gluOrtho2D(0, width, 0, height);
}

// drawing circle 
void DrawCircle(float cx, float cy, float r) {
    glBegin(GL_LINE_LOOP);
    float x,y;
    for (int ii = 0; ii < 1000; ii++)   {
      x= cx + r * cos(ii);
      y= cy + r * sin(ii);
        glVertex2f(x,y);//output vertex 
    }
    glEnd();
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);// Use single display buffer.
	glutInitWindowSize(width,height);	// Set window size.
	glutInitWindowPosition(500, 300);
	glutCreateWindow("Transformations");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}