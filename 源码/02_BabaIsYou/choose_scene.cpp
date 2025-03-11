#include "choose_scene.h"
#include "ui_choose_scene.h"

Choose_Scene::Choose_Scene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Choose_Scene)
{
    ui->setupUi(this);

    //gif动画加载
    QMovie *movie = new QMovie(":/res/flower_1.gif");
    movie->start();
    ui->l2_flower->setMovie(movie);



    //窗口初始化
    setFixedSize(SCENE_M_WIDTH,SCENE_M_HEIGHT);
    //背景颜色初始化
    QPalette w_color(this->palette());
    w_color.setColor(QPalette::Background, QColor(8,9,50));
    setAutoFillBackground(true);
    setPalette(w_color);

    //游戏窗口初始化
    sce_game.setParent(this);
    sce_game.hide();

    //控件初始化
    //label
    //设置颜色
    QPalette l_color;
    l_color.setColor(QPalette::WindowText,Qt::white);
    ui->l1_nameOfLevel->setPalette(l_color);



    //初始化计时器【刷新速率】*
    m_timer.setInterval(GAME_RATE);

    //初始化背景动画
    m_backGround_1.iniAni(ANI_ISLAND_1_INTERVAL,ANI_ISLAND_1_NUM,ANI_ISLAND_1,SCENE_M_HEIGHT-2*SCENE_MARGIN,SCENE_M_WIDTH-2*SCENE_MARGIN);
    m_backGround_2.iniAni(ANI_ISLAND_2_INTERVAL,ANI_ISLAND_2_NUM,ANI_ISLAND_2,SCENE_M_HEIGHT-2*SCENE_MARGIN,SCENE_M_WIDTH-2*SCENE_MARGIN);

    m_backGround_3.iniAni(ANI_ISLAND_1_INTERVAL,ANI_ISLAND_1_NUM,ANI_LAVA,SCENE_M_HEIGHT-2*SCENE_MARGIN,SCENE_M_WIDTH-2*SCENE_MARGIN);

    m_backGround_4.iniAni(ANI_ISLAND_1_INTERVAL,ANI_ISLAND_1_NUM,ANI_WATER,SCENE_M_HEIGHT-2*SCENE_MARGIN,SCENE_M_WIDTH-2*SCENE_MARGIN);

    //开始动画
    playAni();

    //初始化地图
    iniMap(0,score);

    //重加载地图
    connect(&sce_game,&Game_Scene::restart_signal,
            [=]()
    {
        sce_game.iniMAP(game_map,game_name," ",0);
        sce_game.iniText();
    }
    );
}

Choose_Scene::~Choose_Scene()
{
    delete ui;
}
//——————————————————————————————刷新开始—————————————————————————————————————
//
void Choose_Scene::playAni()
{
    //开始计时
    m_timer.start();
    //开始刷新
    connect(&m_timer,&QTimer::timeout,
            [=]()
            {
            //动图下标
            m_backGround_1.updateIndex();
            m_backGround_2.updateIndex();
            m_backGround_3.updateIndex();
            m_backGround_4.updateIndex();
            //绘图刷新
            update();
            //刷新分数
            ui->l3_score->setText(QString::number(score));
            //刷新当前名
            static int frame = 0;
            frame++;
            if(frame>15)
            {
                ui->l1_nameOfLevel->setText(nowName);
                getNowName();
                frame = 0;
            }
            }
    );
}
//——————————————————————————————绘图事件—————————————————————————————————————
//绘制背景图
void Choose_Scene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(back_mark == MAP_ISLAND)
    {
        //底图绘制
        painter.drawPixmap(SCENE_MARGIN,SCENE_MARGIN,m_backGround_1.ani_pixVector[m_backGround_1.ani_index].width(),m_backGround_1.ani_pixVector[m_backGround_1.ani_index].height(),m_backGround_1.ani_pixVector[m_backGround_1.ani_index]);
        //表图绘制
        painter.drawPixmap(SCENE_MARGIN,SCENE_MARGIN,m_backGround_2.ani_pixVector[m_backGround_2.ani_index].width(),m_backGround_2.ani_pixVector[m_backGround_2.ani_index].height(),m_backGround_2.ani_pixVector[m_backGround_2.ani_index]);
    }
    if(back_mark == MAP_LAVA)
    {
        painter.drawPixmap(SCENE_MARGIN,SCENE_MARGIN,m_backGround_3.ani_pixVector[m_backGround_3.ani_index].width(),m_backGround_3.ani_pixVector[m_backGround_3.ani_index].height(),m_backGround_3.ani_pixVector[m_backGround_3.ani_index]);
    }
    if(back_mark == MAP_WATER)
    {
        painter.drawPixmap(SCENE_MARGIN,SCENE_MARGIN,m_backGround_4.ani_pixVector[m_backGround_4.ani_index].width(),m_backGround_4.ani_pixVector[m_backGround_4.ani_index].height(),m_backGround_4.ani_pixVector[m_backGround_4.ani_index]);
    }


    //关卡方块绘制
    for(int i=0;i<LBLOCK_NUM;i++)
    {
        if(m_lblocks[i].lblock_isVisible == true)
        {
            if(m_lblocks[i].lblock_type == LTY_MOVE)
            {
                painter.drawPixmap(m_lblocks[i].lblock_x-5,m_lblocks[i].lblock_y-5,35,35,m_lblocks[i].lblock_pix);
            }else
            {
                painter.drawPixmap(m_lblocks[i].lblock_x,m_lblocks[i].lblock_y,m_lblocks[i].lblock_pix);
            }
        }
    }
}

