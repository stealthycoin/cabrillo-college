/*
 *  turtlefun.cpp
 *  
 *
 *  Created by John Carlyle on 2/26/09.
 *
 */

#define DEG 360
#define PI 3.14159265
#define UP 0
#define LEFT 270
#define DOWN 180
#define RIGHT 90

#include <iostream>
#include <cmath>
#include <algorithm>
#include "turtlelib.cpp"

using namespace std;

void drawRandomShape(Turtle& turtle);
void drawInitials(Turtle& turtle);
void drawTriangle(Turtle& turtle, double size);
void drawSquare(Turtle& turtle, double size);
void drawHexagon(Turtle& turtle, double size);
void drawPentagon(Turtle& turtle, double size);
void drawShape(Turtle& turtle, double size, int sides);
void moveInbounds(Turtle& turtle, double r);


/**
    Entry point for x11 window based applications
 
 
 */
int ccc_win_main() {
    Turtle turtle;
    srand(time(0));
    bool running = true;
    
    while (running) {
        int i;
        for (i = 0 ; i < 10 ; i++) {
            drawRandomShape(turtle);
        }
        drawInitials(turtle);
        string input = turtle.getString("Do you want to run again (y/n)? ");
        if (input == "y") {
            turtle.clear();
        }
        else {
            running = false;
        }
    }
    
    exit(0);
    return 0;
}

/**
    Randomizes the drawing of a shape.
 
    @param turtle The turtle to draw with.
 */
void drawRandomShape(Turtle& turtle) {
    int size, sides;
    sides = rand() % 7 + 3;
    size = rand() % 3 + 1;
    
    switch (sides) {
        case 3:
            drawTriangle(turtle, size);
            break;
        case 4:
            drawSquare(turtle, size);
            break;
        case 5:
            drawPentagon(turtle, size);
            break;
        case 6:
            drawHexagon(turtle, size);
            break;
        case 7:
            drawShape(turtle, size, 7);
            break;
        case 8:
            drawShape(turtle, size, 8);
            break;
        case 9:
            drawShape(turtle, size, 9);
            break;
        case 10:
            drawShape(turtle, size, 10);
            break;
    }
}
/**
    Use the turtle to draw an equilateral triangle of
    the specified size.

    @param turtle The turtle to draw with.
    @param size The size of the sides of the triangle.
*/
void drawTriangle(Turtle& turtle, double size) {
    drawShape(turtle, size, 3);
}

/**
    Use the turtle to draw a square of the specified
    size.

    @param turtle The turtle to draw with.
    @param size The size of the sides of the square.
*/
void drawSquare(Turtle& turtle, double size) {
    drawShape(turtle, size, 4);
}

/**
    Use the turtle to draw a pentagon of the specified
    size.

    @param turtle The turtle to draw with.
    @param size The size of the sides of the pentagon.
*/
void drawPentagon(Turtle& turtle, double size) {
    drawShape(turtle, size, 5);
}

/**
    Use the turtle to draw a hexagon of the specified
    size.

    @param turtle The turtle to draw with.
    @param size The size of the sides of the hexagon.
*/
void drawHexagon(Turtle& turtle, double size) {
    drawShape(turtle, size, 6);
}

/**
     Use the turtle to draw a regular polygon of
     the specified size. Note: extra credit.
     
     @param turtle The turtle to draw with.
     @param size The size of the sides of the shape.
     @param sides The number of sides of the shape.
 */
void drawShape(Turtle& turtle, double size, int sides) {
    double angle = DEG / sides;
    
    double radius = size / (2 * sin(PI /sides));
    moveInbounds(turtle, radius);
    
    for (int i = 0 ; i < sides ; i++) {
        turtle.forward(size);
        turtle.right(angle);
    }
}


/**
    Uses the diameter of the shape to place the turtle in a position
    where it is not possible will not wander too far out of bounds.
 
    @param turtle: turtle to move to a safe place
    @param diameter: diameter of shape to keep in bounds
 
 */
void moveInbounds(Turtle& turtle, double r) {
    int radius = ceil(r);
    int x = rand() % 20;
    x -= 10;
    int y = rand() % 19;
    y -= 10;
    
    x = min(x, 10 - radius);
    x = max(x, -10 + radius);
    y = min(y, 10 - radius);
    y = max(y, -10 + radius);
    
    if (x > 0 && y > 0) {
        // quadrant I
        turtle.setHeading(DOWN);
    }
    else if (x < 0 && y > 0) {
        //quadrant II
        turtle.setHeading(RIGHT);
    }
    else if (x < 0 && y < 0) {
        //quadrant III
        turtle.setHeading(UP);
    }
    else if (x > 0 && y < 0)  {
        //quadrant IV
        turtle.setHeading(LEFT);
    }
    else {
        //centered
        turtle.setHeading(rand() % DEG);
    }
    
    turtle.moveTo(x, y);
}

/**
    Use the turtle to draw my initials.

    @param turtle The turtle to draw with.
*/
void drawInitials(Turtle& turtle) {
    turtle.setHeading(0);
    //J
    turtle.moveTo(-7, -7);
    turtle.right(90);
    turtle.forward(2);
    turtle.right(180);
    turtle.forward(1);
    turtle.left(90);
    turtle.forward(2);
    turtle.right(90);
    turtle.forward(1);
    
    //W
    turtle.moveTo(-4, -7);
    turtle.right(230);
    turtle.forward(2.4);
    turtle.left(90);
    turtle.forward(2);
    turtle.right(90);
    turtle.forward(2);
    turtle.left(90);
    turtle.forward(2.4);
    
    //C
    turtle.moveTo(4, -7);
    turtle.right(40);
    turtle.forward(2);
    turtle.right(180);
    turtle.forward(2);
    turtle.left(90);
    turtle.forward(2);
    turtle.left(90);
    turtle.forward(2);
}