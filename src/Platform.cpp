Platform::Platform(int x, int y)
{
    this->PosX = x;
    this->PosY = y;

    Colliders.resize( 1 );

    Colliders[ 0 ].w = 30;
    Colliders[ 0 ].h = 30;

    ShiftColliders();

    PlatformTexture.loadFromFile("textures/ppp.bmp");
}

Platform::~Platform()
{
    PlatformTexture.free();
}

std::vector<SDL_Rect>& Platform::GetColliders()
{
    return Colliders;
}

void Platform::ShiftColliders()
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

void Platform::Draw(int camX, int camY)
{
    PlatformTexture.render( this->PosX - camX, this->PosY - camY );
}
