#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#pragma once

const unsigned short LEVEL_WIDTH = 12000;
const unsigned short LEVEL_HEIGHT = 800;

const unsigned short SCREEN_WIDTH = 800;
const unsigned short SCREEN_HEIGHT = 580;

const unsigned int GRAVITY = 3;

static const int MARIO_X_VEL = 5;
static const int MARIO_Y_VEL = 10;
static const int MARIO_WIDTH = 20;  
static const int MARIO_HEIGHT = 20;

static const int TUBE_WIDTH = 20;
static const int TUBE_HEIGHT = 20;

static const int MARTIAN_VEL = 3;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
TTF_Font* font = NULL;

void InitializeSDL()
{
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow( "Super Mario", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
    int imgFlags = IMG_INIT_PNG;
    IMG_Init(imgFlags);
    TTF_Init();
    font = TTF_OpenFont("arcade.ttf", 28);
}

bool CollidedWithMario(std::vector<SDL_Rect>& a, std::vector<SDL_Rect>& b)
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Go through the A boxes
    for( int Abox = 0; Abox < a.size(); Abox++ )
    {
        //Calculate the sides of rect A
        leftA = a[ Abox ].x;
        rightA = a[ Abox ].x + a[ Abox ].w;
        topA = a[ Abox ].y;
        bottomA = a[ Abox ].y + a[ Abox ].h;

        //Go through the B boxes
        for( int Bbox = 0; Bbox < b.size(); Bbox++ )
        {
            //Calculate the sides of rect B
            leftB = b[ Bbox ].x;
            rightB = b[ Bbox ].x + b[ Bbox ].w;
            topB = b[ Bbox ].y;
            bottomB = b[ Bbox ].y + b[ Bbox ].h;

            //If no sides from A are outside of B
            if( ( ( bottomA <= topB ) || ( topA >= bottomB ) || ( rightA <= leftB ) || ( leftA >= rightB ) ) == false )
            {
                //A collision is detected
                return true;
            }
        }
    }

    //If neither set of collision boxes touched
    return false;
}

bool CheckCollision(std::vector<SDL_Rect>& a, std::vector<std::vector<SDL_Rect> > groundColliders, std::vector<std::vector<SDL_Rect> > tubeColliders, std::vector<std::vector<SDL_Rect> > platformColliders = std::vector<std::vector<SDL_Rect> >(),
    std::vector<std::vector<SDL_Rect> > blockColliders = std::vector<std::vector<SDL_Rect> >(), std::vector<std::vector<SDL_Rect> > questionBlockColliders = std::vector<std::vector<SDL_Rect> >())
{
    for(int i = 0; i < blockColliders.size(); ++i)
    {
        std::vector<SDL_Rect> collider = blockColliders[i];

        if(CollidedWithMario(a, collider))
            return true;
    }

    for(int i = 0; i < questionBlockColliders.size(); ++i)
    {
        std::vector<SDL_Rect> collider = questionBlockColliders[i];

        if(CollidedWithMario(a, collider))
            return true;
    }

    for(int i = 0; i < platformColliders.size(); ++i)
    {
        std::vector<SDL_Rect> collider = platformColliders[i];

        if(CollidedWithMario(a, collider))
            return true;
    }

    for(int i = 0; i < groundColliders.size(); ++i)
    {
        std::vector<SDL_Rect> collider = groundColliders[i];
        
        if(CollidedWithMario(a, collider))
            return true;
    }

    for(int i = 0; i < tubeColliders.size(); ++i)
    {
        std::vector<SDL_Rect> collider = tubeColliders[i];
        
        if(CollidedWithMario(a, collider))
            return true;
    }

    for(int i = 0; i < platformColliders.size(); ++i)
    {
        std::vector<SDL_Rect> collider = platformColliders[i];
        
        if(CollidedWithMario(a, collider))
            return true;
    }
    return false;
}

void CloseSDL()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = NULL;
    renderer = NULL;
    TTF_CloseFont(font);
    font = NULL;
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}