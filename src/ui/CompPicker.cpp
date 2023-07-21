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
//        gateBtnLayout->setSizeConstraint(QLayout::SetFixedSize);
        addButton(gateBtnLayout, "And", 1, 1);
        addButton(gateBtnLayout, "Nand", 1, 2);
        addButton(gateBtnLayout, "Or", 1, 3);
        addButton(gateBtnLayout, "Nor", 2, 1);
        addButton(gateBtnLayout, "Xor", 2, 2);
        addButton(gateBtnLayout, "Xnor", 2, 3);
        addButton(gateBtnLayout, "Not", 3, 1);
        addButton(gateBtnLayout, "Buffer", 3, 2);
        Section* gateSection = new Section("Section", 300, this);
        gateSection->setContentLayout(*gateBtnLayout);

        QGridLayout *ioButtonLayout = new QGridLayout();
//        ioButtonLayout->setSizeConstraint(QLayout::SetFixedSize);
        addButton(ioButtonLayout, "Switch", 1, 1);
        addButton(ioButtonLayout, "Button", 1, 2);
        addButton(ioButtonLayout, "Light", 1, 3);
        addButton(ioButtonLayout, "Clock", 2, 1);
        addButton(ioButtonLayout, "Seven Seg Display", 2, 2);
        Section* ioSection = new Section("IO", 300, this);
        ioSection->setContentLayout(*ioButtonLayout);

        layout->addWidget(gateSection);
        layout->addWidget(ioSection);
        layout->setAlignment(Qt::AlignTop);
        setLayout(layout);
    }

    void CompPicker::addButton(QGridLayout *layout, const QString& name, int row, int col){
        QPushButton *button = new QPushButton(nullptr);
        QPixmap pixmap(":/images/and.png");
        QIcon icon(pixmap);
        button->setIcon(icon);
        button->setIconSize(QSize(50, 50));
        button->setFixedSize(75, 75);
        layout->addWidget(button, row, col);
    }

    void CompPicker::compClicked() {
        std::cout << "clicked" << std::endl;
    }

}
