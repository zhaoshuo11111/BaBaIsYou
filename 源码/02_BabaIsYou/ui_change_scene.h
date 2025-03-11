/********************************************************************************
** Form generated from reading UI file 'change_scene.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGE_SCENE_H
#define UI_CHANGE_SCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Change_Scene
{
public:

    void setupUi(QWidget *Change_Scene)
    {
        if (Change_Scene->objectName().isEmpty())
            Change_Scene->setObjectName(QStringLiteral("Change_Scene"));
        Change_Scene->resize(795, 517);

        retranslateUi(Change_Scene);

        QMetaObject::connectSlotsByName(Change_Scene);
    } // setupUi

    void retranslateUi(QWidget *Change_Scene)
    {
        Change_Scene->setWindowTitle(QApplication::translate("Change_Scene", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Change_Scene: public Ui_Change_Scene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGE_SCENE_H
