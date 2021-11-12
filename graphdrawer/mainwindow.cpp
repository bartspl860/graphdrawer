#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    logicHandler_instance.expression = "sqrt(x)";

    logicHandler_instance.createGraph();

    //chart_view->setParent(ui->frame);
}

MainWindow::~MainWindow()
{
    delete ui;
}

