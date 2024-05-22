#include "foodlist.h"


Foodlist::Foodlist():firstfood(nullptr),parent(nullptr)
{}
void Foodlist::addfood(int x,int y)
{
    food* temp=new food(x,y);
    temp->nextfood=firstfood;
    if(firstfood!=nullptr)
    firstfood->lastfood=temp;
    firstfood=temp;
    temp->label_food.setParent(parent);

}
void Foodlist::addfood_r(int xmax,int ymax,int xmin,int ymin)
{
    int x=QRandomGenerator::global()->bounded(xmax-xmin) + xmin;
    int y=QRandomGenerator::global()->bounded(ymax-ymin) + ymin;
    addfood(x,y);
}
void Foodlist::deletefood(food* food)
{
    if(food->lastfood==nullptr)
    {
        firstfood=food->nextfood;
        delete food;
    }
    else if(food->nextfood==nullptr)
    {
        food->lastfood->nextfood=nullptr;
        delete food;
    }
    else
    {
        food->lastfood->nextfood= food->nextfood;
        food->nextfood->lastfood=food->lastfood;
        delete food;
    }
}
food* Foodlist::iscrashed(int x,int y)
{
    for(food* food=firstfood;food!=nullptr;food=food->nextfood)
    {
        if(food->iscrashed(x,y))
            return food;
    }
    return nullptr;
}
void Foodlist::updata_food(food* eatedfood,int xmax,int ymax,int xmin,int ymin)
{
    //eatedfood->label_food.hide();
    deletefood(eatedfood);
    addfood_r(xmax,ymax);
    firstfood->label_food.show();
}
    void Foodlist::initialize(int xmax,int ymax,QWidget* parent,int number)
{
        this->parent=parent;
        for(int i=0;i<number;i++)
        {
           addfood_r(xmax,ymax);
            firstfood->label_food.setGeometry(firstfood->food_x,firstfood->food_y,1000,1000);
          firstfood->label_food.show();
        }

}
