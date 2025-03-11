/********************************************************************************
** Form generated from reading UI file 'term_borad.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TERM_BORAD_H
#define UI_TERM_BORAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Term_Borad
{
public:
    QWidget *widget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *Term_Borad)
    {
        if (Term_Borad->objectName().isEmpty())
            Term_Borad->setObjectName(QStringLiteral("Term_Borad"));
        Term_Borad->resize(400, 300);
        widget = new QWidget(Term_Borad);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 1040, 40));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 120, 40));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(120, 0, 120, 40));
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(240, 0, 160, 40));
        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(960, 0, 80, 40));

        retranslateUi(Term_Borad);

        QMetaObject::connectSlotsByName(Term_Borad);
    } // setupUi

    void retranslateUi(QWidget *Term_Borad)
    {
        Term_Borad->setWindowTitle(QApplication::translate("Term_Borad", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Term_Borad", "\346\214\211\345\220\215\347\247\260\346\220\234\347\264\242", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Term_Borad", "\347\247\273\351\231\244\346\220\234\347\264\242\350\257\215", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Term_Borad", "\345\210\207\346\215\242\347\211\251\344\273\266\346\230\276\347\244\272\346\226\271\345\274\217", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Term_Borad", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Term_Borad: public Ui_Term_Borad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TERM_BORAD_H
