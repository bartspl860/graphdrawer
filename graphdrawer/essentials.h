#ifndef ESSENTIALS_H
#define ESSENTIALS_H

#include <QColor>
#include <QLabel>
#include <qcustomplot.h>

namespace essentials {
    void setLabelColor(QLabel* label, QColor color){
        QPixmap pixmap(84,40);
        pixmap.fill(color);
        label->setPixmap(pixmap);
    }

    void resetLabelColor(QLabel* label){
        QPixmap pixmap(84,40);
        pixmap.fill(Qt::black);
        label->setPixmap(pixmap);
    }

    void setGraphTheme(QLinearGradient plotGradient, QColor color, QCustomPlot* plot){
        plot->setBackground(plotGradient);

        plot->xAxis->setBasePen(QPen(color, 1));
        plot->yAxis->setBasePen(QPen(color, 1));

        plot->xAxis->setTickLabelColor(color);
        plot->yAxis->setTickLabelColor(color);

        plot->xAxis->setSubTickPen(QPen(color, 1));
        plot->yAxis->setSubTickPen(QPen(color, 1));
    }
}


#endif // ESSENTIALS_H
