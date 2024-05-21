#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget widget_1;
    widget_1.showFullScreen();
    widget_1.show();
    return a.exec();
}
