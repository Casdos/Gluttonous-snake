#include "modechoose.h"
#include "ui_modechoose.h"

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

void ModeChoose::on_EasyButton_clicked()
{
    this->close();
    MainGame *ui_mg = new MainGame;
    ui_mg -> show();
}

void ModeChoose::on_MidButton_clicked()
{
    this->close();
    MainGame *ui_mg = new MainGame;
    ui_mg -> show();
}

void ModeChoose::on_pushButton_3_clicked()
{
    this->close();
    MainGame *ui_mg = new MainGame;
    ui_mg -> show();
}
