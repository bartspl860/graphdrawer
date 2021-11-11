#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString exp = "sin(x)+x^2+20x^4";
    qDebug() << logicHandler_instance.getResult(exp, 4);
}

MainWindow::~MainWindow()
{
    delete ui;
}

