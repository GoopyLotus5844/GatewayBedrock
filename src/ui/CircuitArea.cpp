//
// Created by Hank Stennes on 7/23/23.
//

#include "CircuitArea.h"
#include <QPainter>

namespace GtwUI {

    CircuitArea::CircuitArea(QWidget *parent) {

    }

    void CircuitArea::paintGL() {
        QPainter painter(this);
        QLineF line(10.0, 80.0, 90.0, 20.0);
        painter.drawLine(line);

        QIcon icon(":/images/and.svg");
        QPixmap pixmap = icon.pixmap(QSize(32, 32));
        painter.drawPixmap(300, 300, pixmap);
    }
}
