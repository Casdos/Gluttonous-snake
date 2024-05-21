#include "snake.h"
snakebody::snakebody(int x,int y):snakebody_x(x),snakebody_y(y),nextbody(nullptr)
{}
Snake::Snake(int x,int y):snakehead_x(x),snakehead_y(y),unit_step(30),direction(0),length(3),nextsnake(nullptr),lastsnake(nullptr)
{
    firstbody=new snakebody(x-unit_step,y);
    lastbody=new snakebody(x-2*unit_step,y);
    firstbody->nextbody=lastbody;
}
bool Snake::iscrashed(int x,int y)
{
    if(snakehead_x>x-unit_step&&snakehead_x<x+unit_step&&snakehead_y>y-unit_step&&snakehead_y<y+unit_step)
        return true;
    else
    {
        for(snakebody* temp=firstbody;temp!=nullptr;temp=temp->nextbody)
        {
            if(temp->snakebody_x>x-unit_step&&temp->snakebody_x<x+unit_step&&temp->snakebody_y>y-unit_step&&temp->snakebody_y<y+unit_step)
                return true;
        }
    }
    return false;
}
int Snake::next_step_x()
{
    return qCos(direction * M_PI / 180.0);
}
int Snake::next_step_y()
{
    return qSin(direction * M_PI / 180.0);
}
Snake::~Snake()
{
    snakebody* first=firstbody;
    for(snakebody* next=first->nextbody;next!=nullptr;next=next->nextbody)
    {
        delete first;
        first=next;
    }
    delete first;
}
snakelist::snakelist():firstsnake(nullptr)
{}
void snakelist::addsnake(int x,int y)
{
    Snake* temp=new Snake(x,y);
    temp->nextsnake=firstsnake;
    firstsnake->lastsnake=temp;
    firstsnake=temp;

}
void snakelist::deletesnake(Snake* snake)
{
    if(snake->lastsnake==nullptr)
    {
        firstsnake=snake->nextsnake;
        delete snake;
    }
    else if(snake->nextsnake==nullptr)
    {
        snake->lastsnake->nextsnake=nullptr;
        delete snake;
    }
    else
    {
        snake->lastsnake->nextsnake= snake->nextsnake;
        snake->nextsnake->lastsnake=snake->lastsnake;
        delete snake;
    }


}
bool snakelist::iscrashed(int x,int y)
{
    for(Snake* snake=firstsnake;snake!=nullptr;snake=snake->nextsnake)
    {
        if(snake->iscrashed(x,y))
            return true;
    }
    return false;
}
