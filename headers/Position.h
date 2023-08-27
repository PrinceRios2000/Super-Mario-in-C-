class Position
{
    public:
        Position(short x, short y);
        short GetX();
        short GetY();
        Position GetPos();
        void ModX(short NewX);
        void ModY(short NewY);
        void ModCoord(short NewX, short NewY);
        void ModPos(Position NewPosition);
        bool operator == (Position other) { return this->x == other.GetX() && this->y == other.GetY(); }

    private:
        short x, y;
};