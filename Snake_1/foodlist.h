#ifndef FOODLIST_H
#define FOODLIST_H
#include <QRandomGenerator>
#include"food.h"
#include<QList.h>
class Foodlist
{
private:
    QList<food> food_list;
public:
    QWidget* parent;
    Foodlist(QWidget* parent);
    void addfood(Coordinate target);
    void addfood_r();//0-xmax
    int findfood(food target);//失败返回-1
    void deletefood(int i);

    void updata_food(int eatedfood);
    void initialize(int number);
};
#endif // FOODLIST_H
