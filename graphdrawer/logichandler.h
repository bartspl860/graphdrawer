#ifndef LOGICHANDLER_H
#define LOGICHANDLER_H

#include "parser/parser.h"
#include "chartcreator/chartcreator.h"
#include <QtDebug>
#include <QMainWindow>


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
    double axix_x_sensitivity = 0.01;
    void createGraph(QString exp, QFrame* frame);
private:
    char* getExpressionResult(QString, double);

};

#endif // LOGICHANDLER_H
