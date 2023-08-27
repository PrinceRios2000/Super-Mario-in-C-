#include "Globals.h"

#pragma once

class QuestionBlock
{
    public:
        QuestionBlock(int x, int y);
        ~QuestionBlock();
        std::vector<SDL_Rect> GetColliders();
        void ShiftColliders();
        void Draw(int camX, int camY);
    private:
        int PosX;
        int PosY;
        LTexture QuestionBlockTexture;
        std::vector<SDL_Rect> Colliders;
};

#include "../src/QuestionBlock.cpp"