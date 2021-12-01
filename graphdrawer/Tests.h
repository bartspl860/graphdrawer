#ifndef TESTS_H
#define TESTS_H

#include "logichandler.h"


void parserTest(){

    LogicHandler t;

    QString str = "x^2";
    double x = 5;

    if(strcmp(t.getExpressionResult(str, x), t.getExpressionResult(str, x))){
        qDebug() << "zajebioza";
    }



}

#endif // TESTS_H
