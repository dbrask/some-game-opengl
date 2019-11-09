#include "Game.h"
#include "boost/lambda/lambda.hpp"
#include <iostream>
#include <iterator>
#include <algorithm>

#include <GL/glut.h>

void display(void)
{
    //Clear all pixels
    glClear(GL_COLOR_BUFFER_BIT);

    //draw white polygon (rectangle) with corners at
    // (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex3f(0.25, 0.25, 0.0);
        glVertex3f(0.75, 0.25, 0.0);
        glVertex3f(0.75, 0.75, 0.0);
        glVertex3f(0.25, 0.75, 0.0);
    glEnd();
    
    // Don't wait start processing buffered OpenGL routines
    glFlush();
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

void callback(unsigned char key, int x, int y) {

    int mod = glutGetModifiers();
    std::cout << "Key: " << key << " Mod: " << mod << "\n";
    
}

int main(int argc, char** argv) {
    //std::cout << "hej1 \n";
    //Game _game;
    //printf("hej2 \n");
    //printf("argc %s", &argc);
    //printf("argv %s \n", argv[1]);

    //using namespace boost::lambda;
    //typedef std::istream_iterator<int> in;
    //std::for_each(
    //    in(std::cin), in(), std::cout << (_1 * 3) << " " );

    //Initialise GLUT with command-line parameters. 
    glutInit(&argc, argv);
   
    //Set Display Mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    //Set the window position
    glutInitWindowPosition(GLUT_INIT_WINDOW_X, GLUT_INIT_WINDOW_Y);
    
    //Set the window size
    glutInitWindowSize(GLUT_INIT_WINDOW_X,GLUT_INIT_WINDOW_Y);
    
    
    
    //Create the window
    glutCreateWindow("Hello World");
    
    //Call init (initialise GLUT
    init();
    
    //Call "display" function
    glutDisplayFunc(display);

    glutKeyboardFunc(&callback);
    
    //Enter the GLUT event loop
    glutMainLoop();

    return 0;
}


