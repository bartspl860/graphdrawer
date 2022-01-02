#include "mainwindow.h"

#include <QApplication>
#include "Tests.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    parserTest();
    parserTest2();
    parserTest3();
    parserTest4();
    parserTest5();
    return a.exec();
}
