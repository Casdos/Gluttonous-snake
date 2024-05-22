#include "snake.h"
snakebody::snakebody(int x,int y,QWidget* parent):snakebody_x(x),snakebody_y(y),next_body(nullptr),last_body(nullptr)
{
    label_snake_body.setPixmap(QPixmap(":/photo/h_body.png"));
    label_snake_body.setParent(parent);
    label_snake_tail.setPixmap(QPixmap(":/photo/tailright.png"));
    label_snake_tail.setParent(parent);
}
Snake::Snake(int x,int y,QWidget* parent):unit_step(unit_step_length),snakehead_x(x),snakehead_y(y),direction(0),length(1),nextsnake(nullptr),lastsnake(nullptr),parent(parent)
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
        if(firstbody!=nullptr)
        {
            while(1)
            {
                snakebody* temp=firstbody;
                if(temp->snakebody_x>x-unit_step&&temp->snakebody_x<x+unit_step&&temp->snakebody_y>y-unit_step&&temp->snakebody_y<y+unit_step)
                    return true;
                if(temp->next_body==nullptr)
                    break;
                temp=temp->next_body;
            }
        }
    }
    return false;
}
int Snake::next_snakehead_x()//遇到了很傻逼的bug

{
    qreal radian=3.14159265359*direction / 180.0;
    return snakehead_x+int(unit_step*qCos(radian));//pi/180
}
int Snake::next_snakehead_y()
{
    qreal radian=3.14159265359*direction / 180.0;
    return snakehead_y-int(unit_step*qSin(radian));//pi/180
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
    snakehead_x=next_snakehead_x();
    snakehead_y=next_snakehead_y();
    label_snake_head.setGeometry(snakehead_x,snakehead_y,100,100);
}
void Snake::updata_food()
{
    length+=1;
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

    snakehead_x=next_snakehead_x();
    snakehead_y=next_snakehead_y();
    label_snake_head.setGeometry(snakehead_x,snakehead_y,100,100);
delete temp;
}
void Snake::show()
{
    label_snake_head.setGeometry(snakehead_x,snakehead_y,100,100);
}
//     void Snake::changedirection(int target)//自由方向移动
// {
//         int difference=target-direction;
//         if(difference<0)
//             difference+=360;
//         if(difference<10||difference>350)
//             direction=target;
//         else
//         {

//             if(difference>180)
//             {
//                 direction-=5;
//             }
//             else
//             {
//                 direction+=5;
//             }
//         }
//         if(direction>359)
//             direction-=360;
// }
void Snake::changedirection(int target)
{
    direction=target;
}
Snake::~Snake()
{
    if(firstbody==nullptr)//只有蛇头
    {

    }
    else
    {
        snakebody* first=firstbody;
        if(firstbody->next_body==nullptr)//只有蛇尾
        {
            delete first;
        }
        else
        {
            for(snakebody* next=first->next_body;next!=nullptr;next=next->next_body)
            {
                delete first;
                first=next;
            }
            delete first;
        }
    }
}

