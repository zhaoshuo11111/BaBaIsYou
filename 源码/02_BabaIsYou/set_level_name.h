#ifndef SET_LEVEL_NAME_H
#define SET_LEVEL_NAME_H

#include <QWidget>
#include <QPainter>
#include"editor.h"
#include"config.h"
namespace Ui {
class Set_Level_Name;
}

class Set_Level_Name : public QWidget
{
    Q_OBJECT

public:
    explicit Set_Level_Name(QWidget *parent = 0);
    ~Set_Level_Name();

    void paintEvent(QPaintEvent *event);
    QString name;
signals:
    void return_to_level();
    void return_to_guide_scene();
    void getname();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Set_Level_Name *ui;
};

#endif // SET_LEVEL_NAME_H
