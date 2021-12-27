#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);        
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::on_add_clicked()
{
    qDebug() <<"jestem";

        QPixmap pixmap(ui->frame->size());
        ui->frame->render(&pixmap);
        pixmap.save(QDir::currentPath()+"/plik.bmp");
}*/

void MainWindow::on_addchart_clicked()
{
    logicHandler_instance.createGraph(
                "name", QColor().red(), ui->function_source->toPlainText(), ChartLimit(-10,10,10,-10), 0.1, ui->plot);
}

