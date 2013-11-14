/*
 *  InputManager.h
 *  
 *
 *  Created by John Carlyle on 4/27/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INPUTMANGER_H
#define INPUTMANGER_H

class InputManager {
private:
    int mouseX;
    int mouseY;
    bool mouseButtonOne;
    bool mouseButtonTwo;
    
public:
    void setMouseLoc( int x, int y )    { mouseX = x; mouseY = y; }
    void setMouseButtonOne( bool down ) { mouseButtonOne = down; }
    void setMouseButtonTwo( bool down ) { mouseButtonTwo = down; }
    
    int  getMouseX()    { return mouseX; }
    int  getMouseY()    { return mouseY; }
    bool getButtonOne() { return mouseButtonOne; }
    bool getButtonTwo() { return mouseButtonTwo; }
    
    bool getButtonOneAndLift();
};

#endif