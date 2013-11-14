/*
 *  triangle.cpp
 *  
 *
 *  Created by John Carlyle on 2/27/09.
 *
 */

#include "turtlelib.cpp"

void drawTriangle(Turtle& boggy, double size) {
    double angle = 120;

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