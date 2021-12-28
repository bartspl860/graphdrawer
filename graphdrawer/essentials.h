#ifndef ESSENTIALS_H
#define ESSENTIALS_H

#include <QColor>
#include <QLabel>

namespace essentials {
    void setLabelColor(QLabel* label, QColor color){
        QPixmap pixmap(45,20);
        pixmap.fill(color);
        label->setPixmap(pixmap);
    }

    void resetLabelColor(QLabel* label){
        QPixmap pixmap(45,20);
        pixmap.fill(Qt::black);
        label->setPixmap(pixmap);
    }
}


#endif // ESSENTIALS_H
