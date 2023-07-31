//
// Created by Hank Stennes on 7/23/23.
//

#ifndef GATEWAYBEDROCK_CIRCUITAREA_H
#define GATEWAYBEDROCK_CIRCUITAREA_H

#include <QtCore>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include "Camera.h"

namespace GtwUI {

    class CircuitArea : public QOpenGLWidget, protected QOpenGLFunctions {
        Q_OBJECT

    public:
        explicit CircuitArea(QWidget* parent = nullptr);

    private:
        Camera camera;

        QPixmap pixmap;

    protected:
        void paintGL() override;

        void mousePressEvent(QMouseEvent *e) override;

        void mouseReleaseEvent(QMouseEvent *e) override;

        void mouseMoveEvent(QMouseEvent *e) override;

        void wheelEvent(QWheelEvent *e) override;
    };
}


#endif //GATEWAYBEDROCK_CIRCUITAREA_H
