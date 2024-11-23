QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
    ui 

RESOURCES += \
    resources.qrc

SOURCES += \
    App.cpp \
    Profile.cpp \
    Radotech.cpp \
    ui/main.cpp \
    ui/mainwindow.cpp \
    ui/measurewidget.cpp \
    ui/profileswidget.cpp \
    ui/radotechwidget.cpp

HEADERS += \
    App.h \
    Profile.h \
    Radotech.h \
    ui/mainwindow.h \
    ui/measurewidget.h \
    ui/profileswidget.h \
    ui/radotechwidget.h

FORMS += \
    ui/mainwindow.ui \
    ui/measurewidget.ui \
    ui/profileswidget.ui \
    ui/radotechwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target