#ifndef MAINGAME_H
#define MAINGAME_H

#include <QWidget>

namespace Ui {
class MainGame;
}

class MainGame : public QWidget
{
    Q_OBJECT

public:
    explicit MainGame(QWidget *parent = nullptr);
    ~MainGame();

private:
    Ui::MainGame *ui;
};

#endif // MAINGAME_H
