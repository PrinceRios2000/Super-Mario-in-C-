#include "../headers/QuestionBlock.h"

QuestionBlock::QuestionBlock(int x, int y)
{
    this->PosX = x;
    this->PosY = y;

    Colliders.resize(1);

    Colliders[0].w = 40;
    Colliders[0].h = 40;
    ShiftColliders();

    QuestionBlockTexture.loadFromFile("textures/questionBlock.bmp");
}

QuestionBlock::~QuestionBlock()
{
    QuestionBlockTexture.free();
}

std::vector<SDL_Rect> QuestionBlock::GetColliders()
{
    return Colliders;
}

void QuestionBlock::ShiftColliders()
{
    //The row offset
    int r = 0;

    //Go through the dot's collision boxes
    for( int set = 0; set < Colliders.size(); ++set )
    {
        //Center the collision box
        // Colliders[ set ].x = this->PosX + ( MARIO_WIDTH - Colliders[ set ].w ) / 2;
        Colliders[ set ].x = this->PosX + r;

        //Set the collision box at its row offset
        Colliders[ set ].y = this->PosY + r;

        //Move the row offset down the height of the collision box
        r += Colliders[ set ].h;
    }
}

void QuestionBlock::Draw(int camX, int camY)
{
    QuestionBlockTexture.render( this->PosX - camX, this->PosY - camY );
}