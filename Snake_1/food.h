#ifndef FOOD_H
#define FOOD_H

const int unit_step=10;
class food
{
public:
    int food_x;
    int food_y;
    food* nextfood;
    food* lastfood;
    food(int x,int y);
    bool iscrashed(int x,int y);
};
class Foodlist
{
private:
    food* firstfood;
public:
    Foodlist();
    void addfood(int x,int y);
    void deletefood(food* food);
    bool iscrashed(int x,int y);
};
#endif // FOOD_H
