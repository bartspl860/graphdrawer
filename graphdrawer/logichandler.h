#ifndef LOGICHANDLER_H
#define LOGICHANDLER_H

#include "parser/parser.h"
#include "chartcreator/chartcreator.h"
#include <QtDebug>
#include <QMainWindow>

struct ChartLimit{
private:
    double left;
    double right;
    double up;
    double down;
public:
    ChartLimit(double l, double r, double u, double d) {setLimit(l,r,u,d);}
    void setLimit(double l, double r, double u, double d){
        left = l;
        right = r;
        up = u;
        down = d;
    }
    double getL()const{return left;}
    double getR()const{return right;}
    double getU()const{return up;}
    double getD()const{return down;}
};

class LogicHandler
{
public:
    LogicHandler();
    void createGraph(QString name, QColor color, QString exp, ChartLimit lim, double sens, QFrame* dest);
    void createGraph(QFrame* dest);
private:
    Parser parser_instance;
    ChartCreator chartCreator_instance;
    char* getExpressionResult(QString, double);
};
#endif // LOGICHANDLER_H
