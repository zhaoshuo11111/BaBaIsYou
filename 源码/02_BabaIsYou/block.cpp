#include "block.h"

Block::Block()
{
    loadPix(0,999,true);

    //初始化坐标
    block_x=-LENGTH_OF_SIDE;
    block_y=-LENGTH_OF_SIDE;

    //初始化边长
    sideLength = LENGTH_OF_SIDE;

    //初始化类型
    block_type=TY_BLOCK;
    //初始化可触碰
    block_isTouch=false;
    //初始化可操作
    block_isMove=false;
    //初始化可推动
    block_isPush=false;
    //初始化可视
    block_isVisible=false;
    //初始化胜利方块
    block_isWin=false;
    //初始化危险方块
    block_isDanger=false;
    //初始化自爆方块
    block_isBomb=false;
    //是否M/H
    block_isMelt=false;
    block_isHot=false;
    //是否S/O
    block_isShut=false;
    block_isOpen=false;
    //是否漂浮
    block_isFloat=false;
    //是否溺水
    block_isSink=false;
    //是否特效
    block_isDuang=false;


    //是否生效
    block_isTextEffect=false;
    //是否占用
    block_isWork=false;

    block_moveType = 0;
}

//——————————————————————————————坐标更新—————————————————————————————————————
//从键盘获得值
void Block::setPosition(int block_to)   //up=0,down=1,left=2,right=3,noway=4
{
    switch (block_to) {
    case DIR_UP:
        block_y-=sideLength;
        break;
    case DIR_DOWN:
        block_y+=sideLength;
        break;
    case DIR_LEFT:
        block_x-=sideLength;
        break;
    case DIR_RIGHT:
        block_x+=sideLength;
        break;
    default:
        break;
    }
}

