//
// Created by HPste on 7/22/2023.
//

#ifndef GATEWAYBEDROCK_TOOLBAR_H
#define GATEWAYBEDROCK_TOOLBAR_H

#include <QToolBar>

namespace GtwUI {

    class ToolBar : public QToolBar {
        Q_OBJECT

    public:
        explicit ToolBar(QWidget* parent = nullptr);

    private:
        void addButton(const QString& name, const QString& iconPath);

    };

}

#endif //GATEWAYBEDROCK_TOOLBAR_H
