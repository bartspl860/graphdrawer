#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);    

    constructGraph("Wykres 1" ,"sin(4)/x", ChartLimit(-10,10,10,-10), 0.1, ui->frame);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::constructGraph(QString name, QString exp, ChartLimit lim, double sens, QFrame* dest){

    logicHandler_instance.createGraph(name, exp, lim, sens, dest);
}
