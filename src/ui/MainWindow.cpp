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
#include "ToolBar.h"
#include "CircuitArea.h"

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

        ToolBar *toolbar = new ToolBar();

        CircuitArea *circuitArea = new CircuitArea();

        addDockWidget(Qt::LeftDockWidgetArea, pickerDock);
        addDockWidget(Qt::RightDockWidgetArea, propertiesDock);
        splitDockWidget(pickerDock, propertiesDock, Qt::Vertical);
        setCentralWidget(circuitArea);
        addToolBar(toolbar);
    }
}