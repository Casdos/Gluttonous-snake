#include "maingame.h"
#include "ui_maingame.h"
#include <QKeyEvent>
MainGame::MainGame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainGame)
{
    int number=5;//食物数量，默认5
    ui->setupUi(this);
    food_list.initialize(this->width(),this->height()/4,this,number);
    snakelist.addsnake(this->width()/2,this->height()/2,this);

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
     if(event->key() == Qt::Key_Escape)
     {
        this->close();
     }
}
