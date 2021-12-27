#ifndef CHARTCREATOR_H
#define CHARTCREATOR_H

#include <QVector>
#include <QtCharts>
#include <fstream>
#include "json.hpp"
#include "qcustomplot.h"
#include "essentials.h"

using json = nlohmann::json;



class ChartCreator
{

public:
    ChartCreator();
    ~ChartCreator();
private:
    QVector<Series> all_series;
public:
    void createSeries(QString name, QColor color, ChartLimit limit, double axix_sen);
    void addPoint(QPointF p);
    void createGraph(QCustomPlot* frame);
    void addSeriesFromJSONFile();
};

#endif // CHARTCREATOR_H
