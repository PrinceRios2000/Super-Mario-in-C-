Mario::Mario()
{
    ButtonPressed = false;
    Lives = 3;
    this->PosX = 5;
    this->PosY = SCREEN_HEIGHT - 200;
    //Create the necessary SDL_Rects
    Colliders.resize( 11 );

    //Initialize the velocity
    this->VelX = 0;
    this->VelY = 0;

    this->Frame = 0;

    MarioTexture.loadFromFile("textures/mario-spritesheet.png");

    //Initialize the collision boxes' width and height 
    Colliders[ 0 ].w = 6;
    Colliders[ 0 ].h = 1;

    Colliders[ 1 ].w = 10;
    Colliders[ 1 ].h = 1;

    Colliders[ 2 ].w = 14;
    Colliders[ 2 ].h = 1;

    Colliders[ 3 ].w = 16;
    Colliders[ 3 ].h = 2;

    Colliders[ 4 ].w = 18;
    Colliders[ 4 ].h = 2;

    Colliders[ 5 ].w = 30;
    Colliders[ 5 ].h = 6;

    Colliders[ 6 ].w = 18;
    Colliders[ 6 ].h = 2;

    Colliders[ 7 ].w = 16;
    Colliders[ 7 ].h = 2;

    Colliders[ 8 ].w = 14;
    Colliders[ 8 ].h = 1; 

    Colliders[ 9 ].w = 10;
    Colliders[ 9 ].h = 1;

    Colliders[ 10 ].w = 6;
    Colliders[ 10 ].h = 1;

    Colliders[0].w += 5;
    // Colliders[0].h += 1;

    Colliders[10].w += 5;
    // Colliders[10].h += 1;

    // for(int i = 0; i < 11; ++i)
    // {
    //     Colliders[i].w += 10;
    //     Colliders[i].h += 10;
    // }

	//Initialize colliders relative to position
	ShiftColliders();

    // Initialize sprite clips
    MarioSpriteClips[ 0 ].x =  0;
    MarioSpriteClips[ 0 ].y =   0;
    MarioSpriteClips[ 0 ].w =  64;
    MarioSpriteClips[ 0 ].h = 205;

    MarioSpriteClips[ 1 ].x =  50;
    MarioSpriteClips[ 1 ].y =   0;
    MarioSpriteClips[ 1 ].w =  64;
    MarioSpriteClips[ 1 ].h = 205;
    
    MarioSpriteClips[ 2 ].x = 100;
    MarioSpriteClips[ 2 ].y =   0;
    MarioSpriteClips[ 2 ].w =  64;
    MarioSpriteClips[ 2 ].h = 205;

    MarioSpriteClips[ 3 ].x = 150;
    MarioSpriteClips[ 3 ].y =   0;
    MarioSpriteClips[ 3 ].w =  64;
    MarioSpriteClips[ 3 ].h = 205;

    MarioSpriteClips[ 4 ].x = 200;
    MarioSpriteClips[ 4 ].y =   0;
    MarioSpriteClips[ 4 ].w =  64;
    MarioSpriteClips[ 4 ].h = 205;

    MarioSpriteClips[ 5 ].x = 250;
    MarioSpriteClips[ 5 ].y =   0;
    MarioSpriteClips[ 5 ].w =  64;
    MarioSpriteClips[ 5 ].h = 205;

    MarioSpriteClips[ 6 ].x = 200;
    MarioSpriteClips[ 6 ].y =   0;
    MarioSpriteClips[ 6 ].w =  64;
    MarioSpriteClips[ 6 ].h = 205;

    MarioSpriteClips[ 7 ].x = 200;
    MarioSpriteClips[ 7 ].y =   0;
    MarioSpriteClips[ 7 ].w =  64;
    MarioSpriteClips[ 7 ].h = 205;

    int count = 0;
    for(int clip = 0; clip < 8; clip++)
    {
        MarioSpriteClips[clip].x = count;
        MarioSpriteClips[clip].w = 100;
        MarioSpriteClips[clip].h = 150;
        count += 150;
    }
}

Mario::~Mario()
{
    MarioTexture.free();
}

int Mario::GetPosX()
{
    return this->PosX;
}

int Mario::GetPosY()
{
    return this->PosY;
}

int Mario::GetVelX()
{
    return this->VelX;
}

void Mario::HandleEvent( SDL_Event& e )
{
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: 
                if( ButtonPressed )
                    break;
                ButtonPressed = true;
                this->VelY -= MARIO_Y_VEL;
                return;
            case SDLK_LEFT:
                this->VelX -= MARIO_X_VEL; 
                break;
            case SDLK_RIGHT: 
                this->VelX += MARIO_X_VEL; 
                break;
        }
    }
    
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_LEFT: 
                this->VelX += MARIO_X_VEL; 
                break;
            case SDLK_RIGHT: 
                this->VelX -= MARIO_X_VEL;
                break;
        }
    }

    if( ButtonPressed )
    {
        this->VelY = 4;
        return;
    }
}

int Mario::GetVelY()
{
    return VelY;
}

void Mario::Move(std::vector<std::vector<SDL_Rect> > groundColliders, std::vector<std::vector<SDL_Rect> > tubeColliders, std::vector<std::vector<SDL_Rect> > platformColliders,
    std::vector<std::vector<SDL_Rect> > blockColliders, std::vector<std::vector<SDL_Rect> > questionBlockColliders)
{
    //Move the dot left or right
    this->PosX += this->VelX;
    ShiftColliders();

    //If the dot collided or went too far to the left or right
    if( ( this->PosX < 0 ) || ( this->PosX + MARIO_WIDTH > LEVEL_WIDTH ) || CheckCollision( Colliders, groundColliders, tubeColliders, platformColliders, blockColliders, questionBlockColliders ) )
    {
        //Move back
        this->PosX -= this->VelX; 
		ShiftColliders();
    }

    // Move the dot up or down
    this->PosY += this->VelY;
    ShiftColliders();

    if ( CheckCollision(Colliders, groundColliders, tubeColliders, platformColliders) && this->VelY == 4)
    {
        ButtonPressed = false;
    }

    //If the dot collided or went too far up or down
    if( ( this->PosY < 0 ) || ( this->PosY + MARIO_HEIGHT > LEVEL_HEIGHT ) || CheckCollision( Colliders, groundColliders, tubeColliders, platformColliders, blockColliders, questionBlockColliders ) )
    {
        //Move back
        this->PosY -= VelY;
        ShiftColliders();
    }
}

std::vector<SDL_Rect>& Mario::GetColliders()
{
    return Colliders;
}

void Mario::SetVelX()
{
    this->VelX = 0;
}

void Mario::Reset()
{
    this->PosX = 5;
    this->PosY = SCREEN_HEIGHT - 200;
}

void Mario::Draw(int camX, int camY)
{
    SDL_Rect* currentClip = &MarioSpriteClips[ this->Frame / 8 ];
    MarioTexture.render( this->PosX - camX, this->PosY - camY, currentClip );

    //Go to next this->Frame
    ++this->Frame;

    //Cycle animation
    if( this->Frame / 8 >= 8 )
    {
        this->Frame = 0;
    }
}

void Mario::ShiftColliders()
{
    //The row offset
    int r = 0;

    //Go through the dot's collision boxes
    for( int set = 0; set < Colliders.size(); ++set )
    {
        //Center the collision box
        Colliders[ set ].x = this->PosX + ( MarioTexture.getWidth() - Colliders[ set ].w ) / 2;

        //Set the collision box at its row offset
        Colliders[ set ].y = this->PosY + r;

        //Move the row offset down the height of the collision box
        r += Colliders[ set ].h;
    }
}