#ifndef SNAKE_H
#define SNAKE_H
#include<QLabel>
#include<coordinate.h>
#include<qdebug.h>
const int initial_length=3;

class snakebody
{
public:
    int direction;
    Coordinate body;
    snakebody(int x,int y,QWidget* parent=nullptr);
    QLabel label_snake_body;
    QLabel label_snake_tail;
    bool ismatched(snakebody& other);
    void show();//未写
};

class Snake//蛇
{
private:
    QWidget* parent;
    Coordinate snakehead;
    QList<snakebody> snake_body_list;
    int length;//蛇长度（包括蛇头）
    QLabel label_snake_head;
    int direction;//0123,右上左下

public:

    Snake(int x,int y,QWidget* parent=nullptr);
    bool iscrashed(int x,int y);
    void updata_nfood();
    void updata_food();
    Coordinate nexthead();
    void changedirection(int target);
    void show();//未写
};


#endif // SNAKE_H
