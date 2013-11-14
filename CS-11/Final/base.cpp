/**
    Base SDL/OpenGL/C++ code
 */

#include <iostream>

#include "SDLGL.h"
#include "GameManager.h"
#include "globals.h"
#include "InputManager.h"
using namespace std;

void shouldExit( SDL_Event event );
int initGL( int width, int height, int depth, bool fullscreen );

Uint32 sendEvent(Uint32 interval, void* code )   {
    SDL_Event *event = new SDL_Event;
    
	event->type = SDL_USEREVENT;
	event->user.code  = 1;
	event->user.data1 = 0;
	event->user.data2 = 0;
    
    SDL_PushEvent( event );
    
    return interval;
}

int main(int argc, char* args[] ) {
    initGL( RES_WIDTH, RES_HEIGHT, RES_DEPTH, false );
    
    GameManager manager = GameManager();
    
    bool running = true;
    SDL_Event event;
    int oldTime = SDL_GetTicks();
    
    SDL_TimerID tid = SDL_AddTimer(5, sendEvent, NULL);
    
    while ( running && SDL_WaitEvent( &event ) ) {
        
        int newTime = SDL_GetTicks();
        int dtime   = newTime - oldTime;
        oldTime     = newTime;
        
        shouldExit( event );
        switch ( event.type ) {
            case SDL_KEYDOWN:
                cout << "key down" << endl;
                break;
            case SDL_KEYUP:
                cout << "key up" << endl;                
                break;
            case SDL_MOUSEBUTTONDOWN:
                manager.mouseDown( event.button.button, event.motion.x, event.motion.y );
                break;
            case SDL_MOUSEBUTTONUP:
                manager.mouseUp( event.button.button, event.motion.x, event.motion.y );
                break;
            case SDL_MOUSEMOTION:
                manager.mouseMoved( event.motion.x, event.motion.y );
                break;
            case SDL_USEREVENT:
                manager.update( dtime );
                manager.render();
                break;
        }
    }
    
    return 0;
}

void kill() {
    exit(0);
}

void shouldExit( SDL_Event event ) {
    if ( event.type == SDL_QUIT ) {
        kill();
    }
    else if ( event.type == SDL_KEYDOWN ) {
        if ( event.key.keysym.sym == SDLK_ESCAPE ) {
            kill();
        }
    }
}

int initGL( int width, int height, int depth, bool fullscreen ) {
    if ( SDL_Init( SDL_INIT_EVERYTHING ) != 0 ) {
        printf( "Unable to initialize SDL: %s\n", SDL_GetError() );
        return 1;
    }

    atexit( SDL_Quit );
    TTF_Init();
    atexit( TTF_Quit );
    
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

    
    int flags;
    if ( fullscreen ) {
        flags = SDL_OPENGL | SDL_FULLSCREEN;
        SDL_GL_SetAttribute( SDL_GL_RED_SIZE,   8 );
        SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 8 );
        SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE,  8 );
        SDL_GL_SetAttribute( SDL_GL_ALPHA_SIZE,  8 );
        SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 ); 
    }
    else flags = SDL_OPENGL;
    
    SDL_WM_SetCaption( "Escape", NULL );
    SDL_Surface* screen = SDL_SetVideoMode( width, height, depth, flags );
    
    SDL_FillRect    ( screen, NULL, SDL_MapRGBA( screen->format, 0, 0, 0, 0 ));	
    glClearColor    ( 1.0f, 1.0f, 1.0f, 0.0f );
    glViewport      ( 0, 0, width, height );
    glClear         ( GL_COLOR_BUFFER_BIT );
    glMatrixMode    ( GL_PROJECTION );
    
    glLoadIdentity();
    glOrtho         ( 0.0f, (float)width, (float)height, 0.0f, -1.0f, 1.0f );
    
    glMatrixMode    ( GL_MODELVIEW );
    glLoadIdentity();
    
    SDL_GL_SwapBuffers();
    
    return 0;
}