#ifndef LBLOCK_H
#define LBLOCK_H

#include "config.h"

#include <QPixmap>

class Lblock
{
//函数
public:
    Lblock();
    //图片初始化
    void loadPix(int name);

//对象
    //图片
    QPixmap lblock_pix;
    //坐标
    int lblock_x;
    int lblock_y;
    //方块类型
    int lblock_type;
    //方块名
    int lblock_name;
    //方块所属大地图
    int lblock_map;
    //方块是否可见
    bool lblock_isVisible;
    //关卡
};

#endif // LBLOCK_H
