#include "../headers/Ground.h"

Ground::Ground(int x)
{
    this->PosX = x;
    this->PosY = SCREEN_HEIGHT - 90;
    LayerOneTexture.loadFromFile("textures/ground.bmp");
    LayerTwoTexture.loadFromFile("textures/ground.bmp");

    Colliders.resize( 1 );

    Colliders[ 0 ].w = 735;
    Colliders[ 0 ].h = 300;

	//Initialize colliders relative to position
	ShiftColliders();
}

Ground::~Ground()
{
    LayerOneTexture.free();
    LayerTwoTexture.free();
}

std::vector<SDL_Rect>& Ground::GetColliders()
{
    return Colliders;
}

void Ground::ShiftColliders()
{
    //The row offset
    int r = 0;

    //Go through the dot's collision boxes
    for( int set = 0; set < Colliders.size(); ++set )
    {
        //Center the collision box
        Colliders[ set ].x = this->PosX;

        //Set the collision box at its row offset
        Colliders[ set ].y = this->PosY + r;

        //Move the row offset down the height of the collision box
        r += Colliders[ set ].h;
    }
}

void Ground::Draw(int camX, int camY)
{
    LayerOneTexture.render( this->PosX - camX, SCREEN_HEIGHT - 35 - camY );
    LayerTwoTexture.render( this->PosX - camX, SCREEN_HEIGHT - 90 - camY );
}