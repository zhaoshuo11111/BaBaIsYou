/********************************************************************************
** Form generated from reading UI file 'guide_scene.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIDE_SCENE_H
#define UI_GUIDE_SCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Guide_Scene
{
public:
    QLabel *label;
    QPushButton *b1_newgame;
    QPushButton *b3_editor;
    QPushButton *b2_setting;
    QPushButton *b4_exit;

    void setupUi(QWidget *Guide_Scene)
    {
        if (Guide_Scene->objectName().isEmpty())
            Guide_Scene->setObjectName(QStringLiteral("Guide_Scene"));
        Guide_Scene->resize(1040, 560);
        label = new QLabel(Guide_Scene);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(290, 90, 431, 161));
        label->setPixmap(QPixmap(QString::fromUtf8(":/res/BIY_title_3.png")));
        label->setScaledContents(true);
        b1_newgame = new QPushButton(Guide_Scene);
        b1_newgame->setObjectName(QStringLiteral("b1_newgame"));
        b1_newgame->setGeometry(QRect(200, 310, 301, 60));
        b1_newgame->setMinimumSize(QSize(60, 60));
        b1_newgame->setIconSize(QSize(20, 20));
        b3_editor = new QPushButton(Guide_Scene);
        b3_editor->setObjectName(QStringLiteral("b3_editor"));
        b3_editor->setGeometry(QRect(200, 390, 301, 60));
        b3_editor->setMinimumSize(QSize(60, 60));
        b2_setting = new QPushButton(Guide_Scene);
        b2_setting->setObjectName(QStringLiteral("b2_setting"));
        b2_setting->setGeometry(QRect(520, 310, 311, 60));
        b2_setting->setMinimumSize(QSize(60, 60));
        b4_exit = new QPushButton(Guide_Scene);
        b4_exit->setObjectName(QStringLiteral("b4_exit"));
        b4_exit->setGeometry(QRect(520, 390, 311, 60));
        b4_exit->setMinimumSize(QSize(60, 60));

        retranslateUi(Guide_Scene);

        QMetaObject::connectSlotsByName(Guide_Scene);
    } // setupUi

    void retranslateUi(QWidget *Guide_Scene)
    {
        Guide_Scene->setWindowTitle(QApplication::translate("Guide_Scene", "Guide_Scene", Q_NULLPTR));
        label->setText(QString());
        b1_newgame->setText(QApplication::translate("Guide_Scene", "\346\230\257\346\226\260\346\270\270\346\210\217\345\223\246", Q_NULLPTR));
        b3_editor->setText(QApplication::translate("Guide_Scene", "\345\205\263\345\215\241\347\274\226\350\276\221\345\231\250", Q_NULLPTR));
        b2_setting->setText(QApplication::translate("Guide_Scene", "\350\256\276\345\256\232", Q_NULLPTR));
        b4_exit->setText(QApplication::translate("Guide_Scene", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Guide_Scene: public Ui_Guide_Scene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIDE_SCENE_H
