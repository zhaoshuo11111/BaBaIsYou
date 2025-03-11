/********************************************************************************
** Form generated from reading UI file 'pause_scene.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAUSE_SCENE_H
#define UI_PAUSE_SCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Pause_Scene
{
public:
    QLabel *label;
    QPushButton *b1_start;
    QPushButton *b2_exitToChoose;
    QPushButton *b3_reStart;
    QPushButton *b5_exitToGuide;

    void setupUi(QWidget *Pause_Scene)
    {
        if (Pause_Scene->objectName().isEmpty())
            Pause_Scene->setObjectName(QStringLiteral("Pause_Scene"));
        Pause_Scene->resize(989, 557);
        label = new QLabel(Pause_Scene);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(320, 40, 291, 61));
        label->setStyleSheet(QString::fromUtf8("font: normal normal 15px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: black;"));
        b1_start = new QPushButton(Pause_Scene);
        b1_start->setObjectName(QStringLiteral("b1_start"));
        b1_start->setGeometry(QRect(310, 130, 371, 41));
        b2_exitToChoose = new QPushButton(Pause_Scene);
        b2_exitToChoose->setObjectName(QStringLiteral("b2_exitToChoose"));
        b2_exitToChoose->setGeometry(QRect(310, 180, 371, 41));
        b3_reStart = new QPushButton(Pause_Scene);
        b3_reStart->setObjectName(QStringLiteral("b3_reStart"));
        b3_reStart->setGeometry(QRect(310, 230, 371, 41));
        b5_exitToGuide = new QPushButton(Pause_Scene);
        b5_exitToGuide->setObjectName(QStringLiteral("b5_exitToGuide"));
        b5_exitToGuide->setGeometry(QRect(310, 330, 371, 41));

        retranslateUi(Pause_Scene);

        QMetaObject::connectSlotsByName(Pause_Scene);
    } // setupUi

    void retranslateUi(QWidget *Pause_Scene)
    {
        Pause_Scene->setWindowTitle(QApplication::translate("Pause_Scene", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Pause_Scene", "\345\205\263\345\215\241\345\220\215\357\274\232------", Q_NULLPTR));
        b1_start->setText(QApplication::translate("Pause_Scene", "\347\273\247\347\273\255\346\270\270\346\210\217", Q_NULLPTR));
        b2_exitToChoose->setText(QApplication::translate("Pause_Scene", "\350\277\224\345\233\236\345\244\247\345\234\260\345\233\276", Q_NULLPTR));
        b3_reStart->setText(QApplication::translate("Pause_Scene", "\351\207\215\346\226\260\345\274\200\345\247\213", Q_NULLPTR));
        b5_exitToGuide->setText(QApplication::translate("Pause_Scene", "\345\233\236\345\210\260\344\270\273\350\217\234\345\215\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Pause_Scene: public Ui_Pause_Scene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAUSE_SCENE_H
