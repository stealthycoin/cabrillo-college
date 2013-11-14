/*
 *  triangle2.cpp
 *  
 *
 *  Created by John Carlyle on 2/28/09.
 *
 */


#include "turtlelib.cpp"

double calcAngle(int sides);
void drawTriangle(Turtle& boggy, double size);

const double DEGREES_IN_CIRCLE = 360;

/**
    Calculates the angle size in a polygon with X sides.

    @param sides The number of sides to the polygon
*/
double calcAngle(int sides) {
    double angle = DEGREES_IN_CIRCLE / sides;
    return angle;
}

/**
    Draws a triangle with sides of length size using the
    Turtle.

    @param turtle The turtle to use for drawing
    @param size The length of each side
*/
void drawTriangle(Turtle& boggy, double size) {
    double angle = calcAngle(3);

    boggy.forward(size);
    boggy.left(angle);
    boggy.forward(size);
    boggy.left(angle);
    boggy.forward(size);
    boggy.left(angle);
}

int ccc_win_main() {
    Turtle boggy;
    boggy.right(90);
    drawTriangle(boggy, 5);
    boggy.moveTo(-4, 0);
    drawTriangle(boggy, 3);

    return 0;
}