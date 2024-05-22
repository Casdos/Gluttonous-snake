#include "modechoose.h"
#include "ui_modechoose.h"
#include <QTime>
ModeChoose::ModeChoose(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModeChoose)
{
    ui->setupUi(this);
}

ModeChoose::~ModeChoose()
{
    delete ui;
}

void ModeChoose::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,width(),height(),QPixmap(":/new/prefix1/2.jpg"));
}

void ModeChoose::on_EasyButton_clicked()  //简单模式
{
    MainGame *Easy = new MainGame;
    Easy -> show();
        Easy -> showFullScreen();
    QTime dieTime = QTime::currentTime().addMSecs(300);//延时300毫秒
    while (QTime::currentTime()< dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    this->hide();


}

void ModeChoose::on_MidButton_clicked()  //一般模式
{
    MainGame *Mid = new MainGame;
    Mid -> showFullScreen();
    Mid -> show();
    QTime dieTime = QTime::currentTime().addMSecs(300);//延时300毫秒
    while (QTime::currentTime()< dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    this->hide();

}

void ModeChoose::on_pushButton_3_clicked()  //困难模式
{
    MainGame *Hard = new MainGame;
    Hard -> showFullScreen();
    Hard -> show();
    QTime dieTime = QTime::currentTime().addMSecs(300);//延时300毫秒
    while (QTime::currentTime()< dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    this->hide();
}
