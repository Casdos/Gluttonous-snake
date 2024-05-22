#ifndef FOOD_H
#define FOOD_H
#include<QLabel>
const int unit_step=100;
const int size=100;
class food
{
public:
    int food_x;
    int food_y;
    food* nextfood;
    food* lastfood;
    food(int x,int y);
    bool iscrashed(int x,int y);
    QLabel label_food;

};

#endif // FOOD_H
