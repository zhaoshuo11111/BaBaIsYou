#ifndef CONFIG_H
#define CONFIG_H

#include<QDebug>
//这是配置文件
//————————————————调试配置——————————————————
#define cout qDebug() <<"[" <<__FILE__ <<":" <<__LINE__ <<"]"
//————————————————其他配置——————————————————
//方向
#define DIR_UP 0
#define DIR_DOWN 1
#define DIR_LEFT 2
#define DIR_RIGHT 3
#define DIR_NOWAY 4
//方块类型
#define TY_BLOCK 0
#define TY_PREDICATE 1
#define TY_NAME 2
#define TY_ADJ 3
//方块名
#define NAME_NOTHING -1


#define NAME_BABA 0
#define NAME_FLAG 1
#define NAME_KEKE 2
#define NAME_CRAB 3
#define NAME_ROCK 4
#define NAME_WALL 5
#define NAME_WATER 6

#define	NAME_LAVA	7
#define	NAME_SKULL	8
#define	NAME_GRASS	9
#define	NAME_JELLY	10
#define	NAME_STAR	11
#define	NAME_ALGAE	12
#define	NAME_LOVE	13
#define	NAME_PILLAR	14
#define	NAME_DOOR	15
#define	NAME_KEY	16
#define	NAME_HEDGE	17
#define	NAME_COG	18

#define	NAME_TEXT	19
//ADJ
#define	NAME_MELT	20
#define NAME_YOU 21
#define NAME_STOP 22
#define NAME_WIN 23
#define NAME_PUSH 24
#define NAME_DEFEAT 25
#define NAME_SINK 26
#define	NAME_MOVE	27
#define	NAME_SHUT	28
#define	NAME_OPEN	29
#define	NAME_FLOAT	30
#define NAME_HOT 31
//谓语
#define	NAME_IS     32
#define	NAME_AND	33




//动画类型
#define ANI_TYPE_1 0
#define ANI_TYPE_2 1
#define ANI_TYPE_3 2
#define ANI_TYPE_4 3

//关卡方块类型
#define LTY_NORMAL 0
#define LTY_LEVEL 1
#define LTY_CHANGE 2
#define LTY_MOVE 3
//关卡方块所属地图
#define MAP_ISLAND 0
#define MAP_WATER 1
#define MAP_LAVA 2
//关卡方块名
//数字关卡直接用数字
#define TWO_UD 30
#define TWO_LR 31
#define TWO_UL 32
#define TWO_UR 33
#define TWO_DL 34
#define TWO_DR 35
#define THREE_NOL 36
#define THREE_NOR 37
#define THREE_NOU 38
#define THREE_NOD 39
#define FOUR 40

#define TOWATER 50
#define TOISLAND 51
#define TOLAVA 52

#define MOVE 60

//————————————————窗口配置——————————————————
#define SCENE_M_HEIGHT 560         //主窗口main
#define SCENE_M_WIDTH 1040

#define SCENE_S_HEIGHT 448  //副窗口sub
#define SCENE_S_WIDTH 896

#define SCENE_E_HEIGHT 560 //编辑器窗口editor
#define SCENE_E_WIDTH 1040

#define GAME_RATE 10  //屏幕刷新速率

#define COLUM_NUM 25 //屏幕可放置方块列数
#define ROW_NUM 12  //屏幕可放置方块行数


#define EBACKGROUND ":/res/uback1.png"
#define BACKGROUND_PATH ":/res/bback_2.png"  //game_scene背景图路径
#define BACKGROUND_1_PATH ":/res/back_2.png"    //guide_scene背景图路径
#define QSS_PATH_1 ":/testQss.qss"    //qss文件     //注：QSS文件只能放在“/”层，即最上层，不然无法找到   //01

#define SCENE_MARGIN 20 //窗口空白

