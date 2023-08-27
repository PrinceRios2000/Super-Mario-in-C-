#include "Globals.h"

#pragma once

class Block
{
    public:
        Block(int x, int y);
        ~Block();
        std::vector<SDL_Rect> GetColliders();
        void ShiftColliders();
        void Draw(int camX, int camY);
    private:
        int PosX;
        int PosY;
        LTexture BlockTexture;
        std::vector<SDL_Rect> Colliders;
};

#include "../src/Block.cpp"