//——————————————————————————————————————从文件读取地图————————————————————————————————————
//根据关卡初始化以下属性：isVisible,type,name,x,y,pix
void Choose_Scene::iniMap(int map,int scores)
{
    score=scores;
    //初始化
    for(int i=0;i<LBLOCK_NUM;i++)
    {
        m_lblocks[i].lblock_x=-LENGTH_OF_SIDE_L;
        m_lblocks[i].lblock_y=-LENGTH_OF_SIDE_L;
        m_lblocks[i].lblock_isVisible=false;
        m_lblocks[i].lblock_map=MAP_ISLAND;
    }
    //载入地图
    QFile file;
    switch (map) {
    case MAP_ISLAND:
        file.setFileName(MAP_ISLAND_PATH);
        break;
    case MAP_LAVA:
        file.setFileName(MAP_LAVA_PATH);
        break;
    case MAP_WATER:
        file.setFileName(MAP_WATER_PATH);
        cout<<"已转到";
        break;
    default:
        break;
    }

    back_mark=map;
    game_map = map;

    bool isOk=file.open(QIODevice::ReadOnly);
    if(isOk == true)
    {
        int t_type;
        int t_name;
        int t_num;
        int t_blocks=0;
        while(file.atEnd() == false)
        {
            //读类型
            t_type=readLineInt(file);
            //读名字
            t_name=readLineInt(file);
            //读数量
            t_num=readLineInt(file);
            for(int i=0;i<t_num;i++)
            {
                //对文档输入方块初始化isVisble,type,name,x,y
                m_lblocks[t_blocks].lblock_isVisible = true;
                m_lblocks[t_blocks].lblock_type = t_type;
                m_lblocks[t_blocks].lblock_name = t_name;
                m_lblocks[t_blocks].loadPix(m_lblocks[t_blocks].lblock_name);
                //读x坐标
                m_lblocks[t_blocks].lblock_x = readLineInt(file);
                //读y坐标
                m_lblocks[t_blocks].lblock_y = readLineInt(file);
                //加载所属地图
                m_lblocks[t_blocks].lblock_map=map;
                t_blocks++;
            }
        }
    }

}

