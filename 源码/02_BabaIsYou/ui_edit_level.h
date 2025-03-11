/********************************************************************************
** Form generated from reading UI file 'edit_level.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDIT_LEVEL_H
#define UI_EDIT_LEVEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Edit_Level
{
public:
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_5;
    QLabel *label;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;

    void setupUi(QWidget *Edit_Level)
    {
        if (Edit_Level->objectName().isEmpty())
            Edit_Level->setObjectName(QStringLiteral("Edit_Level"));
        Edit_Level->resize(1937, 606);
        pushButton_3 = new QPushButton(Edit_Level);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(700, 380, 240, 40));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton = new QPushButton(Edit_Level);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(700, 440, 240, 40));
        pushButton_5 = new QPushButton(Edit_Level);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(700, 120, 111, 41));
        label = new QLabel(Edit_Level);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(275, 60, 131, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("font: normal normal 25px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: white;"));
        pushButton_4 = new QPushButton(Edit_Level);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(700, 70, 111, 41));
        lineEdit = new QLineEdit(Edit_Level);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(820, 70, 140, 41));
        pushButton_2 = new QPushButton(Edit_Level);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(750, 230, 120, 40));
        pushButton_6 = new QPushButton(Edit_Level);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(700, 290, 80, 25));
        pushButton_7 = new QPushButton(Edit_Level);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(840, 290, 80, 25));

        retranslateUi(Edit_Level);

        QMetaObject::connectSlotsByName(Edit_Level);
    } // setupUi

    void retranslateUi(QWidget *Edit_Level)
    {
        Edit_Level->setWindowTitle(QApplication::translate("Edit_Level", "Form", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Edit_Level", "\345\210\233\345\273\272\346\226\260\345\205\263\345\215\241", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Edit_Level", "\345\233\236\345\210\260\344\270\273\350\217\234\345\215\225", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("Edit_Level", "\347\247\273\351\231\244\346\220\234\347\264\242\350\257\215", Q_NULLPTR));
        label->setText(QApplication::translate("Edit_Level", "\350\207\252\345\210\266\345\205\263\345\215\241", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Edit_Level", "\346\220\234\347\264\242", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Edit_Level", "BaBa is You", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("Edit_Level", "\344\270\212\344\270\200\345\205\263", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("Edit_Level", "\344\270\213\344\270\200\345\205\263", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Edit_Level: public Ui_Edit_Level {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDIT_LEVEL_H
