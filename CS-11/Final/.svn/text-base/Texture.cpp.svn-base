/*
 *  Texture.cpp
 *  
 *
 *  Created by John Carlyle on 4/2/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#include "Texture.h"

Texture::Texture()   {
    height  = 0;
    width   = 0;
    name    = "";
    texture = 0;
}

Texture::Texture(GLuint tex, std::string n, int w, int h)  {
    name    = n;
    width   = w;
    height  = h;
    texture = tex;
}

void Texture::render()   {
    if ( texture != 0 ) {
        glEnable    ( GL_TEXTURE_2D );
        glEnable    ( GL_BLEND );
        glBlendFunc ( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
        
        glBindTexture   ( GL_TEXTURE_2D, texture );
        glColor3f       ( 1.0f, 1.0f, 1.0f );
        
        glBegin( GL_QUADS );
        glTexCoord2f( 0, 0 ); glVertex2f( 0, 0 );
        glTexCoord2f( 1, 0 ); glVertex2f( width, 0 );
        glTexCoord2f( 1, 1 ); glVertex2f( width, height );
        glTexCoord2f( 0, 1 ); glVertex2f( 0, height );
        glEnd( );
        
        glDisable( GL_TEXTURE_2D) ;
        glDisable( GL_BLEND );
    }
}