//
// Created by Hank Stennes on 7/8/23.
//

#include <QPushButton>
#include "CompPicker.h"
#include <iostream>
#include <QVBoxLayout>

namespace GtwUI {

    CompPicker::CompPicker(QWidget* parent): QWidget(parent) {
        QPushButton compButton("AND", nullptr);
//        connect(&compButton, SIGNAL(clicked()), this, SLOT(compClicked()));

        QVBoxLayout *compPickerLayout = new QVBoxLayout();
        compPickerLayout->addWidget(&compButton);
        setLayout(compPickerLayout);
        setFixedWidth(300);

        std::cout << "here" << std::endl;
    }

    void CompPicker::compClicked() {
        std::cout << "hello" << std::endl;
    }

}
