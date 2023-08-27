#include "Texture.h"
#include "Globals.h"

#pragma once

class Tube
{
    public:
        Tube(int x, int y);
        ~Tube();
        std::vector<SDL_Rect>& GetColliders();
        void ShiftColliders();
        void Draw(int camX, int camY);
    private:
        LTexture TubeTexture;
        int PosX;
        int PosY;
        std::vector<SDL_Rect> Colliders;
};

#include "../src/Tube.cpp"