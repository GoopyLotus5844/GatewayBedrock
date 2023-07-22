//
// Created by HPste on 7/22/2023.
//

#include <QScrollArea>
#include <QDockWidget>
#include <QToolBar>
#include <QApplication>
#include "MainWindow.h"
#include "CompPicker.h"
#include "Properties.h"

namespace GtwUI {

    MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

        QScrollArea *pickerScrollArea = new QScrollArea();
        CompPicker *compPicker = new CompPicker(nullptr);
        pickerScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        pickerScrollArea->setWidgetResizable( true );
        pickerScrollArea->setWidget(compPicker);
        QDockWidget *pickerDock = new QDockWidget();
        pickerDock->setWidget(pickerScrollArea);

        Properties *properties = new Properties(nullptr);
        QDockWidget *propertiesDock = new QDockWidget();
        propertiesDock->setWidget(properties);

        QPixmap openPixmap(":/images/open_file.png");
        QIcon openIcon(openPixmap);
        QAction *openAction = new QAction(openIcon, "Open", nullptr);
        QToolBar *toolbar = new QToolBar();
        toolbar->addAction(openAction);

        QWidget *circuitArea = new QWidget();

        addDockWidget(Qt::LeftDockWidgetArea, pickerDock);
        addDockWidget(Qt::RightDockWidgetArea, propertiesDock);
        splitDockWidget(pickerDock, propertiesDock, Qt::Vertical);
        setCentralWidget(circuitArea);
        addToolBar(toolbar);
    }
}