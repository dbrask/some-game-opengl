#include "../inc/Game.h"
#include "../inc/keys.h"
#include "../inc/Config.h"
#include <iostream>
#include <GL/glut.h>
#include <functional>


double rotate_y = 0; 
double rotate_x = 0;

Game::Game(Config config)
{
    int base_window_size = 120;
    //glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(-1, -1);

    int argc = 0;
    char** argv = 0;
    glutInit(&argc, argv);
    
    glutInitWindowSize(16*base_window_size,9*base_window_size);    
    glutCreateWindow("Some Game"); //Create the window
    glEnable(GL_DEPTH_TEST); //  Enable Z-buffer depth test
}

Game::~Game()
{
}

void Game::init(void)
{
    // using namespace std::placeholders; // for `_1`

    //select clearing (background) color
    glClearColor(0.0, 0.0, 0.0, 0.0);

    //initialize viewing values 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

    //callbaks
    glutDisplayFunc(&Game::display);
    //glutMouseFunc(&mouse);
    glutKeyboardFunc(&Game::keyboard);
    //glutSpecialFunc(&specialKeys);
    //loop
    glutMainLoop();
}


void Game::display(void)
{
    //Clear all pixels
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glLoadIdentity();

    // Rotate when user changes rotate_x and rotate_y
    glRotatef(rotate_x, 1.0, 0.0, 0.0 );
    glRotatef(rotate_y, 0.0, 1.0, 0.0 );

    //glTranslatef( 0.1, 0.0, 0.0 );      // Not included
    //glRotatef( 180, 0.0, 1.0, 0.0 );    // Not included
    //glScalef(0.5, 0.5, 0.5);

    //Multi-colored side - FRONT
    glBegin(GL_POLYGON);
    
    glColor3f( 1.0, 0.0, 0.0 );     glVertex3f(  0.5, -0.5, -0.5 );      // P1 is red
    glColor3f( 0.0, 1.0, 0.0 );     glVertex3f(  0.5,  0.5, -0.5 );      // P2 is green
    glColor3f( 0.0, 0.0, 1.0 );     glVertex3f( -0.5,  0.5, -0.5 );      // P3 is blue
    glColor3f( 1.0, 0.0, 1.0 );     glVertex3f( -0.5, -0.5, -0.5 );      // P4 is purple
    
    glEnd();

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

void Game::keyboard(unsigned char key, int x, int y) {
    int mod = glutGetModifiers();
    std::cout << "NormKey: " << key << " Mod: " << mod;
    std::cout << " X/Y: " << x << " " << y << "\n";

    int speed_mod = 2;
    if(mod == GLUT_ACTIVE_SHIFT) 
        speed_mod = 3;
    else if(mod == GLUT_ACTIVE_CTRL)
        speed_mod = 1;
    else if(mod == GLUT_ACTIVE_ALT)
        speed_mod = 4;
    
    if (key == GLFW_KEY_D + GLFW_KEY_SPACE || key == GLFW_KEY_D)  //  d - increase rotation by 5 degree
    rotate_y += 3 * speed_mod;
    else if (key == GLFW_KEY_A + GLFW_KEY_SPACE || key == GLFW_KEY_A) //  a - decrease rotation by 5 degree
    rotate_y -= 3 * speed_mod;
    else if (key == GLFW_KEY_W + GLFW_KEY_SPACE || key == GLFW_KEY_W) // w 
    rotate_x += 3 * speed_mod;
    else if (key == GLFW_KEY_S + GLFW_KEY_SPACE || key == GLFW_KEY_S) // s
    rotate_x -= 3 * speed_mod;
  
    glutPostRedisplay(); //  Request display update
}

// void Game::specialKeys(int key, int x, int y) {
//     int mod = glutGetModifiers();
//     std::cout << "SpecKey: " << key << " Mod: " << mod;
//     std::cout << " X/Y: " << x << " " << y << "\n";

//     if (key == GLUT_KEY_RIGHT)
//     rotate_y += 5;
//     else if (key == GLUT_KEY_LEFT)
//     rotate_y -= 5;
//     else if (key == GLUT_KEY_UP)
//     rotate_x += 5;
//     else if (key == GLUT_KEY_DOWN)
//     rotate_x -= 5;
//     glutPostRedisplay();

// }

// void Game::mouse(int button, int state, int x, int y) {
//     int mod = glutGetModifiers();
//     std::cout << "Mouse-X/Y: " << x << " " << y << " ";
//     std::cout << "Button: " << button << " ";
//     std::cout << "Mod: " << mod << "" << "\n";
// }
