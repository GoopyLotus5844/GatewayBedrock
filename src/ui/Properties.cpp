//
// Created by HPste on 7/21/2023.
//

#include <QPushButton>
#include <QVBoxLayout>
#include "Properties.h"

namespace GtwUI {

    Properties::Properties(QWidget* parent): QWidget(parent) {
        QPushButton *button = new QPushButton("Do something", nullptr);
        QVBoxLayout *layout = new QVBoxLayout();
        layout->setAlignment(Qt::AlignTop);
        layout->addWidget(button);
        setLayout(layout);
    }

}