#include "foodlist.h"


Foodlist::Foodlist(QWidget* parent):parent(parent)
{}
void Foodlist::addfood(Coordinate target)
{
    food_list.append(food(target.x_coord,target.y_coord,parent));
}
void Foodlist::addfood_r()
{
    int x=QRandomGenerator::global()->bounded(maxsize_x);
    int y=QRandomGenerator::global()->bounded(maxsize_y);
    addfood(Coordinate(x,y));
}
int Foodlist::findfood(food target)
{
    for(int i=0;i<food_list.size();i++)
    {
        if(target.iscrashed(food_list[i]))
            return i;
    }
    return -1;
}
void Foodlist::deletefood(int i)
{
    food_list.removeAt(i);
}
void Foodlist::updata_food(int eatedfood)
{
    deletefood(eatedfood);
    addfood_r();
}
void Foodlist::initialize(int number)
{
    for(int i=0;i<number;i++)
    {
        addfood_r();
    }
    for(int i=0;i<food_list.size();i++)
    {
        food_list[i].show();
    }

}
