/*
 *  Resources.h
 *  
 *
 *  Created by John Carlyle on 4/9/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef RESOURCES_H
#define RESOURCES_H

#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string>
#include <vector>

#include "SDLGL.h"
#include "Texture.h"

class Texture;

class Resources {
private:
    static std::vector<Texture*> textures;
    static Resources* instance;
    
    Resources();
public:
    static Resources *getInstance       ( );
    static Texture *SDL_GL_LoadTexture  ( char*, char* );
    
    static void loadTextures    ( );
    static void crawlDirAndLoad ( char*, char* );
    static Texture* getTexture  ( char* );
    
    static void renderText      ( TTF_Font*, GLubyte, GLubyte, GLubyte, double, double, double, char* );
    static void renderTexture   ( char* name, float r, float g, float b );
    static int  texIndexForName ( char* );
};
#endif