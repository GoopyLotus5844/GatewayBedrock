//
// Created by HPste on 7/22/2023.
//

#include "ToolBar.h"

namespace GtwUI {

    ToolBar::ToolBar(QWidget *parent) : QToolBar(parent) {
        addButton("New", ":/images/new_file.png");
        addButton("Open", ":/images/open_file.png");
        addButton("Save", ":/images/save_file.png");
        addSeparator();
        addButton("Undo", ":/images/undo.png");
        addButton("Redo", ":/images/redo.png");
        addButton("Cut", ":/images/cut.png");
        addButton("Copy", ":/images/copy.png");
        addButton("Paste", ":/images/paste.png");
        addSeparator();
        addButton("Delete", ":/images/delete.png");
        addButton("Rotate Counter-Clockwise", ":/images/rotate_counter.png");
        addButton("Rotate Clockwise", ":/images/rotate.png");
        addButton("Create Chip", ":/images/custom.png");
        addButton("Debug Console", ":/images/console.png");
    }

    void ToolBar::addButton(const QString &name, const QString &iconPath) {
        QPixmap pixmap(iconPath);
        QIcon openIcon(pixmap);
        QAction *action = new QAction(openIcon, name, nullptr);
        addAction(action);
    }

}