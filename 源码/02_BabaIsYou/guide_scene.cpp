#include "guide_scene.h"
#include "ui_guide_scene.h"

Guide_Scene::Guide_Scene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Guide_Scene)
{
    ui->setupUi(this);

    //本窗口初始化
    setFixedSize(SCENE_M_WIDTH,SCENE_M_HEIGHT); //固定大小
    QIcon icon("://res/mainPic.png");
    setWindowIcon(icon);
    setWindowTitle("Baba Is You");
    setMouseTracking(true);

    //加载QSS文件，本窗口及其子窗口全部通用
    QFile file(QSS_PATH_1);
    QTextStream fileText(&file);
    QString stylesheet = fileText.readAll();
    this->setStyleSheet(stylesheet);
    file.close();

    //设定窗口初始化
    sce_setting.setParent(this);
    sce_setting.hide();
    sce_setting.move(SCENE_M_WIDTH*0.5-SCENE_S_WIDTH*0.5,SCENE_M_HEIGHT*0.5-SCENE_S_HEIGHT*0.5);

    //切换窗口初始化
    sce_change.setParent(this);
    sce_change.hide();
    sce_change.move(0,0);

    //切换窗口初始化
    sce_choose.setParent(this);
    sce_choose.hide();

    //编辑器窗口初始化
    sce_editor.setParent(this);
    sce_editor.hide();

    //音乐
    //预加载
    musicBaba.setSource(QUrl::fromLocalFile(":/music/baba.wav"));
    musicBaba.setLoopCount(7);
    musicBaba.setVolume(0.7f);

    musicMenu.setSource(QUrl::fromLocalFile(":/music/menu.wav"));
    musicMenu.setLoopCount(7);
    musicMenu.setVolume(0.7f);

    musicMAP.setSource(QUrl::fromLocalFile(":/music/map.wav"));
    musicMAP.setLoopCount(7);
    musicMAP.setVolume(0.7f);

    musicStar.setSource(QUrl::fromLocalFile(":/music/star.wav"));
    musicStar.setLoopCount(7);
    musicStar.setVolume(0.7f);

    musicCrystal.setSource(QUrl::fromLocalFile(":/music/crystal.wav"));
    musicCrystal.setLoopCount(7);
    musicCrystal.setVolume(0.7f);

    musicRain.setSource(QUrl::fromLocalFile(":/music/rain.wav"));
    musicRain.setLoopCount(7);
    musicRain.setVolume(0.7f);

    musicPlay(2);

    //音效
    buttonUp_0.setSource(QUrl::fromLocalFile(":/music/buttonUp.wav"));
    buttonUp_0.setLoopCount(1);
    buttonUp_0.setVolume(100);

    buttonUp_1.setSource(QUrl::fromLocalFile(":/music/buttonUp.wav"));
    buttonUp_1.setLoopCount(1);
    buttonUp_1.setVolume(100);

    buttonUp_2.setSource(QUrl::fromLocalFile(":/music/buttonUp.wav"));
    buttonUp_2.setLoopCount(1);
    buttonUp_2.setVolume(100);

    beastDesu.setSource(QUrl::fromLocalFile(":/music/beast.wav"));
    beastDesu.setLoopCount(1);
    beastDesu.setVolume(0.2f);
    canButton = true;

    inTop = true;
    //初始化分数
    iniScore();
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<20;j++)
        {
            if(yourScore[i][j] == 1)
            {
                score++;
            }
        }
    }

    //信号接受,播动画
    connect(&sce_choose,&Choose_Scene::chooseToGuide_signal,
            [=]()
    {
        alterType=CHOOSE_TO_GUIDE;
        cout<<"接受到choose的信号，可以播动画";
        sce_change.show();
        sce_change.raise();
        sce_change.playAni(ANI_TYPE_1," ");

    }
    );

    connect(&sce_choose,&Choose_Scene::chooseToGame_signal,
            [=]()
    {
        alterType=CHOOSE_TO_GAME;
        sce_change.show();
        sce_change.raise();
        sce_change.playAni(ANI_TYPE_3,sce_choose.nowName);
    }
    );

    connect(&sce_choose.sce_game.sce_pause,&Pause_Scene::gameToChoose_signal,
            [=]()
    {
        alterType=GAME_TO_CHOOSE;
        sce_change.show();
        sce_change.raise();
        sce_change.playAni(ANI_TYPE_1," ");
    }
    );
    //编辑器特供
    connect(&sce_editor.edit.Game_Testlevel.sce_pause,&Pause_Scene::testLevelToEdit_signal,
            [=]()
    {
        sce_editor.edit.Game_Testlevel.sce_pause.hide();
        sce_editor.edit.Game_Testlevel.isPause = false;
        sce_editor.edit.Game_Testlevel.hide();
        cout<<"隐藏";
    }
    );

    connect(&sce_choose.sce_game.sce_pause,&Pause_Scene::gameToGuide_signal,
            [=]()
    {

        alterType=GAME_TO_GUIDE;
        sce_change.show();
        sce_change.raise();
        sce_change.playAni(ANI_TYPE_1," ");
    }
    );

    connect(&sce_choose.sce_game,SIGNAL(win_signal(int,int)),this,SLOT(winLevel(int,int)));

    connect(&sce_choose,&Choose_Scene::toWater_signal,
            [=]()
    {
        alterType=TO_WATER;
        sce_change.show();
        sce_change.raise();
        sce_change.playAni(ANI_TYPE_1," ");
    }
    );
    connect(&sce_choose,&Choose_Scene::toLava_signal,
            [=]()
    {
        alterType=TO_LAVA;
        sce_change.show();
        sce_change.raise();
        sce_change.playAni(ANI_TYPE_1," ");
    }
    );
    connect(&sce_choose,&Choose_Scene::toIsland_signal,
            [=]()
    {
        alterType=TO_ISLAND;
        sce_change.show();
        sce_change.raise();
        sce_change.playAni(ANI_TYPE_1," ");
    }
    );



    //动画结束切屏
    connect(&sce_change,&Change_Scene::endAni_signal,
            [=]()
            {
        switch (alterType) {
        case GUIDE_TO_CHOOSE:
            sce_change.hide();
            sce_choose.show();
            sce_choose.setFocus();
            musicPlay(1);
            break;
        case CHOOSE_TO_GUIDE:
            inTop = true;
            sce_change.hide();
            sce_choose.hide();
            musicPlay(2);
            break;
        case CHOOSE_TO_GAME:
            sce_change.hide();
            //sce_game是sce_choose的子窗口
            sce_choose.sce_game.show();
            sce_choose.sce_game.setFocus();
            musicPlay(3);
            break;
        case GAME_TO_CHOOSE:
            sce_change.hide();
            sce_choose.sce_game.sce_pause.hide();
            sce_choose.sce_game.isPause=false;
            sce_choose.sce_game.hide();
            sce_choose.setFocus();
            if(sce_choose.game_map == MAP_ISLAND)
                musicPlay(1);
            if(sce_choose.game_map == MAP_WATER)
                musicPlay(4);
            if(sce_choose.game_map == MAP_LAVA)
                musicPlay(5);
            break;
        case GAME_TO_GUIDE:
            inTop = true;
            sce_change.hide();
            sce_choose.sce_game.sce_pause.hide();
            sce_choose.sce_game.isPause=false;
            sce_choose.sce_game.hide();
            sce_choose.hide();
            musicPlay(1);
            break;
        case GAME_TO_CHOOSE_WIN:
            sce_change.hide();
            sce_choose.sce_game.hide();
            sce_choose.setFocus();
            if(sce_choose.game_map == MAP_ISLAND)
                musicPlay(1);
            if(sce_choose.game_map == MAP_WATER)
                musicPlay(4);
            if(sce_choose.game_map == MAP_LAVA)
                musicPlay(5);
            break;
        case TO_WATER:
            sce_change.hide();
            sce_choose.iniMap(MAP_WATER,score);
            musicPlay(4);
            break;
        case TO_LAVA:
            sce_change.hide();
            sce_choose.iniMap(MAP_LAVA,score);
            musicPlay(5);
            break;
        case TO_ISLAND:
            sce_change.hide();
            sce_choose.iniMap(MAP_ISLAND,score);
            musicPlay(1);
            break;
        case 114:
            cout<<"结束了";
            sce_change.hide();
            sce_editor.edit.Game_Testlevel.hide();
            sce_editor.edit.Game_Testlevel.sce_pause.hide();
            sce_editor.edit.setFocus();
        default:
            break;
        }

            }
            );

    //设定改变
    connect(&sce_setting,&Setting_Scene::openAniChange_signal,
            [=]()
            {
        if(sce_choose.sce_game.openAni == true)
            sce_choose.sce_game.openAni = false;
        else
            sce_choose.sce_game.openAni = true;


            }
            );
    connect(&sce_setting,&Setting_Scene::shakeWin_signal,
            [=]()
            {
        if(sce_choose.sce_game.shakeWin == true)
            sce_choose.sce_game.shakeWin = false;
        else
            sce_choose.sce_game.shakeWin = true;


            }
            );

    //音量改变
    connect(&sce_setting,SIGNAL(eVolumeChange(int)),this,SLOT(eVChange(int)));
    connect(&sce_setting,SIGNAL(mVolumeChange(int)),this,SLOT(mVChange(int)));

    //初始化计时器【刷新速率】*
    m_timer.setInterval(GAME_RATE);

    //初始化图片
    m_back1.load(":/res/newBack2.png");
    m_back2.load(":/res/newBack2.png");

    //初始化图片坐标
    y1=0;
    y2=-SCENE_M_HEIGHT;

    //初始化切屏类型
    alterType = -1;

    //开始动画
    playAni();


    //关卡编辑器界面切回sce_editor
    connect(&sce_editor,&Edit_Level::exit_signal,
            [=]()
            {
            //this->show();
            sce_editor.hide();
            }
            );
}

