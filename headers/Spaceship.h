#include "Globals.h"

#pragma once

class Spaceship
{
    public:
        Spaceship(int x, int y);
        ~Spaceship();
        int GetPosX();
        int GetPosY();
        void Fly();
        void Shoot();
        void Draw(int camX, int camY);
    private:
        int Frame;
        int PosX;
        int PosY;
        int VelX;
        int LeftBound;
        int RightBound;
        LTexture SpaceshipTexture;
        SDL_Rect SpaceshipSpriteClips[ 5 ];
};

#include "../src/Spaceship.cpp"