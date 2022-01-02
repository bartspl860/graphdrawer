#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtDebug>
#include "logichandler.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addchart_clicked();
    void getSelect();
    void on_delete_selected_graph_clicked();
    void on_pick_color_clicked();
    void getColor(const QColor&);
    void onColorDestroy();
    void on_checkBox_stateChanged(int arg1);
    void on_exp_clicked();
    void on_export_json_clicked();
    void on_import_json_clicked();
    void getJSONFile(const QString &file);

    void on_x_limit_negative_valueChanged(double arg1);

    void on_y_limit_negative_valueChanged(double arg1);

    void on_x_limit_positive_valueChanged(double arg1);

    void on_y_limit_positive_valueChanged(double arg1);

private:
    Ui::MainWindow *ui;
    LogicHandler logicHandler_instance;
    QColorDialog* color_picker;
    QColor current_color = Qt::black;
    QFileDialog* file_dialog;
};
#endif // MAINWINDOW_H
