#ifndef CHARTCREATOR_H
#define CHARTCREATOR_H

#include <QVector>
#include <QtCharts>
#include <QPixmap>
class ChartCreator
{

public:
    ChartCreator();
private:
    QChart* chart;
    QVector<QLineSeries*> all_series;
public:
    void createSeries(QString name, QColor color);
    void addPoint(QPointF p);
    void createChart(QFrame* frame);
};

#endif // CHARTCREATOR_H
