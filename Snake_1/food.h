#ifndef FOOD_H
#define FOOD_H
#include<QLabel>
#include<coordinate.h>
class food
{
public:
    Coordinate coord;
    food(int x,int y,QWidget* parent);
    QLabel label_food;
    bool iscrashed(food &target);
    void show();//显示函数，未写


};

#endif // FOOD_H
