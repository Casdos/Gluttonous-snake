#include "foodlist.h"


Foodlist::Foodlist():firstfood(nullptr),parent(nullptr),xmax(0),ymax(0),xmin(0),ymin(0)
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
void Foodlist::addfood_r()
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
    for(food* thefood=firstfood;thefood!=nullptr;thefood=thefood->nextfood)
    {
        if(thefood->iscrashed(x,y))
            return thefood;
    }
    return nullptr;
}
void Foodlist::updata_food(food* eatedfood)
{
    //eatedfood->label_food.hide();
    deletefood(eatedfood);
    addfood_r();
    firstfood->label_food.show();
}
void Foodlist::initialize(int xma,int yma,int xmi,int ymi,QWidget* parent,int number)
{
    xmax=xma;
    ymax=yma;
    xmin=xmi;
    ymin=ymi;
    this->parent=parent;
    for(int i=0;i<number;i++)
    {
        addfood_r();
        firstfood->label_food.setGeometry(firstfood->food_x,firstfood->food_y,1000,1000);
        firstfood->label_food.show();
    }

}
