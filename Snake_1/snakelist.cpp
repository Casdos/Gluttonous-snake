#include "snakelist.h"

snakelist::snakelist():firstsnake(nullptr)
{}
void snakelist::addsnake(int x,int y,QWidget* parent)
{
    Snake* temp=new Snake(x,y,parent);
    if(firstsnake==nullptr)
        firstsnake=temp;
    else
    {
        temp->nextsnake=firstsnake;
        firstsnake->lastsnake=temp;
        firstsnake=temp;
    }
    firstsnake->show();
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
