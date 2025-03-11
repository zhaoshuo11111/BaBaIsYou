#ifndef TERM_BORAD_H
#define TERM_BORAD_H

#define ALL_SHOW 4
#include "config.h"
#include"block.h"
#include"search.h"


#include <QWidget>
#include <QTimer>
#include <QTime>
#include <ctime>
#include <QPainter>
#include<QMouseEvent>

namespace Ui {
class Term_Borad;
}

class Term_Borad : public QWidget
{
    Q_OBJECT

public:
    explicit Term_Borad(QWidget *parent = 0);
    ~Term_Borad();
    //绘图事件*
    void paintEvent(QPaintEvent *event);
    //初始化右上角可供选择的图标
    void initoptions();
    void updateblocks();
    void mousePressEvent(QMouseEvent *event);
    //初始化allname数组
    void iniallname();
    QString switch_num_to_name(int a);
    //计时器对象*
    QTimer m_timer;
    //方块对象
    Block m_blocks[BLOCK_NUM];
    //对应游戏界面效果图
    QPixmap m_background;
    search tsearch;
    QString searchword;
    int bl_num;
    int typeb;
    int emittype;
    int emitname;
    bool issearch;
    QString allname[70];//看后期要不要扩大

signals:
    void back_to_editor();
    void have_chosen();
private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Term_Borad *ui;
};

#endif // TERM_BORAD_H
