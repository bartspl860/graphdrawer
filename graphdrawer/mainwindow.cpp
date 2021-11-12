#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);    

    constructGraph("sqrt(x)");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::constructGraph(QString exp){

    logicHandler_instance.createGraph(exp , ui->frame);
}
