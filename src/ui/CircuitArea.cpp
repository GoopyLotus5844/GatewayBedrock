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
        pixmap = QPixmap(74, 64);
        QPainter pixPainter = QPainter(&pixmap);

        QSvgRenderer svgRenderer(QString(":/images/xor.svg"), nullptr);
        svgRenderer.render(&pixPainter, QRectF(0, 0, 74, 64));
    }

    double clockToMilliseconds(clock_t ticks){
        return (ticks / (double) CLOCKS_PER_SEC)*1000.0;
    }

    void CircuitArea::paintGL() {
        clock_t beginFrame = clock();
        renderCircuit();
        clock_t endFrame = clock();

        deltaTime += endFrame - beginFrame;
        frames ++;

        if(clockToMilliseconds(deltaTime) > 1000.0) {
            frameRate = (double) frames * 0.5 +  frameRate * 0.5;
            frames = 0;
            deltaTime -= CLOCKS_PER_SEC;
            averageFrameTimeMilliseconds  = 1000.0 / (frameRate == 0 ? 0.001 : frameRate);

            if(true)
                std::cout<<"FrameTime was:"<<averageFrameTimeMilliseconds<<std::endl;
            else
                std::cout<<"CPU time was:"<<averageFrameTimeMilliseconds<<std::endl;
        }
    }

    void CircuitArea::renderCircuit() {
        QPainter painter(this);
        painter.fillRect(QRect(0, 0, width(), height()), QBrush(QColor(100, 100, 100)));

        painter.scale(camera.getZoom(), camera.getZoom());
        painter.translate(camera.getX(), camera.getY());

        QLineF line(10.0, 80.0, 90.0, 20.0);
        painter.drawLine(line);

        for(int y = 0; y < 100; y++) {
            for(int x = 0; x < 100; x++) {
                painter.drawPixmap(x * 74, y * 64, pixmap);
            }
        }
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
