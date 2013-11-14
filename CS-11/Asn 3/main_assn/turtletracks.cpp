/**
    CS-11 Asn 3
    turtletracks.cpp
    

    @author John Carlyle
    @version 1.0 9/23/09
*/

#define SIZE 2
#define DEG 360.0

#include <iostream>
using namespace std;

#include "turtlelib.cpp"

void drawShapes(Turtle myrtle, int start, int finish);
void drawShape(Turtle myrtle, int sides);

void drawShapes(Turtle myrtle, int start, int finish)   {
    int i;
    for (i = start ; i <= finish ; i++) {
        drawShape(myrtle, i);
    }
}

void drawShape(Turtle myrtle, int sides) {
    float turnAngle = DEG / sides;
    
    int i;
    for (i = 0 ; i < sides ; i++) {
        myrtle.forward(SIZE);
        myrtle.left(turnAngle);
    }
    myrtle.right(90);
}

int ccc_win_main() {
    Turtle myrtle;
    myrtle.moveTo(-1, -5);
    myrtle.right(90);
    drawShapes(myrtle, 3, 23);
    
    //J
    myrtle.moveTo(-7, -7);
    myrtle.forward(2);
    myrtle.right(180);
    myrtle.forward(1);
    myrtle.left(90);
    myrtle.forward(2);
    myrtle.right(90);
    myrtle.forward(1);
    
    //W
    myrtle.moveTo(-4, -7);
    myrtle.right(230);
    myrtle.forward(2.4);
    myrtle.left(90);
    myrtle.forward(2);
    myrtle.right(90);
    myrtle.forward(2);
    myrtle.left(90);
    myrtle.forward(2.4);
    
    //C
    myrtle.moveTo(4, -7);
    myrtle.right(40);
    myrtle.forward(2);
    myrtle.right(180);
    myrtle.forward(2);
    myrtle.left(90);
    myrtle.forward(2);
    myrtle.left(90);
    myrtle.forward(2);
    
    return 0;
}
