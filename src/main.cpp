/*This source code copyrighted by Lazy Foo' Productions 2004-2023
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, vectors, and strings
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <sstream>
#include <string>
#include <cmath>
#include "../headers/Texture.h"
#include "../headers/Globals.h"
#include "../headers/Game.h"
#include "../headers/Ground.h"

int main( int argc, char* args[] )
{
	InitializeSDL();

	Game game;
	game.Run();

	CloseSDL();
	return 0;
}
