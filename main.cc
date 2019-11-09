#include "Game.h"
#include "boost/lambda/lambda.hpp"
#include <iostream>
#include <iterator>
#include <algorithm>

#include <GL/glut.h>

#define 	GLFW_KEY_SPACE   32
#define 	GLFW_KEY_A   65
#define 	GLFW_KEY_B   66
#define 	GLFW_KEY_C   67
#define 	GLFW_KEY_D   68
#define 	GLFW_KEY_E   69
#define 	GLFW_KEY_F   70
#define 	GLFW_KEY_G   71
#define 	GLFW_KEY_H   72
#define 	GLFW_KEY_I   73
#define 	GLFW_KEY_J   74
#define 	GLFW_KEY_K   75
#define 	GLFW_KEY_L   76
#define 	GLFW_KEY_M   77
#define 	GLFW_KEY_N   78
#define 	GLFW_KEY_O   79
#define 	GLFW_KEY_P   80
#define 	GLFW_KEY_Q   81
#define 	GLFW_KEY_R   82
#define 	GLFW_KEY_S   83
#define 	GLFW_KEY_T   84
#define 	GLFW_KEY_U   85
#define 	GLFW_KEY_V   86
#define 	GLFW_KEY_W   87
#define 	GLFW_KEY_X   88
#define 	GLFW_KEY_Y   89
#define 	GLFW_KEY_Z   90

// Global Variables
double rotate_y=0; 
double rotate_x=0;

void display(void)
{
    //Clear all pixels
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glLoadIdentity();

    // Rotate when user changes rotate_x and rotate_y
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    //White side - BACK
    glBegin(GL_POLYGON);
    glColor3f(   1.0,  1.0, 1.0 );
    glVertex3f(  0.5, -0.5, 0.5 );
    glVertex3f(  0.5,  0.5, 0.5 );
    glVertex3f( -0.5,  0.5, 0.5 );
    glVertex3f( -0.5, -0.5, 0.5 );
    glEnd();

    // Purple side - RIGHT
    glBegin(GL_POLYGON);
    glColor3f(  1.0,  0.0,  1.0 );
    glVertex3f( 0.5, -0.5, -0.5 );
    glVertex3f( 0.5,  0.5, -0.5 );
    glVertex3f( 0.5,  0.5,  0.5 );
    glVertex3f( 0.5, -0.5,  0.5 );
    glEnd();

    // Green side - LEFT
    glBegin(GL_POLYGON);
    glColor3f(   0.0,  1.0,  0.0 );
    glVertex3f( -0.5, -0.5,  0.5 );
    glVertex3f( -0.5,  0.5,  0.5 );
    glVertex3f( -0.5,  0.5, -0.5 );
    glVertex3f( -0.5, -0.5, -0.5 );
    glEnd();

    // Blue side - TOP
    glBegin(GL_POLYGON);
    glColor3f(   0.0,  0.0,  1.0 );
    glVertex3f(  0.5,  0.5,  0.5 );
    glVertex3f(  0.5,  0.5, -0.5 );
    glVertex3f( -0.5,  0.5, -0.5 );
    glVertex3f( -0.5,  0.5,  0.5 );
    glEnd();

    // Red side - BOTTOM
    glBegin(GL_POLYGON);
    glColor3f(   1.0,  0.0,  0.0 );
    glVertex3f(  0.5, -0.5, -0.5 );
    glVertex3f(  0.5, -0.5,  0.5 );
    glVertex3f( -0.5, -0.5,  0.5 );
    glVertex3f( -0.5, -0.5, -0.5 );
    glEnd();
    
    glFlush();
    glutSwapBuffers();
}

void init(void)
{
    //select clearing (background) color
    glClearColor(0.0, 0.0, 0.0, 0.0);

    //initialize viewing values 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void keyboard(unsigned char key, int x, int y) {
    int mod = glutGetModifiers();
    std::cout << "NormKey: " << key << " Mod: " << mod;
    std::cout << " X/Y: " << x << " " << y << "\n";
    if (key == GLFW_KEY_D + GLFW_KEY_SPACE)  //  d - increase rotation by 5 degree
    rotate_y += 5;
    else if (key == GLFW_KEY_A + GLFW_KEY_SPACE) //  a - decrease rotation by 5 degree
    rotate_y -= 5;
    else if (key == GLFW_KEY_W + GLFW_KEY_SPACE) // w 
    rotate_x += 5;
    else if (key == GLFW_KEY_S + GLFW_KEY_SPACE) // s
    rotate_x -= 5;
  
//  Request display update
glutPostRedisplay();
}

void specialKeys(int key, int x, int y) {
    int mod = glutGetModifiers();
    std::cout << "SpecKey: " << key << " Mod: " << mod;
    std::cout << " X/Y: " << x << " " << y << "\n";

    if (key == GLUT_KEY_RIGHT)
    rotate_y += 5;
    else if (key == GLUT_KEY_LEFT)
    rotate_y -= 5;
    else if (key == GLUT_KEY_UP)
    rotate_x += 5;
    else if (key == GLUT_KEY_DOWN)
    rotate_x -= 5;
    glutPostRedisplay();

}

void mouse(int button, int state, int x, int y) {
    int mod = glutGetModifiers();
    std::cout << "Mouse-X/Y: " << x << " " << y << " ";
    std::cout << "Button: " << button << " ";
    std::cout << "Mod: " << mod << "" << "\n";
}

int main(int argc, char** argv) {

    int base_window_size = 120;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(-1, -1);
    
    glutInitWindowSize(16*base_window_size,9*base_window_size);    
    glutCreateWindow("Some Game"); //Create the window
    glEnable(GL_DEPTH_TEST); //  Enable Z-buffer depth test
    
    init(); //Call init (initialise GLUT
    
    //callbaks
    glutDisplayFunc(&display);
    glutMouseFunc(&mouse);
    glutKeyboardFunc(&keyboard);
    glutSpecialFunc(&specialKeys);
    //loop
    glutMainLoop();

    return 0;
}


