// Fun things to do with turtles
#include<iostream>
using namespace std;

#include "turtlelib.cpp"

void drawPolygon(Turtle& turtle, double size, int sides) {
    double angle = 360.0 / sides;
    for (int count = 0; count < sides; count++) {
        turtle.forward(size);
        turtle.left(angle);
    }
}

void drawStar(Turtle& turtle, double size, int sides) {
    for (int i = 0; i < sides; i++) {
        turtle.forward(size);
        turtle.right(360.0 / sides);
        turtle.forward(size);
        turtle.left(2 * 360.0 / sides);
    }
}

void drawRosette(Turtle& turtle, double size, int squares) {
    double angle = 360.0 / squares;
    for (int i = 0; i < squares; i++) {
        for (int j = 0; j < 4; j++) {
            turtle.forward(size);
            turtle.right(90);
        }
        turtle.right(angle);
    }
}

void drawSpiral(Turtle& turtle, double size) {
    while (size < 1.25) {
        turtle.forward(size);
        turtle.right(15);
        size = size * 1.02;
    }
}

// Recursive fractal "tree" structure
void tree(Turtle& turtle, int level, double size, double angle,
        double scale) {
    if (level == 0) {
        turtle.forward(size);
        turtle.backward(size);
    } else {
        turtle.forward(size);
        turtle.left(angle);
        tree(turtle, level - 1, size * scale, angle, scale);
        turtle.right(angle);
        turtle.right(angle);
        tree(turtle, level - 1, size * scale, angle, scale);
        turtle.left(angle);
        turtle.backward(size);
    }
}

// Recursive Koch fractal
void koch(Turtle& turtle, int level, double size, double angle) {
    if (level == 0) {
        turtle.forward(size);
    } else {
        koch(turtle, level - 1, size, angle);
        turtle.left(angle);
        koch(turtle, level - 1, size, angle);
        turtle.right(angle);
        turtle.right(angle);
        koch(turtle, level - 1, size, angle);
        turtle.left(angle);
        koch(turtle, level - 1, size, angle);
    }
}

// Use Koch fractal to draw a "snowflake"
void kochSnowflake(Turtle& turtle, int level, double size) {
    double angle = 60;
    turtle.left(angle);
    koch(turtle, level, size, angle);
    turtle.right(angle);
    turtle.right(angle);
    koch(turtle, level, size, angle);
    turtle.right(angle);
    turtle.right(angle);
    koch(turtle, level, size, angle);
}


/**
    The main function begins execution of the program.
*/
int ccc_win_main() {
    Turtle myrtle;
    double size = 3;
    const int DELAY = 2500000;

    myrtle.moveTo(-1, 0);
    myrtle.print("Drawing shapes");
    usleep(DELAY);
    myrtle.clear();

    myrtle.moveTo(5 - size / 2, -9); // bottom of drawing area
    myrtle.setHeading(90);
    for (int i = 3; i < 10; i++) {
        drawPolygon(myrtle, size, i);
    }

    myrtle.moveTo(-4 + size / 2, 1);
    myrtle.setHeading(-18);
    drawStar(myrtle, size, 5);

    myrtle.moveTo(-5, -5); // center of drawing area
    myrtle.setHeading(0);
    drawRosette(myrtle, size, 40);

    myrtle.moveTo(5, 5); // center of drawing area
    myrtle.setHeading(90);
    drawSpiral(myrtle, .01);
    usleep(DELAY);

    myrtle.clear();
    myrtle.moveTo(-1, 0);
    myrtle.print("Drawing fractals");
    usleep(DELAY);
    myrtle.clear();

    myrtle.clear();
    myrtle.moveTo(-1, 9);
    myrtle.print("Recursive tree");
    myrtle.moveTo(0, -9); // start of drawing area
    myrtle.setHeading(0);
    tree(myrtle, 10, 7, 60, .6);

    usleep(DELAY);
    myrtle.clear();
    myrtle.moveTo(-1, 9);
    myrtle.print("Koch side");
    myrtle.moveTo(-9, -9); // start of drawing area
    myrtle.setHeading(90);
    koch(myrtle, 5, .25, 80);

    for (int i = 0; i < 6; i++) {
        usleep(DELAY);
        myrtle.clear();
        myrtle.moveTo(-1, 9);
        myrtle.print("Koch snowflake");
        myrtle.moveTo(-7.5, -5); // start of drawing area
        myrtle.setHeading(90);
        size = 15.0 / pow(3.0, i);
        kochSnowflake(myrtle, i, size);
    }
}
