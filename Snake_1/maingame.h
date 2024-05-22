#ifndef MAINGAME_H
#define MAINGAME_H

#include <QWidget>
#include <Qpainter>
#include<QTimer>
#include"foodlist.h"
#include"snakelist.h"
namespace Ui {
class MainGame;
}

class MainGame : public QWidget
{
    Q_OBJECT
    Foodlist food_list;
    snakelist snakelist;
public:

    explicit MainGame(QWidget *parent = nullptr);
    ~MainGame();
    void paintEvent(QPaintEvent *event);

private:
    Ui::MainGame *ui;

    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event);

};

#endif // MAINGAME_H
