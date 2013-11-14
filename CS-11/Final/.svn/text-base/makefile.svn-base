Escape : base.o Animation.o Coin.o Entity.o GameManager.o Grid.o InputManager.o Part.o Resources.o Texture.o Tile.o World.o SDLMain.m
	g++ -Wall -Wextra -Wno-unused-parameter -Wnewline-eof -Werror -I /Library/Frameworks/SDL.framework/Headers -framework SDL -framework SDL_image -framework OpenGL -framework SDL_ttf -framework Cocoa -o Escape *.o SDLMain.m

base.o : base.cpp SDLGL.h GameManager.h
	g++ -I /Library/Frameworks/SDL.framework/Headers -c base.cpp
Animation.o : Animation.h Animation.cpp Texture.cpp Texture.h
	g++ -I /Library/Frameworks/SDL.framework/Headers -c Animation.cpp
Coin.o : Coin.cpp Coin.h Entity.h
	g++ -I /Library/Frameworks/SDL.framework/Headers -c Coin.cpp
Entity.o : Entity.cpp Entity.h Texture.h
	g++ -I /Library/Frameworks/SDL.framework/Headers -c Entity.cpp
GameManager.o : GameManager.cpp GameManager.h SDLGL.h World.h Resources.h Animation.h Animation.cpp Utilities.h InputManager.h InputManager.cpp
	g++ -I /Library/Frameworks/SDL.framework/Headers -c GameManager.cpp
Grid.o : Grid.cpp Grid.h Utilities.h Tile.cpp Tile.h globals.h
	g++ -I /Library/Frameworks/SDL.framework/Headers -c Grid.cpp
InputManager.o : InputManager.cpp InputManager.h
	g++ -I /Library/Frameworks/SDL.framework/Headers -c InputManager.cpp
Part.o : Part.cpp Part.h Entity.cpp Entity.h
	g++ -I /Library/Frameworks/SDL.framework/Headers -c Part.cpp
Resources.o : Resources.cpp Resources.h SDLGL.h
	g++ -I /Library/Frameworks/SDL.framework/Headers -c Resources.cpp
Texture.o : Texture.cpp Texture.h SDLGL.h
	g++ -I /Library/Frameworks/SDL.framework/Headers -c Texture.cpp
Tile.o : Tile.cpp Tile.h Entity.h SDLGL.h
	g++ -I /Library/Frameworks/SDL.framework/Headers -c Tile.cpp
World.o : World.cpp World.h Part.cpp Part.h Grid.cpp Grid.h SDLGL.h globals.h
	g++ -I /Library/Frameworks/SDL.framework/Headers -c World.cpp

clean : 
	rm Escape *.o

run :
	./Escape