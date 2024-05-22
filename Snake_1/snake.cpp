#include "snake.h"
snakebody::snakebody(int x,int y,QWidget* parent):body(x,y)
{
    label_snake_body.setPixmap(QPixmap(":/photo/h_body.png"));
    label_snake_body.setParent(parent);
    label_snake_tail.setPixmap(QPixmap(":/photo/tailright.png"));
    label_snake_tail.setParent(parent);
}
 bool snakebody::ismatched(snakebody& other)
{
    return body.isequal(other.body);
 }
Snake::Snake(int x,int y,QWidget* parent):parent(parent),snakehead(x,y),length(3),direction(0)
{
    label_snake_head.setPixmap(QPixmap(":/photo/headright.png"));
    label_snake_head.setParent(parent);
    snake_body_list.prepend(snakebody(x-2,y,parent));
    snake_body_list.prepend(snakebody(x-1,y,parent));
}
bool Snake::iscrashed(int x,int y)
{
    if(snakehead.isequal(Coordinate(x,y)))
        return true;
    else
    {
        snakebody temp(x,y);
        for(int i=0;i<snake_body_list.size();i++)
        {
            if(snake_body_list[i].ismatched(temp))
                return true;
        }
    }
    return false;
}
Coordinate Snake::nexthead()
{
      switch(direction)
    {
    case 0:
          return snakehead+Coordinate(1,0);
    case 1:
        return snakehead+Coordinate(0,-1);
    case 2:
        return snakehead+Coordinate(-1,0);
    case 3:
        return snakehead+Coordinate(0,1);
    }
}
void Snake::updata_nfood()
{
    snake_body_list.prepend(snakebody(snakehead.x_coord,snakehead.y_coord));
    snake_body_list[0].show();
    //disshow()，停止显示最后一个元素
    snake_body_list.removeAt(snake_body_list.size()-1);
}
void Snake::updata_food()
{
    snake_body_list.prepend(snakebody(snakehead.x_coord,snakehead.y_coord));
    snake_body_list[0].show();
}
void Snake::show()
{

}
void Snake::changedirection(int target)
{
    direction=target;
}
