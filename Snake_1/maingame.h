#ifndef MAINGAME_H
#define MAINGAME_H

#include <QWidget>
#include <Qpainter>

namespace Ui {
class MainGame;
}

class MainGame : public QWidget
{
    Q_OBJECT

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
