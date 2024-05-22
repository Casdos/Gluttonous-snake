QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    food.cpp \
    foodlist.cpp \
    main.cpp \
    maingame.cpp \
    modechoose.cpp \
    snake.cpp \
    snakelist.cpp \
    widget_1.cpp

HEADERS += \
    food.h \
    foodlist.h \
    maingame.h \
    modechoose.h \
    snake.h \
    snakelist.h \
    widget.h

FORMS += \
    maingame.ui \
    modechoose.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pic1.qrc \
    pic2.qrc \
    pic3.qrc \
    snakephoto.qrc

DISTFILES += \
    1.jpg
