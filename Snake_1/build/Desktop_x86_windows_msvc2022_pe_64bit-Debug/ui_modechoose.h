/********************************************************************************
** Form generated from reading UI file 'modechoose.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODECHOOSE_H
#define UI_MODECHOOSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModeChoose
{
public:
    QPushButton *EasyButton;
    QPushButton *MidButton;
    QPushButton *pushButton_3;

    void setupUi(QWidget *ModeChoose)
    {
        if (ModeChoose->objectName().isEmpty())
            ModeChoose->setObjectName("ModeChoose");
        ModeChoose->resize(1200, 900);
        ModeChoose->setMinimumSize(QSize(1200, 900));
        ModeChoose->setMaximumSize(QSize(1200, 900));
        EasyButton = new QPushButton(ModeChoose);
        EasyButton->setObjectName("EasyButton");
        EasyButton->setGeometry(QRect(225, 600, 150, 50));
        MidButton = new QPushButton(ModeChoose);
        MidButton->setObjectName("MidButton");
        MidButton->setGeometry(QRect(525, 600, 150, 50));
        pushButton_3 = new QPushButton(ModeChoose);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(825, 600, 150, 50));

        retranslateUi(ModeChoose);

        QMetaObject::connectSlotsByName(ModeChoose);
    } // setupUi

    void retranslateUi(QWidget *ModeChoose)
    {
        ModeChoose->setWindowTitle(QCoreApplication::translate("ModeChoose", "Form", nullptr));
        EasyButton->setText(QCoreApplication::translate("ModeChoose", "\347\256\200\345\215\225", nullptr));
        MidButton->setText(QCoreApplication::translate("ModeChoose", "\344\270\255\347\255\211", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ModeChoose", "\345\233\260\351\232\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModeChoose: public Ui_ModeChoose {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODECHOOSE_H
