#ifndef MAINGAME_H
#define MAINGAME_H

#include <QWidget>
#include <Qpainter>
#include<QTimer>
#include"foodlist.h"
#include"snakelist.h"
#include<qdebug.h>
namespace Ui {
class MainGame;
}

class MainGame : public QWidget
{
    Q_OBJECT
    Foodlist food_list;
    snakelist usersnake_list;
    QTimer* timer;
public:

    explicit MainGame(QWidget *parent = nullptr);
    ~MainGame();
    void paintEvent(QPaintEvent *event);

private:
    Ui::MainGame *ui;

    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event);
public slots:
    void timeout();
};

#endif // MAINGAME_H
