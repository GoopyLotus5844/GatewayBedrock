#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QTableView>
#include <QHBoxLayout>
#include <iostream>
#include <QSplitter>
#include <QStyleFactory>
#include <QScrollArea>
#include <QMainWindow>
#include <QDockWidget>
#include <QToolBar>
#include "../circuit/Component.h"
#include "../circuit/Circuit.h"
#include "../chip/ChipSim.h"
#include "../chip/TemplateList.h"
#include "../ui/CompPicker.h"
#include "../ui/Properties.h"

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
    QMainWindow window;

    QPushButton toolbarButton1(nullptr);

    QPixmap pixmap(":/images/open_file.png");
    QIcon openFileIcon(pixmap);
    QAction *openAction = new QAction(openFileIcon, "Open", nullptr);

//    toolbarButton1.setFixedSize(50, 50);

    QPushButton toolbarButton2("Save", nullptr);
//    toolbarButton2.setFixedSize(30, 30);

    QHBoxLayout *toolbarLayout = new QHBoxLayout();
    toolbarLayout->addWidget(&toolbarButton1);
    toolbarLayout->addWidget(&toolbarButton2);
    toolbarLayout->addStretch(1);

    QSplitter *mainSplitter = new QSplitter();

    QWidget *sidebar = new QWidget();
    QVBoxLayout *sidebarLayout = new QVBoxLayout();

    QSplitter *sidebarSplitter = new QSplitter();
    sidebarSplitter->setOrientation(Qt::Vertical);

    QScrollArea *scrollArea = new QScrollArea();
    scrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    scrollArea->setWidgetResizable( true );
    scrollArea->setGeometry( 10, 10, 200, 200 );

    GtwUI::CompPicker compPicker(nullptr);

    scrollArea->setWidget(&compPicker);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    GtwUI::Properties properties(nullptr);
    sidebarSplitter->addWidget(scrollArea);
    sidebarSplitter->addWidget(&properties);
    sidebarLayout->addWidget(sidebarSplitter);
    sidebar->setLayout(sidebarLayout);

    QWidget *circuitArea = new QWidget();
    mainSplitter->addWidget(sidebar);
    mainSplitter->addWidget(circuitArea);

    QVBoxLayout *windowLayout = new QVBoxLayout();
    windowLayout->addLayout(toolbarLayout);
    windowLayout->addWidget(mainSplitter);
//    window.setLayout(windowLayout);

    QDockWidget *sidebarDock = new QDockWidget();
    sidebarDock->setWidget(sidebar);
    window.addDockWidget(Qt::LeftDockWidgetArea, sidebarDock);
    window.setCentralWidget(circuitArea);

    QToolBar *toolbar = new QToolBar();
    toolbar->addAction(openAction);
    window.addToolBar(toolbar);

    // Set up the model and configure the view...
    window.setWindowTitle(
            QApplication::translate("nestedlayouts", "GtwEngine"));
    window.show();
    window.setWindowState(Qt::WindowMaximized);
    QApplication::setStyle(QStyleFactory::create("Fusion"));

    return app.exec();
}
