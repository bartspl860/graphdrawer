#include "logichandler.h"

LogicHandler::LogicHandler()
{
    limit.setLimit(-10,10,10,-10);
}

double LogicHandler::getExpressionResult(QString exp, double x){

    QString new_exp;
    QString x_as_qstring = QString::number(x); //convert x to QString

    foreach(QChar exp_it, exp){ //it -> iterator
        if(exp_it == "x" || exp_it == "X"){ //add elements to new array till you find x, only then add QString x
            foreach(QChar x_it, x_as_qstring){
                new_exp.push_back(x_it);
            }
        }
        else{
            new_exp.push_back(exp_it);
        }
    }

    QByteArray bytes = new_exp.toLocal8Bit(); //convert QString to 8bytes
    const char *prep_exp = bytes.data(); //convert to const char*


    return parser_instance.parse(prep_exp); //parse expression and get result
}

QChartView& LogicHandler::createGraph(){
    double iterator = limit.getL();


    while(iterator < limit.getR()){


        double y = getExpressionResult(expression, iterator);
        qDebug() << expression << iterator << " " << y;

        if(y < limit.getD() || y > limit.getU()){
            iterator+=axix_x_sensitivity;
            continue;
        }

        QPointF current_point = {iterator, y};
        chartCreator_instance.addPoint(current_point);

        iterator+=axix_x_sensitivity;
    }

    return chartCreator_instance.getChart();
}
