/********************************************************************************
** Form generated from reading UI file 'game_scene.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_SCENE_H
#define UI_GAME_SCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Game_Scene
{
public:
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *Game_Scene)
    {
        if (Game_Scene->objectName().isEmpty())
            Game_Scene->setObjectName(QStringLiteral("Game_Scene"));
        Game_Scene->resize(1029, 562);
        label = new QLabel(Game_Scene);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(310, 20, 61, 31));
        label->setPixmap(QPixmap(QString::fromUtf8(":/res/KEY_Z_2.png")));
        label_2 = new QLabel(Game_Scene);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(580, 20, 101, 31));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/res/KEY_R_2.png")));

        retranslateUi(Game_Scene);

        QMetaObject::connectSlotsByName(Game_Scene);
    } // setupUi

    void retranslateUi(QWidget *Game_Scene)
    {
        Game_Scene->setWindowTitle(QApplication::translate("Game_Scene", "\346\270\270\346\210\217\347\225\214\351\235\242", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Game_Scene: public Ui_Game_Scene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_SCENE_H
