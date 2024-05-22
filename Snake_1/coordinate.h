#ifndef COORDINATE_H
#define COORDINATE_H

const int size=20;//棋盘每格大小
const int maxsize_x=172;
const int maxsize_y=148;
class Coordinate//坐标类
{
public:
    int x_coord;
    int y_coord;
    Coordinate(int x,int y);
    bool isequal(const Coordinate &other);
    Coordinate operator+(const Coordinate &other);
};

#endif // COORDINATE_H
