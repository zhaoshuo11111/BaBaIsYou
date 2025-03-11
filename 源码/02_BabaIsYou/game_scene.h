#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "config.h"
#include "block.h"
#include "pause_scene.h"
#include "change_scene.h"

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <ctime>
#include <QPainter>
#include <QKeyEvent>
#include <QFile>
#include <QStack>
#include <QSoundEffect>
#include <QSound>
#include <QMediaPlayer>

namespace Ui {
class Game_Scene;
}

class Game_Scene : public QWidget
{
    Q_OBJECT
//函数
public:
    explicit Game_Scene(QWidget *parent = 0);
    ~Game_Scene();

    //启动游戏 开始利用计数器刷新画面和坐标*(加星号的是实时刷新的)
    void playGame();
        //绘图事件*
        void paintEvent(QPaintEvent *event);
        //键盘事件
        void keyPressEvent(QKeyEvent *event);
        //方块移动和推动*
        bool blockMove(int key_value,int i,bool isFirst);
            //边界判断
            bool isBorder(int key_value,int i);

    //初始化词条
    void iniText();
    //地图初始化
    void iniMAP(int map, int name, QString qName, int mode);
        //文件行int读取
        int readLineInt(QFile &file);

    //方块修改
    void updateBlock();
    //属性（效果）更新
    void updateEffect();
        //属性（效果）修改
        void changeEffect(int k,int j);
    //效果实现
    void effectWork();
        //方块清除
        void killBlock(int i);
        //胜利效果
        void winGame();
        //屏幕抖动
        void shakeWindow();

    //撤销功能
        //记录信息
        void pushStack(int x,int y,int num);
        //返回
        void popStack();

    //提示按键
        void isDeadGame();

//对象
public:
    //计时器对象*
    QTimer m_timer;

    QTimer m_shakeTimer;

    QTimer m_shakeTimerEnd;
    //方块对象
    Block m_blocks[BLOCK_NUM];

    //背景图
    QPixmap m_background;
    QPixmap m_ubackground_1;
    QPixmap m_ubackground_2;

    //暂停界面
    Pause_Scene sce_pause;
        //暂停状态
        bool isPause;
    //胜利标记
    bool isWin;

    struct block_data
    {
        int x;
        int y;
        int num;

        int name;
    };
    //信息记录栈
    QStack<block_data> remStack;
    //单词撤回量栈
    QStack<int> numStack;
    //临时变量，记录单次键入改变方块数
    int popNum;


    //地图与关卡名
    int nowMap;
    int nowLevel;

    //动态屏幕
    int columNum;
    int rowNum;
    int sideLength;


    int inHeight;
    int inWidth;

    int originX;
    int originY;

    //动效
    bool openAni;

    //屏幕抖动
    bool shakeWin;
    bool beginShake;

    //音效
    double soundVolume;
    QSoundEffect move_sound;
    QSoundEffect move_sound_2;

    QSoundEffect win_sound;

    QSoundEffect defeat_sound;
    QSoundEffect effectUpdate_sound;

    //保障胜利信号只发送一次
    bool canWin;

    //同名占用
    bool allName[100];

    //上上下下（漂浮）
    int upAndDown;
    bool goUp;

    //生效词条数
    int effectTextNum;



//信号
signals:
    //返回choose_scene界面的胜利信号
    void win_signal(int map,int level);
    //重开信号
    void restart_signal();



private slots:


private:
    Ui::Game_Scene *ui;
};

#endif // GAME_SCENE_H
