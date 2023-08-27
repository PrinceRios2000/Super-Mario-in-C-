Plant::Plant(int x, int y)
{
    this->PosX = x;
    this->PosY = y;

    Colliders.resize( 1 );

    Colliders[0].w = 100;
    Colliders[0].h = 100;

    ShiftColliders();

    PlantTexture.loadFromFile("textures/newwPlant.png");
}

Plant::~Plant()
{
    PlantTexture.free();
}

bool Plant::CheckCollision(std::vector<SDL_Rect>& marioColliders)
{
    return CollidedWithMario(Colliders, marioColliders);
}

void Plant::ShiftColliders()
{
    //The row offset
    int r = 0;

    //Go through the dot's collision boxes
    for( int set = 0; set < Colliders.size(); ++set )
    {
        //Center the collision box
        Colliders[ set ].x = this->PosX + ( MARIO_WIDTH - Colliders[ set ].w ) / 2;

        //Set the collision box at its row offset
        Colliders[ set ].y = this->PosY + r;

        //Move the row offset down the height of the collision box
        r += Colliders[ set ].h;
    }
}

void Plant::Draw(int camX, int camY)
{
    PlantTexture.render( this->PosX - camX, this->PosY - camY);
}