/********************************************************************************
** Form generated from reading UI file 'set_level_name.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SET_LEVEL_NAME_H
#define UI_SET_LEVEL_NAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Set_Level_Name
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *Set_Level_Name)
    {
        if (Set_Level_Name->objectName().isEmpty())
            Set_Level_Name->setObjectName(QStringLiteral("Set_Level_Name"));
        Set_Level_Name->resize(400, 300);
        verticalLayout = new QVBoxLayout(Set_Level_Name);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer);

        widget = new QWidget(Set_Level_Name);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(127, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("font: normal normal 25px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: white;"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(127, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(Set_Level_Name);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(120, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        lineEdit = new QLineEdit(widget_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        horizontalSpacer_4 = new QSpacerItem(120, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(Set_Level_Name);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(141, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        pushButton_2 = new QPushButton(widget_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(80, 30));
        pushButton_2->setMaximumSize(QSize(80, 30));

        horizontalLayout_3->addWidget(pushButton_2);

        pushButton = new QPushButton(widget_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(80, 30));
        pushButton->setMaximumSize(QSize(80, 30));

        horizontalLayout_3->addWidget(pushButton);

        horizontalSpacer_6 = new QSpacerItem(141, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout->addWidget(widget_3);

        verticalSpacer_2 = new QSpacerItem(20, 121, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(Set_Level_Name);

        QMetaObject::connectSlotsByName(Set_Level_Name);
    } // setupUi

    void retranslateUi(QWidget *Set_Level_Name)
    {
        Set_Level_Name->setWindowTitle(QApplication::translate("Set_Level_Name", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Set_Level_Name", "\350\276\223\345\205\245\346\226\260\345\205\263\345\215\241\347\232\204\345\220\215\345\255\227\357\274\232", Q_NULLPTR));
        lineEdit->setText(QString());
        pushButton_2->setText(QApplication::translate("Set_Level_Name", "back", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Set_Level_Name", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Set_Level_Name: public Ui_Set_Level_Name {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SET_LEVEL_NAME_H
