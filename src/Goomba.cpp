Goomba::Goomba(int x)
{
    this->PosX = x;
    this->PosY = SCREEN_HEIGHT - 151;

    this->StartX = this->PosX;
    this->StartY = this->PosY;

    this->VelX = 0;
    this->Frame = 0;
    this->Direction = 'L';

    IsActivated = false;
    //Initialize the collision boxes' width and height
    Colliders.resize( 1 );

    Colliders[ 0 ].w = 50;
    Colliders[ 0 ].h = 50;

	//Initialize colliders relative to position
	ShiftColliders();
    GoombaTexture.loadFromFile("textures/goomba-spritesheet.png");

    GoombaSpriteClips[ 0 ].x =  0;
    GoombaSpriteClips[ 0 ].y =   0;
    GoombaSpriteClips[ 0 ].w =  64;
    GoombaSpriteClips[ 0 ].h = 205;

    GoombaSpriteClips[ 1 ].x =  50;
    GoombaSpriteClips[ 1 ].y =   0;
    GoombaSpriteClips[ 1 ].w =  64;
    GoombaSpriteClips[ 1 ].h = 205;
    
    GoombaSpriteClips[ 2 ].x = 100;
    GoombaSpriteClips[ 2 ].y =   0;
    GoombaSpriteClips[ 2 ].w =  64;
    GoombaSpriteClips[ 2 ].h = 205;

    GoombaSpriteClips[ 3 ].x = 150;
    GoombaSpriteClips[ 3 ].y =   0;
    GoombaSpriteClips[ 3 ].w =  64;
    GoombaSpriteClips[ 3 ].h = 205;

    GoombaSpriteClips[ 4 ].x = 200;
    GoombaSpriteClips[ 4 ].y =   0;
    GoombaSpriteClips[ 4 ].w =  64;
    GoombaSpriteClips[ 4 ].h = 205;

    GoombaSpriteClips[ 5 ].x = 250;
    GoombaSpriteClips[ 5 ].y =   0;
    GoombaSpriteClips[ 5 ].w =  64;
    GoombaSpriteClips[ 5 ].h = 205;

    int count = 0;
    for(int clip = 0; clip < 6; clip++)
    {
        GoombaSpriteClips[clip].x = count;
        GoombaSpriteClips[clip].w = 60;
        GoombaSpriteClips[clip].h = 50;
        count += 60;
    }

    isAlive = true;
}

Goomba::~Goomba()
{
    GoombaTexture.free();
}

void Goomba::SetPosX(int x)
{
    this->PosX = x;
}

void Goomba::SetPosY(int y)
{
    this->PosY = y;
}

void Goomba::Bury()
{
    this->PosX = 0;
    this->PosY = SCREEN_HEIGHT;
    this->VelX = 0;
}

void Goomba::CheckGoombaCollision(std::vector<std::vector<SDL_Rect> > groundColliders, std::vector<std::vector<SDL_Rect> > tubeColliders, std::vector<SDL_Rect>& marioColliders, int MarioPosX, int MarioPosY)
{
    if( this->PosX - MarioPosX == 500 && !IsActivated )
    {
        this->VelX = -3;
        IsActivated = true;
    }

    //Move the dot left or right
    this->PosX += this->VelX;
    ShiftColliders();

    // Check collision with mario
    if( CollidedWithMario(Colliders, marioColliders) )
    {
        if( MarioPosY == 410 )
        {
            this->PosY;
            for(int clip = 0; clip < 6; clip++)
            {
                GoombaSpriteClips[clip].w = 30;
                GoombaSpriteClips[clip].h = 30;
            }
            Bury();
        }
    }

    //If the dot collided or went too far to the left or right
    if( ( this->PosX < 0 ) || ( this->PosX + MARIO_WIDTH > LEVEL_WIDTH ) || CheckCollision(Colliders, groundColliders, tubeColliders) )
    {
        //Move back
        this->PosX -= this->VelX;
        ShiftColliders();
    }
}

void Goomba::Reset()
{
    this->PosX = this->StartX;
    this->PosY = this->StartY;
    ShiftColliders();
    IsActivated = false;
}

std::vector<SDL_Rect> Goomba::GetColliders()
{
    return Colliders;
}

void Goomba::ShiftColliders()
{
    //The row offset
    int r = 0;

    //Go through the dot's collision boxes
    for( int set = 0; set < Colliders.size(); ++set )
    {
        //Center the collision box
        // Colliders[ set ].x = this->PosX + ( MARIO_WIDTH - Colliders[ set ].w ) / 2;
        Colliders[ set ].x = this->PosX;

        //Set the collision box at its row offset
        Colliders[ set ].y = this->PosY + r;

        //Move the row offset down the height of the collision box
        r += Colliders[ set ].h;
    }
}

void Goomba::Draw(int camX, int camY)
{
    SDL_Rect* currentClip = &GoombaSpriteClips[ this->Frame / 6 ];
    GoombaTexture.render( this->PosX - camX, this->PosY - camY, currentClip );

    //Go to next this->Frame
    ++this->Frame;

    //Cycle animation
    if( this->Frame / 6 >= 6 )
    {
        this->Frame = 0;
    }
}