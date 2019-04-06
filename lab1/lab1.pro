#-------------------------------------------------
#
# Project created by QtCreator 2019-02-16T19:33:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    form.cpp \
    change.cpp \
    changed.cpp \
    add.cpp \
    del.cpp \
    check.cpp \
    sort.cpp \
    sor1t.cpp

HEADERS += \
        mainwindow.h \
    form.h \
    change.h \
    changed.h \
    add.h \
    del.h \
    check.h \
    sort.h \
    sor1t.h

FORMS += \
        mainwindow.ui \
    form.ui \
    change.ui \
    changed.ui \
    add.ui \
    del.ui \
    check.ui \
    sort.ui \
    sor1t.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
