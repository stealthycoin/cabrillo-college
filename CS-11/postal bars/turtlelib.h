#ifndef TURTLE_H
#define TURTLE_H

//#define DEBUG
#include "ccc_win.h"

const double T_PI_180 = M_PI / 180;
const int T_FULL_CIRCLE = 360;
const int T_INIT_HEADING = 90;

class Turtle {
public:
    /**
        Constructs a Turtle object and intializes its heading to North
        (up) and position to (0, 0).
     */
    Turtle();

    /**
        Constructs a Turtle object and intializes its heading to North
        (up) and position to the x- and y-coordinates.
     */
    Turtle(double x, double y);

    /**
        Move this turtle forwards the given distance in the direction
        it is heading.
        @param distance The distance to move
     */
    void forward(double distance);

    /**
        Move this turtle backwards the given distance from the direction
        it is heading.
        @param distance The distance to move
     */
    void backward(double distance);

    /**
        Turn this turtle to the left (counter-clockwise) the given number
        of degrees from the current direction it is heading.
        @param degrees The number of degrees to turn.
     */
    void left(double degrees);

    /**
        Turn this turtle to the right (clockwise) the given number of degrees
        from the current direction it is heading.
        @param degrees The number of degrees to turn.
     */
    void right(double degrees);

    /**
        Returns the current heading (direction) in degrees for this turtle
        as the number of degrees clockwise from the North (up).
        @return The current heading in degrees between 0 and 360.
     */
    double getHeading() const { return heading + T_INIT_HEADING; }

    /**
        Turn this turtle to the given heading (direction).

        <p>Headings are based on the degrees of the compass with zero (0)
        degrees meaning to point straight up and turning clockwise through
        360 degrees.
        @param degrees The new heading for this Turtle.
     */
    void setHeading(double degrees);

    /**
     * Returns the current x-coordinate of this Turtle.
     *
     * @return The x-coordinate
     */
    double getX() const { return posX; }

    /**
     * Returns the current y-coordinate of this Turtle.
     *
     * @return The y-coordinate
     */
    double getY() const { return posY; }

    /**
        Move this turtle to the given x and y location without drawing.
        @param x The x-coordinate to which to move this Turtle.
        @param y The y-coordinate to which to move this Turtle.
     */
    void moveTo(double x, double y);

    /**
        Move this turtle to the position of the mouse when clicked.
        @param prompt The message to display while waiting for the
            mouse click.
     */
    void moveTo(string prompt);

    /**
        Checks whether the pen is down for this turtle.
        @return <code>true</code> if the pen is down else <code>false</code>
     */
    bool isPenDown() const { return penDown; }

    /**
        Enables or disables drawing when this turtle moves.
        @param down Set true to enable drawing and false to disable drawing.
     */
    void setPenDown(bool down) { penDown = down; }

    /**
        Prints a text message at the current Turtle position.
        @param message The string to display.
     */
    void print(string message);

    /**
        Prints a number at the current Turtle position.
        @param number The number to display.
     */
    void print(double number);

    /**
        Stops program execution for the specified delay time.
        @param millis The delay in milliseconds.
    */
    void sleep(int millis) { usleep(millis * 1000); }

    // Facade for cwin

    /**
        Clears the Turtle window.
    */
    void clear() { cwin.clear(); }

    /**
        Prompts the user for a string.
        @param prompt The message to display while waiting for user input.
        @return the string that the user entered.
    */
    string getString(string prompt) { return cwin.get_string(prompt); }

    /**
        Prompts the user for an integer.
        @param prompt The message to display while waiting for user input.
        @return the number that the user entered.
    */
    int getInt(const string& prompt) { return cwin.get_int(prompt); }

    /**
        Prompts the user for a floating-point value.
        @param prompt The message to display while waiting for user input.
        @return the number that the user entered.
    */
    double getDouble(const string& prompt) { return cwin.get_double(prompt); }

private:
    double heading;
    double posX, posY;
    bool penDown;
    double reduceAngle(double angle);
};

#endif
