#ifndef CHANGE_SCENE_H
#define CHANGE_SCENE_H

#include "config.h"

#include <QTimer>
#include <QTime>
#include <ctime>
#include <QWidget>
#include <QPainter>
#include <QFont>
#include <QPolygon>
#include <QSoundEffect>

namespace Ui {
class Change_Scene;
}

class Change_Scene : public QWidget
{
    Q_OBJECT
//函数
public:
    explicit Change_Scene(QWidget *parent = 0);
    ~Change_Scene();
    //绘画事件
    void paintEvent(QPaintEvent *event);
    //动图开始
    void playAni(int type, QString name);
//对象
public:
    //刷新计时器对象*
    QTimer m_timer;
    //结束计时器
    QTimer m_singelTimer;
    //倍率
    int times;
    //动画类型
    int m_aniType;
    //音乐
    QSoundEffect musicChange;
    //关卡名
    QString levelName;

signals:
    //动画结束信号
    void endAni_signal();

private:
    Ui::Change_Scene *ui;
};

#endif // CHANGE_SCENE_H
