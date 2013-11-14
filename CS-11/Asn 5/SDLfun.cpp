#include <iostream>
#include <cmath>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

/**
    Macros for PI and degree-radian manipulation
*/
#define PI 3.1415926
#define DEGTORAD(Deg) ((Deg * PI) / 180.0)
#define RADTODEG(Rad) ((180.0 * Rad) / PI)

/**
    Dimensions of window.
    width height and bitdepth
*/
#define wWidth 800
#define wHeight 600
#define wDepth 32

SDL_Surface *screen;    //windows drawable area (setup in initGL function)

/**
    Vector2D class. Represents dx/dy.
 */
class Vector2D {
public:
    double x;
    double y;
    Vector2D();
    Vector2D(double, double);
    void normalize();
};

/**
    Defult constructor. Creates stationary vector.
 */
Vector2D::Vector2D() {
    Vector2D(0, 0);
}


/**
    Creates vector traveling initX/initY (dx/dy)
 
    @param initX - starting dx value
    @param initY - staring dy value
 */
Vector2D::Vector2D(double initX, double initY) {
    x = initX;
    y = initY;
}

/**
    Normalizes the vector for scaling.
 */
void Vector2D::normalize() {
    double mag = sqrt(x*x + y*y);
    x /= mag;
    y /= mag;
}

/**
    End Vector2D class;
 */


/**
    Used for easily understandable drawing
    without worrying about vertecies.
 */
class Pen {
public:
    double x;                   // position x
    double y;                   // position y
    Vector2D vector;            // dx/dy
    double heading;             // angle to travel in
    Pen();                      // default constructor
    void setHeading(double);    // sets heading directly
    void forward(int);          //draws a line
    void turn(double);          //changes heading
    void clear();               //clears screen
};


/**
    Default constructor.
    Makes a pen at (100, 100) traveling right.
 */
Pen::Pen()   {
    x = 100;
    y = 100;
    heading = 0.0;
}

/**
    Sets heading directly.
 
    @param newHeading - New direction to travel in.
 */
void Pen::setHeading(double newHeading) {
    heading = newHeading;
}


/**
    Moves pen forward, leaving a line behind it.
 
    @param amount - distance to move forward by.
 */
void Pen::forward(int amount)    {
     glColor3f(0.0f, 0.0f, 0.0f);                   //black color
    
    vector = Vector2D(cos(DEGTORAD(heading)),      
                      sin(DEGTORAD(heading)));      //split angle into dx/dy using sin/cos and changing degrees to radians
    vector.normalize();                             //prepare vector for scaling
    vector.x *= amount;                             //scale x scalar value of vector up by distance
    vector.y *= amount;                             //scale y scalar value of vector up by distance
    
    glBegin(GL_LINES);                              //start drawing lines with OpenGL
    glVertex2d(x, y);                               //first vertex at current location
    x += vector.x;                                  //move pen's x value based on the vector
    y += vector.y;                                  //move pen's y value based on the vector
    glVertex2d(x, y);                               //second vertex at new pen location
    glEnd();                                        //stop drawing lines
    
    SDL_GL_SwapBuffers();                           //swap buffers, update screen
}


/**
    Turns the pen left or right changing its heading.
 
    @param turnAngle - angle to turn at. Negative turns left. Positive turns right.
 */
void Pen::turn(double turnAngle)   {
    heading += turnAngle;
}

void Pen::clear() {
    glColor3f(1.0f, 1.0f, 1.0f);            //set color to white
    glBegin(GL_QUADS);                      //draw a quad the size of the window
    glVertex2i(0, 0);
    glVertex2i(wWidth, 0);
    glVertex2i(wWidth, wHeight);
    glVertex2i(0, wHeight);
    glEnd();
    
    SDL_GL_SwapBuffers();
}

/**
    Loads SDL and OpenGL to play nicely.
 
    @param width - width of window in pixels
    @param height - height of window in pixels
    @param depth - bitdepth of drawing in window
    @param fullscreen - determines if the window captures and fills the screen 
 */
