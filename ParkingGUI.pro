QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AdministratorParkingu.cpp \
    Bilet.cpp \
    Kierowca.cpp \
    MiejsceParkingowe.cpp \
    SystemParkingowy.cpp \
    admindialog.cpp \
    main.cpp \
    mainwindow.cpp \
    startdialog.cpp

HEADERS += \
    AdministratorParkingu.h \
    Bilet.h \
    Kierowca.h \
    MiejsceParkingowe.h \
    SystemParkingowy.h \
    admindialog.h \
    mainwindow.h \
    startdialog.h

FORMS += \
    admindialog.ui \
    mainwindow.ui \
    startdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
