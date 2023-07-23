//
// Created by Hank Stennes on 7/23/23.
//

#ifndef GATEWAYBEDROCK_CIRCUITAREA_H
#define GATEWAYBEDROCK_CIRCUITAREA_H

#include <QtCore>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

namespace GtwUI {

    class CircuitArea : public QOpenGLWidget, protected QOpenGLFunctions {
        Q_OBJECT

    public:
        explicit CircuitArea(QWidget* parent = nullptr);

    protected:
        void paintGL() override;

    };
}


#endif //GATEWAYBEDROCK_CIRCUITAREA_H
