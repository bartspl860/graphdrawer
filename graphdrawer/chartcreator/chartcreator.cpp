#include "chartcreator.h"

ChartCreator::ChartCreator()
{

}

void ChartCreator::addPoint(QPointF p){
    series.append(p);
}

void ChartCreator::getChart(){

    QChart chart;
    chart.addSeries(&series);
    chart.legend()->hide();

    chart.createDefaultAxes();

    QChartView* chart_view = new QChartView();
    chart_view->setChart(&chart); //tu gdzieś jest coś popsute, przerób żeby instancji nie było


    //return chart_view; //zrób dynamiczną alokacje
}
