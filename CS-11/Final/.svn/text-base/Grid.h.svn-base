/*
 *  Grid.h
 *  
 *
 *  Created by John Carlyle on 3/28/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef GRID_H
#define GRID_H

#include <iostream>

#include "globals.h"
#include "Utilities.h"
#include "SDLGL.h"
#include "Tile.h"
#include "Resources.h"

class Tile;

class Grid {
private:
    int offsetX, offsetY;
    int width, height;
    Matrix< Tile >* tiles;
    Resources *res;
public:
    Grid        ( int, int, int, int );
    ~Grid       () { }
    void render  ();
    
    bool inBounds   ( int, int );
    void tileFor    ( int, int );
};

#endif