//——————————————————————————————————————从文件读行转INT————————————————————————————————————
//读取一行文件，输入INT
int Choose_Scene::readLineInt(QFile &file)
{
    bool ok;
    int num;
    QByteArray array;
    array+=file.readLine();
    array=array.trimmed();
    num=array.toInt(&ok,10);
    array.clear();
    return num;
}
//——————————————————————————————————————键盘输入————————————————————————————————————
//移动或者进入游戏界面或者切换大地图
void Choose_Scene::keyPressEvent(QKeyEvent *event)
{
    int block_to=DIR_NOWAY;
    int move_i=-1;
    bool intoLevel = false;

    if(event->key() == Qt::Key_W)block_to=DIR_UP;
    if(event->key() == Qt::Key_S)block_to=DIR_DOWN;
    if(event->key() == Qt::Key_A)block_to=DIR_LEFT;
    if(event->key() == Qt::Key_D)block_to=DIR_RIGHT;
    if(event->key() == Qt::Key_Space)intoLevel=true;

    //找到可移动方块
    for(int i=0;i<LBLOCK_NUM;i++)
    {
        if(m_lblocks[i].lblock_type == LTY_MOVE && m_lblocks[i].lblock_isVisible == true)
        {
            move_i=i;
        }
    }

    if(move_i == -1)
    {
        cout<<"无可移动方块";
        return;
    }

    switch (block_to) {
    case DIR_UP:
        for(int i=0;i<LBLOCK_NUM;i++)
        {
            if(m_lblocks[i].lblock_x == m_lblocks[move_i].lblock_x && m_lblocks[i].lblock_y == m_lblocks[move_i].lblock_y-LENGTH_OF_SIDE_L && m_lblocks[i].lblock_isVisible == true)
            {
                m_lblocks[move_i].lblock_y-=LENGTH_OF_SIDE_L;
                break;
            }
        }
        break;
    case DIR_DOWN:
        for(int i=0;i<LBLOCK_NUM;i++)
        {
            if(m_lblocks[i].lblock_x == m_lblocks[move_i].lblock_x && m_lblocks[i].lblock_y == m_lblocks[move_i].lblock_y+LENGTH_OF_SIDE_L && m_lblocks[i].lblock_isVisible == true)
            {
                m_lblocks[move_i].lblock_y+=LENGTH_OF_SIDE_L;
                break;
            }
        }
        break;
    case DIR_LEFT:
        for(int i=0;i<LBLOCK_NUM;i++)
        {
            if(m_lblocks[i].lblock_x == m_lblocks[move_i].lblock_x-LENGTH_OF_SIDE_L && m_lblocks[i].lblock_y == m_lblocks[move_i].lblock_y && m_lblocks[i].lblock_isVisible == true)
            {
                m_lblocks[move_i].lblock_x-=LENGTH_OF_SIDE_L;
                break;
            }
        }
        break;
    case DIR_RIGHT:
        for(int i=0;i<LBLOCK_NUM;i++)
        {
            if(m_lblocks[i].lblock_x == m_lblocks[move_i].lblock_x+LENGTH_OF_SIDE_L && m_lblocks[i].lblock_y == m_lblocks[move_i].lblock_y && m_lblocks[i].lblock_isVisible == true)
            {
                m_lblocks[move_i].lblock_x+=LENGTH_OF_SIDE_L;
                break;
            }
        }
        break;
    default:
        break;
    }

    if(intoLevel == true)
    {
        sce_game.sce_pause.nowName = nowName;
        for(int i=0;i<LBLOCK_NUM;i++)
        {
            //寻找当前所在关卡
            if(m_lblocks[i].lblock_x == m_lblocks[move_i].lblock_x && m_lblocks[i].lblock_y == m_lblocks[move_i].lblock_y && m_lblocks[i].lblock_isVisible == true )
            {
                if(m_lblocks[i].lblock_type == LTY_LEVEL)
                {
                    emit chooseToGame_signal();
                    //初始化地图、词条、开始计时
                    sce_game.iniMAP(m_lblocks[i].lblock_map,m_lblocks[i].lblock_name," ",0);
                    game_map=m_lblocks[i].lblock_map;
                    game_name=m_lblocks[i].lblock_name;
                    sce_game.iniText();
                    sce_game.playGame();
                    cout<<"进图";
                    break;
                }
                if(m_lblocks[i].lblock_type == LTY_CHANGE)
                {
                    switch (m_lblocks[i].lblock_name) {
                    case TOWATER:
                        emit toWater_signal();
                        break;
                    case TOLAVA:
                        emit toLava_signal();
                        break;
                    case TOISLAND:
                        emit toIsland_signal();
                        break;
                    default:
                        break;
                    }
                    break;
                }

            }
        }
    }
}

void Choose_Scene::getNowName()
{
    for(int i=0;i<LBLOCK_NUM;i++)
    {
        if(m_lblocks[i].lblock_isVisible == true && m_lblocks[i].lblock_type == LTY_MOVE)
        {
            for(int j=0;j<LBLOCK_NUM;j++)
            {
                if(m_lblocks[i].lblock_x == m_lblocks[j].lblock_x && m_lblocks[i].lblock_y == m_lblocks[j].lblock_y && i!=j)
                {
                    if(m_lblocks[j].lblock_type == LTY_LEVEL)
                    {
                        switch (game_map) {
                        case MAP_ISLAND:
                            nowName = islandName[m_lblocks[j].lblock_name];
                            break;
                        case MAP_LAVA:
                            nowName = lavaName[m_lblocks[j].lblock_name];
                            break;
                        case MAP_WATER:
                            nowName = waterName[m_lblocks[j].lblock_name];
                            break;
                        default:
                            break;
                        }
                    }
                    else
                    {
                        nowName = " ";
                    }
                }
            }
        }
    }
}


//——————————————————————————————槽函数—————————————————————————————————————
void Choose_Scene::on_b1_exit_released()
{
    emit chooseToGuide_signal();
}

void Choose_Scene::on_b2_gameStart_released()
{
    emit chooseToGame_signal();
    //初始化地图、词条、开始计时
    sce_game.iniMAP(0,999,"test",1);        //注意看
    sce_game.iniText();
    sce_game.playGame();

}
