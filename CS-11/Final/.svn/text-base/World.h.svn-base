/*
 *  World.h
 *  
 *
 *  Created by John Carlyle on 3/28/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef WORLD_H
#define WORLD_H

#include "Grid.h"
#include "Part.h"
#include "globals.h"

class World {
private:
    Grid* grid;
public:
    World();
    ~World() { delete grid; }
    void render();
    
    Grid* getGrid() { return grid; }
};

#endif