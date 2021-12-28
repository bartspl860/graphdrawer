#include "chartcreator.h"

ChartCreator::ChartCreator()
{

}

ChartCreator::~ChartCreator(){

}

void ChartCreator::createSeries(QString name, QColor color, ChartLimit limit, double axis_sen, QString exp){
    QVector<double> x, y;
    Series _series(name, color, x, y, limit, axis_sen, exp);
    all_series.push_back(_series);
}

void ChartCreator::addPoint(QPointF p){
    all_series.back().series_x.push_back(p.x());
    all_series.back().series_y.push_back(p.y());
}

void ChartCreator::createGraph(QCustomPlot* plot){

    plot->clearGraphs();
    all_graphs.clear();

    int i = 0;
    foreach(auto value, all_series){
        plot->addGraph();

        plot->graph(i)->setPen(QPen(value.getColor()));
        plot->graph(i)->setData(value.series_x, value.series_y);
        all_graphs.push_back(plot->graph(i));

        plot->xAxis->setLabel("x");
        plot->yAxis->setLabel("y");
        plot->xAxis->setRange(value.getLimit().getL(), value.getLimit().getR());
        plot->yAxis->setRange(value.getLimit().getD(), value.getLimit().getU());
        i++;
    }

    plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    plot->replot();
}

void ChartCreator::addSeriesFromJSONFile(){

}
