#include "Globals.h"

#pragma once

class Goomba
{
    public:
        Goomba(int x);
        ~Goomba();
        void CheckGoombaCollision( std::vector<std::vector<SDL_Rect> > groundColliders, std::vector<std::vector<SDL_Rect> > tubeColliders, std::vector<SDL_Rect>& marioColliders, int MarioPosX, int MarioPosY);
        void SetPosX(int x);
        void SetPosY(int y);
        std::vector<SDL_Rect> GetColliders();
        void ShiftColliders();
        void Reset();
        void Bury();
        void Draw(int camX, int camY);
    private:
        int StartX;
        int StartY;
        int Frame;
        int PosX;
        int PosY;
        int VelX;
        int VelY;
        char Direction;
        bool IsActivated;
        LTexture GoombaTexture;
        SDL_Rect GoombaSpriteClips[ 6 ];
        std::vector<SDL_Rect> Colliders;
        bool isAlive;
};

#include "../src/Goomba.cpp"