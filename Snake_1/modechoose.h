#ifndef MODECHOOSE_H
#define MODECHOOSE_H

#include <QWidget>
#include <maingame.h>

namespace Ui {
class ModeChoose;
}

class ModeChoose : public QWidget
{
    Q_OBJECT

public:
    explicit ModeChoose(QWidget *parent = nullptr);
    ~ModeChoose();

private slots:
    void on_EasyButton_clicked();

    void on_MidButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::ModeChoose *ui;
};

#endif // MODECHOOSE_H