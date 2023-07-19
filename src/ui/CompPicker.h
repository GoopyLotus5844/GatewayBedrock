//
// Created by Hank Stennes on 7/8/23.
//

#ifndef GATEWAYBEDROCK_COMPPICKER_H
#define GATEWAYBEDROCK_COMPPICKER_H

#include <QWidget>
#include <QGridLayout>

namespace GtwUI {

    class CompPicker : public QWidget {
        Q_OBJECT

    public:
        explicit CompPicker(QWidget* parent = nullptr);

    private slots:
        void compClicked();

    private:
        void addButton(QGridLayout *layout, const QString& name, int row, int col);
    };

}

#endif //GATEWAYBEDROCK_COMPPICKER_H
