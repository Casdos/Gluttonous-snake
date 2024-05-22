#include "coordinate.h"

Coordinate::Coordinate(int x,int y):x_coord(x),y_coord(y)
{}
bool Coordinate::isequal(const Coordinate &other)
{
    if(other.x_coord==x_coord&&other.y_coord==y_coord)
        return true;
    else
        return false;
}
Coordinate Coordinate::operator+(const Coordinate &other)
{
    Coordinate one(this->x_coord,this->y_coord);
    one.x_coord+=other.x_coord;
    one.y_coord+=other.y_coord;
    return one;
}
