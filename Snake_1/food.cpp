#include "food.h"
food::food(int x,int y,QWidget* parent):coord(x,y)
{
    label_food.setPixmap(QPixmap(":/photo/apple.png"));
    label_food.setParent(parent);
}
bool food::iscrashed(food &target)
{
    if(target.coord.isequal(coord))
        return true;
    else
        return false;
}
