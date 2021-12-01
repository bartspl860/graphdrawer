#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);    

    constructGraph("Wykres 1" , QColor().red(), "sinx", ChartLimit(-10,10,10,-10), 0.1, ui->frame);
    constructGraph("Wykres 2", QColor().blue(), "x", ChartLimit(-10,10,10,-10), 1, ui->frame);
    constructGraph("Wykres 3", QColor().blue(), "logx", ChartLimit(-10,10,10,-10), 0.1, ui->frame);
    constructGraph("Wykres 4", QColor().blue(), "x^3+x^2+x", ChartLimit(-10,10,10,-10), 0.1, ui->frame);
    //constructGraphJSON(ui->frame);
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
    qDebug() <<"jestem";

        QPixmap pixmap(ui->frame->size());
        ui->frame->render(&pixmap);
        pixmap.save("plik.bmp");

}

void MainWindow::constructGraphJSON(QFrame *dest){
    logicHandler_instance.createGraph(dest);
}
