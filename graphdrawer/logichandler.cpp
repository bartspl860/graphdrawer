#include "logichandler.h"

LogicHandler::LogicHandler()
{

}

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
                               ChartLimit limit, double axix_x_sensitivity, QFrame* frame){
    double iterator = limit.getL();

    chartCreator_instance.createSeries(name, color);

    while(iterator <= limit.getR()){

        char* string_y = getExpressionResult(expression, iterator);
        qDebug() << expression << iterator << " " << string_y;

        double y = atof(string_y);

        if(y < limit.getD() || y > limit.getU() || !strcmp(string_y, "inf")){
            qDebug() << "Pomijam";
            iterator+=axix_x_sensitivity;
            continue;
        }

        QPointF current_point = {iterator, y};
        chartCreator_instance.addPoint(current_point);

        iterator+=axix_x_sensitivity;
        iterator = round( iterator * 1000.0 ) / 1000.0;
    }

    chartCreator_instance.createChart(frame);
}
