//
// Created by Hank Stennes on 7/8/23.
//

#include <QPushButton>
#include "CompPicker.h"
#include "Section.h"
#include <iostream>
#include <QVBoxLayout>

namespace GtwUI {

    CompPicker::CompPicker(QWidget* parent): QWidget(parent) {
        QVBoxLayout *layout = new QVBoxLayout();

        QGridLayout *gateBtnLayout = new QGridLayout();
        gateBtnLayout->setSizeConstraint(QLayout::SetFixedSize);
        addButton(gateBtnLayout, ":/images/and.svg", 1, 1);
        addButton(gateBtnLayout, ":/images/or.svg", 1, 2);
        addButton(gateBtnLayout, ":/images/buffer.svg", 1, 3);
        addButton(gateBtnLayout, ":/images/and.svg", 2, 1);
        addButton(gateBtnLayout, ":/images/or.svg", 2, 2);
        addButton(gateBtnLayout, ":/images/buffer.svg", 2, 3);
        addButton(gateBtnLayout, ":/images/and.svg", 3, 1);
        addButton(gateBtnLayout, ":/images/or.svg", 3, 2);
        Section* gateSection = new Section("Gates", 200, this);
        gateSection->setContentLayout(*gateBtnLayout);

        QGridLayout *ioButtonLayout = new QGridLayout();
        ioButtonLayout->setSizeConstraint(QLayout::SetFixedSize);
        addButton(ioButtonLayout, ":/images/switch_off.svg", 1, 1);
        addButton(ioButtonLayout, ":/images/button_off.svg", 1, 2);
        addButton(ioButtonLayout, ":/images/light_on.svg", 1, 3);
        addButton(ioButtonLayout, ":/images/clock_off.svg", 2, 1);
        addButton(ioButtonLayout, ":/images/display.svg", 2, 2);
        Section* ioSection = new Section("IO", 200, this);
        ioSection->setContentLayout(*ioButtonLayout);

        layout->addWidget(gateSection);
        layout->addWidget(ioSection);
        layout->setAlignment(Qt::AlignTop);
        setLayout(layout);
    }

    void CompPicker::addButton(QGridLayout *layout, const QString& iconPath, int row, int col){
        QPushButton *button = new QPushButton(nullptr);
        QPixmap pixmap(iconPath);
        QIcon icon(pixmap);
        button->setIcon(icon);
        button->setIconSize(QSize(40, 40));
        button->setFixedSize(60, 60);
        layout->addWidget(button, row, col);
    }

    void CompPicker::compClicked() {
        std::cout << "clicked" << std::endl;
    }

}
