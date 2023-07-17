//
// Created by Hank Stennes on 7/8/23.
//

#ifndef GATEWAYBEDROCK_COMPPICKER_H
#define GATEWAYBEDROCK_COMPPICKER_H

#include <QWidget>

namespace GtwUI {

    class CompPicker : public QWidget {
        Q_OBJECT

    public:
        CompPicker(QWidget* parent = nullptr);

    private slots:
        void compClicked();
    };

}

#endif //GATEWAYBEDROCK_COMPPICKER_H
