#include "food.h"
food::food(int x,int y):food_x(x),food_y(y),nextfood(nullptr)
{}
bool food::iscrashed(int x,int y)
{
    if(food_x>x-unit_step&&food_x<x+unit_step&&food_y>y-unit_step&&food_y<y+unit_step)
        return true;
    else
        return false;
}
Foodlist::Foodlist():firstfood(nullptr)
{}
void Foodlist::addfood(int x,int y)
{
    food* temp=new food(x,y);
    temp->nextfood=firstfood;
    firstfood->lastfood=temp;
    firstfood=temp;

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
bool Foodlist::iscrashed(int x,int y)
{
    for(food* food=firstfood;food!=nullptr;food=food->nextfood)
    {
        if(food->iscrashed(x,y))
            return true;
    }
    return false;
}
