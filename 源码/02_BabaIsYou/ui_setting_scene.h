/********************************************************************************
** Form generated from reading UI file 'setting_scene.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_SCENE_H
#define UI_SETTING_SCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Setting_Scene
{
public:
    QPushButton *b6_exit;
    QSlider *s1_dffectVolum;
    QSlider *s2_musicVolum;
    QLabel *l1_effect;
    QLabel *l2_music;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *b2_animation;
    QPushButton *b3_shake;

    void setupUi(QWidget *Setting_Scene)
    {
        if (Setting_Scene->objectName().isEmpty())
            Setting_Scene->setObjectName(QStringLiteral("Setting_Scene"));
        Setting_Scene->setEnabled(true);
        Setting_Scene->resize(894, 447);
        Setting_Scene->setStyleSheet(QStringLiteral(""));
        b6_exit = new QPushButton(Setting_Scene);
        b6_exit->setObjectName(QStringLiteral("b6_exit"));
        b6_exit->setGeometry(QRect(220, 70, 201, 40));
        b6_exit->setMinimumSize(QSize(60, 40));
        s1_dffectVolum = new QSlider(Setting_Scene);
        s1_dffectVolum->setObjectName(QStringLiteral("s1_dffectVolum"));
        s1_dffectVolum->setGeometry(QRect(540, 200, 271, 22));
        s1_dffectVolum->setOrientation(Qt::Horizontal);
        s2_musicVolum = new QSlider(Setting_Scene);
        s2_musicVolum->setObjectName(QStringLiteral("s2_musicVolum"));
        s2_musicVolum->setGeometry(QRect(540, 320, 271, 22));
        s2_musicVolum->setOrientation(Qt::Horizontal);
        l1_effect = new QLabel(Setting_Scene);
        l1_effect->setObjectName(QStringLiteral("l1_effect"));
        l1_effect->setGeometry(QRect(440, 190, 79, 41));
        l1_effect->setMinimumSize(QSize(40, 30));
        l1_effect->setStyleSheet(QString::fromUtf8("font: normal normal 15px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: white;"));
        l2_music = new QLabel(Setting_Scene);
        l2_music->setObjectName(QStringLiteral("l2_music"));
        l2_music->setGeometry(QRect(440, 280, 79, 89));
        l2_music->setMinimumSize(QSize(40, 30));
        l2_music->setStyleSheet(QString::fromUtf8("font: normal normal 15px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: white;"));
        widget = new QWidget(Setting_Scene);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(60, 160, 359, 221));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        b2_animation = new QPushButton(widget);
        b2_animation->setObjectName(QStringLiteral("b2_animation"));
        b2_animation->setMinimumSize(QSize(60, 80));

        verticalLayout_2->addWidget(b2_animation);

        b3_shake = new QPushButton(widget);
        b3_shake->setObjectName(QStringLiteral("b3_shake"));
        b3_shake->setMinimumSize(QSize(60, 80));

        verticalLayout_2->addWidget(b3_shake);


        retranslateUi(Setting_Scene);

        QMetaObject::connectSlotsByName(Setting_Scene);
    } // setupUi

    void retranslateUi(QWidget *Setting_Scene)
    {
        Setting_Scene->setWindowTitle(QApplication::translate("Setting_Scene", "\350\256\276\347\275\256", Q_NULLPTR));
        b6_exit->setText(QApplication::translate("Setting_Scene", "\350\277\224\345\233\236", Q_NULLPTR));
        l1_effect->setText(QApplication::translate("Setting_Scene", "\351\237\263\346\225\210\346\216\247\345\210\266", Q_NULLPTR));
        l2_music->setText(QApplication::translate("Setting_Scene", "\351\237\263\344\271\220\346\216\247\345\210\266", Q_NULLPTR));
        b2_animation->setText(QApplication::translate("Setting_Scene", "\351\227\262\347\275\256\345\212\250\347\224\273\357\274\232\345\274\200", Q_NULLPTR));
        b3_shake->setText(QApplication::translate("Setting_Scene", "\345\261\217\345\271\225\346\212\226\345\212\250\357\274\232\345\274\200", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Setting_Scene: public Ui_Setting_Scene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_SCENE_H
