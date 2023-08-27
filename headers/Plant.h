#include "Globals.h"

#pragma once

class Plant
{
    public:
        Plant(int x, int y);
        ~Plant();
        bool CheckCollision(std::vector<SDL_Rect>& marioColliders);
        void ShiftColliders();
        void Draw(int camX, int camY);
    private:
        LTexture PlantTexture;
        int PosX;
        int PosY;
        std::vector<SDL_Rect> Colliders;
};

#include "../src/Plant.cpp"