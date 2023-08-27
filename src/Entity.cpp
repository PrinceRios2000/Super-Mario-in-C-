Entity::Entity(EntityType MyIdentity)
{
    this->Identity = MyIdentity;
    this->Direction = 0;
    this->Facing = 0;
    this->LifeStatement = true;
}

unsigned char Entity::GetIdentity()
{
    return this->Identity;
}

unsigned char Entity::GetSpeed()
{
    return this->Speed;
}

unsigned char Entity::GetDirection()
{
    return this->Direction;
}

unsigned char Entity::GetFacing()
{
    return this->Facing;
}

bool Entity::IsAlive()
{
    return this->LifeStatement;
}

void Entity::ModSpeed(unsigned char NewSpeed)
{
    this->Speed = NewSpeed;
}

void Entity::ModDirection(unsigned char NewDirection)
{
    this->Direction = NewDirection;
}

void Entity::ModFacing(unsigned char NewFacing)
{
    this->Facing = NewFacing;
}

void Entity::ModLifeStatement(unsigned char NewLifeStatement)
{
    this->LifeStatement = NewLifeStatement;
}

void Entity::GetPossiblePosition(short &x, short &y, unsigned char mover)
{
    switch (mover)
    {
        case Right:
            x++;
            break;
        case Up:
            y--;
            break;
        case Left:
            x--;
            break;
        case Down:
            y++;
            break;
        default:
            break;
    }
}

