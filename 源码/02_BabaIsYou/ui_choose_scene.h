/********************************************************************************
** Form generated from reading UI file 'choose_scene.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSE_SCENE_H
#define UI_CHOOSE_SCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Choose_Scene
{
public:
    QPushButton *b1_exit;
    QLabel *l1_nameOfLevel;
    QLabel *l2_flower;
    QLabel *l3_score;

    void setupUi(QWidget *Choose_Scene)
    {
        if (Choose_Scene->objectName().isEmpty())
            Choose_Scene->setObjectName(QStringLiteral("Choose_Scene"));
        Choose_Scene->resize(1036, 585);
        b1_exit = new QPushButton(Choose_Scene);
        b1_exit->setObjectName(QStringLiteral("b1_exit"));
        b1_exit->setGeometry(QRect(10, 40, 93, 28));
        l1_nameOfLevel = new QLabel(Choose_Scene);
        l1_nameOfLevel->setObjectName(QStringLiteral("l1_nameOfLevel"));
        l1_nameOfLevel->setGeometry(QRect(10, 10, 161, 21));
        l2_flower = new QLabel(Choose_Scene);
        l2_flower->setObjectName(QStringLiteral("l2_flower"));
        l2_flower->setGeometry(QRect(860, 30, 61, 101));
        l2_flower->setPixmap(QPixmap(QString::fromUtf8(":/res/flower_1.gif")));
        l2_flower->setScaledContents(true);
        l3_score = new QLabel(Choose_Scene);
        l3_score->setObjectName(QStringLiteral("l3_score"));
        l3_score->setGeometry(QRect(930, 40, 72, 15));
        l3_score->setStyleSheet(QString::fromUtf8("font: normal normal 20px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: white;"));

        retranslateUi(Choose_Scene);

        QMetaObject::connectSlotsByName(Choose_Scene);
    } // setupUi

    void retranslateUi(QWidget *Choose_Scene)
    {
        Choose_Scene->setWindowTitle(QApplication::translate("Choose_Scene", "\345\205\263\345\215\241\351\200\211\346\213\251", Q_NULLPTR));
        b1_exit->setText(QApplication::translate("Choose_Scene", "\350\277\224\345\233\236\350\217\234\345\215\225", Q_NULLPTR));
        l1_nameOfLevel->setText(QApplication::translate("Choose_Scene", "\345\205\263\345\215\241\345\220\215\357\274\232", Q_NULLPTR));
        l2_flower->setText(QString());
        l3_score->setText(QApplication::translate("Choose_Scene", "00", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Choose_Scene: public Ui_Choose_Scene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSE_SCENE_H
