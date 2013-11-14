/*
 *  Grid.cpp
 *  
 *
 *  Created by John Carlyle on 3/28/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#include "Grid.h"

Grid::Grid( int x, int y, int _width, int _height ) {
    offsetX = x;
    offsetY = y;
    width   = _width;
    height  = _height;
    tiles   = new Matrix< Tile >( width, height );
    res     = Resources::getInstance();
}

void Grid::render() {
    glPushMatrix();
    glTranslatef(offsetX, offsetY, 0);
    for ( int x = 0 ; x < tiles->getWidth() ; x++ ) {
        for ( int y = 0 ; y < tiles->getHeight() ; y++ ) {
            glPushAttrib( GL_CURRENT_BIT );
            glPushMatrix();
            
            glTranslatef( x * TILE_WIDTH, y * TILE_HEIGHT, 0 );
            tiles->get( x, y )->render();
            
            glPopMatrix();
            glPopAttrib();
        }
    }
    glPopMatrix();
}

bool Grid::inBounds( int x, int y ) {
    if ( x <= offsetX + width * TILE_WIDTH && x >= offsetX ) {
        if ( y <= offsetY + height * TILE_HEIGHT && y >= offsetY )  {
            return true;
        }
    }
    
    return false;
}

void Grid::tileFor( int x, int y )  {
    if ( !inBounds( x, y ) ) return;
    x -= offsetX;
    y -= offsetY;
    x /= TILE_WIDTH;
    y /= TILE_HEIGHT;
    
    std::cout << x << " " << y << std::endl;
}