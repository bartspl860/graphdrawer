#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);    

    constructGraph("Wykres 1" , QColor().red(),"-x", ChartLimit(-10,10,10,-10), 1, ui->frame);
    constructGraph("Wykres 2", QColor().blue(),"x", ChartLimit(-10,10,10,-10), 1, ui->frame);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::constructGraph(QString name, QColor color, QString exp, ChartLimit lim, double sens, QFrame* dest){
    logicHandler_instance.createGraph(name, color, exp, lim, sens, dest);
}

void MainWindow::on_add_clicked()
{
    qDebug() <<"gown";
    bool xd;
    if(xd)
    {
        xd=false;
        QPixmap pixmap(ui->frame->size());
        ui->frame->render(&pixmap);
        pixmap.save("gowno.bmp");
        xd=true;
    }
}

