/*
 *  Texture.h
 *  
 *
 *  Created by John Carlyle on 4/2/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include "SDLGL.h"

class Texture {
private:
    GLuint texture;
    int width, height;
    std::string name;
public:
    Texture                 ( );
    Texture                 ( GLuint, std::string, int, int );
    int getWidth            ( ) { return width; }
    int getHeight           ( ) { return height; }
    std::string getName     ( ) { return name; }
    void render             ( );
};

#endif TEXTURE_H