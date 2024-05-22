#include "snake.h"
snakebody::snakebody(int x,int y,QWidget* parent):snakebody_x(x),snakebody_y(y),next_body(nullptr),last_body(nullptr)
{
    label_snake_body.setPixmap(QPixmap(":/photo/h_body.png"));
    label_snake_body.setParent(parent);
    label_snake_tail.setPixmap(QPixmap(":/photo/tailright.png"));
    label_snake_tail.setParent(parent);
}
Snake::Snake(int x,int y,QWidget* parent):unit_step(30),snakehead_x(x),snakehead_y(y),direction(0),length(3),nextsnake(nullptr),lastsnake(nullptr),parent(parent)
{
    firstbody=nullptr;
    lastbody=nullptr;
    label_snake_head.setPixmap(QPixmap(":/photo/headright.png"));
    label_snake_head.setParent(parent);

}
bool Snake::iscrashed(int x,int y)
{
    if(snakehead_x>x-unit_step&&snakehead_x<x+unit_step&&snakehead_y>y-unit_step&&snakehead_y<y+unit_step)
        return true;
    else
    {
        for(snakebody* temp=firstbody;temp!=nullptr;temp=temp->next_body)
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
void Snake::updata_nfood()
{


     if(firstbody==nullptr)//只有蛇头
    {

    }
     else if(firstbody->next_body==nullptr)//只有蛇头蛇身
     {
         firstbody->snakebody_x=snakehead_x;
        firstbody->snakebody_y=snakehead_y;
         firstbody->label_snake_tail.setGeometry(firstbody->snakebody_x,firstbody->snakebody_y,100,100);
     }
    else//有蛇头蛇尾蛇身
    {
        lastbody->label_snake_tail.hide();
         lastbody->snakebody_x=snakehead_x;
        lastbody->snakebody_y=snakehead_y;
         lastbody->label_snake_body.setGeometry(lastbody->snakebody_x,lastbody->snakebody_y,100,100);


        firstbody->last_body=lastbody;
         lastbody->next_body=firstbody;
        firstbody=lastbody;
         lastbody=firstbody->last_body;
        lastbody->next_body=nullptr;
         firstbody->last_body=nullptr;

        lastbody->label_snake_body.hide();
        lastbody->label_snake_tail.setGeometry(lastbody->snakebody_x,lastbody->snakebody_y,100,100);

    }
    snakehead_x=snakehead_x+next_step_x();
    snakehead_y=snakehead_y+next_step_y();
    label_snake_head.setGeometry(snakehead_x,snakehead_y,100,100);
}
void Snake::updata_food()
{
    snakebody* temp=new snakebody(snakehead_x,snakehead_y);
    if(firstbody==nullptr)//只有蛇头
    {
        firstbody=temp;
        lastbody=firstbody;
        firstbody->label_snake_tail.setGeometry(firstbody->snakebody_x,firstbody->snakebody_y,100,100);
    }
    else if(firstbody->next_body==nullptr)//只有蛇头蛇身
    {

        firstbody->label_snake_tail.hide();
        firstbody->label_snake_body.setGeometry(firstbody->snakebody_x,firstbody->snakebody_y,100,100);
        temp->next_body=firstbody;
        firstbody=temp;
        firstbody->label_snake_body.setGeometry(firstbody->snakebody_x,firstbody->snakebody_y,100,100);
  }
    else//有蛇头蛇尾蛇身
    {
        temp->next_body=firstbody;
        firstbody=temp;
        firstbody->label_snake_body.setGeometry(firstbody->snakebody_x,firstbody->snakebody_y,100,100);
    }

    snakehead_x=snakehead_x+next_step_x();
    snakehead_y=snakehead_y+next_step_y();
    label_snake_head.setGeometry(snakehead_x,snakehead_y,100,100);
    delete temp;
}
void Snake::show()
{
    label_snake_head.setGeometry(snakehead_x,snakehead_y,100,100);
}


Snake::~Snake()
{

    snakebody* first=firstbody;
    for(snakebody* next=first->next_body;next!=nullptr;next=next->next_body)
    {
        delete first;
        first=next;
    }
    delete first;
}
