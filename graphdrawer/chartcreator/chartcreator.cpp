#include "chartcreator.h"


ChartCreator::ChartCreator()
{

}

void ChartCreator::createSeries(QString name, QColor color){
    QLineSeries* temp_series = new QLineSeries();
    temp_series->setName(name);
    //temp_series->setColor(color);

    all_series.push_front(temp_series);

    Q_UNUSED(temp_series);
}

void ChartCreator::addPoint(QPointF p){
    all_series.first()->append(p);
}

void ChartCreator::createChart(QFrame* frame){

    chart = new QChart();
    chart->legend()->hide();
    chart->createDefaultAxes();

    foreach(auto v, all_series){       
        chart->addSeries(v);
    }

    QChartView* chart_view = new QChartView();
    chart_view->setChart(chart);

    frame->setParent(chart_view);

    Q_UNUSED(chart_view);
    Q_UNUSED(chart);
}