//——————————————————————————————加载图片—————————————————————————————————————
//根据type和name加载图片
void Block::loadPix(int type,int name,bool openAni)
{
    //-----赵硕感觉要加
    block_type=type;
    block_name=name;
    //加载三种text类型的图片
    if(openAni == false)
    {
        if(type == TY_PREDICATE || type == TY_NAME || type == TY_ADJ)
            {
                switch (name) {
                case NAME_BABA:
                    block_pix.load(TEXT_BABA_PATH);
                    break;
                case NAME_FLAG:
                    block_pix.load(TEXT_FLAG_PATH);
                    break;
                case NAME_KEKE:
                    block_pix.load(TEXT_KEKE_PATH);
                    break;
                case NAME_CRAB:
                    block_pix.load(TEXT_CRAB_PATH);
                    break;
                case NAME_ROCK:
                    block_pix.load(TEXT_ROCK_PATH);
                    break;
                case NAME_WALL:
                    block_pix.load(TEXT_WALL_PATH);
                    break;
                case NAME_WATER:
                    block_pix.load(TEXT_WATER_PATH);
                    break;
                case NAME_YOU:
                    block_pix.load(TEXT_YOU_PATH);
                    break;
                case NAME_STOP:
                    block_pix.load(TEXT_STOP_PATH);
                    break;
                case NAME_WIN:
                    block_pix.load(TEXT_WIN_PATH);
                    break;
                case NAME_PUSH:
                    block_pix.load(TEXT_PUSH_PATH);
                    break;
                case NAME_DEFEAT:
                    block_pix.load(TEXT_DEFEAT_PATH);
                    break;
                case NAME_SINK:
                    block_pix.load(TEXT_SINK_PATH);
                    break;
                case NAME_IS:
                    block_pix.load(TEXT_IS_PATH);
                    break;
                case NAME_AND:
                    block_pix.load(TEXT_AND_PATH);
                    break;
                    //
                case NAME_LAVA:
                    block_pix.load(TEXT_LAVA_PATH);
                    break;
                case NAME_SKULL:
                    block_pix.load(TEXT_SKULL_PATH);
                    break;
                case NAME_GRASS:
                    block_pix.load(TEXT_GRASS_PATH);
                    break;
                case NAME_JELLY:
                    block_pix.load(TEXT_JELLY_PATH);
                    break;
                case NAME_STAR:
                    block_pix.load(TEXT_STAR_PATH);
                    break;
                case NAME_ALGAE:
                    block_pix.load(TEXT_ALGAE_PATH);
                    break;
                case NAME_LOVE:
                    block_pix.load(TEXT_LOVE_PATH);
                    break;
                case NAME_PILLAR:
                    block_pix.load(TEXT_PILLAR_PATH);
                    break;
                case NAME_DOOR:
                    block_pix.load(TEXT_DOOR_PATH);
                    break;
                case NAME_KEY:
                    block_pix.load(TEXT_KEY_PATH);
                    break;
                case NAME_HEDGE:
                    block_pix.load(TEXT_HEDGE_PATH);
                    break;
                case NAME_COG:
                    block_pix.load(TEXT_COG_PATH);
                    break;
                case NAME_TEXT:
                    block_pix.load(TEXT_TEXT_PATH);
                    break;
                case NAME_MELT:
                    block_pix.load(TEXT_MELT_PATH);
                    break;
                case NAME_MOVE:
                    block_pix.load(TEXT_MOVE_PATH);
                    break;
                case NAME_SHUT:
                    block_pix.load(TEXT_SHUT_PATH);
                    break;
                case NAME_OPEN:
                    block_pix.load(TEXT_OPEN_PATH);
                    break;
                case NAME_FLOAT:
                    block_pix.load(TEXT_FLOAT_PATH);
                    break;
                case NAME_HOT:
                    block_pix.load(TEXT_HOT_PATH);
                    break;

                default:
                    block_pix.load(BLOCK_TEST_PATH);
                    break;
                }
            }
            else   //鍔犺浇block绫诲瀷鐨勫浘鐗?
            {
                switch (name) {
                case NAME_BABA:
                    block_pix.load(BLOCK_BABA_PATH);
                    break;
                case NAME_FLAG:
                    block_pix.load(BLOCK_FLAG_PATH);
                    break;
                case NAME_CRAB:
                    block_pix.load(BLOCK_CRAB_PATH);
                    break;
                case NAME_KEKE:
                    block_pix.load(BLOCK_KEKE_PATH);
                    break;
                case NAME_ROCK:
                    block_pix.load(BLOCK_ROCK_PATH);
                    break;
                case NAME_WALL:
                    block_pix.load(BLOCK_WALL_PATH);
                    break;
                case NAME_WATER:
                    block_pix.load(BLOCK_WATER_PATH);
                    break;

                case NAME_LAVA:
                    block_pix.load(BLOCK_LAVA_PATH);
                    break;
                case NAME_SKULL:
                    block_pix.load(BLOCK_SKULL_PATH);
                    break;
                case NAME_GRASS:
                    block_pix.load(BLOCK_GRASS_PATH);
                    break;
                case NAME_JELLY:
                    block_pix.load(BLOCK_JELLY_PATH);
                    break;
                case NAME_STAR:
                    block_pix.load(BLOCK_STAR_PATH);
                    break;
                case NAME_ALGAE:
                    block_pix.load(BLOCK_ALGAE_PATH);
                    break;
                case NAME_LOVE:
                    block_pix.load(BLOCK_LOVE_PATH);
                    break;
                case NAME_PILLAR:
                    block_pix.load(BLOCK_PILLAR_PATH);
                    break;
                case NAME_DOOR:
                    block_pix.load(BLOCK_DOOR_PATH);
                    break;
                case NAME_KEY:
                    block_pix.load(BLOCK_KEY_PATH);
                    break;
                case NAME_HEDGE:
                    block_pix.load(BLOCK_HEDGE_PATH);
                    break;
                case NAME_COG:
                    block_pix.load(BLOCK_COG_PATH);
                    break;
                default:
                    block_pix.load(BLOCK_TEST_PATH);
                    break;
                }
            }
            block_pix = block_pix.scaled(LENGTH_OF_SIDE,LENGTH_OF_SIDE,Qt::KeepAspectRatio);
    }
    else
    {
        if(type == TY_PREDICATE || type == TY_NAME || type == TY_ADJ)
        {
            switch (name) {
            case NAME_BABA:
                block_animation.iniAni(40,3,":/res/text_baba_0_%1",sideLength,sideLength);
                break;
            case NAME_FLAG:
                block_animation.iniAni(40,3,":/res/text_flag_0_%1",sideLength,sideLength);
                break;
            case NAME_KEKE:
                block_animation.iniAni(40,3,":/res/text_keke_0_%1",sideLength,sideLength);
                break;
            case NAME_CRAB:
                block_animation.iniAni(40,3,":/res/text_crab_0_%1",sideLength,sideLength);
                break;
            case NAME_ROCK:
                block_animation.iniAni(40,3,":/res/text_rock_0_%1",sideLength,sideLength);
                break;
            case NAME_WALL:
                block_animation.iniAni(40,3,":/res/text_wall_0_%1",sideLength,sideLength);
                break;
            case NAME_YOU:
                block_animation.iniAni(40,3,":/res/text_you_0_%1",sideLength,sideLength);
                break;
            case NAME_STOP:
                block_animation.iniAni(40,3,":/res/text_stop_0_%1",sideLength,sideLength);
                break;
            case NAME_WIN:
                block_animation.iniAni(40,3,":/res/text_win_0_%1",sideLength,sideLength);
                break;
            case NAME_PUSH:
                block_animation.iniAni(40,3,":/res/text_push_0_%1",sideLength,sideLength);
                break;
            case NAME_DEFEAT:
                block_animation.iniAni(40,3,":/res/text_defeat_0_%1",sideLength,sideLength);
                break;
            case NAME_SINK:
                block_animation.iniAni(40,3,":/res/text_sink_0_%1",sideLength,sideLength);
                break;
            case NAME_IS:
                block_animation.iniAni(40,3,":/res/text_is_0_%1",sideLength,sideLength);
                break;
            case NAME_AND:
                block_animation.iniAni(40,3,":/res/text_and_0_%1",sideLength,sideLength);
                break;
            case NAME_LAVA:
                block_animation.iniAni(40,3,":/res/text_lava_0_%1",sideLength,sideLength);
                break;
            case NAME_SKULL:
                block_animation.iniAni(40,3,":/res/text_skull_0_%1",sideLength,sideLength);
                break;
            case NAME_GRASS:
                block_animation.iniAni(40,3,":/res/text_grass_0_%1",sideLength,sideLength);
                break;
            case NAME_JELLY:
                block_animation.iniAni(40,3,":/res/text_jelly_0_%1",sideLength,sideLength);
                break;
            case NAME_STAR:
                block_animation.iniAni(40,3,":/res/text_star_0_%1",sideLength,sideLength);
                break;
            case NAME_ALGAE:
                block_animation.iniAni(40,3,":/res/text_algae_0_%1",sideLength,sideLength);
                break;
            case NAME_LOVE:
                block_animation.iniAni(40,3,":/res/text_love_0_%1",sideLength,sideLength);
                break;
            case NAME_PILLAR:
                block_animation.iniAni(40,3,":/res/text_pillar_0_%1",sideLength,sideLength);
                break;
            case NAME_DOOR:
                block_animation.iniAni(40,3,":/res/text_door_0_%1",sideLength,sideLength);
                break;
            case NAME_KEY:
                block_animation.iniAni(40,3,":/res/text_key_0_%1",sideLength,sideLength);
                break;
            case NAME_HEDGE:
                block_animation.iniAni(40,3,":/res/text_hedge_0_%1",sideLength,sideLength);
                break;
            case NAME_COG:
                block_animation.iniAni(40,3,":/res/text_cog_0_%1",sideLength,sideLength);
                break;
            case NAME_TEXT:
                block_animation.iniAni(40,3,":/res/text_text_0_%1",sideLength,sideLength);
                break;
            case NAME_MELT:
                block_animation.iniAni(40,3,":/res/text_melt_0_%1",sideLength,sideLength);
                break;
            case NAME_MOVE:
                block_animation.iniAni(40,3,":/res/text_move_0_%1",sideLength,sideLength);
                break;
            case NAME_SHUT:
                block_animation.iniAni(40,3,":/res/text_shut_0_%1",sideLength,sideLength);
                break;
            case NAME_OPEN:
                block_animation.iniAni(40,3,":/res/text_open_0_%1",sideLength,sideLength);
                break;
            case NAME_FLOAT:
                block_animation.iniAni(40,3,":/res/text_float_0_%1",sideLength,sideLength);
                break;
            case NAME_HOT:
                block_animation.iniAni(40,3,":/res/text_hot_0_%1",sideLength,sideLength);
                break;
            case NAME_WATER:
                block_animation.iniAni(40,3,":/res/text_water_0_%1",sideLength,sideLength);
                break;
            default:
                break;
            }
        }else   //加载block类型的图片
        {
            switch (name) {
            case NAME_BABA:
                block_animation.iniAni(40,3,":/res/baba_0_%1",sideLength,sideLength);
                break;
            case NAME_FLAG:
                block_animation.iniAni(40,3,":/res/flag_0_%1",sideLength,sideLength);
                break;
            case NAME_CRAB:
                block_animation.iniAni(40,3,":/res/crab_0_%1",sideLength,sideLength);
                break;
            case NAME_KEKE:
                block_animation.iniAni(40,3,":/res/keke_0_%1",sideLength,sideLength);
                break;
            case NAME_ROCK:
                block_animation.iniAni(40,3,":/res/rock_0_%1",sideLength,sideLength);
                break;
            case NAME_WALL:
                block_animation.iniAni(40,3,":/res/wall_0_%1",sideLength,sideLength);
                break;
            case NAME_WATER:
                block_animation.iniAni(40,3,":/res/water_0_%1",sideLength,sideLength);
                break;
            case NAME_LAVA:
                block_animation.iniAni(40,3,":/res/lava_0_%1",sideLength,sideLength);
                break;
            case NAME_SKULL:
                block_animation.iniAni(40,3,":/res/skull_24_%1",sideLength,sideLength);
                break;
            case NAME_GRASS:
                block_animation.iniAni(40,3,":/res/grass_0_%1",sideLength,sideLength);
                break;
            case NAME_JELLY:
                block_animation.iniAni(40,3,":/res/jelly_0_%1",sideLength,sideLength);
                break;
            case NAME_STAR:
                block_animation.iniAni(40,3,":/res/star_0_%1",sideLength,sideLength);
                break;
            case NAME_ALGAE:
                block_animation.iniAni(40,3,":/res/algae_0_%1",sideLength,sideLength);
                break;
            case NAME_LOVE:
                block_animation.iniAni(40,3,":/res/love_0_%1",sideLength,sideLength);
                break;
            case NAME_PILLAR:
                block_animation.iniAni(40,3,":/res/pillar_0_%1",sideLength,sideLength);
                break;
            case NAME_DOOR:
                block_animation.iniAni(40,3,":/res/door_0_%1",sideLength,sideLength);
                break;
            case NAME_KEY:
                block_animation.iniAni(40,3,":/res/key_0_%1",sideLength,sideLength);
                break;
            case NAME_HEDGE:
                block_animation.iniAni(40,3,":/res/hedge_0_%1",sideLength,sideLength);
                break;
            case NAME_COG:
                block_animation.iniAni(40,3,":/res/cog_0_%1",sideLength,sideLength);
                break;
            default:
                break;
            }
        }
    }

}


