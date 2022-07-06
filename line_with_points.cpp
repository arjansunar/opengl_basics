#include <GL/glut.h>

void init () 
{
    glClearColor (0.0, 0.0, 0.0, 0.0);//select clearing (background) color
    glMatrixMode(GL_PROJECTION);  //initialize viewing values 
    glLoadIdentity(); // to load the program
    gluOrtho2D (0.0, 200.0, 0.0, 300.0); //glOrtho2D - the display will be in the range of this area
}
void display()
{
    glClear (GL_COLOR_BUFFER_BIT);//clear all pixels
    glColor3f (1.0, 1.0, 0.0);//set color to yellow
    glPointSize(5.0f);//set point size to 10 pixels
    glBegin(GL_POINTS);
      glVertex2i(50, 100);//defines a point at x = 100, y = 150, z = 0; 
      glVertex2i(75, 150);//this function takes only 2 parameters, z is always 0.
      glVertex2i(100, 200);
    glEnd();
    glFlush (); //start processing buffered OpenGL routines
}

//Declare initial window size, position, and display mode (single buffer and RGBA). 
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    //GLUT_SINGLE - This means that the program is automatically drawing straight to the window.
    //GLUT_DOUBLE -  giving the program buffer to draw what it has to, then transfer what is actually needed to the screen.
    //GLUT_RGB - An alias for GLUT_RGBA.
    //GLUT_DEPTH - Bit mask to request a window with a depth buffer.
    glutInitWindowSize (200, 300); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Lab 2 – Create Points");
    init ();
    glutDisplayFunc(display); 
    glutMainLoop();
}