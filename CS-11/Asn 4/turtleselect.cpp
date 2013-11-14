/*  CS-11 Asn 4
 *  turtleselect.cpp
 *  Purpose: Drawing "Doodads"
 *
 *  Created by John Carlyle & Michelle Giovnnari on 3/5/09.
 *  Version 1.0
 *
 */
#include <iostream>
#include <cmath>
#include "turtlelib.cpp"

using namespace std;


const int DEGREES_IN_CIRCLE = 360;
const int NTHREE = -3;
const int STRAIGHT = 180;
const int RIGHT_TURN = 90;
const int G_TURN = 30;
const int G_TURN2 = 160;
const int C_TURN = 40;
const int SMALL_TURN = 45;
const int FORWARD_INC = 8;
const int TEN = 10;
const int NNINE = -9;
const double SEVEN_POINT_FIVE = 7.5;
const double W_INC = 2.4;
const double N_ONE_POINT_FIVE = -1.5;
const int FIVE = 5;
const int FOUR = 4;
const int TWO_THIRTY = 230;
const int NSEVEN = -7;
const int ONE_THIRTY = 130;
const int LEFT = 270;
const double PI = 3.14159265;

int ccc_win_main() {
    Turtle t;
    bool running = true;
    while (running == true) {
        double sides = -1;
        while (sides < 1)   {
            sides = t.getInt("Enter number of sides:");
        }
        double length = t.getDouble("Enter length of sides:");

        if (sides > 1) {
            int degrees = DEGREES_IN_CIRCLE / sides;
            t.setHeading(LEFT);
            
            /* 
            Apothem is the distance of the normal of any side of the polygon
            to the centerpoint of the polygon. The following code will
            center the shape in the window.
            */
            double apothem = length / (2 * tan(PI / sides)); 
            t.moveTo(length / 2, -apothem);
            
            int i = 0;
            while (i < sides) {
                t.forward(length);
                t.right(degrees);
                i++;
            }
        }
        if (sides == 1) {
            t.setHeading(0);
            // Creates the upper case letter M.
            t.moveTo(NTHREE,NNINE);
            t.right(TEN);
            t.forward(FORWARD_INC);
            t.right(G_TURN2);
            t.forward(FORWARD_INC);
            t.left(G_TURN2);
            t.forward(FORWARD_INC);
            t.right(G_TURN2);
            t.forward(FORWARD_INC);   

            // Creates the upper case letter G.
            t.moveTo(SEVEN_POINT_FIVE, N_ONE_POINT_FIVE);
            t.left(G_TURN);
            t.forward(2);
            t.backward(2);
            t.right(ONE_THIRTY);
            t.forward(2);
            t.left(G_TURN);
            t.forward(2);
            t.left(G_TURN);
            t.forward(2);
            t.left(G_TURN);
            t.forward(2);
            t.left(G_TURN);
            t.forward(2);
            t.left(G_TURN);
            t.forward(2);
            t.left(G_TURN);
            t.forward(2);
            t.left(SMALL_TURN);
            t.forward(1);
            t.left(SMALL_TURN);
            t.forward(1);
            t.left(SMALL_TURN);
            t.forward(1);
            t.left(SMALL_TURN);
            t.forward(1);
            t.backward(2);

            // Creates the upper case letter J.
            t.setHeading(RIGHT_TURN);
            t.moveTo(NSEVEN, FIVE);
            t.forward(2);
            t.right(STRAIGHT);
            t.forward(1);
            t.left(RIGHT_TURN);
            t.forward(2);
            t.right(RIGHT_TURN);
            t.forward(1);

            // Creates the upper case letter W.
            t.moveTo(-FOUR, FIVE);
            t.right(TWO_THIRTY);
            t.forward(W_INC);
            t.left(RIGHT_TURN);
            t.forward(2);
            t.right(RIGHT_TURN);
            t.forward(2);
            t.left(RIGHT_TURN);
            t.forward(W_INC);

            // Creates the upper case letter C.
            t.moveTo(FOUR, FIVE);
            t.right(C_TURN);
            t.forward(2);
            t.right(STRAIGHT);
            t.forward(2);
            t.left(RIGHT_TURN);
            t.forward(2);
            t.left(RIGHT_TURN);
            t.forward(2);
        }

        string repeat = t.getString("Do you wish to continue (y/n)? ");
        if (repeat != "y") running = false;
        else t.clear();
    }

    cout << "Exiting Program.\n";

    exit(0);
    return 0;

}
