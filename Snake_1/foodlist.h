#ifndef FOODLIST_H
#define FOODLIST_H
#include <QRandomGenerator>
#include"food.h"

class Foodlist
{
private:
    int xmax;//设置边界
    int ymax;
    int xmin;
    int ymin;
    food* firstfood;
public:
    QWidget* parent;
    Foodlist();
    void addfood(int x,int y);
    void addfood_r();//0-xmax
    void deletefood(food* food);//如果食物数量少于2，由于指针问题会出bug，但食物数量恒定情况下不需修改
    food* iscrashed(int x,int y);//找到返回，找不到返回空
    void updata_food(food* eatedfood);
    void initialize(int xma,int yma,int xmi,int ymi,QWidget* parent=nullptr,int number=5);
    void setparent(QWidget* parent);
    //缺少析构函数
};
#endif // FOODLIST_H
