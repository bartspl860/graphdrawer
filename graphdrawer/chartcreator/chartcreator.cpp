#include "chartcreator.h"


ChartCreator::ChartCreator()
{

}

ChartCreator::~ChartCreator(){

}

void ChartCreator::createSeries(QString name, QColor color, ChartLimit limit, double axis_sen){
    QVector<double> x, y;
    Series _series(name, color, x, y, limit, axis_sen);
    all_series.push_front(_series);
}

void ChartCreator::addPoint(QPointF p){
    all_series.front().series_x.push_back(p.x());
    all_series.front().series_y.push_back(p.y());
}

void ChartCreator::createGraph(QCustomPlot* plot){

    plot->clearGraphs();

    int i = 0;
    foreach(auto value, all_series){
        plot->addGraph();
        plot->graph(i)->setPen(QPen(value.getColor()));
        plot->graph(i)->setData(value.series_x, value.series_y);
        plot->xAxis->setLabel("x");
        plot->yAxis->setLabel("y");
        plot->xAxis->setRange(value.getLimit().getL(), value.getLimit().getR());
        plot->yAxis->setRange(value.getLimit().getD(), value.getLimit().getU());
        i++;
    }

    plot->replot();
}

void ChartCreator::addSeriesFromJSONFile(){

}
