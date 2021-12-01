#include "mainwindow.h"

#include <QApplication>
#include "Tests.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    parserTest();

    return a.exec();
}