#define GUIDE_TO_CHOOSE 0   //窗口跳转类型
#define CHOOSE_TO_GUIDE 1
#define CHOOSE_TO_GAME 2
#define GAME_TO_CHOOSE 3
#define GAME_TO_GUIDE 4
#define GAME_TO_CHOOSE_WIN 5
#define TO_WATER 6
#define TO_LAVA 7
#define TO_ISLAND 8
//关卡编辑器还未定义

//————————————————方块/词条配置——————————————————
#define LENGTH_OF_SIDE 40   //方块边长
//#define BLOCK_NUM 20 //方块数量
//#define TEXT_NUM 20 //词条数量
//不能太多？
//——————————感觉根本不够
#define BLOCK_NUM 1000 //更新后方块数量    //01

//————————————————方块图片配置——————————————————
#define BLOCK_TEST_PATH ":/res/block_test.png"  //测试方块
#define BLOCK_BABA_PATH ":/res/baba_0_1.png"
#define BLOCK_FLAG_PATH ":/res/flag_0_1.png"
#define BLOCK_KEKE_PATH ":/res/keke_0_1.png"
#define BLOCK_CRAB_PATH ":/res/crab_0_1.png"
#define BLOCK_ROCK_PATH ":/res/rock_0_1.png"
#define BLOCK_WALL_PATH ":/res/wall_0_1.png"
#define BLOCK_WATER_PATH ":/res/water_0_1.png"
#define	BLOCK_LAVA_PATH     ":/res/lava_0_1.png"
#define	BLOCK_SKULL_PATH	":/res/skull_24_1.png"
#define	BLOCK_GRASS_PATH	":/res/grass_0_1.png"
#define	BLOCK_JELLY_PATH	":/res/jelly_0_1.png"
#define	BLOCK_STAR_PATH     ":/res/star_0_1.png"
#define	BLOCK_ALGAE_PATH	":/res/Algae_0_1.png"
#define	BLOCK_LOVE_PATH     ":/res/love_0_1.png"
#define	BLOCK_PILLAR_PATH	":/res/pillar_0_1.png"
#define	BLOCK_DOOR_PATH     ":/res/door_0_1.png"
#define	BLOCK_KEY_PATH      ":/res/key_0_1.png"
#define	BLOCK_HEDGE_PATH	":/res/hedge_0_1.png"
#define	BLOCK_COG_PATH      ":/res/cog_0_1.png"


#define TEXT_BABA_PATH ":/res/text_baba_0_2.png"
#define TEXT_FLAG_PATH ":/res/text_flag_0_1.png"
#define TEXT_KEKE_PATH ":/res/text_keke_0_3.png"
#define TEXT_CRAB_PATH ":/res/text_crab_0_1.png"
#define TEXT_ROCK_PATH ":/res/text_rock_0_1.png"
#define TEXT_WALL_PATH ":/res/text_wall_0_1.png"
#define TEXT_WATER_PATH     ":/res/text_water_0_1.png"
#define	TEXT_LAVA_PATH      ":/res/text_lava_0_1.png"
#define	TEXT_SKULL_PATH     ":/res/text_skull_0_1.png"
#define	TEXT_GRASS_PATH     ":/res/text_grass_0_1.png"
#define	TEXT_JELLY_PATH     ":/res/text_jelly_0_1.png"
#define	TEXT_STAR_PATH      ":/res/text_star_0_1.png"
#define	TEXT_ALGAE_PATH     ":/res/text_algae_0_1.png"
#define	TEXT_LOVE_PATH      ":/res/text_love_0_1.png"
#define	TEXT_PILLAR_PATH	":/res/text_pillar_0_1.png"
#define	TEXT_DOOR_PATH      ":/res/text_door_0_1.png"
#define	TEXT_KEY_PATH       ":/res/text_key_0_1.png"
#define	TEXT_HEDGE_PATH     ":/res/text_hedge_0_1.png"
#define	TEXT_COG_PATH       ":/res/text_cog_0_1.png"

#define TEXT_TEXT_PATH      ":/res/text_text_0_1.png"

