/*
 *  Animation.cpp
 *  
 *
 *  Created by John Carlyle on 4/17/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#include <iostream>
#include "Animation.h"

Animation::Animation( ) {
    currentFrame    = 0;
    dt              = 0;
    totalDuration   = 0;
    frames          = new std::vector< AnimFrame* >();
}

void Animation::update( int _dt )    {
    dt += _dt;
    while ( dt >= totalDuration )    {
        currentFrame++;
        dt %= totalDuration;
    }
    if ( currentFrame >= frames->size() )    {
        currentFrame = 0;
    }
}

void Animation::addFrame( Texture* tex, int duration )  {
    totalDuration += duration;
    
    frames->push_back( new AnimFrame( tex, totalDuration ) );
}

void Animation::render()    {
    frames->at( currentFrame )->render();
}

void Animation::reset() {
    currentFrame = 0;
    dt           = 0;
	frames->clear();
}