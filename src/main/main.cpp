#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QTableView>
#include <QHBoxLayout>
#include <iostream>
#include "../circuit/Component.h"
#include "../circuit/Circuit.h"
#include "../chip/ChipSim.h"
#include "../chip/TemplateList.h"
#include "../ui/CompPicker.h"

int main(int argc, char *argv[]) {
    using namespace GtwEngine;

    Circuit chipCirc;
    int sw1 = chipCirc.addComp(CompType::SWITCH, 0, 0);
    int sw2 = chipCirc.addComp(CompType::SWITCH, 0, 0);
    int and1 = chipCirc.addComp(CompType::AND, 50, 50);
    int xor1 = chipCirc.addComp(CompType::XOR, 50, 50);
    int lt1 = chipCirc.addComp(CompType::LIGHT, 100, 100);
    int lt2 = chipCirc.addComp(CompType::LIGHT, 100, 100);

    chipCirc.connect(sw1, 0, and1, 0);
    chipCirc.connect(sw2, 0, and1, 1);
    chipCirc.connect(sw1, 0, xor1, 0);
    chipCirc.connect(sw2, 0, xor1, 1);
    chipCirc.connect(and1, 0, lt1, 0);
    chipCirc.connect(xor1, 0, lt2, 0);

    int chipTemplate = TEMPLATE_LIST.createTemplate(chipCirc);
    TemplateList stuff = TEMPLATE_LIST;

    Circuit mainCirc;
    int chip = mainCirc.addComp(CompType::CHIP, 0, 0);
    int sw1a = mainCirc.addComp(CompType::SWITCH, 0, 0);
    int sw2a = mainCirc.addComp(CompType::SWITCH, 0, 0);
    int lt1a = mainCirc.addComp(CompType::LIGHT, 0, 0);
    int lt2a = mainCirc.addComp(CompType::LIGHT, 0, 0);

    mainCirc.getComp(chip).initChip(chipTemplate);
    mainCirc.connect(sw1a, 0, chip, 0);
    mainCirc.connect(sw2a, 0, chip, 1);
    mainCirc.connect(chip, 0, lt1a, 0);
    mainCirc.connect(chip, 1, lt2a, 0);

    std::cout << "Done compiling" << std::endl;

    QApplication app(argc, argv);
    QWidget window;

    QPushButton toolbarButton1(nullptr);

    QPixmap pixmap(":/images/open_file.png");
    QIcon ButtonIcon(pixmap);
    toolbarButton1.setIcon(ButtonIcon);
//    toolbarButton1.setFixedSize(50, 50);

    QPushButton toolbarButton2("Save", nullptr);
//    toolbarButton2.setFixedSize(30, 30);

    QHBoxLayout *toolbarLayout = new QHBoxLayout();
    toolbarLayout->addWidget(&toolbarButton1);
    toolbarLayout->addWidget(&toolbarButton2);
    toolbarLayout->addStretch(1);

    QHBoxLayout *mainLayout = new QHBoxLayout();
    GtwUI::CompPicker compPicker(nullptr);
    QWidget *circuitArea = new QWidget();
    mainLayout->addWidget(&compPicker);
    mainLayout->addWidget(circuitArea);

    QVBoxLayout *windowLayout = new QVBoxLayout();
    windowLayout->addLayout(toolbarLayout);
    windowLayout->addLayout(mainLayout);
    window.setLayout(windowLayout);

    // Set up the model and configure the view...
    window.setWindowTitle(
            QApplication::translate("nestedlayouts", "GtwEngine"));
    window.setWindowState(Qt::WindowMaximized);
    window.show();

    return app.exec();
}
