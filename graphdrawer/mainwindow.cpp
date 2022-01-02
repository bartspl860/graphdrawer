#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "essentials.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    logicHandler_instance.logic_plot = ui->plot;
    logicHandler_instance.logic_combo = ui->function_list;

    this->setStyleSheet("background-image:url(:/bg.jpg);");

    setWindowFlags(windowFlags() | Qt::CustomizeWindowHint |
                                   Qt::WindowMinimizeButtonHint |
                                   Qt::WindowMaximizeButtonHint |
                                   Qt::WindowCloseButtonHint);

    connect(ui->plot, &QCustomPlot::selectionChangedByUser, this, &MainWindow::getSelect);

    color_picker = new QColorDialog();
    color_picker->hide();
    connect(color_picker, &QColorDialog::colorSelected, this, &MainWindow::getColor);
    connect(color_picker, &QColorDialog::rejected, this, &MainWindow::onColorDestroy);

    file_dialog = new QFileDialog();
    file_dialog->setNameFilter(tr("JSON files (*.json)"));
    file_dialog->hide();
    connect(file_dialog, &QFileDialog::fileSelected, this, &MainWindow::getJSONFile);
    connect(file_dialog, &QFileDialog::rejected, this, &MainWindow::onFileDestroy);

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
    file_dialog->deleteLater();
    delete ui;
}


void MainWindow::on_addchart_clicked()
{
    logicHandler_instance.createGraph(
                ui->function_name->displayText(),
                current_color,
                ui->function_source->displayText(),
                ChartLimit(ui->x_limit_negative->value(),
                           ui->x_limit_positive->value(),
                           ui->y_limit_positive->value(),
                           ui->y_limit_negative->value()),
                           ui->graph_frequency->value());

    ui->function_name->clear();
    ui->function_source->clear();
    current_color = Qt::black;
    essentials::resetLabelColor(ui->label_color);
}

void MainWindow::on_delete_selected_graph_clicked()
{
    QMessageBox::StandardButton resBtn = QMessageBox::question(nullptr,"Delete?" ,
                                                                    tr("Are You sure, that you want to delete this chart?\n"),
                                                                    QMessageBox::Cancel | QMessageBox::Yes);
    if (resBtn == QMessageBox::Cancel)
        QMessageBox().close();
    else if (resBtn == QMessageBox::Yes)
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

void MainWindow::onFileDestroy(){
    file_dialog->hide();
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

        essentials::setGraphTheme(plotGradient, Qt::white, ui->plot);
    }
    else{
        essentials::setGraphTheme(QLinearGradient(), Qt::black, ui->plot);
    }

    ui->plot->replot();
}

void MainWindow::on_exp_clicked()
{
    ui->plot->saveBmp("graph.png",1000,1000);
}

void MainWindow::on_export_json_clicked()
{
    logicHandler_instance.triggerExportJSON();    
}

void MainWindow::on_import_json_clicked()
{
    this->hide();
    file_dialog->show();
}

void MainWindow::getJSONFile(const QString& file){
    this->show();

    logicHandler_instance.triggerImportJSON(file);
}

void MainWindow::on_x_limit_negative_valueChanged(double arg)
{
    Q_UNUSED(arg);

    if(ui->x_limit_negative->value() >= ui->x_limit_positive->value())
        ui->x_limit_positive->setValue(ui->x_limit_negative->value()+1);
}

void MainWindow::on_y_limit_negative_valueChanged(double arg)
{
    Q_UNUSED(arg);

    if(ui->y_limit_negative->value() >= ui->y_limit_positive->value())
        ui->y_limit_positive->setValue(ui->y_limit_negative->value()+1);
}

void MainWindow::on_x_limit_positive_valueChanged(double arg)
{
    Q_UNUSED(arg);

    if(ui->x_limit_positive->value() <= ui->x_limit_negative->value())
        ui->x_limit_negative->setValue(ui->x_limit_positive->value()-1);
}

void MainWindow::on_y_limit_positive_valueChanged(double arg)
{
    Q_UNUSED(arg);

    if(ui->y_limit_positive->value() <= ui->y_limit_negative->value())
        ui->y_limit_negative->setValue(ui->y_limit_positive->value()-1);
}
