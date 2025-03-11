 #ifndef CHOOSE_SCENE_H
#define CHOOSE_SCENE_H

#include "config.h"
#include "game_scene.h"
#include "change_scene.h"
#include "animation.h"
#include "lblock.h"

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <ctime>
#include <QPainter>
#include <QPalette>
#include <QFile>
#include <QMovie>

//调试用
#include <QDebug>


namespace Ui {
class Choose_Scene;
}

class Choose_Scene : public QWidget
{
    Q_OBJECT
//函数
public:
    explicit Choose_Scene(QWidget *parent = 0);
    ~Choose_Scene();

    //背景动图开始
    void playAni();
    //绘图事件
    void paintEvent(QPaintEvent *event);
    //地图初始化
    void iniMap(int map,int scores);
    //行读取
    int readLineInt(QFile &file);
    //键盘事件
    void keyPressEvent(QKeyEvent *event);
    //获取当前名
    void getNowName();

//对象
public:
    //游戏界面
    Game_Scene sce_game;

    //当前背景标识
    int back_mark;

    //背景动画
    Animation m_backGround_1;
    Animation m_backGround_2;

    Animation m_backGround_3;

    Animation m_backGround_4;

    //计时器对象*
    QTimer m_timer;

    //关卡方块
    Lblock m_lblocks[LBLOCK_NUM];

    //重加载游戏地图参数
    int game_map;
    int game_name;

    //分数
    int score;

    //关卡名
    QString islandName[20]={"Baba Is You","我到哪里去？","这次是什么？","遥不可及","仍遥不可及","火山","禁止入内","草地"};
    QString waterName[20]={" ","冰水","接手","沉默的遗迹","柱子庭园","砖墙","锁","见习锁匠","锁在里面","不变","二扇门","水木玉座","藏蟹室","盗窃"};
    QString lavaName[20]={" ","浮游","温暖的河","建造桥梁","建造桥梁？","胜利之泉水","组装队"," 小岛","小小池塘","沸腾的河","....桥？","监狱"};

    QString nowName=" ";

//信号
signals:
    //chooseToGuide信号
    void chooseToGuide_signal();
    //chooseToGame信号
    void chooseToGame_signal();
    //toWater
    void toWater_signal();
    //toLava
    void toLava_signal();
    //toIsland
    void toIsland_signal();

private slots:
    //返回guide界面
    void on_b1_exit_released();

    void on_b2_gameStart_released();

private:
    Ui::Choose_Scene *ui;
};

#endif // CHOOSE_SCENE_H
