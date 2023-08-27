#include "../headers/Tube.h"

Tube::Tube(int x, int y)
{
    TubeTexture.loadFromFile("textures/tube.bmp");

    this->PosX = x;
    this->PosY = y;

    Colliders.resize( 2 );

    Colliders[0].w = 74;
    Colliders[0].h = 35;

    Colliders[1].w = 50;
    Colliders[1].h = 150;

    ShiftColliders();
}

Tube::~Tube()
{
    TubeTexture.free();
}

std::vector<SDL_Rect>& Tube::GetColliders()
{
    return Colliders;
}

void Tube::ShiftColliders()
{
    int r = 0;

    for( int set = 0; set < Colliders.size(); ++set)
    {
        Colliders[set].x = this->PosX + ( TubeTexture.getWidth() - Colliders[set].w ) / 2;
        Colliders[set].y = this->PosY + r;

        r += Colliders[set].h;
    }
}

void Tube::Draw(int camX, int camY)
{
    TubeTexture.render( this->PosX - camX, this->PosY - camY );
}