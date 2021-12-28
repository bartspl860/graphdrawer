#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "essentials.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowFlags(windowFlags() | Qt::CustomizeWindowHint |
                                   Qt::WindowMinimizeButtonHint |
                                   Qt::WindowMaximizeButtonHint |
                                   Qt::WindowCloseButtonHint);

    connect(ui->plot, &QCustomPlot::selectionChangedByUser, this, &MainWindow::getSelect);

    color_picker = new QColorDialog();
    color_picker->hide();
    connect(color_picker, &QColorDialog::colorSelected, this, &MainWindow::getColor);
    connect(color_picker, &QColorDialog::rejected, this, &MainWindow::onColorDestroy);

    essentials::setLabelColor(ui->label_color, Qt::black);
}

void MainWindow::getSelect(){
    logicHandler_instance.getSelectedGraph();
}

MainWindow::~MainWindow()
{
    color_picker->deleteLater();
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
                ui->function_name->displayText(), current_color,
                ui->function_source->displayText(),
                ChartLimit(-1000,1000,1000,-1000),
                0.1, ui->plot, ui->function_list);

    ui->function_name->clear();
    ui->function_source->clear();
    current_color = Qt::black;
    essentials::resetLabelColor(ui->label_color);
}

void MainWindow::on_delete_selected_graph_clicked()
{
    logicHandler_instance.delete_selected_plot();
}


void MainWindow::on_pick_color_clicked()
{
    color_picker->show();
    this->hide();
}

void MainWindow::getColor(const QColor& color){
    current_color = color;
    color_picker->hide();
    this->show();

    essentials::setLabelColor(ui->label_color, color);
}

void MainWindow::onColorDestroy(){
    color_picker->hide();
    this->show();
}

