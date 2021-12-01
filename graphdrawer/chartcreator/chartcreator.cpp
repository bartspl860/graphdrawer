#include "chartcreator.h"


ChartCreator::ChartCreator()
{

}

void ChartCreator::createSeries(QString name, QColor color){
    QLineSeries* temp_series = new QLineSeries();
    temp_series->setName(name);
    temp_series->setColor(color);

    all_series.push_front(temp_series);

    Q_UNUSED(temp_series);
}

void ChartCreator::addPoint(QPointF p){    
    all_series.first()->append(p);    
}

void ChartCreator::createChart(QFrame* frame){

    ///////////////////////////////
    /// Pozdrawiam użytkowników c++
    /// Znam wasz ból...
    //////////////////////////////

    chart = new QChart();      

    foreach(auto v, all_series){       
        chart->addSeries(v);
    }
    chart->legend()->show();
    chart->createDefaultAxes();

    QChartView* chart_view = new QChartView();
    chart_view->setChart(chart);
    chart_view->setRenderHint(QPainter::Antialiasing);


    chart_view->setParent(frame);

    Q_UNUSED(chart_view);
    Q_UNUSED(chart);
}

void ChartCreator::addSeriesFromJSONFile(){
    std::ifstream input(":/input.json");
    QLineSeries* s;

    if(input.is_open()){

        qDebug() << "Tutaj";

        json data;
        input >> data;

        //QString name(data["Name"]);

        foreach(auto value, data["list"]){
            QPointF p(value["x"], value["y"]);
            s->append(p);
        }

    }

    all_series.push_front(s);

    qDebug() << s->points();

    Q_UNUSED(s);
}
