#ifndef CONTAINER_CLASSES_H
#define CONTAINER_CLASSES_H

#include <QString>
#include <QVector>
#include <QColor>

class ChartLimit{
    double left;
    double right;
    double up;
    double down;
public:
    ChartLimit(){}
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

class Series{
    QString name;
    QColor color;
    ChartLimit limit;
    double axix_sensitivity;
    QString expression;
    QVector<double> series_x;
    QVector<double> series_y;
    friend class ChartCreator;
public:
    Series(){}
    Series(QString _name, QColor _color, QVector<double> _series_x, QVector<double> _series_y,
           ChartLimit _limit, double _axix_sensitivity, QString _expression)
        : name(_name), color(_color), series_x(_series_x), series_y(_series_y),
    limit(_limit), axix_sensitivity(_axix_sensitivity), expression(_expression){}
    QString getName()const {return name;}
    QColor getColor()const {return color;}
    ChartLimit getLimit()const{return limit;}
    double getSen()const{return axix_sensitivity;}
};
#endif // CONTAINER_CLASSES_H
