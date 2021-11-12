#include "chartcreator.h"


ChartCreator::ChartCreator()
{

}

void ChartCreator::addPoint(QPointF p){
    series.append(p);
}

void ChartCreator::createChart(QFrame* frame){

    QChart* chart = new QChart();
    chart->addSeries(&series);
    chart->legend()->hide();

    chart->createDefaultAxes();

    QChartView* chart_view = new QChartView();
    chart_view->setChart(chart); //tu gdzieś jest coś popsute, przerób żeby instancji nie było

    chart_view->setParent(frame);

    Q_UNUSED(chart);
    Q_UNUSED(chart_view);
}
