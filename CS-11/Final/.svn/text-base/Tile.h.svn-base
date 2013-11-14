/*
 *  Tile.h
 *  
 *
 *  Created by John Carlyle on 3/28/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef TILE_H
#define TILE_H

#include "SDLGL.h"
#include "Entity.h"
#include "Texture.h"
#include "globals.h"

class Tile  {
private:
    int r, g, b;
    Entity* content;
    Texture* background;
public:
    Tile                ( );
    Tile                ( Entity* );
    ~Tile               ( ) { delete background; delete content; }
    void setColor       ( int, int, int );
    void setContent     ( Entity* );
    void setBackground  ( Texture* );
    void render         ( );
};

#endif