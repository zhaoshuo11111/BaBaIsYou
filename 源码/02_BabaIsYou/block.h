#ifndef BLOCK_H
#define BLOCK_H

#include "config.h"
#include "animation.h"

#include <QPixmap>
#include <QLabel>

class Block
{
//函数
public:
    Block();
    //坐标更新
    void setPosition(int block_to);
    //载入图片
    void loadPix(int type, int name, bool openAni);

//对象
public:
    //图片资源
    QPixmap block_pix;

    //动图
    Animation block_animation;

    //坐标
    int block_x;
    int block_y;

    //方块边长
    int sideLength;

    //是否可见
    bool block_isVisible;
    //是否可触碰
    bool block_isTouch;
    //是否可操作
    bool block_isMove;
    //是否可推动
    bool block_isPush;
    //是否是胜利方块
    bool block_isWin;
    //是否是危险方块
    bool block_isDanger;
    //是否是自爆方块
    bool block_isBomb;
    //是否M/H
    bool block_isMelt;
    bool block_isHot;
    //是否S/O
    bool block_isShut;
    bool block_isOpen;
    //是否漂浮
    bool block_isFloat;
    //是否溺水
    bool block_isSink;
    //是否是特效方块
    bool block_isDuang;

    //是否被动移动
    bool block_isBeMove;

    //是否生效
    bool block_isTextEffect;

    //是否占用（name修改只能生效一个词条）
    bool block_isWork;
    //朝向
    int block_faceTo;

    //方块类型
    int block_type;     //ty_block=1 ty_subject=1 ty_predicate=2
    //方块名
    int block_name;   //详情见配置文件

    //主角
    int block_moveType;

};

#endif // BLOCK_H
