#ifndef LOGICHANDLER_H
#define LOGICHANDLER_H

#include "parser/parser.h"
#include "chartcreator/chartcreator.h"
#include <QtDebug>
#include <QMainWindow>
#include "qcustomplot.h"
#include "essentials.h"


class LogicHandler
{
public:
    LogicHandler();
    void createGraph(QString name, QColor color, QString exp, ChartLimit lim, double sens, QCustomPlot* dest);
    void createGraph(QFrame* dest);
    char* getExpressionResult(QString, double);
private:
    Parser parser_instance;
    ChartCreator chartCreator_instance;    
};
#endif // LOGICHANDLER_H
