/*
 *  World.cpp
 *  
 *
 *  Created by John Carlyle on 3/28/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "World.h"

World::World()  {
    grid = new Grid( BOARD_OFFSET_X, BOARD_OFFSET_Y, BOARD_WIDTH, BOARD_HEIGHT );
}

void World::render() {
    grid->render();
}

