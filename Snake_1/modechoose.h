#ifndef MODECHOOSE_H
#define MODECHOOSE_H

#include <QWidget>
#include <maingame.h>
#include <Qpainter>

namespace Ui {
class ModeChoose;
}

class ModeChoose : public QWidget
{
    Q_OBJECT

public:
    explicit ModeChoose(QWidget *parent = nullptr);
    ~ModeChoose();
    void paintEvent(QPaintEvent *event);

private slots:
    void on_EasyButton_clicked();

    void on_MidButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::ModeChoose *ui;
};

#endif // MODECHOOSE_H
