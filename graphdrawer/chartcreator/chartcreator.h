#ifndef CHARTCREATOR_H
#define CHARTCREATOR_H

#include <QVector>
#include <QtCharts>
#include <fstream>
#include "json.hpp"
#include "qcustomplot.h"
#include "container_classes.h"

using json = nlohmann::json;

class ChartCreator
{
    friend class LogicHandler;

public:
    ChartCreator();
    ~ChartCreator();
private:
    QVector<Series> all_series;
    QVector<QCPGraph*> all_graphs;
public:
    void createSeries(QString name, QColor color, ChartLimit limit, double axix_sen, QString exp);
    void addPoint(QPointF p);
    void createGraph(QCustomPlot* frame);
    void addSeriesFromJSONFile(const QString& file, QCustomPlot* plot, QComboBox* combo);
    void insertSeriesToJSONFile(int selected_graph);
};

#endif // CHARTCREATOR_H
