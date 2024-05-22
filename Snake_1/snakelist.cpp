#include "snakelist.h"

snakelist::snakelist()
{}
void snakelist::addsnake(int x,int y,QWidget* parent)
{
    snake_list.prepend( Snake(x,y,parent));
    snake_list[0].show();
}
void snakelist::deletesnake(int target)
{
    //disshow()
    snake_list.removeAt(target);

}
bool snakelist::ismatched(int x,int y)
{
    for(int i=0;i<snake_list.size();i++)
    {
        if(snake_list[i].iscrashed(x,y))
            return true;
    }
    return false;
}

