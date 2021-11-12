#ifndef CHARTCREATOR_H
#define CHARTCREATOR_H

#include <QList>
#include <QtCharts>


class ChartCreator
{

public:
    ChartCreator();
private:
    QChart chart;
    QChartView chart_view;
    QLineSeries series;
public:
    void addPoint(QPointF p);
    QChartView& getChart();
};

#endif // CHARTCREATOR_H
