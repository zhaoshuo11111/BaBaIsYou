#include "lblock.h"

Lblock::Lblock()
{
//    loadPix(999);
    //初始化坐标
    lblock_x=-LENGTH_OF_SIDE_L;
    lblock_y=-LENGTH_OF_SIDE_L;
    //初始化类型
    lblock_type = LTY_NORMAL;
    //初始化关卡所属大地图
    lblock_map =MAP_ISLAND;
    //初始化是否可见
    lblock_isVisible = false;
}

void Lblock::loadPix(int name)
{
    //加载数字关卡
    if(name < TWO_UD)
    {
        QString str;
        str = LBLOCK_NUMBER_PATH;
        str = str.arg(name);
        lblock_pix.load(str);
    }else
    {
        switch (name) {
        case TWO_UD:
            lblock_pix.load(LBLOCK_UD_PATH);
            break;
        case TWO_LR:
            lblock_pix.load(LBLOCK_LR_PATH);
            break;
        case TWO_UL:
            lblock_pix.load(LBLOCK_UL_PATH);
            break;
        case TWO_UR:
            lblock_pix.load(LBLOCK_UR_PATH);
            break;
        case TWO_DL:
            lblock_pix.load(LBLOCK_DL_PATH);
            break;
        case TWO_DR:
            lblock_pix.load(LBLOCK_DR_PATH);
            break;
        case THREE_NOL:
            lblock_pix.load(LBLOCK_NL_PATH);
            break;
        case THREE_NOR:
            lblock_pix.load(LBLOCK_NR_PATH);
            break;
        case THREE_NOU:
            lblock_pix.load(LBLOCK_NU_PATH);
            break;
        case THREE_NOD:
            lblock_pix.load(LBLOCK_ND_PATH);
            break;
        case MOVE:
            lblock_pix.load(LBLOCK_MOVE_PATH);
            break;
        case TOWATER:
            lblock_pix.load(":/res/toWater.png");
            break;
        case TOISLAND:
            lblock_pix.load(":/res/change_1.png");
            break;
        case TOLAVA:
            lblock_pix.load(":/res/toLava.png");
            break;
        default:
            lblock_pix.load(LBLOCK_TEST_PATH);
            break;
        }
    }
    //固定图片大小
    lblock_pix = lblock_pix.scaled(LENGTH_OF_SIDE_L,LENGTH_OF_SIDE_L,Qt::KeepAspectRatio);    //设定图像大小
}
