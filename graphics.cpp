// Jacob Schneck
// CS 120
// Final Project

#include "graphics.h"
#include "shapes/circle.h"
#include "shapes/rect.h"
#include "shapes/shape.h"
#include "flower.h"
#include "BasicFlower.h"
#include "ElongatedFlower.h"
#include "SunFlower.h"

#include <iostream>
#include <math.h>  // cos, sin and pi
#include <memory>
#include <stdlib.h> // rand
#include <vector>

using namespace std;

//================= Global Variables ==================
GLdouble width, height;
int wd;
const color skyBlue(77/255.0, 213/255.0, 240/255.0);
const color blue(0, 0 , 1);
const color grassGreen(26/255.0, 176/255.0, 56/255.0);
const color white(1, 1, 1);
const color brickRed(201/255.0, 20/255.0, 20/255.0);
const color darkBlue(1/255.0, 110/255.0, 214/255.0);
const color purple(119/255.0, 11/255.0, 224/255.0);
const color black(0, 0, 0);
const color magenta(1, 0, 1);
const color orange(1, 163/255.0, 22/255.0);
const color cyan (0, 1, 1);
const color yellow(1, 1, 0);
const color green(0, .5, 0);


vector<unique_ptr<Flower>> flowers;
bool rotation_flag = false; // default spin off
bool rand_colors_flag = false; // default rand colors off

//=================== Functions =====================

void init() {
    width = 500;
    height = 500;
}


/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    // glClearColor(grassGreen.red, grassGreen.green, grassGreen.blue, 1.0f);
    // glClearColor(black.red, black.green, black.blue, 1.0f);
    glClearColor(green.red, green.green, green.blue, 1.0f);

}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // Tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height); // DO NOT CHANGE THIS LINE
    
    // Do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
    glLoadIdentity(); // DO NOT CHANGE THIS LINE
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f); // DO NOT CHANGE THIS LINE

    // Clear the color buffer with current clearing color
    glClear(GL_COLOR_BUFFER_BIT); // DO NOT CHANGE THIS LINE
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // DO NOT CHANGE THIS LINE
    
    /*
     * Draw here
     */
    for (auto &f : flowers) {
        f->draw();
    }
    
    glFlush();  // Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html

void kbd(unsigned char key, int x, int y) {
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    } else if (key == 's') {  // toggles flower spinnig
        rotation_flag = !rotation_flag;
    } else if (key == 'r')  { // toggles between standard color scheme and random color scheme
        rand_colors_flag = !rand_colors_flag;
    }
    
    glutPostRedisplay();
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:
            
            break;
        case GLUT_KEY_LEFT:
            
            break;
        case GLUT_KEY_RIGHT:
            
            break;
        case GLUT_KEY_UP:
            
            break;
    }
    
    glutPostRedisplay();
}

void cursor(int x, int y) {

    glutPostRedisplay();
}

/*  
    mouse is responsible for planting and removing flowers from display window
*/
void mouse(int button, int state, int x, int y) {
    point2D center = {(double) x, (double) y}; // center of flower
    int flower_type = rand() % 3; // picks the type of flower
    int RADIUS = 10; // default radius

    // If left mouse click add flower
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (rand_colors_flag) { // random flower
            if (flower_type == 0) { // BasicFlower
                flowers.push_back(make_unique<BasicFlower>(BasicFlower(
                    {rand() % 10 / 10.0*(rand() % 2 + 1), rand() % 10 / 10.0*(rand() % 2 + 1), rand() % 10 / 10.0*(rand() % 2 + 1)}, 
                    {rand() % 10 / 10.0*(rand() % 2 + 1), rand() % 10 / 10.0*(rand() % 2 + 1), rand() % 10 / 10.0*(rand() % 2 + 1)}, 
                    center, 
                    rand() % 10 + 5)));
            } else if (flower_type == 1) { // ElongatedFlower
                flowers.push_back(make_unique<ElongatedFlower>(ElongatedFlower(
                    {rand() % 10 / 10.0*(rand() % 2 + 1), rand() % 10 / 10.0*(rand() % 2 + 1), rand() % 10 / 10.0*(rand() % 2 + 1)}, 
                    {rand() % 10 / 10.0*(rand() % 2 + 1), rand() % 10 / 10.0*(rand() % 2 + 1), rand() % 10 / 10.0*(rand() % 2 + 1)}, 
                    {rand() % 10 / 10.0*(rand() % 2 + 1), rand() % 10 / 10.0*(rand() % 2 + 1), rand() % 10 / 10.0*(rand() % 2 + 1)}, 
                    center, 
                    rand() % 10 + 5)));
            } else if (flower_type == 2) { // SunFlower
                flowers.push_back(make_unique<SunFlower>(SunFlower(
                    {rand() % 10 / 10.0*(rand() % 2 + 1), rand() % 10 / 10.0*(rand() % 2 + 1), rand() % 10 / 10.0*(rand() % 2 + 1)}, 
                    {rand() % 10 / 10.0*(rand() % 2 + 1), rand() % 10 / 10.0*(rand() % 2 + 1), rand() % 10 / 10.0*(rand() % 2 + 1)}, 
                    {rand() % 10 / 10.0*(rand() % 2 + 1), rand() % 10 / 10.0*(rand() % 2 + 1), rand() % 10 / 10.0*(rand() % 2 + 1)}, 
                    center,
                    rand() % 10 + 5)));
            }
        } else { // standard flower
            if (flower_type == 0) {
                flowers.push_back(make_unique<BasicFlower>(BasicFlower(orange, white, center, RADIUS)));
            } else if (flower_type == 1) {
                flowers.push_back(make_unique<ElongatedFlower>(ElongatedFlower(orange, darkBlue, magenta, center, RADIUS)));
            } else if (flower_type == 2) {
                flowers.push_back(make_unique<SunFlower>(SunFlower(black, yellow, orange, center, RADIUS)));
            }
        }
    
    // Remove flower with right click
    } else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        if (flowers.size() < 1) {
            flowers.clear();

        } else {
            flowers.erase(flowers.end() - 1);
        }
    }

    glutPostRedisplay();
}

// Use rotation Timer to spin the flower 
void rotationTimer(int dummy) {
    if (rotation_flag) {
        for (auto &f : flowers) {
            f->rotate(50);
        }
    } 
    glutPostRedisplay();
    glutTimerFunc(30, rotationTimer, dummy);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {

    // Set the color scheme (user input validation)
    string userInput;
    cout << "Random colors or standard colors? Press r for random or s for standard: ";
    getline(cin, userInput);
    while (userInput != "r" && userInput != "s") {
        cout << "Press r for random or s for standard: ";
        getline(cin, userInput);
    }
    if (userInput == "r") {
        rand_colors_flag = true;
    } else if (userInput == "s") {
        rand_colors_flag = false;
    }
    
    init();
    
    glutInit(&argc, argv);          // Initialize GLUT
    
    glutInitDisplayMode(GLUT_RGBA);
    
    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(100, 200); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Flowers!" /* title */ );
    
    // Register callback handler for window re-paint event
    glutDisplayFunc(display);
    
    // Our own OpenGL initialization
    initGL();
    
    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);
    
    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);
    
    // handles mouse movement
    glutPassiveMotionFunc(cursor);
    
    // handles mouse click
    glutMouseFunc(mouse);
    
    // handles timer
    glutTimerFunc(0, rotationTimer, 0);
    
    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}
