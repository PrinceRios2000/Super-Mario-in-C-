#include "Globals.h"

#pragma once

class Platform
{
    public:
        Platform(int x, int y);
        ~Platform();
        void ShiftColliders();
        std::vector<SDL_Rect>& GetColliders();
        void Draw(int camX, int camY);
    private:
        int PosX;
        int PosY;
        std::vector<SDL_Rect> Colliders;
        LTexture PlatformTexture;
};

#include "../src/Platform.cpp"