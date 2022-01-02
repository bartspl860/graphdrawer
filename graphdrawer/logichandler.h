#ifndef LOGICHANDLER_H
#define LOGICHANDLER_H

#include "parser/parser.h"
#include "chartcreator/chartcreator.h"
#include <QtDebug>
#include <QMainWindow>
#include <QMessageBox>
#include "qcustomplot.h"
#include "container_classes.h"

class LogicHandler : public QObject
{
    Q_OBJECT
    friend class MainWindow;
public:
    explicit LogicHandler(QObject *parent = nullptr);
    void createGraph(QString name, QColor color, QString exp, ChartLimit lim, double sens);
    char* getExpressionResult(QString, double);
    void getSelectedGraph();
    void delete_selected_plot();
    void triggerExportJSON();
    void triggerImportJSON(const QString& file);
private:
    bool list_at_start = true;
    Parser parser_instance;
    ChartCreator chartCreator_instance;
    int lastly_selected_graph = -1;
    QCustomPlot* logic_plot;
    QComboBox* logic_combo;

};
#endif // LOGICHANDLER_H
