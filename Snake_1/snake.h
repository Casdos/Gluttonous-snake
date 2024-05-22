#ifndef SNAKE_H
#define SNAKE_H
#include <QtMath>
#include<QLabel>
#include<qdebug.h>
const int initial_length=3;
const int unit_step_length=10;


class snakebody
{
public:
    int snakebody_x;
    int snakebody_y;
    snakebody* next_body;//从蛇头开始，向蛇尾方向
    snakebody* last_body;
    snakebody(int x,int y,QWidget* parent=nullptr);
    QLabel label_snake_body;
    QLabel label_snake_tail;

};

class Snake//蛇
{
private:
    QWidget* parent;
    int unit_step;//单位步长，通过这个控制速度
    int snakehead_x;
    int snakehead_y;
    snakebody* firstbody;
    snakebody* lastbody;
    int length;//蛇长度（包括蛇头）
    QLabel label_snake_head;
    int direction;//以向右为0，右上的角度


public:

    Snake(int x,int y,QWidget* parent=nullptr);
    bool iscrashed(int x,int y);//该坐标是否与蛇碰撞，通过检查距离是否小于单位步长得到
    int next_snakehead_x();
    int next_snakehead_y();
    ~Snake();//析构函数，涉及delete感觉有可能出问题
    Snake* nextsnake;
    Snake* lastsnake;
    void updata_nfood();
    void updata_food();
    void show();
    void changedirection(int target);
};


#endif // SNAKE_H
