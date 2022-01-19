#include "chartcreator.h"

ChartCreator::ChartCreator(){}
ChartCreator::~ChartCreator(){}

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

void ChartCreator::addSeriesFromJSONFile(const QString& file, QCustomPlot* plot, QComboBox* combo){

    std::string file_name = file.toLocal8Bit().constData();
    std::ifstream reader(file_name);

    try{
        json j;
        reader >> j;
        reader.close();

        if(j["Data"]["x"].size() != j["Data"]["y"].size())
            throw std::logic_error("Amount of X does not equal Y");

        std::string name = j["Name"];
        std::string color_hex = j["Color"];
        QColor color; color.setNamedColor(QString::fromUtf8(color_hex.c_str()));
        ChartLimit lim = ChartLimit(
                j["Limit"]["Left"],
                j["Limit"]["Right"],
                j["Limit"]["Up"],
                j["Limit"]["Down"]);
        double axis_sensitivity = j["Sensitivity"];

        createSeries(QString::fromUtf8(name.c_str()), color, lim, axis_sensitivity, "from JSON");

        for(int i=0; i < j["Data"]["x"].size(); i++){
            addPoint(QPointF(j["Data"]["x"][i], j["Data"]["y"][i]));
        }

        if(name != "")
            combo->addItem(QString::fromUtf8(name.c_str()));
        else
            combo->addItem(file);

        createGraph(plot);
    }
    catch(json::exception& e){
        QMessageBox::critical(nullptr, "Error", e.what());
    }
    catch(std::logic_error& e){
        QMessageBox::critical(nullptr, "Error", e.what());
    }
}

void ChartCreator::insertSeriesToJSONFile(int selected_graph){

    json j;
    Series series = all_series[selected_graph];

    j["Name"] = (series.getName().toLocal8Bit().constData());
    j["Sensitivity"] = (series.getSen());
    j["Color"] = (series.getColor().name().toLocal8Bit().constData());
    j["Limit"]["Left"] = series.getLimit().getL();
    j["Limit"]["Right"] = series.getLimit().getR();
    j["Limit"]["Down"] = series.getLimit().getD();
    j["Limit"]["Up"] = series.getLimit().getU();

    int lim = all_series[selected_graph].series_x.size()-1;

    for(int i=0; i<=lim; i++){
        j["Data"]["x"] += series.series_x[i];
        j["Data"]["y"] += series.series_y[i];
    }

    std::ofstream writer;
    writer.open("data.json", std::ifstream::trunc);
    writer << j.dump(4);
}

void ChartCreator::exportPNG(QCustomPlot* plot){
    plot->savePng("graph.png",1000,1000);
    QMessageBox::information(nullptr,"Exported to png" ,QMessageBox::tr("Done!\n"));
}
