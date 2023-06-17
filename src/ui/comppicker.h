//
// Created by HPste on 6/15/2023.
//

#ifndef GATEWAYBEDROCK_COMPPICKER_H
#define GATEWAYBEDROCK_COMPPICKER_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class CompPicker; }
QT_END_NAMESPACE

class CompPicker : public QWidget {
Q_OBJECT

public:
    explicit CompPicker(QWidget *parent = nullptr);

    ~CompPicker() override;

private:
    Ui::CompPicker *ui;
};


#endif //GATEWAYBEDROCK_COMPPICKER_H
