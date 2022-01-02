#ifndef TESTS_H
#define TESTS_H

#include "logichandler.h"
#include <QDebug>

#define EPSILON 0.0001

void parserTest(){

    LogicHandler t;
    QString str = "x^2";
    double x = 5;

    try
    {
        if(atof(t.getExpressionResult(str,x)) - 25 > EPSILON)
        {
                throw std::logic_error("Nie dziala");
        }
    }
    catch(std::logic_error& e)
    {
        qDebug()<<e.what();
    }
}


void parserTest2(){

    LogicHandler t;    
    QString str = "sinx";
    double x = 5;

    try
    {
        if(abs(atof(t.getExpressionResult(str,x)) - -0.9589) > EPSILON)
        {
                throw std::logic_error("Nie dziala");
        }
    }
    catch(std::logic_error& e)
    {
        qDebug()<<e.what();
    }
}
void parserTest3(){

    LogicHandler t;
    QString str = "cosx";
    double x = 5;

    try
    {
        if(atof(t.getExpressionResult(str,x)) - 0.283662 > EPSILON)
        {
                throw std::logic_error("Nie dziala");
        }
    }
    catch(std::logic_error& e)
    {
        qDebug()<<e.what();
    }
}

void parserTest4(){

    LogicHandler t;
    QString str = "sqrtx";
    double x = 9;

    try
    {
        if(atof(t.getExpressionResult(str,x)) - 3 > EPSILON)
        {
                throw std::logic_error("Nie dziala");
        }        
    }
    catch(std::logic_error& e)
    {
        qDebug()<<e.what();
    }
}
void parserTest5(){

    LogicHandler t;
    QString str = "(x^4)-(16*x^3)+64";
    double x = 2;

    try
    {
        if(atof(t.getExpressionResult(str,x)) - -48 > EPSILON)
        {
                throw std::logic_error("Nie dziala");
        }
    }
    catch(std::logic_error& e)
    {
        qDebug()<<e.what();
    }
}


#endif // TESTS_H
