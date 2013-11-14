/*
 *  Part.h
 *  
 *
 *  Created by John Carlyle on 3/28/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef PART_H
#define PART_H

#include "Entity.h"
class Entity;

class Part : public Entity {
private:
    int blast[3][3];
    bool rotatable;
    int direction;
public:
    void explode();
    int getCost();
    void rotate(int);
};

#endif