Guide_Scene::~Guide_Scene()
{
    delete ui;
}

//——————————————————————————————————————背景动画——————————————————————————————————————
//背景动画
void Guide_Scene::playAni()
{
    //开始计时
    m_timer.start();
    //开始刷新
    connect(&m_timer,&QTimer::timeout,
            [=]()
            {
            y1++;
            y2++;
            if(y1>SCENE_M_HEIGHT)
            {
                y1=-SCENE_M_HEIGHT;
            }
            if(y2>SCENE_M_HEIGHT)
            {
                y2=-SCENE_M_HEIGHT;
            }
            //绘图刷新
            update();
            //（全局）鼠标位置
            if ((ui->b1_newgame->geometry().contains(this->mapFromGlobal(QCursor::pos()))
                    || ui->b2_setting->geometry().contains(this->mapFromGlobal(QCursor::pos()))
                    || ui->b3_editor->geometry().contains(this->mapFromGlobal(QCursor::pos()))
                    || ui->b4_exit->geometry().contains(this->mapFromGlobal(QCursor::pos())))
                    && inTop == true)
            {
                if(canButton == true)
                {
                    if(buI == 0)
                    {
                        buttonUp_0.play();
                        buI=1;
                    }else if(buI == 1)
                    {
                        buttonUp_1.play();
                        buI=2;
                    }else if(buI == 2)
                    {
                        buttonUp_2.play();
                        buI=0;
                    }
                    canButton = false;
                    cout<<"播放按钮";
                }
            }else
            {
                canButton = true;
            }

            }
    );
}
//——————————————————————————————————————绘画事件——————————————————————————————————————
//
void Guide_Scene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.drawPixmap(0,y1,SCENE_M_WIDTH,SCENE_M_HEIGHT+5,m_back1);
    painter.drawPixmap(0,y2,SCENE_M_WIDTH,SCENE_M_HEIGHT+5,m_back2);
}
//——————————————————————————————————————初始化积分——————————————————————————————————————
//从文件获得关卡通过情况，初始化总积分
void Guide_Scene::iniScore()
{
    QFile file(SCORE_PATH);
    bool isOK=file.open(QIODevice::ReadOnly);
    if(isOK == true)
    {
        for(int i=0;i<3;i++)
        {
            int num = readLineInt(file);
            for(int j=0;j<num;j++)
            {
                yourScore[i][j]=readLineInt(file);
            }
        }
    }
    int temp=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<20;j++)
        {
            if(yourScore[i][j] == 1)
            {
                temp++;
            }
        }
    }
    sce_choose.score=temp;
}
//——————————————————————————————————————写入积分——————————————————————————————————————
//将关卡通过情况上传
void Guide_Scene::uploadScore()
{
    QFile file(SCORE_PATH);
    QTextStream out(&file);
    int nums[10];

    //读文件，获得关卡数*3
    bool isOK=file.open(QIODevice::ReadOnly);

    if(isOK == true)
    {
        for(int i=0;i<3;i++)
        {
            int num = readLineInt(file);
            nums[i]=num;
            for(int j=0;j<num;j++)
            {
                readLineInt(file);
            }
        }
    }
    //写文件，清空文件，同时修改关卡通过情况
    bool isFine=file.open(QIODevice::WriteOnly);

    if(isFine == true)
    {
        file.flush();
        for(int i=0;i<3;i++)
        {
            out<<nums[i];
            for(int j=0;j<nums[i];j++)
            {
                out<<yourScore[i][j];
            }
        }
    }



}

