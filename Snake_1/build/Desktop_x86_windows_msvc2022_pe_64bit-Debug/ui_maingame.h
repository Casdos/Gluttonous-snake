/********************************************************************************
** Form generated from reading UI file 'maingame.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINGAME_H
#define UI_MAINGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainGame
{
public:

    void setupUi(QWidget *MainGame)
    {
        if (MainGame->objectName().isEmpty())
            MainGame->setObjectName("MainGame");
        MainGame->resize(1200, 900);
        MainGame->setMinimumSize(QSize(1200, 900));
        MainGame->setMaximumSize(QSize(1200, 900));

        retranslateUi(MainGame);

        QMetaObject::connectSlotsByName(MainGame);
    } // setupUi

    void retranslateUi(QWidget *MainGame)
    {
        MainGame->setWindowTitle(QCoreApplication::translate("MainGame", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainGame: public Ui_MainGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINGAME_H
