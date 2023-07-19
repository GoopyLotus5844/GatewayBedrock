//
// Created by Hank Stennes on 7/8/23.
//

#include <QPushButton>
#include "CompPicker.h"
#include <iostream>
#include <QVBoxLayout>

namespace GtwUI {

    CompPicker::CompPicker(QWidget* parent): QWidget(parent) {
        QGridLayout *layout = new QGridLayout();
        layout->setSizeConstraint(QLayout::SetFixedSize);
        addButton(layout, "And", 1, 1);
        addButton(layout, "Nand", 1, 2);
        addButton(layout, "Or", 1, 3);
        addButton(layout, "Nor", 2, 1);
        addButton(layout, "Xor", 2, 2);
        addButton(layout, "Xnor", 2, 3);
        addButton(layout, "Not", 3, 1);
        addButton(layout, "Buffer", 3, 2);
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
        std::cout << "hello" << std::endl;
    }

}