void Guide_Scene::musicPlay(int type)
{
    switch (type) {
    case 0:
        cout<<"播放0";
        musicMenu.stop();
        musicMAP.stop();
        musicStar.stop();
        musicCrystal.stop();
        musicRain.stop();
        musicBaba.stop();

        musicBaba.play();
        break;
    case 1:
        cout<<"播放1";
        musicMenu.stop();
        musicMAP.stop();
        musicStar.stop();
        musicCrystal.stop();
        musicRain.stop();
        musicBaba.stop();

        musicMAP.play();
        break;
    case 2:
        cout<<"播放2";
        musicMenu.stop();
        musicMAP.stop();
        musicStar.stop();
        musicCrystal.stop();
        musicRain.stop();
        musicBaba.stop();

        musicMenu.play();
        break;
    case 3:
        cout<<"播放3";
        musicMenu.stop();
        musicMAP.stop();
        musicStar.stop();
        musicCrystal.stop();
        musicRain.stop();
        musicBaba.stop();

        musicRain.play();
        break;
    case 4:
        cout<<"播放4";
        musicMenu.stop();
        musicMAP.stop();
        musicStar.stop();
        musicCrystal.stop();
        musicRain.stop();
        musicBaba.stop();

        musicCrystal.play();
        break;
    case 5:
        cout<<"播放5";
        musicMenu.stop();
        musicMAP.stop();
        musicStar.stop();
        musicCrystal.stop();
        musicRain.stop();
        musicBaba.stop();

        musicStar.play();
        break;
    default:
        break;
    }
}



