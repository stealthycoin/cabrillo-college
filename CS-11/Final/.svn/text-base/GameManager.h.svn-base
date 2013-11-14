#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "globals.h"
#include "SDLGL.h"
#include "World.h"
#include "Resources.h"
#include "Animation.h"
#include "InputManager.h"
#include "Utilities.h"

class GameManager {
private:
    StateStack state;
    Resources* res;
    World*  gameWorld;
    InputManager* im;
    
    
    Animation a;
public:
    GameManager();
    ~GameManager() { delete im; delete gameWorld; delete res; }
    void init();
    void update(int);
    void render();
    
    void mouseMoved( int, int );
    void mouseDown ( int, int, int );
    void mouseUp   ( int, int, int );
};
    
#endif