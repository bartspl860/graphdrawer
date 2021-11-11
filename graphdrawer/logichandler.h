#ifndef LOGICHANDLER_H
#define LOGICHANDLER_H

#include "parser/parser.h"
#include <QtDebug>

class LogicHandler
{
public:
    LogicHandler();
    Parser parser_instance;
    double getResult(QString, double);
};

#endif // LOGICHANDLER_H
