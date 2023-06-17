//
// Created by HPste on 6/15/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_CompPicker.h" resolved

#include "comppicker.h"
#include "ui_CompPicker.h"


CompPicker::CompPicker(QWidget *parent) :
        QWidget(parent), ui(new Ui::CompPicker) {
    ui->setupUi(this);
}

CompPicker::~CompPicker() {
    delete ui;
}
