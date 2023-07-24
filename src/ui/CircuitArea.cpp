//
// Created by Hank Stennes on 7/23/23.
//

#include "CircuitArea.h"
#include <QPainter>
#include <iostream>
#include <QMouseEvent>
#include <QSvgRenderer>

namespace GtwUI {

    CircuitArea::CircuitArea(QWidget *parent) {

    }

    void CircuitArea::paintGL() {
        QPainter painter(this);

        painter.scale(camera.getZoom(), camera.getZoom());
        painter.translate(camera.getX(), camera.getY());

        QLineF line(10.0, 80.0, 90.0, 20.0);
        painter.drawLine(line);

        QSvgRenderer svgRenderer(QString(":/images/and.svg"), nullptr);
        svgRenderer.render(&painter, QRectF(300, 300, 50, 50));
    }

    void CircuitArea::mousePressEvent(QMouseEvent *e) {
        QPoint pos = e->pos();
        camera.setInitialMousePos(pos.x(), pos.y());
    }

    void CircuitArea::mouseReleaseEvent(QMouseEvent *e) {
        QWidget::mouseReleaseEvent(e);
    }

    void CircuitArea::mouseMoveEvent(QMouseEvent *e) {
        QPoint pos = e->pos();
        camera.pan(pos.x(), pos.y());
        repaint();
    }

    void CircuitArea::wheelEvent(QWheelEvent *e) {
        QPointF pos = e->position();
        float angleDelta = e->angleDelta().y();
        camera.changeZoom(angleDelta / 200, pos.x(), pos.y(), width(), height());
        repaint();
    }
}
