/*
 *  Entity.h
 *  
 *
 *  Created by John Carlyle on 3/28/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef ENTITY_H
#define ENTITY_H

#include "SDLGL.h"
#include "Texture.h"

class Entity    {
private:
    Texture* texture;
public:
    Entity();
    Entity( Texture* );
    ~Entity() { }
    void render();
};


#endif