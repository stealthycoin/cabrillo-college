/*
 *  Entity.cpp
 *  
 *
 *  Created by John Carlyle on 3/28/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "Entity.h"

Entity::Entity()    {
    texture = NULL;
}

Entity::Entity( Texture* _tex ) {
    Entity();
    texture = _tex;
}

void Entity::render() {
    if ( texture != NULL)  {
        texture->render();
    }
}