LaserBall::LaserBall(int x, int y)
{
    this->PosX = x;
    this->PosY = y;

    this->VelX = -10;
    this->VelY = 10;

    Colliders.resize( 11 );
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

    Colliders[ 5 ].w = 20;
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

	//Initialize colliders relative to position
	ShiftColliders();

    LaserBallTexture.loadFromFile("textures/test.png");
}

LaserBall::~LaserBall()
{
    LaserBallTexture.free();
}

void LaserBall::SetPosX(int x)
{
    this->PosX = x;
}

void LaserBall::SetPosY(int y)
{
    this->PosY = y;
}

std::vector<SDL_Rect> LaserBall::GetColliders()
{
    return Colliders;
}

bool LaserBall::CheckCollision(int MarioPosX, int MarioPosY, int SpaceshipPosX, int SpaceshipPosY, std::vector<SDL_Rect>& marioColliders)
{
    bool result = false;
    this->PosX += this->VelX;
    this->PosY += this->VelY;

    ShiftColliders();

    if( CollidedWithMario(Colliders, marioColliders) )
    {
        result = true;
    }
    
    if(this->PosY > SCREEN_HEIGHT)
    {
        this->PosX = SpaceshipPosX;
        this->PosY = SpaceshipPosY;

        ShiftColliders();

        if(MarioPosX > this->PosX)
        {
            this->VelX = 10;
        }

        else
        {
            this->VelX = -10;
        }
    }

    return result;
}

void LaserBall::ShiftColliders()
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

void LaserBall::Draw(int camX, int camY)
{
    LaserBallTexture.render(this->PosX - camX, this->PosY - camY);
}