//——————————————————————————————————————从文件读行转INT————————————————————————————————————
//读取一行文件，输入INT
int Guide_Scene::readLineInt(QFile &file)
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


//————————————————————————————————————按钮槽函数————————————————————————————————————————————————
void Guide_Scene::on_b4_exit_released()
{
    this->close();
}

void Guide_Scene::on_b2_setting_released()
{
    inTop = false;
    sce_setting.show();
}

void Guide_Scene::on_b3_editor_released()
{
    beastDesu.play();
    inTop = false;
    //this->hide();
    sce_editor.show();
}

void Guide_Scene::on_b1_newgame_released()
{
    inTop = false;
    alterType = GUIDE_TO_CHOOSE;
    sce_change.show();
    sce_change.playAni(ANI_TYPE_1," ");
}

//胜利，更新总分数，关卡通过情况，上传分数
void Guide_Scene::winLevel(int map, int level)
{
    alterType=GAME_TO_CHOOSE_WIN;
    //分数
    if(yourScore[map][level] == 0)
    {
        yourScore[map][level] = 1;
        //上传分数
        uploadScore();
    }
    //计算总分
    int temp=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<20;j++)
        {
            if(yourScore[i][j] == 1)
            {
                temp++;
            }
        }
    }
    sce_choose.score=temp;
    cout<<"当GUIDE前分数"<<score;
    cout<<"当前CHOOSE分数"<<sce_choose.score;
    //退出暂停状态
    sce_choose.sce_game.sce_pause.hide();
    sce_choose.sce_game.isPause =false;
    //初始化游戏窗口（避免win_signal持续传递）
//    sce_choose.sce_game.iniMAP(999,999," ",0);
//    sce_choose.sce_game.iniMAP(sce_choose.game_map,sce_choose.game_name," ",0);
    sce_change.show();
    sce_change.raise();
    sce_change.playAni(ANI_TYPE_2," ");
}

void Guide_Scene::eVChange(int value)
{
    sce_choose.sce_game.soundVolume = value;
    //音效
    sce_choose.sce_game.move_sound.setVolume((double)value/100);
}

void Guide_Scene::mVChange(int value)
{
    cout<<"改变音乐音量";
    musicVolume = value;
    //音量
    musicRain.setVolume((double)musicVolume/100);
    musicBaba.setVolume((double)musicVolume/100);
    musicCrystal.setVolume((double)musicVolume/100);
    musicMAP.setVolume((double)musicVolume/100);
    musicMenu.setVolume((double)musicVolume/100);
    musicStar.setVolume((double)musicVolume/100);
}
