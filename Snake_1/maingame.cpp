#include "maingame.h"
#include "ui_maingame.h"
#include <QKeyEvent>

MainGame::MainGame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainGame)
{
    ui->setupUi(this);
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
