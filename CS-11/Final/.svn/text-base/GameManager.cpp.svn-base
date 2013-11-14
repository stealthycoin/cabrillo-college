/*
 *  GameManager.cpp
 *  
 *
 *  Created by John Carlyle on 3/27/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "GameManager.h"

GameManager::GameManager()  {
    init();
}

void GameManager::init()  {
    gameWorld   = new World();
    res         = Resources::getInstance();
    
    state.pushState( STATE_MAIN_MENU );
    state.pushState( STATE_PLAYING_GAME );
    
    a.addFrame( res->getTexture( "kupa-1.png" ), 12 );
    a.addFrame( res->getTexture( "kupa-2.png" ), 12 );
    a.addFrame( res->getTexture( "kupa-3.png" ), 12 );
    a.addFrame( res->getTexture( "kupa-4.png" ), 12 );
    a.addFrame( res->getTexture( "kupa-5.png" ), 12 );
    a.addFrame( res->getTexture( "kupa-6.png" ), 12 );
    a.addFrame( res->getTexture( "kupa-7.png" ), 12 );
    a.addFrame( res->getTexture( "kupa-8.png" ), 12 );
    a.addFrame( res->getTexture( "kupa-9.png" ), 12 );
}
    
void GameManager::update( int dtime )  {
    
    switch ( state.getState() ) {
        case STATE_MAIN_MENU:
            break;
        case STATE_PLAYING_GAME:
            a.update ( dtime );
            break;
        default:
            std::cout << "Error in update() state switch." << std::endl;
            break;
    }
}

void GameManager::render()   {
    glClear( GL_COLOR_BUFFER_BIT );
    
    switch ( state.getState() ) {
        case STATE_PLAYING_GAME:
            gameWorld->render();
            a.render();
            break;
        default:
            std::cout << "Error in render() state switch." << std::endl;
            break;
    }
    
    SDL_GL_SwapBuffers();
}

void GameManager::mouseMoved( int x , int y ) {
    
}

void GameManager::mouseDown( int button, int x, int y )    {
    
}

void GameManager::mouseUp( int button, int x, int y )    {
    
}