#define TEXT_MELT_PATH ":/res/text_melt_0_1.png"
#define TEXT_YOU_PATH ":/res/text_you_0_1.png"
#define TEXT_STOP_PATH ":/res/text_stop_0_1.png"
#define TEXT_WIN_PATH ":/res/text_win_0_1.png"
#define TEXT_PUSH_PATH ":/res/text_push_0_3.png"
#define TEXT_DEFEAT_PATH ":/res/text_defeat_0_1.png"
#define TEXT_SINK_PATH ":/res/text_sink_0_1.png"
#define TEXT_MOVE_PATH ":/res/text_move_0_1.png"
#define TEXT_SHUT_PATH ":/res/text_shut_0_3.png"
#define TEXT_OPEN_PATH ":/res/text_open_0_1.png"
#define TEXT_FLOAT_PATH ":/res/text_float_0_1.png"
#define TEXT_HOT_PATH ":/res/text_hot_0_1.png"


#define TEXT_IS_PATH ":/res/text_is_0_1.png"
#define TEXT_AND_PATH ":/res/text_and_0_1.png"


//————————————————地图配置——————————————————
//#define FILE_PATH_1 ":/res/test.txt"
//别删，当作默认地图
#define FILE_PATH_1 ":/level/0.txt"
#define FILE_PATH_2 ":/level/island/test.txt"


//
#define IMAGE_PATH "../02_BabaIsYou/level/image/%0.png"

//编辑地图测试路径
//#define FILE_EDITOR_TEST ":/level/etest.txt
#define FILE_PATH_EDITOR "../02_BabaIsYou/level/editor/%0.txt"
#define SEARCH_BLOCK "NAME_%0"

//正式关卡路径
#define LEVEL_ISLAND_PATH ":/level/island/%0.txt"
#define LEVEL_WATER_PATH ":/level/water/%1.txt"
#define LEVEL_LAVA_PATH  ":/level/lava/%1.txt"

//————————————————动画配置——————————————————
//背景图加载
#define ANI_ISLAND_1 ":/res/island_%1.png"
#define ANI_ISLAND_2 ":/res/island_decor_%1.png"
#define ANI_LAVA ":/res/lava_%1.png"
#define ANI_WATER ":/res/water_%1.png"

#define ANI_ISLAND_1_NUM 3
#define ANI_ISLAND_2_NUM 3

#define ANI_ISLAND_1_INTERVAL 40
#define ANI_ISLAND_2_INTERVAL 35

#define ANI_MAX_NUM 10

//————————————————关卡方块配置——————————————————
#define LENGTH_OF_SIDE_L 30 //关卡方块边长
#define LBLOCK_NUM 100

//————————————————关卡方块图片配置——————————————————
#define LBLOCK_TEST_PATH ":/res/block_test.png"  //测试方块
#define LBLOCK_NUMBER_PATH "://res/%0.png"   //关卡数字图片

#define LBLOCK_UD_PATH ":/res/UD.png"        //关卡方向图片
#define LBLOCK_LR_PATH ":/res/LR.png"
#define LBLOCK_UL_PATH ":/res/UL.png"
#define LBLOCK_UR_PATH ":/res/UR.png"
#define LBLOCK_DL_PATH ":/res/DL.png"
#define LBLOCK_DR_PATH ":/res/DR.png"

#define LBLOCK_NU_PATH ":/res/NU.png"
#define LBLOCK_ND_PATH ":/res/ND.png"
#define LBLOCK_NL_PATH ":/res/NL.png"
#define LBLOCK_NR_PATH ":/res/NR.png"


#define LBLOCK_MOVE_PATH ":/res/choose_me.png"   //移动键图片

#define LBLOCK_CHANGE_PATH ""   //大地图切换图片


//————————————————关卡方块地图初始化配置——————————————————
#define MAP_ISLAND_PATH ":/map/map_island.txt"
#define MAP_LAVA_PATH ":/map/map_lava.txt"
#define MAP_WATER_PATH ":/map/map_water.txt"

//
#define SCORE_PATH "./score/yourScore.txt"


#endif // CONFIG_H