int initGL(int width, int height, int depth, bool fullscreen) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {                                    //init sdl video functionality
        printf("Unable to initialize SDL: %s\n", SDL_GetError());
        return 1;
    }
    atexit(SDL_Quit);                                                       //dont litter, cleanup SDL when the program exits
    
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);                            //double buffer!
    
    int flags;
    if (fullscreen) flags = SDL_OPENGL | SDL_FULLSCREEN;
    else flags = SDL_OPENGL;                                                //prepare video mode flags
    
    screen = SDL_SetVideoMode(width, height, depth, flags);                 //create SDL representation of the screen
    
    glLineWidth(2);                                                         //thicker lines
    
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);                                 //anti alias the lines
    
    glEnable(GL_TEXTURE_2D);                                                //enable OpenGL textures
    
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);                                   //set background color to white
    
    glViewport(0, 0, width, height);                                        //create OpenGL viewport encapulating the window
    
    glClear(GL_COLOR_BUFFER_BIT);                                           //clear the buffer now that we have set background to white it clears to white
    
    glMatrixMode(GL_PROJECTION);                                            //use projection matrix 
    glLoadIdentity();                                                       //load identity matrix into projection matrix stack
    
    glOrtho(0.0f, (float)width, (float)height, 0.0f, -1.0f, 1.0f);          //scale window to base drawing on pixels
	
    glMatrixMode(GL_MODELVIEW);                                             //use modelview matrix
    glLoadIdentity();                                                       //load identity matrix into modelview matrix stack
    
    SDL_GL_SwapBuffers();                                                   //swap buffers, update screen
    
    return 0;
}

/**
    Draws a shape with variable size and sides.
 
    @param pen - pen to draw shape with
    @param sides - number of sides polygon has
    @param size - length of each polygon side
 */

void drawShape(Pen& pen, int sides, int size) {
    double angle = 360.0 / sides;           //find out angle to turn at
    pen.x = rand() % 300 + 100;             //randomize pen x location
    pen.y = rand() % 400 + 100;             //randomize pen y location
    pen.setHeading(rand() % 360);           //randomize pen heading
    
    for (int i = 0 ; i < sides ; i++) {     //move forward size and turn
        pen.forward(size);                  //at angle once for every side
        pen.turn(angle);                    //in polygon
    }
}

/**
    Drawing instructions originate here.
 
    @param pen - Pen to draw shapes with.
 */
void draw(Pen& pen) {
    for (int i = 0 ; i < 10 ; i++) {
        int sides = rand() % 8 + 3;         //3-10 sides 
        int size = rand() % 51 + 50;        //50-100 in size
        drawShape(pen, sides, size);        //draw the shape
    }
    
    printf("Press a key to redraw.\n");
}


/**
    Launching of program
 
    @param argc - coung of args
    @param args - array of arguments
    @return error codes.
 */
int main(int argc, char* args[]) {
    initGL(wWidth, wHeight, wDepth, false);     //setup SDL and OpenGL in a window wWidth x wHeight x wDepth that is not fullscreen
    SDL_WM_SetCaption("Shape Drawing", NULL);   //set window caption and no icon
    srand(time(0));                             //seed random
    
    SDL_Event event;                            //sdl event to drop events into
    
    Pen pen = Pen();                            //create a pen object for drawing
    
    draw(pen);                                  //start drawing routines
    
    bool running = true;                        //need a loop to keep the window open or SDL simply inits and then exits
    while (running) {
        
        SDL_PollEvent(&event);                  //poll for events and put it in event
        
        if (event.type == SDL_QUIT) 
            running = false;                    //if the window is closed kill program
        if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                running = false;                //if escape is pressed kill program
            }
            else    {
                pen.clear();
                draw(pen);
            }
        }
        
        SDL_Delay(50);                          //learn to share, dont hog CPU cycles
    }
    
    SDL_Quit();                                 //cleanup SDL and OpenGL
    return 0;                                   //YAY NO ERRORS!
}
