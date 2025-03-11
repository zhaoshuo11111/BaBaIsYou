#ifndef EDIT_LEVEL_H
#define EDIT_LEVEL_H

#include <QWidget>
#include <QDir>
#include<QPainter>
#include"config.h"
#include"set_level_name.h"
#include"editor.h"
//#include"search.h"
#include<QPainter>
#include<QStringList>
#include<QGridLayout>
#include<QPushButton>

namespace Ui {
class Edit_Level;
}

class Edit_Level : public QWidget
{
    Q_OBJECT

public:
    explicit Edit_Level(QWidget *parent = 0);
    ~Edit_Level();

    Set_Level_Name set_level_name;
    editor edit;
    void getpath();
    void paintEvent(QPaintEvent *event);
    QString returnname;
    QString levelname;
    QString level[100];
    int levelnum;
    int levelnummax;

    QPixmap levelpix;
    bool judge;
    //search esearch;
signals:
    //返回editor界面信号
    void exit_signal();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::Edit_Level *ui;
};

#endif // EDIT_LEVEL_H
