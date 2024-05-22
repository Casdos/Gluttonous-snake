#include "food.h"
food::food(int x,int y):food_x(x),food_y(y),nextfood(nullptr),lastfood(nullptr)
{
    label_food.setPixmap(QPixmap(":/photo/apple.png"));
}
bool food::iscrashed(int x,int y)
{
    qDebug()<<x<<y<<food_x<<food_y;
    if(food_x>x-unit_step&&food_x<x+unit_step&&food_y>y-unit_step&&food_y<y+unit_step)
        return true;
    else
        return false;
}
