#ifndef LOGICHANDLER_H
#define LOGICHANDLER_H

#include "parser/parser.h"
#include "chartcreator/chartcreator.h"
#include <QtDebug>

struct Limit{
private:
    double left;
    double right;
    double up;
    double down;
public:
    void setLimit(double l, double r, double u, double d){
        left = l;
        right = r;
        up = u;
        down = d;
    }
    double getL(){return left;}
    double getR(){return right;}
    double getU(){return up;}
    double getD(){return down;}
};

class LogicHandler
{

public:
    LogicHandler();
    Parser parser_instance;
    ChartCreator chartCreator_instance;
    Limit limit;
    QString expression = "";
    double axix_x_sensitivity = 0.1;
    QChartView* createGraph();
private:
    char* getExpressionResult(QString, double);

};

#endif // LOGICHANDLER_H
