#include<cmath>
#include<iostream>
using namespace std;

#include "turtlelib.h"

Turtle::Turtle() {
    heading = T_INIT_HEADING;
    posX = 0;
    posY = 0;
    penDown = true;
}

Turtle::Turtle(double x, double y) {
    heading = T_INIT_HEADING;
    posX = x;
    posY = y;
    penDown = true;
}

void Turtle::forward(double distance) {
    Point p1(posX, posY);
    posX += distance * cos(heading * T_PI_180);
    posY += distance * sin(heading * T_PI_180);
    if (penDown) {
        Point p2(posX, posY);
        Line trail(p1, p2);
        cwin << trail;
    }
    #ifdef DEBUG
    cout << "forward: " << distance << endl;
    #endif
}

void Turtle::backward(double distance) {
    forward(-distance);
    #ifdef DEBUG
    cout << "backward: " << distance << endl;
    #endif
}

void Turtle::left(double degrees) {
    heading = reduceAngle(heading + degrees);
    #ifdef DEBUG
    cout << "left: " << degrees << endl;
    #endif
}

void Turtle::right(double degrees) {
    left(-degrees);
    #ifdef DEBUG
    cout << "right: " << degrees << endl;
    #endif
}

void Turtle::setHeading(double angle) {
    heading = reduceAngle(T_FULL_CIRCLE - angle + T_INIT_HEADING);
    #ifdef DEBUG
    cout << "setHeading: " << angle << endl;
    #endif
}

void Turtle::moveTo(double x, double y) {
    posX = x;
    posY = y;
    #ifdef DEBUG
    cout << "moveTo: " << x << ", " << y << endl;
    #endif
}

void Turtle::moveTo(string prompt) {
    Point p = cwin.get_mouse(prompt);
    moveTo(p.get_x(), p.get_y());
}

void Turtle::print(string message) {
    Point p = Point(getX(), getY());
    Message msg = Message(p, message);
    cwin << msg;
}

void Turtle::print(double number) {
    Point p = Point(getX(), getY());
    Message msg = Message(p, number);
    cwin << msg;
}

double Turtle::reduceAngle(double angle) {
    int intAngle = static_cast<int>(angle);
    double fraction = angle - intAngle;
    return intAngle % T_FULL_CIRCLE + fraction;
}
