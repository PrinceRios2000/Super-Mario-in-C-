#include "Globals.h"

#pragma once

class Mario
{
    public:
        Mario();
        ~Mario();
		void HandleEvent( SDL_Event& e );
        void Move( std::vector<std::vector<SDL_Rect> > groundColliders, std::vector<std::vector<SDL_Rect> > tubeColliders, std::vector<std::vector<SDL_Rect> > platformColliders,
            std::vector<std::vector<SDL_Rect> > blockColliders, std::vector<std::vector<SDL_Rect> > questionBlockColliders );
        int GetPosX();
        int GetPosY();
        int GetVelX();
        int GetVelY();
        void SetVelX();
        void Reset();
        void ShiftColliders();
		std::vector<SDL_Rect>& GetColliders();
        void Draw( int camX, int camY );
    private:
        int Frame;
        bool ButtonPressed;
        int Lives;
        LTexture MarioTexture;
        int PosX;
        int PosY;
		int VelX, VelY;
	    std::vector<SDL_Rect> Colliders;
        SDL_Rect MarioSpriteClips[ 8 ];
};
#include "../src/Mario.cpp"