#include "maingame.h"
#include "ui_maingame.h"
#include <QKeyEvent>
MainGame::MainGame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainGame)
{
    int time=20;
    int number=5;//食物数量，默认5
    ui->setupUi(this);
    food_list.initialize(this->width(),this->height()/4,0,0,this,number);
    usersnake_list.addsnake(this->width()/2,this->height()/2,this);
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeout()));
    timer->start(time);

}

MainGame::~MainGame()
{
    delete ui;
}

void MainGame::paintEvent(QPaintEvent *event)
{
     QPainter painter(this);
    painter.drawPixmap(0,0,width(),height(),QPixmap(":/new/prefix1/3.jpg"));
 }


 void MainGame::keyPressEvent(QKeyEvent *event)
 {
     switch(event->key())
     {
     case  Qt::Key_Escape:
         this->close();
         break;
     case Qt::Key_W:
     {
         usersnake_list.firstsnake->changedirection(90);
     }
     break;
     case Qt::Key_S:
     {
         usersnake_list.firstsnake->changedirection(270);
     }
     break;
     case Qt::Key_A:
     {
         usersnake_list.firstsnake->changedirection(180);
     }
     break;
     case Qt::Key_D:
     {
         usersnake_list.firstsnake->changedirection(0);
     }
     break;


     }
 }
     void MainGame::timeout()
     {
    for(Snake* temp=usersnake_list.firstsnake;temp!=nullptr;temp=temp->nextsnake)
    {
        food* tempfood=food_list.iscrashed(temp->next_snakehead_x(),temp->next_snakehead_y());
        if(tempfood!=nullptr)
        {

            temp->updata_food();
            food_list.updata_food(tempfood);
        }
        else
        {
            if(usersnake_list.iscrashed(temp->next_snakehead_x(),temp->next_snakehead_y()))
            {
                usersnake_list.deletesnake(temp);
            }
            else
            {
                temp->updata_nfood();
            }
        }
    }
}
