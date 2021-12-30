#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "essentials.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    this->setStyleSheet("background-color:#2F4F4F;");




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

    ui->plot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->plot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);

    ui->plot->replot();

}

void MainWindow::getSelect(){
    logicHandler_instance.getSelectedGraph();
}

MainWindow::~MainWindow()
{
    color_picker->deleteLater();
    delete ui;
}



void MainWindow::on_addchart_clicked()
{
    logicHandler_instance.createGraph(
                ui->function_name->displayText(), current_color,
                ui->function_source->displayText(),
                ChartLimit(-10,10,10,-10),
                0.1, ui->plot, ui->function_list);

    ui->function_name->clear();
    ui->function_source->clear();
    current_color = Qt::black;
    essentials::resetLabelColor(ui->label_color);
}

void MainWindow::on_delete_selected_graph_clicked()
{

    QMessageBox::StandardButton resBtn = QMessageBox::question(nullptr,"U Sure M8?" ,
                                                                    tr("U Sure M8?\n"),
                                                                    QMessageBox::Cancel | QMessageBox::Yes);
    if (resBtn == QMessageBox::Cancel)
        {
            QMessageBox().close();

        }
        else if (resBtn == QMessageBox::Yes)
        {
            logicHandler_instance.delete_selected_plot();
        }


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


void MainWindow::on_checkBox_stateChanged(int state)
{
    if(state){
        QLinearGradient plotGradient;
        plotGradient.setStart(0, 0);
        plotGradient.setFinalStop(0, 350);
        plotGradient.setColorAt(0, QColor(80, 80, 80));
        plotGradient.setColorAt(1, QColor(50, 50, 50));

        ui->plot->setBackground(plotGradient);

        ui->plot->xAxis->setBasePen(QPen(Qt::white, 1));
        ui->plot->yAxis->setBasePen(QPen(Qt::white, 1));

        ui->plot->xAxis->setTickLabelColor(Qt::white);
        ui->plot->yAxis->setTickLabelColor(Qt::white);

        ui->plot->xAxis->setSubTickPen(QPen(Qt::white, 1));
        ui->plot->yAxis->setSubTickPen(QPen(Qt::white, 1));
    }
    else{
        ui->plot->setBackground(QLinearGradient());

        ui->plot->xAxis->setBasePen(QPen(Qt::black, 1));
        ui->plot->yAxis->setBasePen(QPen(Qt::black, 1));

        ui->plot->xAxis->setTickLabelColor(Qt::black);
        ui->plot->yAxis->setTickLabelColor(Qt::black);

        ui->plot->xAxis->setSubTickPen(QPen(Qt::black, 1));
        ui->plot->yAxis->setSubTickPen(QPen(Qt::black, 1));
    }


    ui->plot->replot();
}


void MainWindow::on_exp_clicked()
{
    ui->plot->saveBmp("xd.png",1000,1000);
}


