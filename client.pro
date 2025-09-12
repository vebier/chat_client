QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

QMAKE_PROJECT_DEPTH = 0


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/httpmgr.cpp \
    src/global.cpp \
    src/register_dialog.cpp \
    src/login_dialog.cpp \
    main.cpp \
    src/mainwindow.cpp

HEADERS += \
    include/httpmgr.h \
    include/global.h \
    include/mainwindow.h \
    include/login_dialog.h \
    include/register_dialog.h \
    include/singleton.h

FORMS += \
    ui/register_dialog.ui \
    ui/login_dialog.ui \
    ui/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rc.qrc

DISTFILES +=
