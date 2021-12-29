QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11
QT += charts

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chartcreator/chartcreator.cpp \
    logichandler.cpp \
    main.cpp \
    mainwindow.cpp \
    parser/error.cpp \
    parser/functions.cpp \
    parser/parser.cpp \
    parser/variablelist.cpp \
    parser/variablelist.cpp \
    qcustomplot.cpp

HEADERS += \
    Tests.h \
    chartcreator/chartcreator.h \
    container_classes.h \
    essentials.h \
    json.hpp \
    logichandler.h \
    mainwindow.h \
    parser/constants.h \
    parser/error.h \
    parser/functions.h \
    parser/parser.h \
    parser/variablelist.h \
    parser/variablelist.h \
    qcustomplot.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

RC_ICONS = icon.ico
