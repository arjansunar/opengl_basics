#include <math.h>
#include <GL/glut.h>

// drawing circle 
void DrawCircle(float cx, float cy, float r) {
    glBegin(GL_LINE_LOOP);
    float x,y;
    for (int ii = 0; ii < 50; ii++)   {
      x= cx + r * cos(ii);
      y= cy + r * sin(ii);
        glVertex2f(x,y);//output vertex 
    }
    glEnd();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	// Drawing two circle A
    glColor3ub(255,255,0);        
    DrawCircle(100,100,50);
    glColor3ub(255,0,0);        
    DrawCircle(100,100,35);

    // Drawing two circle B
    glColor3ub(255,255,0);        
    DrawCircle(300,200,150);
    glColor3ub(255,0,0);        
    DrawCircle(300,200,105);

	glFlush();
}

int main(int argc, char** argv)
{
    double scale = 1;
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
