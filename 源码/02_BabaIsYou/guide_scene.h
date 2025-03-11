#ifndef GUIDE_SCENE_H
#define GUIDE_SCENE_H

#include "config.h"
#include "setting_scene.h"
#include "game_scene.h"

#include "choose_scene.h"
#include "change_scene.h"
#include "edit_level.h"


#include <QWidget>
#include <QDebug>
#include <QTimer>
#include <QPainter>
#include <QPixmap>
#include <QMovie>
#include <QSoundEffect>
#include <QSound>
#include <QIcon>
#include <QMouseEvent>
#include <QCursor>

namespace Ui {
class Guide_Scene;
}

class Guide_Scene : public QWidget
{
    Q_OBJECT

//函数
public:
    explicit Guide_Scene(QWidget *parent = 0);
    ~Guide_Scene();
    //启动刷新
    void playAni();
    //绘图事件*
    void paintEvent(QPaintEvent *event);
    //读行文件
    int readLineInt(QFile &file);
    //初始化积分
    void iniScore();
    //上传积分
    void uploadScore();
    //音乐播放
    void musicPlay(int type);


//对象
public:
    //设定页
    Setting_Scene sce_setting;
    //
    Edit_Level sce_editor;
    //关卡选择页
    Choose_Scene sce_choose;
    //切换页
    Change_Scene sce_change;

    //计时器
    QTimer m_timer;
    //背景图1
    QPixmap m_back1;
    //背景图2
    QPixmap m_back2;
    //背景动画坐标
    int x1;
    int x2;
    int y1;
    int y2;

    //切屏类型
    int alterType;

    //通关分数
    int yourScore[3][20];
    //分数
    int score=0;

    //音乐
    double musicVolume;

    QSoundEffect musicBaba;
    QSoundEffect musicMenu;
    QSoundEffect musicMAP;
    QSoundEffect musicStar;
    QSoundEffect musicCrystal;
    QSoundEffect musicRain;

    QSoundEffect buttonUp_0;
    QSoundEffect buttonUp_1;
    QSoundEffect buttonUp_2;

    QSoundEffect beastDesu;
    int buI;
    //音效单次播放
    bool canButton;
    //当前窗口最上层
    bool inTop;

private slots:
    void on_b4_exit_released();

    void on_b2_setting_released();

    void on_b3_editor_released();

    void on_b1_newgame_released();


    void winLevel(int map,int level);

    void eVChange(int value);

    void mVChange(int value);

private:
    Ui::Guide_Scene *ui;
};

#endif // GUIDE_SCENE_H
