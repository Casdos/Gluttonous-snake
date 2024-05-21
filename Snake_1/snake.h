#ifndef SNAKE_H
#define SNAKE_H
#include <QtMath>

const int initial_length=3;


class snakebody
{
public:
    int snakebody_x;
    int snakebody_y;
    snakebody* nextbody;//从蛇头开始，向蛇尾方向
    snakebody(int x,int y);

};

class Snake//蛇
{
private:
    int unit_step;//单位步长，通过这个控制速度
    int snakehead_x;
    int snakehead_y;
    snakebody* firstbody;
    snakebody* lastbody;
    int direction;//以向右为0，右上的角度
    int length;//蛇长度（包括蛇头）


public:
    Snake(int x,int y);//生成蛇长度为3，方向朝右
    bool iscrashed(int x,int y);//该坐标是否与蛇碰撞，通过检查距离是否小于单位步长得到
    int next_step_x();
    int next_step_y();
    ~Snake();//析构函数，涉及delete感觉有可能出问题
    Snake* nextsnake;
    Snake* lastsnake;
};
class snakelist//蛇队列
{
private:
    Snake* firstsnake;
public:
    snakelist();
    void addsnake(int x,int y);
    void deletesnake(Snake* snake);
    bool iscrashed(int x,int y);
};

#endif // SNAKE_H
