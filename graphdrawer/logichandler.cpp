#include "logichandler.h"

LogicHandler::LogicHandler()
{

}

double LogicHandler::getResult(QString exp, double x){

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
