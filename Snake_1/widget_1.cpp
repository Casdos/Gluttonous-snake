#include "widget.h"
#include "ui_widget.h"
#include <QTime>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,width(),height(),QPixmap(":/1.jpg"));

}



void Widget::on_pushButton_clicked()
{
    ModeChoose *ui_mc = new ModeChoose;
    ui_mc->showFullScreen();
    ui_mc->show();
    QTime dieTime = QTime::currentTime().addMSecs(300);//延时300毫秒
    while (QTime::currentTime()< dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    this->hide();//主界面关闭

}
