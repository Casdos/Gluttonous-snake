#include "maingame.h"
#include "ui_maingame.h"

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
