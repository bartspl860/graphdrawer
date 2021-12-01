#ifndef TESTS_H
#define TESTS_H

#include "logichandler.h"
#include <QDebug>

void parserTest(){

    LogicHandler t;

    QString str = "x^2";
    double x = 5;
    try
    {
        if(atof(t.getExpressionResult(str,x))==25)
        {
                qDebug() << "zajebioza";
        }
        else
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
        if(atof(t.getExpressionResult(str,x))==25)
        {
                qDebug() << "zajebioza";
        }
        else
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
        if(atof(t.getExpressionResult(str,x))==0.283662)
        {
                qDebug() << "Działa";
        }
        else
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
        if(atof(t.getExpressionResult(str,x))==3)
        {
                qDebug() << "Działa";
        }
        else
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
    qDebug()<<atof(t.getExpressionResult(str,x));
    try
    {
        if(atof(t.getExpressionResult(str,x))==-48)
        {
                qDebug() << "Działa";
        }
        else
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
