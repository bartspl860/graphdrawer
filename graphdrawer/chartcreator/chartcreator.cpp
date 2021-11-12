#include "chartcreator.h"

ChartCreator::ChartCreator()
{

}

void ChartCreator::addPoint(QPointF p){
    series.append(p);
}

QChartView& ChartCreator::getChart(){
    chart.addSeries(&series);
    chart.legend()->hide();

    chart.createDefaultAxes();

    chart_view.setChart(&chart); //tu gdzieś jest coś popsute, przerób żeby instancji nie było
    return chart_view; //zrób dynamiczną alokacje
}
