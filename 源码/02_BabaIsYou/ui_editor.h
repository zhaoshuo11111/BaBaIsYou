/********************************************************************************
** Form generated from reading UI file 'editor.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITOR_H
#define UI_EDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_editor
{
public:
    QWidget *widget;
    QWidget *widget_2;
    QWidget *widget_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton;
    QPushButton *pushButton_6;
    QPushButton *pushButton_4;
    QWidget *widget_4;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *editor)
    {
        if (editor->objectName().isEmpty())
            editor->setObjectName(QStringLiteral("editor"));
        editor->resize(1204, 615);
        widget = new QWidget(editor);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 1040, 40));
        widget_2 = new QWidget(editor);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(0, 40, 1000, 480));
        widget_3 = new QWidget(editor);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(0, 520, 1040, 52));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy);
        pushButton_2 = new QPushButton(widget_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setEnabled(true);
        pushButton_2->setGeometry(QRect(500, 0, 100, 40));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(40);
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);
        pushButton_2->setMinimumSize(QSize(0, 40));
        QFont font;
        font.setFamily(QStringLiteral("AcadEref"));
        font.setPointSize(10);
        pushButton_2->setFont(font);
        pushButton_3 = new QPushButton(widget_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(600, 0, 100, 40));
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);
        pushButton_3->setMinimumSize(QSize(0, 40));
        pushButton_3->setFont(font);
        pushButton_5 = new QPushButton(widget_3);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(700, 0, 100, 40));
        sizePolicy1.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy1);
        pushButton_5->setMinimumSize(QSize(0, 40));
        pushButton_5->setFont(font);
        pushButton = new QPushButton(widget_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(940, 0, 100, 40));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setMinimumSize(QSize(0, 40));
        pushButton->setFont(font);
        pushButton_6 = new QPushButton(widget_3);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setEnabled(true);
        pushButton_6->setGeometry(QRect(800, 0, 100, 40));
        sizePolicy1.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy1);
        pushButton_6->setMinimumSize(QSize(0, 40));
        pushButton_6->setFont(font);
        pushButton_4 = new QPushButton(widget_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(350, 0, 100, 40));
        widget_4 = new QWidget(editor);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(1000, 40, 40, 480));
        spinBox = new QSpinBox(widget_4);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(0, 20, 40, 22));
        spinBox_2 = new QSpinBox(widget_4);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setGeometry(QRect(0, 70, 40, 22));
        spinBox_3 = new QSpinBox(widget_4);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setGeometry(QRect(0, 120, 40, 22));
        label = new QLabel(widget_4);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 100, 40, 15));
        label_2 = new QLabel(widget_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 50, 40, 15));
        label_3 = new QLabel(widget_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 0, 40, 15));

        retranslateUi(editor);

        QMetaObject::connectSlotsByName(editor);
    } // setupUi

    void retranslateUi(QWidget *editor)
    {
        editor->setWindowTitle(QApplication::translate("editor", "Form", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("editor", "\346\265\213\350\257\225", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("editor", "\345\210\207\346\215\242", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("editor", "\344\277\235\345\255\230", Q_NULLPTR));
        pushButton->setText(QApplication::translate("editor", "\345\233\236\345\205\263\345\215\241\345\210\227\350\241\250", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("editor", "\347\211\251\344\273\266\346\235\277", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("editor", "\345\233\236\344\270\273\350\217\234\345\215\225", Q_NULLPTR));
        label->setText(QApplication::translate("editor", "\350\276\271\351\225\277", Q_NULLPTR));
        label_2->setText(QApplication::translate("editor", "\345\256\275", Q_NULLPTR));
        label_3->setText(QApplication::translate("editor", "\351\225\277", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class editor: public Ui_editor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITOR_H
