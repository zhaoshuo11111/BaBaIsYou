#ifndef ANIMATION_H
#define ANIMATION_H


#include "config.h"

#include <QPixmap>
#include <QVector>
#include <QString>
#include <QDebug>



class Animation
{
//函数
public:
    Animation();

    //参数初始化
    void iniAni(int interval,int maxIndex,QString str,int height,int width);
    //更新下标
    void updateIndex();


//对象
public:
    //图库
    QVector<QPixmap> ani_pixVector;
    //切图计时
    int ani_recorder;
    //切图间隔
    int ani_interval;
    //图片下标
    int ani_index;
    //图片最大下标
    int ani_maxIndex;

};

#endif // ANIMATION_H
