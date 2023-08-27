class Entity : public Position
{
    public:
        Entity(MyEntity MyIdentity);
        unsigned char GetIdentity();
        unsigned char GetSpeed();
        unsigned char GetDirection();
        unsigned char GetFacing();
        bool IsAlive();
        void ModSpeed(unsigned char NewSpeed);
        void ModDirection(unsigned char NewDirection);
        void ModFacing(unsigned char NewFacing);
        void ModLifeStatement(bool NewLifeStatement);
        void GetPossiblePosition(short &x, short &y, unsigned char mover);
        bool IsColliding(Position other);
    private:
        unsigned char Identity;
        unsigned char Speed;
        unsigned char Direction;
        unsigned char Facing;
        bool LifeStatement;
}