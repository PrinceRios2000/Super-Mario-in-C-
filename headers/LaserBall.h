#include "Globals.h"

#pragma once

class LaserBall
{
    public:
        LaserBall(int x, int y);
        ~LaserBall();
        void SetPosX(int x);
        void SetPosY(int y);
        std::vector<SDL_Rect> GetColliders();
        bool CheckCollision(int MarioPosX, int MarioPosY, int SpaceshipPosX, int SpaceshipPosY, std::vector<SDL_Rect>& marioColliders);
        void ShiftColliders();
        void Draw(int camX, int camY);
    private:
        int PosX;
        int PosY;
        int VelX;
        int VelY;
        LTexture LaserBallTexture;
        SDL_Rect LaserBallSpriteClips[ 5 ];
        std::vector<SDL_Rect> Colliders;
};

#include "../src/LaserBall.cpp"