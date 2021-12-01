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
    void on_add_clicked();

private:
    Ui::MainWindow *ui;
    LogicHandler logicHandler_instance;
    void constructGraph(QString name, QColor color, QString exp, ChartLimit lim, double sens, QFrame* dest);
    void constructGraphJSON(QFrame* dest);
};
#endif // MAINWINDOW_H
