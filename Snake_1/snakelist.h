#ifndef SNAKELIST_H
#define SNAKELIST_H
#include"snake.h"
class snakelist//蛇队列
{
public:
    QList<Snake> snake_list;
public:
    snakelist();
    void addsnake(int x,int y,QWidget* parent);
    void deletesnake(int target);
    bool ismatched(int x,int y);
};

#endif // SNAKELIST_H
