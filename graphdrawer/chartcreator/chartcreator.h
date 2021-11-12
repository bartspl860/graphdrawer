#ifndef CHARTCREATOR_H
#define CHARTCREATOR_H

#include <QList>
#include <QtCharts>


class ChartCreator
{

public:
    ChartCreator();
private:
    QLineSeries series;
public:
    void addPoint(QPointF p);
    void getChart();
};

#endif // CHARTCREATOR_H
