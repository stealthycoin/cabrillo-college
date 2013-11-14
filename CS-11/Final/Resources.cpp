/*
 *  Resources.cpp
 *  
 *
 *  Created by John Carlyle on 4/9/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "Resources.h"

Resources* Resources::instance = 0;
std::vector<Texture*> Resources::textures; 

Resources* Resources::getInstance()    {
    if (Resources::instance == NULL) Resources::instance = new Resources;
    
    return Resources::instance;
}

Resources::Resources()  {
    loadTextures();
}

Texture* Resources::SDL_GL_LoadTexture( char* file, char* name )   {
    SDL_Surface* surf = IMG_Load( file );
    
    if ( surf != NULL )   {
        int w = surf->w;
        int h = surf->h;
        
        GLuint texture = 0;
        
        GLenum format = GL_BGRA;
        if ( surf->format->Rmask == 0x000000ff )  format = GL_RGBA;
        
        glGenTextures   ( 1, &texture );
        glBindTexture   ( GL_TEXTURE_2D, texture );
        glTexImage2D    ( GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, format, GL_UNSIGNED_BYTE, surf->pixels );
        glTexParameterf ( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameterf ( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        
        SDL_FreeSurface ( surf );
        
        return new Texture( texture, name, w, h );
    }
    
    return NULL;
    
}

void Resources::loadTextures()  {
    std::cout << std::endl << "Begining resource crawler" << std::endl;
    crawlDirAndLoad( "./", ".png" );
    std::cout << "Loaded " << textures.size() << " pngs" << std::endl;
}

void Resources::crawlDirAndLoad( char* path, char* ext )   {
    DIR* dir = opendir ( path );
    struct dirent* ep;
    
    if ( dir )  {
        while ( ep = readdir( dir ) ) {
            std::string name    = std::string( ep->d_name );
            unsigned int i      = name.find_last_of( "." );
            
            std::string strPath = std::string( path );
            strPath += name;
            
            if ( i < NAME_MAX ) {
                if ( name.substr( i ) == ext )  {
                    textures.push_back( SDL_GL_LoadTexture( ( char* )strPath.c_str(), ( char* )name.c_str() ) );
                }
            }
            else    {
                strPath += "/";
                crawlDirAndLoad( ( char* )strPath.c_str(), ext );
            }
        }
    }
    
}

Texture* Resources::getTexture( char* name )   {
    int index = texIndexForName( name );
    if ( index >= 0 && index < textures.size() )    {
        return textures[index];
    }
    return NULL;
}

void Resources::renderText(TTF_Font* font, GLubyte R, GLubyte G, GLubyte B, double X, double Y, double Z, char* text) {
    SDL_Color color         =  { R, G, B };
	SDL_Surface *message    =  TTF_RenderText_Blended( font, text, color );
	unsigned Texture        =  0;
    
	glGenTextures   ( 1, &Texture );
	glBindTexture   ( GL_TEXTURE_2D, Texture );
    
	glTexParameterf ( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	glTexParameterf ( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    
	glTexImage2D    ( GL_TEXTURE_2D, 0, GL_RGBA, message->w, message->h, 0, GL_BGRA, GL_UNSIGNED_BYTE, message->pixels );
    
    glEnable        ( GL_TEXTURE_2D );
    glEnable        ( GL_BLEND );
    glBlendFunc     ( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    
    
	glBegin( GL_QUADS );
    glTexCoord2d( 0, 0 ); glVertex3d( X, Y, Z );
    glTexCoord2d( 1, 0 ); glVertex3d( X + message->w, Y, Z );
    glTexCoord2d( 1, 1 ); glVertex3d( X + message->w, Y + message->h, Z );
    glTexCoord2d( 0, 1 ); glVertex3d( X, Y + message->h, Z );
	glEnd( );
    
    glDisable   ( GL_TEXTURE_2D );
    glDisable   ( GL_BLEND );
    
	glDeleteTextures( 1, &Texture );
	SDL_FreeSurface ( message );
}


void Resources::renderTexture( char* name, float r, float g, float b )    {
    int index = texIndexForName( name );
    
    if ( index >= 0 && index < textures.size() ) {
        glColor3f( r, g, b );
        textures[index]->render();
    }
}


int Resources::texIndexForName( char* name )   {
    for ( int i = 0 ; i < textures.size() ; i++ )    {
        if ( textures[i]->getName() == name ) {
            return i;
        }
    }
    
    return -1;
}