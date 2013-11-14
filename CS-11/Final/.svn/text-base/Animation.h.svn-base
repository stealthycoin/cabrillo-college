/*
 *  Animation.h
 *  
 *
 *  Created by John Carlyle on 4/17/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>
#include "Texture.h";

class AnimFrame {
private:
    int duration;
    Texture* tex;
public:
    AnimFrame           ( Texture* t, int d )   { tex = t; duration = d; };
    int getDuration     () { return duration; }
    void render         () { if ( tex ) tex->render(); }
};



class Animation {
private:
    std::vector< AnimFrame* >* frames;
    int dt;
    int totalDuration;
    int currentFrame;
public:
    Animation        ();
    void update      ( int );
    void addFrame    ( Texture*, int );
    void render      ();
    void reset       ();
};

#endif
