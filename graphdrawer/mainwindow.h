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

private:
    Ui::MainWindow *ui;
    LogicHandler logicHandler_instance;
    QColorDialog* color_picker;
    QColor current_color = Qt::black;
};
#endif // MAINWINDOW_H
