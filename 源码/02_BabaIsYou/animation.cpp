#include "animation.h"

Animation::Animation()
{

    //下标初始化
    ani_index=0;
    //切图计时初始化
    ani_recorder=0;
}

//——————————————————————————————动画初始化—————————————————————————————————————
//初始化：动图宽高、动图路径、最大下标ani_maxIndex、切图间隔ani_interval
void Animation::iniAni(int interval,int maxIndex,QString str,int height,int width)
{
    ani_pixVector.clear();
    ani_interval=interval;
    ani_maxIndex=maxIndex;
    QPixmap temp;
    QString t_str=str;  //带占位符的路径
    //载入图库
    for(int i=1;i<maxIndex+1;i++)
    {
        //获得多个路径
        str=t_str;
        str = str.arg(i);
        //载入图片
        temp.load(str);
        temp=temp.scaled(width,height,Qt::IgnoreAspectRatio);
        ani_pixVector.push_back(temp);
    }
}

//——————————————————————————————切图计时—————————————————————————————————————
//
void Animation::updateIndex()
{
    ani_recorder++;
    //计时结束
    if(ani_recorder>ani_interval)
    {
        ani_index++;
        ani_recorder=0;
    }
    //下标超出重置
    if(ani_index>=ani_maxIndex)
    {
        ani_index=0;
    }
}
