#ifndef SNAKELIST_H
#define SNAKELIST_H
#include"snake.h"
class snakelist//蛇队列
{
private:
    Snake* firstsnake;
public:
    snakelist();
    void addsnake(int x,int y,QWidget* parent);
    void deletesnake(Snake* snake);
    bool iscrashed(int x,int y);
};

#endif // SNAKELIST_H
