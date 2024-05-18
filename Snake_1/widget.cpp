#include "widget.h"
#include "ui_widget.h"
#include <QTime>>
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
    ui_mc->show();
    this->hide();
}
