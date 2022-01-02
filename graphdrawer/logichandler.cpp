#include "logichandler.h"
#include "parser/error.h"

LogicHandler::LogicHandler(QObject *parent) : QObject(parent){}

char* LogicHandler::getExpressionResult(QString exp, double x){
    QString new_exp;
    QString x_as_qstring = QString::number(x); //convert x to QString

    foreach(QChar exp_it, exp){ //it -> iterator
        if(exp_it == "x" || exp_it == "X"){ //add elements to new array till you find x, only then add QString x
            new_exp.push_back("(");
            foreach(QChar x_it, x_as_qstring){
                new_exp.push_back(x_it);
            }
            new_exp.push_back(")");
        }
        else{
            new_exp.push_back(exp_it);
        }
    }

    QByteArray bytes = new_exp.toLocal8Bit(); //convert QString to 8bytes
    const char *prep_exp = bytes.data(); //convert to const char*

    return parser_instance.parse(prep_exp); //parse expression and get result
}

void LogicHandler::createGraph(QString name, QColor color, QString expression,
                               ChartLimit limit, double axix_x_sensitivity)
{
    QVector<QPointF> data;
    double iterator = limit.getL();

    try{
        while(iterator <= limit.getR()){
            char* string_y = getExpressionResult(expression, iterator);
            double y = atof(string_y);

            if(y < limit.getD() || y > limit.getU() || !strcmp(string_y, "inf")){
                iterator+=axix_x_sensitivity;
                continue;
            }
            data.push_back(QPointF(iterator, y));

            iterator += axix_x_sensitivity;
            iterator = round( iterator * 1000.0 ) / 1000.0;
        }
    }
    catch(Error& error){
        QMessageBox::critical(nullptr, "Error", error.get_msg());
        return;
    }

    if(list_at_start){
        logic_combo->clear(); list_at_start = false;
    }

    if(name.isEmpty())
        logic_combo->addItem(expression);
    else
        logic_combo->addItem(name);

    chartCreator_instance.createSeries(name, color, limit, axix_x_sensitivity, expression);

    foreach(auto value, data){
        chartCreator_instance.addPoint(value);
    }

    chartCreator_instance.createGraph(logic_plot);
}

void LogicHandler::getSelectedGraph(){
    int i=0;
    foreach(auto value, chartCreator_instance.all_graphs){
        if(value->selected()){
            lastly_selected_graph = i;
            break;
        }
        i++;
    }
    logic_combo->setCurrentIndex(lastly_selected_graph);
}

void LogicHandler::delete_selected_plot(){
    if(chartCreator_instance.all_series.empty())
        return;
    if(lastly_selected_graph == -1)
        return;

    logic_combo->removeItem(lastly_selected_graph);
    chartCreator_instance.all_series.erase(
                chartCreator_instance.all_series.begin()+lastly_selected_graph);
    chartCreator_instance.createGraph(logic_plot);
    if(logic_combo->count() == 0){
        list_at_start = true;
        logic_combo->addItem("Empty");
    }
    lastly_selected_graph = -1;
}

void LogicHandler::triggerExportJSON(){
    if(lastly_selected_graph != -1){
        chartCreator_instance.insertSeriesToJSONFile(lastly_selected_graph);
        QMessageBox::information(nullptr,"Exported to json" ,tr("Done!\n"));
    }
}

void LogicHandler::triggerImportJSON(const QString &file){
    if(list_at_start){
        logic_combo->clear(); list_at_start = false;
    }
    chartCreator_instance.addSeriesFromJSONFile(file, logic_plot, logic_combo);
}
