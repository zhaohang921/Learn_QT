#-------------------------------------------------
#
# Project created by QtCreator 2018-05-01T11:08:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VRTrain
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    choose_mode_dialog.cpp \
    secure_tip_dialog.cpp \
    second_step_dialog.cpp \
    login_dialog.cpp \
    first_step_dialog.cpp \
    choose_steps_dialog.cpp \
    fourth_step_dialog.cpp \
    fifth_step_dialog.cpp \
    sixth_step_dialog.cpp \
    third_step_dialog.cpp

HEADERS += \
        mainwindow.h \
    choose_mode_dialog.h \
    choose_steps_dialog.h \
    first_step_dialog.h \
    login_dialog.h \
    second_step_dialog.h \
    secure_tip_dialog.h \
    fourth_step_dialog.h \
    fifth_step_dialog.h \
    sixth_step_dialog.h \
    third_step_dialog.h

FORMS += \
        mainwindow.ui \
    choose_mode_dialog.ui \
    choose_steps_dialog.ui \
    login_dialog.ui \
    secure_tip_dialog.ui \
    second_step_dialog.ui \
    first_step_dialog.ui \
    fourth_step_dialog.ui \
    fifth_step_dialog.ui \
    sixth_step_dialog.ui \
    third_step_dialog.ui
