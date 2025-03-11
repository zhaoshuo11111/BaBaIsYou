#ifndef EDITOR_H
#define EDITOR_H
#define one_per_time 1
#define many_per_time 2
#define recordmax 1000

#include "block.h"
#include "game_scene.h"
#include"term_borad.h"

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <ctime>
#include <QPainter>
#include <QFile>
#include<QTextStream>
#include<QMouseEvent>
namespace Ui {
class editor;
}

class editor : public QWidget
{
    Q_OBJECT

public:
    explicit editor(QWidget *parent = 0);
    ~editor();

    //绘图事件*
    void paintEvent(QPaintEvent *event);
    //初始化右上角可供选择的图标
    void initoptions();
    void place(int tpos_x,int tpos_y);//tempposition,临时记录方块应放置的位置
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    bool readmap(QString path);
    int readLineInt(QFile &file);
    //对象
    int record[recordmax];
    int recordnum;//有多少条记录
    int placenum;
    bool ismove;//判断是否有拖动
    bool place_map[25][12];//用于拖动连续放置方块
    int place_method;
    //计时器对象*
    QTimer m_timer;
    //方块对象
    Block m_blocks[BLOCK_NUM];

    //对应游戏界面效果图
    QPixmap m_background;
    //测试地图
    Game_Scene Game_Testlevel;
    //物品栏
    Term_Borad term;

    //QFile efile;
    QString level_name;

    QString filepath;
    //现在选中的方块类型名称
    int now_b_pos;
    int now_type;
    int now_name;


signals:

    void return_to_guide_scene();
    void return_to_level();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();



    void on_pushButton_4_clicked();

private:
    Ui::editor *ui;
    int bl_num;
};

#endif // EDITOR_H
