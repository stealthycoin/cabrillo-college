/*
 *  Tile.cpp
 *  
 *
 *  Created by John Carlyle on 3/28/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#include <iostream>
#include "Tile.h"

Tile::Tile( Entity* e )    {
    Tile();
    content = e;
}

Tile::Tile()   {
    r = 1;
    g = 1;
    b = 1;
    background = NULL;
    content = NULL;
}

void Tile::setColor( int _r, int _g, int _b )   {
    r = _r;
    g = _g;
    b = _b;
}

void Tile::setContent( Entity* e ) {
    content = e;
}

void Tile::setBackground( Texture* t )    {
    background = t;
}

void Tile::render() {
    glColor3f( r, g, b );
    glBegin( GL_QUADS );
    glVertex2i( 0, 0 );
    glVertex2i( TILE_WIDTH, 0 );
    glVertex2i( TILE_WIDTH, TILE_HEIGHT );
    glVertex2i( 0, TILE_HEIGHT );
    glEnd();
    
    if ( background ) {
        background->render();
    }
    
    if ( content )    {
        content->render();
    }
    
    glColor3f( 0, 0, 0 );
    glBegin( GL_LINE_STRIP );
    glVertex2i( 0, 0 );
    glVertex2i( TILE_WIDTH, 0 );
    glVertex2i( TILE_WIDTH, TILE_HEIGHT );
    glVertex2i( 0, TILE_HEIGHT );
    glVertex2i( 0, 0 );
    glEnd();
}