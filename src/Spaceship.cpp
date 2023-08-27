Spaceship::Spaceship(int x, int y)
{
    this->Frame = 0;
    this->PosX = x;
    this->PosY = y;
    this->VelX = 10;

    LeftBound = this->PosX;
    RightBound = this->PosX + 1000;

    SpaceshipSpriteClips[ 0 ].x =  0;
    SpaceshipSpriteClips[ 0 ].y =   0;
    SpaceshipSpriteClips[ 0 ].w =  64;
    SpaceshipSpriteClips[ 0 ].h = 205;

    SpaceshipSpriteClips[ 1 ].x =  50;
    SpaceshipSpriteClips[ 1 ].y =   0;
    SpaceshipSpriteClips[ 1 ].w =  64;
    SpaceshipSpriteClips[ 1 ].h = 205;
    
    SpaceshipSpriteClips[ 2 ].x = 100;
    SpaceshipSpriteClips[ 2 ].y =   0;
    SpaceshipSpriteClips[ 2 ].w =  64;
    SpaceshipSpriteClips[ 2 ].h = 205;

    SpaceshipSpriteClips[ 3 ].x = 150;
    SpaceshipSpriteClips[ 3 ].y =   0;
    SpaceshipSpriteClips[ 3 ].w =  64;
    SpaceshipSpriteClips[ 3 ].h = 205;

    SpaceshipSpriteClips[ 4 ].x = 200;
    SpaceshipSpriteClips[ 4 ].y =   0;
    SpaceshipSpriteClips[ 4 ].w =  64;
    SpaceshipSpriteClips[ 4 ].h = 205;

    int count = 0;

    for(int i = 0; i < 5; ++i)
    {
        SpaceshipSpriteClips[i].x = count;
        SpaceshipSpriteClips[i].y = 0;
        SpaceshipSpriteClips[i].w = 85;
        SpaceshipSpriteClips[i].h = 75;
        count += 89;
    }

    SpaceshipTexture.loadFromFile("textures/space-spritesheet.png");
}

Spaceship::~Spaceship()
{
    SpaceshipTexture.free();
}

int Spaceship::GetPosX()
{
    return this->PosX;
}

int Spaceship::GetPosY()
{
    return this->PosY;
}

void Spaceship::Fly()
{
    this->PosX += this->VelX;

    if(this->PosX >= RightBound)
    {
        this->PosX -= this->VelX;
        this->VelX = -10;
    }

    if(this->PosX < LeftBound)
    {
        this->PosX -= this->VelX;
        this->VelX = 10;
    }
}

void Spaceship::Draw(int camX, int camY)
{
    Fly();
    SDL_Rect* currentClip = &SpaceshipSpriteClips[ this->Frame / 5 ];
    SpaceshipTexture.render( this->PosX - camX, this->PosY - camY, currentClip );

    //Go to next this->Frame
    ++this->Frame;

    //Cycle animation
    if( this->Frame / 5 >= 5 )
    {
        this->Frame = 0;
    }
}