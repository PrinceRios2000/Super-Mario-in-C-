#include "Globals.h"

#pragma once

class Ground
{
    public:
        Ground(int x);
        ~Ground();
        std::vector<SDL_Rect>& GetColliders();
        void ShiftColliders();
        void Draw(int camX, int camY);
    private:
        int PosX;
        int PosY;
        LTexture LayerOneTexture;
        LTexture LayerTwoTexture;
        std::vector<SDL_Rect> Colliders;
};

#include "../src/Ground.cpp"