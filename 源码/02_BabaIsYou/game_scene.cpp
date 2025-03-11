#include "game_scene.h"
#include "ui_game_scene.h"

Game_Scene::Game_Scene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game_Scene)
{
    ui->setupUi(this);
    //调试

    //底图
    m_background.load(BACKGROUND_PATH);

    //动效
    openAni = true;

    //屏幕抖动
    shakeWin = true;

    //动效
    soundVolume = 100;

    //赢！
    canWin = true;

    //漂浮
    upAndDown = 0;
    goUp = true;
    //音乐

        //移动
        move_sound.setSource(QUrl::fromLocalFile(":/music/move.wav"));
        move_sound.setLoopCount(1);
        move_sound.setVolume(100);

        move_sound_2.setSource(QUrl::fromLocalFile(":/music/move.wav"));
        move_sound_2.setLoopCount(1);
        move_sound_2.setVolume(100);

        //胜利
        win_sound.setSource(QUrl::fromLocalFile(":/music/win.wav"));
        win_sound.setLoopCount(1);
        win_sound.setVolume(100);

        //defeat
        defeat_sound.setSource(QUrl::fromLocalFile(":/music/defeat.wav"));
        defeat_sound.setLoopCount(1);
        defeat_sound.setVolume(100);

        //词条生效
        effectUpdate_sound.setSource(QUrl::fromLocalFile(":/music/effectUpdate.wav"));
        effectUpdate_sound.setLoopCount(1);
        effectUpdate_sound.setVolume(1);

    //初始化抖屏
    beginShake = false;

    //生效词条数
    effectTextNum=0;



    //暂停窗口初始化
    sce_pause.setParent(this);
    sce_pause.hide();
    sce_pause.move(0,0);

    //本窗口初始化
    setFixedSize(SCENE_M_WIDTH,SCENE_M_HEIGHT);
    isPause=false;

    //UI控件初始化
    ui->label->hide();
    ui->label_2->hide();


    //初始化计时器【刷新速率】*
    m_timer.setInterval(GAME_RATE);
    m_shakeTimer.setInterval(40);
    m_shakeTimerEnd.setInterval(40);

    //退出暂停
    connect(&sce_pause,&Pause_Scene::exitToGame_signal,
            [=]()
            {
                //退出暂停状态
                sce_pause.hide();
                isPause=false;
                cout<<"退出暂停"<<isPause;
                setFocus();
            }
            );
    //重启本关
    connect(&sce_pause,&Pause_Scene::restart_signal,
            [=]()
            {
                //退出暂停状态
                sce_pause.hide();
                isPause=false;
                emit restart_signal();
                setFocus();
            }
            );

    connect(&m_shakeTimer,&QTimer::timeout,
            [=]()
    {
        for(int i=0;i<BLOCK_NUM;i++)
        {
            m_blocks[i].block_y+=10;
        }
        originY+=10;
        m_shakeTimerEnd.start();
        m_shakeTimer.stop();
        cout<<"振动开始";
    }
            );
    connect(&m_shakeTimerEnd,&QTimer::timeout,
            [=]()
    {
        for(int i=0;i<BLOCK_NUM;i++)
        {
            m_blocks[i].block_y-=10;
        }
        originY-=10;
        m_shakeTimerEnd.stop();
        cout<<"振动结束";
    }
            );
}

Game_Scene::~Game_Scene()
{
    delete ui;
}

//——————————————————————————————————————定期调用——————————————————————————————————————
//此函数内的函数会定期调用
void Game_Scene::playGame()
{
    //开始计时
    m_timer.start();
    //开始刷新
    connect(&m_timer,&QTimer::timeout,
            [=]()
            {
            //方块修改
            updateBlock();
            //属性修改
            updateEffect();
            //效果实现
            effectWork();
            //绘图刷新
            update();
            //音量更新
            if(goUp == true)
            {
                upAndDown++;
            }else
            {
                upAndDown--;
            }
            if(upAndDown>sideLength*4)
                goUp = false;
            if(upAndDown<sideLength*2)
                goUp = true;
            //提示按键
            isDeadGame();
            }
            );

}

//——————————————————————————————————————绘图——————————————————————————————————————
//绘制地图，isVisible方块
void Game_Scene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    // !!按顺序绘制!!
    //调试
//    cout<<"有画画";

    //绘制背景图

    painter.drawPixmap(0,0,SCENE_M_WIDTH,SCENE_M_HEIGHT,m_background);
    painter.drawPixmap(originX,originY,inWidth,inHeight,m_ubackground_1);
    //绘制方块

    for(int i=0;i<BLOCK_NUM;i++)
    {
        //先画装饰
        if(m_blocks[i].block_isVisible == true && m_blocks[i].block_isTouch == false && m_blocks[i].block_isFloat == false)
        {
            if(openAni == true)
            {
                Animation temp = m_blocks[i].block_animation;
                painter.drawPixmap(m_blocks[i].block_x,m_blocks[i].block_y,temp.ani_pixVector[temp.ani_index].width(),temp.ani_pixVector[temp.ani_index].height(),temp.ani_pixVector[temp.ani_index]);
                m_blocks[i].block_animation.updateIndex();

            }
            else
            {
                painter.drawPixmap(m_blocks[i].block_x,m_blocks[i].block_y,m_blocks[i].block_pix);

            }
        }
    }
    for(int i=0;i<BLOCK_NUM;i++)
    {
        //先画非漂浮
        if(m_blocks[i].block_isVisible == true && m_blocks[i].block_isFloat == false && m_blocks[i].block_isTouch == true)
        {
            if(openAni == true)
            {
                Animation temp = m_blocks[i].block_animation;
                painter.drawPixmap(m_blocks[i].block_x,m_blocks[i].block_y,temp.ani_pixVector[temp.ani_index].width(),temp.ani_pixVector[temp.ani_index].height(),temp.ani_pixVector[temp.ani_index]);
                m_blocks[i].block_animation.updateIndex();

            }
            else
            {
                painter.drawPixmap(m_blocks[i].block_x,m_blocks[i].block_y,m_blocks[i].block_pix);

            }
        }
    }
    for(int i=0;i<BLOCK_NUM;i++)
    {
        // 后画漂浮
        if(m_blocks[i].block_isVisible == true && m_blocks[i].block_isFloat == true)
        {
            if(openAni == true)
            {
                Animation temp = m_blocks[i].block_animation;
                painter.drawPixmap(m_blocks[i].block_x,m_blocks[i].block_y-upAndDown/8,temp.ani_pixVector[temp.ani_index].width(),temp.ani_pixVector[temp.ani_index].height(),temp.ani_pixVector[temp.ani_index]);
                m_blocks[i].block_animation.updateIndex();

            }
            else
            {
                painter.drawPixmap(m_blocks[i].block_x,m_blocks[i].block_y-upAndDown/8,m_blocks[i].block_pix);

            }
        }
    }

    //调试
//    cout<<"方块画完了";
}

//——————————————————————————————————————键盘操作输入——————————————————————————————————————
//从键盘获取键值key_value
//寻找可移动方块进行移动操作
//
void Game_Scene::keyPressEvent(QKeyEvent *event)
{
    int block_to=DIR_NOWAY;
    cout<<"键盘输入检测中";
    if((event->key() == Qt::Key_Escape || event->key() == Qt::Key_P) && isWin == false)
    {
        if(isPause == false)
        {
            cout<<"进入暂停";
            sce_pause.iniName();
            sce_pause.show();
            isPause=true;
        }else
        {
            sce_pause.hide();
            isPause=false;
        }
    }

    if(isPause == false)
    {
        if(event->key() == Qt::Key_W)block_to=DIR_UP;
        if(event->key() == Qt::Key_S)block_to=DIR_DOWN;
        if(event->key() == Qt::Key_A)block_to=DIR_LEFT;
        if(event->key() == Qt::Key_D)block_to=DIR_RIGHT;

        if(event->key() == Qt::Key_W || event->key() == Qt::Key_S || event->key() == Qt::Key_A || event->key() == Qt::Key_D)
        {


            static int soundNO=0;
            if(soundNO == 0)
            {
                move_sound.play();
                soundNO = 1;
            }else if(soundNO == 1)
            {
                move_sound_2.play();
                soundNO = 0;
            }

            popNum=0;
            cout<<"移动调用";
            for(int i=0;i<BLOCK_NUM;i++)
            {
                if(m_blocks[i].block_isMove == true && m_blocks[i].block_type == TY_BLOCK && m_blocks[i].block_isVisible == true)
                {
                    if(m_blocks[i].block_type == TY_BLOCK && m_blocks[i].block_name == NAME_BABA && openAni == true)
                    {
                        switch (block_to) {
                        case DIR_UP:
                            if(m_blocks[i].block_moveType == 0)
                            {
                                 m_blocks[i].block_animation.iniAni(40,3,":/res/baba_9_%1.png",sideLength,sideLength);
                                 m_blocks[i].block_moveType = 1;
                            }
                            else if(m_blocks[i].block_moveType == 1)
                            {
                                 m_blocks[i].block_animation.iniAni(40,3,":/res/baba_10_%1.png",sideLength,sideLength);
                                 m_blocks[i].block_moveType = 2;
                            }
                            else if(m_blocks[i].block_moveType == 2)
                            {
                                 m_blocks[i].block_animation.iniAni(40,3,":/res/baba_8_%1.png",sideLength,sideLength);
                                 m_blocks[i].block_moveType = 0;
                            }
                            break;
                        case DIR_DOWN:
                            if(m_blocks[i].block_moveType == 0)
                            {
                                 m_blocks[i].block_animation.iniAni(40,3,":/res/baba_24_%1.png",sideLength,sideLength);
                                 m_blocks[i].block_moveType = 1;
                            }
                            else if(m_blocks[i].block_moveType == 1)
                            {
                                 m_blocks[i].block_animation.iniAni(40,3,":/res/baba_25_%1.png",sideLength,sideLength);
                                 m_blocks[i].block_moveType = 2;
                            }
                            else if(m_blocks[i].block_moveType == 2)
                            {
                                 m_blocks[i].block_animation.iniAni(40,3,":/res/baba_23_%1.png",sideLength,sideLength);
                                 m_blocks[i].block_moveType = 0;
                            }
                            break;
                        case DIR_LEFT:
                            if(m_blocks[i].block_moveType == 0)
                            {
                                 m_blocks[i].block_animation.iniAni(40,3,":/res/baba_16_%1.png",sideLength,sideLength);
                                 m_blocks[i].block_moveType = 1;
                            }
                            else if(m_blocks[i].block_moveType == 1)
                            {
                                 m_blocks[i].block_animation.iniAni(40,3,":/res/baba_17_%1.png",sideLength,sideLength);
                                 m_blocks[i].block_moveType = 2;
                            }
                            else if(m_blocks[i].block_moveType == 2)
                            {
                                 m_blocks[i].block_animation.iniAni(40,3,":/res/baba_15_%1.png",sideLength,sideLength);
                                 m_blocks[i].block_moveType = 0;
                            }
                            break;
                        case DIR_RIGHT:
                            if(m_blocks[i].block_moveType == 0)
                            {
                                 m_blocks[i].block_animation.iniAni(40,3,":/res/baba_2_%1.png",sideLength,sideLength);
                                 m_blocks[i].block_moveType = 1;
                            }
                            else if(m_blocks[i].block_moveType == 1)
                            {
                                 m_blocks[i].block_animation.iniAni(40,3,":/res/baba_3_%1.png",sideLength,sideLength);
                                 m_blocks[i].block_moveType = 2;
                            }
                            else if(m_blocks[i].block_moveType == 2)
                            {
                                 m_blocks[i].block_animation.iniAni(40,3,":/res/baba_0_%1.png",sideLength,sideLength);
                                 m_blocks[i].block_moveType = 0;
                            }
                            break;
                        default:
                            break;
                        }

                    }
                    blockMove(block_to,i,true);
                }
            }
            cout<<"入栈数量："<<popNum;
            numStack.push(popNum);

            //生效音效
            updateEffect();
            int temps=0;
            for(int i=0;i<BLOCK_NUM;i++)
            {
                if(m_blocks[i].block_isVisible == true && m_blocks[i].block_isTextEffect == true)
                {
                    temps++;
                }
            }
            cout<<"目前生效数"<<temps<<"之前生效数"<<effectTextNum;
            if(temps>effectTextNum)
            {
                effectUpdate_sound.play();
                cout<<"生效音效";
            }
            effectTextNum=temps;
        }
    }

    if(isPause == false)
    {


        if(event->key() == Qt::Key_Z && remStack.isEmpty() == false && numStack.isEmpty() == false)
        {


            int temp=numStack.back();
            numStack.pop();
            for(int i=0;i<temp;i++)
            {
                popStack();
            }
            //生效音效
            updateEffect();
            int temps=0;
            for(int i=0;i<BLOCK_NUM;i++)
            {
                if(m_blocks[i].block_isVisible == true && m_blocks[i].block_isTextEffect == true)
                {
                    temps++;
                }
            }
            cout<<"目前生效数"<<temps<<"之前生效数"<<effectTextNum;
            if(temps>effectTextNum)
            {
                effectUpdate_sound.play();
                cout<<"生效音效";
            }
            effectTextNum=temps;
        }
    }

    if(isPause == false)
    {
        if(event->key() == Qt::Key_R)
        {
            sce_pause.quickRestart();
        }
    }
}

//——————————————————————————————————————键盘操作移动——————————————————————————————————————
//从上个函数获取键值key_value，方块序号i，对该方块前方询问是否可以前进/推动
//递归调用只有最开始的方块进行前进/推动
bool Game_Scene::blockMove(int key_value,int i,bool isFirst)
{
    bool stepIn=true;

    int x_adjust=0;
    int y_adjust=0;
    if(key_value == DIR_UP)
    {
        x_adjust=0;
        y_adjust=-1;
    }
    if(key_value == DIR_DOWN)
    {
        x_adjust=0;
        y_adjust=1;
    }
    if(key_value == DIR_LEFT)
    {
        x_adjust=-1;
        y_adjust=0;
    }
    if(key_value == DIR_RIGHT)
    {
        x_adjust=1;
        y_adjust=0;
    }
    for(int j=0;j<BLOCK_NUM;j++)
    {
        //前方是open方块
        if(m_blocks[j].block_y == m_blocks[i].block_y+y_adjust*sideLength && m_blocks[j].block_x == m_blocks[i].block_x+x_adjust*sideLength && m_blocks[j].block_isVisible == true &&m_blocks[j].block_isOpen == true)
        {
            for(int k=0;k<BLOCK_NUM;k++)
            {
                //前前方是shut方块
                if(m_blocks[k].block_y == m_blocks[j].block_y+y_adjust*sideLength && m_blocks[k].block_x == m_blocks[j].block_x+x_adjust*sideLength && m_blocks[k].block_isVisible == true &&m_blocks[k].block_isShut == true)
                {
                    killBlock(j);
                    killBlock(k);
                    cout<<"开锁";
                }
            }
        }
        //前方是open方块
        if(m_blocks[j].block_y == m_blocks[i].block_y+y_adjust*sideLength && m_blocks[j].block_x == m_blocks[i].block_x+x_adjust*sideLength && m_blocks[j].block_isVisible == true &&m_blocks[j].block_isShut == true)
        {
            for(int k=0;k<BLOCK_NUM;k++)
            {
                //前前方是shut方块
                if(m_blocks[k].block_y == m_blocks[j].block_y+y_adjust*sideLength && m_blocks[k].block_x == m_blocks[j].block_x+x_adjust*sideLength && m_blocks[k].block_isVisible == true &&m_blocks[k].block_isOpen == true)
                {
                    killBlock(j);
                    killBlock(k);
                    cout<<"开锁";
                }
            }
        }
        //前方方块
        if(m_blocks[j].block_y == m_blocks[i].block_y+y_adjust*sideLength && m_blocks[j].block_x == m_blocks[i].block_x+x_adjust*sideLength && m_blocks[j].block_isVisible == true)
        {
            if(m_blocks[j].block_isTouch == false ||(m_blocks[j].block_isFloat != m_blocks[i].block_isFloat && m_blocks[j].block_isTouch == false))  // 跳过装饰方块
            {
                continue;
            }
            if(m_blocks[j].block_isPush == false || isBorder(key_value,j))  //边界判断
            {
                cout<<"不可推或边界,类型："<<m_blocks[j].block_type<<" 名："<<m_blocks[j].block_name;
                return false;  //退出：前方方块不可推动，返回不可推动
            }
            stepIn=blockMove(key_value,j,false); //递归调用，向前方方块询问
        }
    }
    if(stepIn == true && isBorder(key_value,i) == false)  //前方方块可推动
    {
        if(m_blocks[i].block_isMove == true && isFirst == false)    //本方块不是第一个方块且可移动，那就不动
        {
            cout<<"不是第一个方块，但可以前进";
            return true;
        }
        //坐标记录
        pushStack(m_blocks[i].block_x,m_blocks[i].block_y,i);

        m_blocks[i].setPosition(key_value);

        popNum++;
        return true;    //退出：向上一个方块返回可前进
    }else
    {
        cout<<"前方方块不可推动";
        return false;   //退出：前进方向方块无法推动，向上一个方块返回不可前进
    }
    return stepIn;

}
//——————————————————————————————————————边界判断——————————————————————————————————————
//通过移动方位和序号确定是否在边界
bool Game_Scene::isBorder(int key_value, int i)
{
    switch (key_value) {
    case DIR_UP:
        if(m_blocks[i].block_y-sideLength<originY)return true;
        break;
    case DIR_DOWN:
        if(m_blocks[i].block_y+sideLength>=SCENE_M_HEIGHT-originY)return true;
        break;
    case DIR_LEFT:
        if(m_blocks[i].block_x-sideLength<originX)return true;
        break;
    case DIR_RIGHT:
        if(m_blocks[i].block_x+sideLength>=SCENE_M_WIDTH-originX)return true;
        break;
    default:
        break;
    }
    return false;
}

//——————————————————————————————————————方块修改——————————————————————————————————————————
//只进行方块名/图片修改，不需要持续生效
//合法语法是"NAME IS NAME"，从左到右，从上到下
void Game_Scene::updateBlock()
{
    //占用初始化
    for(int i=0;i<100;i++)
    {
        allName[i]=false;
    }

    //寻找谓语text
    for(int i=0;i<BLOCK_NUM;i++)
    {
        if(m_blocks[i].block_type == TY_PREDICATE && m_blocks[i].block_name == NAME_IS)
        {
            //寻找左边上边，NAME型text
            for(int j=0;j<BLOCK_NUM;j++)
            {
                //baba(j) is(i) keke(k)
                //如果左边
                if(m_blocks[j].block_x == m_blocks[i].block_x-sideLength && m_blocks[j].block_y == m_blocks[i].block_y && m_blocks[j].block_type == TY_NAME)
                {
                    //寻找右边，NAME型或ADJ型text
                    for(int k=0;k<BLOCK_NUM;k++)
                    {
                        //如果是NAME
                        if(m_blocks[k].block_x == m_blocks[i].block_x+sideLength && m_blocks[k].block_y == m_blocks[i].block_y && m_blocks[k].block_type == TY_NAME)
                        {

                            //寻找同名，并改名改图片
                            for(int l=0;l<BLOCK_NUM;l++)
                            {
                                if(m_blocks[l].block_name == m_blocks[j].block_name && m_blocks[l].block_type == TY_BLOCK && allName[m_blocks[l].block_name] == false)
                                {
                                    m_blocks[l].block_name=m_blocks[k].block_name;
                                    m_blocks[l].loadPix(m_blocks[l].block_type,m_blocks[l].block_name,openAni);
                                }
                            }
                            allName[m_blocks[j].block_name]=true;
                        }
                    }
                }
                //如果上边
                if(m_blocks[j].block_y == m_blocks[i].block_y-sideLength && m_blocks[j].block_x == m_blocks[i].block_x && m_blocks[j].block_type == TY_NAME)
                {
                    //寻找下边，NAME型text
                    for(int k=0;k<BLOCK_NUM;k++)
                    {
                        //如果是NAME
                        if(m_blocks[k].block_y == m_blocks[i].block_y+sideLength && m_blocks[k].block_x == m_blocks[i].block_x && m_blocks[k].block_type == TY_NAME)
                        {

                            //寻找同名，并改名改图片
                            for(int l=0;l<BLOCK_NUM;l++)
                            {
                                if(m_blocks[l].block_name == m_blocks[j].block_name && m_blocks[l].block_type == TY_BLOCK && allName[m_blocks[l].block_name] == false)
                                {
                                    m_blocks[l].block_name=m_blocks[k].block_name;
                                    m_blocks[l].loadPix(m_blocks[l].block_type,m_blocks[l].block_name,openAni);
                                }
                            }
                            //改完设为以占用
                            allName[m_blocks[j].block_name]=true;
                        }
                    }
                }
            }
        }
        if(m_blocks[i].block_type == TY_PREDICATE && m_blocks[i].block_name == NAME_AND)
        {
            for(int j=0;j<BLOCK_NUM;j++)
            {
                //baba(m) is you and keke(l)
                //左边IS
                if(m_blocks[j].block_x == m_blocks[i].block_x-2*sideLength && m_blocks[j].block_y == m_blocks[i].block_y && m_blocks[j].block_name == NAME_IS)
                {
                    for(int k=0;k<BLOCK_NUM;k++)
                    {
                        //左边ADJ
                        if(m_blocks[k].block_x == m_blocks[i].block_x-sideLength && m_blocks[k].block_y == m_blocks[i].block_y && (m_blocks[k].block_type == TY_ADJ||m_blocks[k].block_type == TY_NAME))
                        {
                            for(int l=0;l<BLOCK_NUM;l++)
                            {
                                //右边name
                                if(m_blocks[l].block_x == m_blocks[i].block_x+sideLength && m_blocks[l].block_y == m_blocks[i].block_y && m_blocks[l].block_type == TY_NAME )
                                {
                                    for(int m=0;m<BLOCK_NUM;m++)
                                    {
                                        //左边名
                                        if(m_blocks[m].block_x == m_blocks[i].block_x-3*sideLength && m_blocks[m].block_y == m_blocks[i].block_y && m_blocks[m].block_type == TY_NAME && allName[m_blocks[m].block_name]==false)
                                        {

                                            //同名改图片
                                            for(int n=0;n<BLOCK_NUM;n++)
                                            {
                                                if(m_blocks[n].block_name == m_blocks[m].block_name && m_blocks[n].block_type == TY_BLOCK && allName[m_blocks[n].block_name] == false)
                                                m_blocks[m].block_name=m_blocks[l].block_name;
                                                m_blocks[m].loadPix(m_blocks[m].block_type,m_blocks[m].block_name,openAni);
                                            }
                                            //改为设为已占用
                                            allName[m_blocks[m].block_name]=true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                //上边IS
                if(m_blocks[j].block_x == m_blocks[i].block_x && m_blocks[j].block_y == m_blocks[i].block_y-2*sideLength && m_blocks[j].block_name == NAME_IS)
                {
                    for(int k=0;k<BLOCK_NUM;k++)
                    {
                        //上边ADJ
                        if(m_blocks[k].block_x == m_blocks[i].block_x && m_blocks[k].block_y == m_blocks[i].block_y-sideLength && (m_blocks[k].block_type == TY_ADJ||m_blocks[k].block_type == TY_NAME))
                        {
                            for(int l=0;l<BLOCK_NUM;l++)
                            {
                                //下边name
                                if(m_blocks[l].block_x == m_blocks[i].block_x && m_blocks[l].block_y == m_blocks[i].block_y+sideLength && m_blocks[l].block_type == TY_NAME )
                                {
                                    for(int m=0;m<BLOCK_NUM;m++)
                                    {
                                        //上边名
                                        if(m_blocks[m].block_x == m_blocks[i].block_x && m_blocks[m].block_y == m_blocks[i].block_y-3*sideLength && m_blocks[m].block_type == TY_NAME && allName[m_blocks[m].block_name]==false)
                                        {

                                            //同名改图片
                                            for(int n=0;n<BLOCK_NUM;n++)
                                            {
                                                if(m_blocks[n].block_name == m_blocks[m].block_name && m_blocks[n].block_type == TY_BLOCK && allName[m_blocks[n].block_name] == false)
                                                m_blocks[m].block_name=m_blocks[l].block_name;
                                                m_blocks[m].loadPix(m_blocks[m].block_type,m_blocks[m].block_name,openAni);
                                            }
                                            //改为设为已占用
                                            allName[m_blocks[m].block_name]=true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                // crab(m) and baba is(j) keke(k)
                //右边is
                if(m_blocks[j].block_x == m_blocks[i].block_x+2*sideLength && m_blocks[j].block_y == m_blocks[i].block_y && m_blocks[j].block_name == NAME_IS)
                {
                    for(int k=0;k<BLOCK_NUM;k++)
                    {
                        //最右边Name
                        if(m_blocks[k].block_x == m_blocks[i].block_x+3*sideLength && m_blocks[k].block_y == m_blocks[i].block_y && (m_blocks[k].block_type == TY_NAME))
                        {
                            for(int l=0;l<BLOCK_NUM;l++)
                            {
                                //右边name
                                if(m_blocks[l].block_x == m_blocks[i].block_x+sideLength && m_blocks[l].block_y == m_blocks[i].block_y && m_blocks[l].block_type == TY_NAME)
                                {
                                    for(int m=0;m<BLOCK_NUM;m++)
                                    {
                                        //左边名
                                        if(m_blocks[m].block_x == m_blocks[i].block_x-sideLength && m_blocks[m].block_y == m_blocks[i].block_y && m_blocks[m].block_type == TY_NAME)
                                        {
                                            //修改同名
                                            for(int n=0;n<BLOCK_NUM;n++)
                                            {
                                                if(m_blocks[n].block_name == m_blocks[k].block_name && m_blocks[n].block_type == TY_BLOCK && allName[m_blocks[n].block_name] == false)
                                                {
                                                    m_blocks[n].block_name=m_blocks[k].block_name;
                                                    m_blocks[n].loadPix(m_blocks[n].block_type,m_blocks[n].block_name,openAni);
                                                }
                                            }
                                            //改为设为已占用
                                            allName[m_blocks[m].block_name]=true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                // crab(m) and baba is(j) keke(k)
                //下边IS
                if(m_blocks[j].block_x == m_blocks[i].block_x && m_blocks[j].block_y == m_blocks[i].block_y+2*sideLength && m_blocks[j].block_name == NAME_IS)
                {
                    for(int k=0;k<BLOCK_NUM;k++)
                    {
                        //最下边Name
                        if(m_blocks[k].block_x == m_blocks[i].block_x && m_blocks[k].block_y == m_blocks[i].block_y+3*sideLength && (m_blocks[k].block_type == TY_NAME))
                        {
                            for(int l=0;l<BLOCK_NUM;l++)
                            {
                                //下边name
                                if(m_blocks[l].block_x == m_blocks[i].block_x && m_blocks[l].block_y == m_blocks[i].block_y+sideLength && m_blocks[l].block_type == TY_NAME)
                                {
                                    for(int m=0;m<BLOCK_NUM;m++)
                                    {
                                        //上边名
                                        if(m_blocks[m].block_x == m_blocks[i].block_x && m_blocks[m].block_y == m_blocks[i].block_y-sideLength && m_blocks[m].block_type == TY_NAME)
                                        {
                                            //修改同名
                                            for(int n=0;n<BLOCK_NUM;n++)
                                            {
                                                if(m_blocks[n].block_name == m_blocks[k].block_name && m_blocks[n].block_type == TY_BLOCK && allName[m_blocks[n].block_name] == false)
                                                {
                                                    m_blocks[n].block_name=m_blocks[k].block_name;
                                                    m_blocks[n].loadPix(m_blocks[n].block_type,m_blocks[n].block_name,openAni);
                                                }
                                            }
                                            //改为设为已占用
                                            allName[m_blocks[m].block_name]=true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

//——————————————————————————————————————属性修改—————————————————————————————————————————
//只进行方块属性修改，需要持续生效
//合法语法是"NAME IS ADJ"/"NAME IS ADJ AND ADJ"（还没写），从左到右，从上到下
void Game_Scene::updateEffect()
{
    //恢复默认
    for(int i=0;i<BLOCK_NUM;i++)
    {
        if(m_blocks[i].block_type == TY_BLOCK && m_blocks[i].block_isVisible == true)
        {
            m_blocks[i].block_isBomb = false;
            m_blocks[i].block_isDanger = false;
            m_blocks[i].block_isMove = false;
            m_blocks[i].block_isPush = false;
            m_blocks[i].block_isTouch = false;
            m_blocks[i].block_isWin = false;
            m_blocks[i].block_isMelt = false;
            m_blocks[i].block_isHot = false;
            m_blocks[i].block_isOpen = false;
            m_blocks[i].block_isShut = false;
            m_blocks[i].block_isSink = false;
            m_blocks[i].block_isFloat = false;
        }
        m_blocks[i].block_isTextEffect = false;

    }
    //根据text组合修改
    for(int i=0;i<BLOCK_NUM;i++)
    {
        if(m_blocks[i].block_type == TY_PREDICATE)
        {
            if(m_blocks[i].block_name == NAME_IS)
            {
                for(int j=0;j<BLOCK_NUM;j++)
                {
                    //左边
                    if(m_blocks[j].block_x == m_blocks[i].block_x-sideLength && m_blocks[j].block_y == m_blocks[i].block_y &&m_blocks[j].block_type == TY_NAME)
                    {
                        for(int k=0;k<BLOCK_NUM;k++)
                        {
                            //右边是ADJ
                            if(m_blocks[k].block_x == m_blocks[i].block_x+sideLength && m_blocks[k].block_y == m_blocks[i].block_y && m_blocks[k].block_type == TY_ADJ)
                            {
                                m_blocks[k].block_isTextEffect=true;
                                m_blocks[j].block_isTextEffect=true;
                                m_blocks[i].block_isTextEffect=true;
                                changeEffect(k,j);
                            }
                        }
                    }
                    //上边
                    if(m_blocks[j].block_y == m_blocks[i].block_y-sideLength && m_blocks[j].block_x == m_blocks[i].block_x && m_blocks[j].block_type == TY_NAME)
                    {
                        for(int k=0;k<BLOCK_NUM;k++)
                        {
                            //下边是ADJ
                            if(m_blocks[k].block_y == m_blocks[i].block_y+sideLength && m_blocks[k].block_x == m_blocks[i].block_x && m_blocks[k].block_type == TY_ADJ)
                            {
                                m_blocks[k].block_isTextEffect=true;
                                m_blocks[j].block_isTextEffect=true;
                                m_blocks[i].block_isTextEffect=true;
                                changeEffect(k,j);
                            }
                        }
                    }
                }
            }
            if(m_blocks[i].block_name == NAME_AND)
            {
                for(int j=0;j<BLOCK_NUM;j++)
                {
                    //左边IS
                    if(m_blocks[j].block_x == m_blocks[i].block_x-2*sideLength && m_blocks[j].block_y == m_blocks[i].block_y && m_blocks[j].block_name == NAME_IS)
                    {
                        for(int k=0;k<BLOCK_NUM;k++)
                        {
                            //左边ADJ
                            if(m_blocks[k].block_x == m_blocks[i].block_x-sideLength && m_blocks[k].block_y == m_blocks[i].block_y && (m_blocks[k].block_type == TY_ADJ||m_blocks[k].block_type == TY_NAME))
                            {
                                for(int l=0;l<BLOCK_NUM;l++)
                                {
                                    //左边name
                                    if(m_blocks[l].block_x == m_blocks[i].block_x-3*sideLength && m_blocks[l].block_y == m_blocks[i].block_y && m_blocks[l].block_type == TY_NAME)
                                    {
                                        for(int m=0;m<BLOCK_NUM;m++)
                                        {
                                            //右边adj
                                            if(m_blocks[m].block_x == m_blocks[i].block_x+sideLength && m_blocks[m].block_y == m_blocks[i].block_y && m_blocks[m].block_type == TY_ADJ)
                                            {
                                                m_blocks[k].block_isTextEffect=true;
                                                m_blocks[j].block_isTextEffect=true;
                                                m_blocks[i].block_isTextEffect=true;
                                                m_blocks[l].block_isTextEffect=true;
                                                m_blocks[m].block_isTextEffect=true;
                                                changeEffect(m,l);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    //上边IS
                    if(m_blocks[j].block_x == m_blocks[i].block_x && m_blocks[j].block_y == m_blocks[i].block_y-2*sideLength && m_blocks[j].block_name == NAME_IS)
                    {
                        for(int k=0;k<BLOCK_NUM;k++)
                        {
                            //上边ADJ
                            if(m_blocks[k].block_x == m_blocks[i].block_x && m_blocks[k].block_y == m_blocks[i].block_y-sideLength && (m_blocks[k].block_type == TY_ADJ||m_blocks[k].block_type == TY_NAME))
                            {
                                for(int l=0;l<BLOCK_NUM;l++)
                                {
                                    //上边name
                                    if(m_blocks[l].block_x == m_blocks[i].block_x && m_blocks[l].block_y == m_blocks[i].block_y-3*sideLength && m_blocks[l].block_type == TY_NAME)
                                    {
                                        for(int m=0;m<BLOCK_NUM;m++)
                                        {
                                            //下边adj
                                            if(m_blocks[m].block_x == m_blocks[i].block_x && m_blocks[m].block_y == m_blocks[i].block_y+sideLength && m_blocks[m].block_type == TY_ADJ)
                                            {
                                                m_blocks[k].block_isTextEffect=true;
                                                m_blocks[j].block_isTextEffect=true;
                                                m_blocks[i].block_isTextEffect=true;
                                                m_blocks[l].block_isTextEffect=true;
                                                m_blocks[m].block_isTextEffect=true;
                                                changeEffect(m,l);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    // crab and baba(l) is you(k)
                    //右边IS
                    if(m_blocks[j].block_x == m_blocks[i].block_x+2*sideLength && m_blocks[j].block_y == m_blocks[i].block_y && m_blocks[j].block_name == NAME_IS)
                    {
                        for(int k=0;k<BLOCK_NUM;k++)
                        {
                            //右边ADJ
                            if(m_blocks[k].block_x == m_blocks[i].block_x+3*sideLength && m_blocks[k].block_y == m_blocks[i].block_y && (m_blocks[k].block_type == TY_ADJ))
                            {
                                for(int l=0;l<BLOCK_NUM;l++)
                                {
                                    //右边name
                                    if(m_blocks[l].block_x == m_blocks[i].block_x+sideLength && m_blocks[l].block_y == m_blocks[i].block_y && m_blocks[l].block_type == TY_NAME)
                                    {
                                        for(int m=0;m<BLOCK_NUM;m++)
                                        {
                                            //左边name
                                            if(m_blocks[m].block_x == m_blocks[i].block_x-sideLength && m_blocks[m].block_y == m_blocks[i].block_y && m_blocks[m].block_type == TY_NAME)
                                            {
                                                m_blocks[k].block_isTextEffect=true;
                                                m_blocks[j].block_isTextEffect=true;
                                                m_blocks[i].block_isTextEffect=true;
                                                m_blocks[l].block_isTextEffect=true;
                                                m_blocks[m].block_isTextEffect=true;
                                                changeEffect(k,m);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    // crab and baba(l) is you(k)
                    //下边IS
                    if(m_blocks[j].block_x == m_blocks[i].block_x && m_blocks[j].block_y == m_blocks[i].block_y+2*sideLength && m_blocks[j].block_name == NAME_IS)
                    {
                        for(int k=0;k<BLOCK_NUM;k++)
                        {
                            //下边ADJ
                            if(m_blocks[k].block_x == m_blocks[i].block_x && m_blocks[k].block_y == m_blocks[i].block_y+3*sideLength && (m_blocks[k].block_type == TY_ADJ))
                            {
                                for(int l=0;l<BLOCK_NUM;l++)
                                {
                                    //下边name
                                    if(m_blocks[l].block_x == m_blocks[i].block_x && m_blocks[l].block_y == m_blocks[i].block_y+sideLength && m_blocks[l].block_type == TY_NAME)
                                    {
                                        for(int m=0;m<BLOCK_NUM;m++)
                                        {
                                            //上边name
                                            if(m_blocks[m].block_x == m_blocks[i].block_x && m_blocks[m].block_y == m_blocks[i].block_y-sideLength && m_blocks[m].block_type == TY_NAME)
                                            {
                                                m_blocks[k].block_isTextEffect=true;
                                                m_blocks[j].block_isTextEffect=true;
                                                m_blocks[i].block_isTextEffect=true;
                                                m_blocks[l].block_isTextEffect=true;
                                                m_blocks[m].block_isTextEffect=true;
                                                changeEffect(k,m);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

}

//——————————————————————————————————————实际属性修改—————————————————————————————————————————
//进行实际修改
void Game_Scene::changeEffect(int k,int j)
{
    switch (m_blocks[k].block_name) {
    case NAME_DEFEAT:
        for(int l=0;l<BLOCK_NUM;l++)
        {
            if(m_blocks[l].block_name == m_blocks[j].block_name && m_blocks[l].block_type ==TY_BLOCK && m_blocks[l].block_isVisible == true)
            {
                m_blocks[l].block_isDanger=true;
            }
        }
        break;
    case NAME_PUSH:
        for(int l=0;l<BLOCK_NUM;l++)
        {
            if(m_blocks[l].block_name == m_blocks[j].block_name && m_blocks[l].block_type ==TY_BLOCK && m_blocks[l].block_isVisible == true)
            {
                m_blocks[l].block_isPush=true;
                m_blocks[l].block_isTouch=true;
            }
        }
        break;
    case NAME_SINK:
        for(int l=0;l<BLOCK_NUM;l++)
        {
            if(m_blocks[l].block_name == m_blocks[j].block_name && m_blocks[l].block_type ==TY_BLOCK && m_blocks[l].block_isVisible == true)
            {
                m_blocks[l].block_isBomb=true;
                if(m_blocks[l].block_name == NAME_BABA)
                {
                    m_blocks[l].block_isSink = true;
                }
            }
        }
        break;
    case NAME_STOP:
        for(int l=0;l<BLOCK_NUM;l++)
        {
            if(m_blocks[l].block_name == m_blocks[j].block_name && m_blocks[l].block_type ==TY_BLOCK && m_blocks[l].block_isVisible == true)
            {
                m_blocks[l].block_isTouch=true;
            }
        }
        break;
    case NAME_WIN:
        for(int l=0;l<BLOCK_NUM;l++)
        {
            if(m_blocks[l].block_name == m_blocks[j].block_name && m_blocks[l].block_type ==TY_BLOCK && m_blocks[l].block_isVisible == true)
            {
                m_blocks[l].block_isWin=true;
            }
        }
        break;
    case NAME_YOU:
        for(int l=0;l<BLOCK_NUM;l++)
        {
            if(m_blocks[l].block_name == m_blocks[j].block_name && m_blocks[l].block_type ==TY_BLOCK && m_blocks[l].block_isVisible == true)
            {
                m_blocks[l].block_isMove=true;
                m_blocks[l].block_isPush=true;
                m_blocks[l].block_isTouch=true;   //如果直接设为false或许blockmove就可以少一个判断
            }
        }
        break;
    case NAME_MELT:
        for(int l=0;l<BLOCK_NUM;l++)
        {
            if(m_blocks[l].block_name == m_blocks[j].block_name && m_blocks[l].block_type ==TY_BLOCK && m_blocks[l].block_isVisible == true)
            {
                m_blocks[l].block_isMelt = true;   //如果直接设为false或许blockmove就可以少一个判断
            }
        }
        break;
    case NAME_HOT:
        for(int l=0;l<BLOCK_NUM;l++)
        {
            if(m_blocks[l].block_name == m_blocks[j].block_name && m_blocks[l].block_type ==TY_BLOCK && m_blocks[l].block_isVisible == true)
            {
                m_blocks[l].block_isHot = true;   //如果直接设为false或许blockmove就可以少一个判断
            }
        }
        break;
    case NAME_SHUT:
        for(int l=0;l<BLOCK_NUM;l++)
        {
            if(m_blocks[l].block_name == m_blocks[j].block_name && m_blocks[l].block_type ==TY_BLOCK && m_blocks[l].block_isVisible == true)
            {
                m_blocks[l].block_isShut = true;   //如果直接设为false或许blockmove就可以少一个判断
            }
        }
        break;
    case NAME_OPEN:
        for(int l=0;l<BLOCK_NUM;l++)
        {
            if(m_blocks[l].block_name == m_blocks[j].block_name && m_blocks[l].block_type ==TY_BLOCK && m_blocks[l].block_isVisible == true)
            {
                m_blocks[l].block_isOpen = true;   //如果直接设为false或许blockmove就可以少一个判断
            }
        }
        break;
    case NAME_FLOAT:
        for(int l=0;l<BLOCK_NUM;l++)
        {
            if(m_blocks[l].block_name == m_blocks[j].block_name && m_blocks[l].block_type == TY_BLOCK && m_blocks[l].block_isVisible == true)
            {
                m_blocks[l].block_isFloat = true;
            }
            if(m_blocks[j].block_name == NAME_TEXT && m_blocks[l].block_type != TY_BLOCK && m_blocks[l].block_isVisible == true)
            {
                m_blocks[l].block_isFloat = true;
            }
        }
        break;
    default:
        break;
    }
}

//——————————————————————————————————————效果实现—————————————————————————————————————————
//实现isBomb的效果：接触到isbomb的方块与isbomb方块都会消失
void Game_Scene::effectWork()
{
    //所有实现都要求isVisible == true

    for(int i=0;i<BLOCK_NUM;i++)
    {
        if(m_blocks[i].block_isVisible == true)
        {
            //bomb实现
            if(m_blocks[i].block_isBomb == true && m_blocks[i].block_type == TY_BLOCK)
            {
                //互爆（sink）
                for(int j=0;j<BLOCK_NUM;j++)
                {
                    if(j!=i && m_blocks[j].block_x == m_blocks[i].block_x && m_blocks[j].block_y == m_blocks[i].block_y && m_blocks[j].block_isVisible == true && m_blocks[i].block_isFloat == m_blocks[j].block_isFloat)
                    {
                        killBlock(j);
                        killBlock(i);
                        shakeWindow();
                        cout<<"sink";
                    }
                }
            }
            //danger实现（defeat）
            if(m_blocks[i].block_isDanger == true && m_blocks[i].block_type == TY_BLOCK)
            {
                //自爆
                if(m_blocks[i].block_isMove == true)
                {
                    killBlock(i);
                    shakeWindow();
                }
                //爆别人
                for(int j=0;j<BLOCK_NUM;j++)
                {
                    if(j!=i && m_blocks[j].block_x == m_blocks[i].block_x && m_blocks[j].block_y == m_blocks[i].block_y && m_blocks[j].block_isVisible == true && m_blocks[j].block_isMove == true && m_blocks[i].block_isFloat == m_blocks[j].block_isFloat)
                    {
                        killBlock(j);
                        shakeWindow();
                    }
                }
            }
            //win实现
            if(m_blocks[i].block_isWin == true && m_blocks[i].block_type == TY_BLOCK)
            {
                if(m_blocks[i].block_isMove == true)
                {
                    winGame();
                }
                for(int j=0;j<BLOCK_NUM;j++)
                {
                    if(j!=i && m_blocks[j].block_isMove == true && m_blocks[j].block_x == m_blocks[i].block_x && m_blocks[j].block_y == m_blocks[i].block_y && m_blocks[j].block_isFloat == m_blocks[i].block_isFloat)
                    {
                        winGame();
                    }
                }
            }
            //H/M实现
            if(m_blocks[i].block_isHot == true && m_blocks[i].block_type == TY_BLOCK)
            {
                for(int j=0;j<BLOCK_NUM;j++)
                {
                    if(j!=i && m_blocks[j].block_isMelt == true && m_blocks[j].block_x == m_blocks[i].block_x && m_blocks[j].block_y == m_blocks[i].block_y && m_blocks[j].block_isVisible == true && m_blocks[i].block_isFloat == m_blocks[j].block_isFloat)
                    {
                        killBlock(j);
                        shakeWindow();
                    }
                }
            }
            //S/O实现
            if(m_blocks[i].block_isShut == true &&  m_blocks[i].block_isOpen == true && m_blocks[i].block_type == TY_BLOCK)
            {
                killBlock(i);
                shakeWindow();
            }
            //sink实现
            if(m_blocks[i].block_isSink == true && m_blocks[i].block_type == TY_BLOCK)
            {
                //溺水
                for(int j=0;j<BLOCK_NUM;j++)
                {
                    if(j!=i && m_blocks[j].block_x == m_blocks[i].block_x && m_blocks[j].block_y == m_blocks[i].block_y && m_blocks[j].block_name == NAME_WATER && m_blocks[j].block_isVisible == true)
                    {
                        killBlock(j);
                        killBlock(i);
                        shakeWindow();
                        cout<<"溺水";
                    }
                }
            }
        }
    }
}

//——————————————————————————————————————方块清除—————————————————————————————————————————
//清除对应序号的方块
//
void Game_Scene::killBlock(int i)
{
    cout<<"销毁方块"<<i;
    defeat_sound.play();

    if(m_blocks[i].block_isMove == false)
    {
        pushStack(m_blocks[i].block_x,m_blocks[i].block_y,i);

        int temp=numStack.back();
        numStack.pop();
        temp++;
        numStack.push(temp);
    }

    m_blocks[i].block_name =NAME_NOTHING;
    m_blocks[i].block_isVisible =false;
    m_blocks[i].block_x=-LENGTH_OF_SIDE;
    m_blocks[i].block_y=-LENGTH_OF_SIDE;
}

//——————————————————————————————————————游戏胜利—————————————————————————————————————————
//
void Game_Scene::winGame()
{
    if(canWin == true)
    {
        //停止刷新
        m_timer.stop();
        isPause=true;
        isWin=true;
        //发射胜利信号
        cout<<"胜利！当前地图："<<nowMap<<" 当前关卡："<<nowLevel;
        emit win_signal(nowMap,nowLevel);
        win_sound.play();

        canWin = false;
    }
}
//——————————————————————————————————————屏幕振动————————————————————————————————————————
//
void Game_Scene::shakeWindow()
{
    m_shakeTimer.start();
//    for(int i=0;i<BLOCK_NUM;i++)
//    {
//        m_blocks[i].block_y+=10;
//    }
//    originY+=10;
    cout<<"振动信号发出";
}
//——————————————————————————————————————信息入栈————————————————————————————————————————
//
void Game_Scene::pushStack(int x, int y, int num)
{
    block_data temp;
    temp.x=x;
    temp.y=y;
    temp.num=num;

    temp.name=m_blocks[num].block_name;



    remStack.push(temp);

}
//——————————————————————————————————————信息出栈—————————————————————————————————————————
//
void Game_Scene::popStack()
{
    block_data temp = remStack.back();
    remStack.pop();
    m_blocks[temp.num].block_x=temp.x;
    m_blocks[temp.num].block_y=temp.y;
    m_blocks[temp.num].block_isVisible=true;

    m_blocks[temp.num].block_name=temp.name;


}

void Game_Scene::isDeadGame()
{
    int temp=0;
    for(int i=0;i<BLOCK_NUM;i++)
    {
       if(m_blocks[i].block_isMove == true && m_blocks[i].block_isVisible == true)
       {
           temp++;
       }
    }
    if(temp == 0)
    {
        ui->label->show();
        ui->label_2->show();
    }
    else
    {
        ui->label->hide();
        ui->label_2->hide();
    }
}

//——————————————————————————————————————从文件读取地图————————————————————————————————————
//根据txt文本初始化以下属性：isVisible,type,name,x,y,pix
void Game_Scene::iniMAP(int map,int name,QString qName,int mode)
{
    nowMap=map;
    nowLevel=name;

    effectTextNum=0;
    //清除所有占用
    for(int i=0;i<100;i++)
    {
        allName[i]=false;
    }

    //赢！
    canWin = true;

    //清空栈
    remStack.clear();
    numStack.clear();
    isWin=false;
    //清空地图（不清空会留存到下局）
    for(int i=0;i<BLOCK_NUM;i++)
    {
        m_blocks[i].block_isVisible = false;
        //坐标
        m_blocks[i].block_x=-sideLength;
        m_blocks[i].block_y=-sideLength;

        //是否可见
        m_blocks[i].block_isVisible=false;
        //是否可触碰
        m_blocks[i].block_isTouch=false;
        //是否可操作
        m_blocks[i].block_isMove=false;
        //是否可推动
        m_blocks[i].block_isPush=false;
        //是否是胜利方块
        m_blocks[i].block_isWin=false;
        //是否是危险方块
        m_blocks[i].block_isDanger=false;
        //是否是自爆方块
        m_blocks[i].block_isBomb=false;
        //是否M/H
        m_blocks[i].block_isMelt=false;
        m_blocks[i].block_isHot=false;
        //是否S/O
        m_blocks[i].block_isShut=false;
        m_blocks[i].block_isOpen=false;
        //是否漂浮
        m_blocks[i].block_isFloat=false;
        //是否溺水
        m_blocks[i].block_isSink=false;
        //是否特效
        m_blocks[i].block_isDuang=false;

        //是否被动移动
        m_blocks[i].block_isBeMove=false;

        //是否生效
        m_blocks[i].block_isTextEffect=false;
    }


    if(map == MAP_ISLAND)
    {
        m_ubackground_1.load(":/res/uback2.png");
    }else if(map == MAP_WATER)
    {
        m_ubackground_1.load(":/res/uback3.png");
    }else if(map == MAP_LAVA)
    {
        m_ubackground_1.load(":/res/uback1.png");
    }

    QString str;
    if(mode == 0)
    {
        //初始化游戏地图路径
        switch (map) {
        case MAP_ISLAND:
            str = LEVEL_ISLAND_PATH;
            str = str.arg(name);
            break;
        case MAP_WATER:
            str = LEVEL_WATER_PATH;
            str = str.arg(name);
            break;
        case MAP_LAVA:
            str = LEVEL_LAVA_PATH;
            str = str.arg(name);
            break;
        default:
            str = FILE_PATH_2;
            break;
        }
        cout<<"打开关卡地图："<<str;
    }
    else
    {
        str=FILE_PATH_EDITOR;
        str=str.arg(qName);

    }

    cout<<map<<" "<<name<<" "<<"地图路径为"<<str;


    //以下没问题
    QFile file(str);
    bool isOk=file.open(QIODevice::ReadOnly);
    cout<<"文件正常打开："<<isOk;
    if(isOk == true)
    {
        int t_type;
        int t_name;
        int t_num;
        int t_blocks=0;
        cout<<"文件正常读取："<<file.atEnd();
        columNum = readLineInt(file);
        rowNum = readLineInt(file);
        sideLength = readLineInt(file);
        cout<<"动态屏幕宽，长方块数+边长"<<columNum<<" "<<rowNum<<" "<<sideLength;

        inWidth=columNum*sideLength;
        inHeight=rowNum*sideLength;
        originX=(SCENE_M_WIDTH-inWidth)/2;
        originY=(SCENE_M_HEIGHT-inHeight)/2;

        cout<<"动态屏幕原点："<<originX<<" "<<originY;
        while(file.atEnd() == false)
        {
            //读类型
            t_type=readLineInt(file);
            //读名字
            t_name=readLineInt(file);
            //读数量
            t_num=readLineInt(file);
            cout<<t_type<<t_name<<t_num;
            for(int i=0;i<t_num;i++)
            {
                //对文档输入方块初始化isVisble,type,name,x,y
                m_blocks[t_blocks].block_isVisible = true;
                m_blocks[t_blocks].block_type = t_type;
                m_blocks[t_blocks].block_name = t_name;
                m_blocks[t_blocks].sideLength = sideLength;
                m_blocks[t_blocks].loadPix(m_blocks[t_blocks].block_type,m_blocks[t_blocks].block_name,openAni);

                //读x坐标
                m_blocks[t_blocks].block_x = readLineInt(file)*sideLength+originX;
                //读y坐标
                m_blocks[t_blocks].block_y = readLineInt(file)*sideLength+originY;
                t_blocks++;
            }
        }
    }

    updateEffect();
    //统计生效词条数
    for(int i=0;i<BLOCK_NUM;i++)
    {
        if(m_blocks[i].block_isVisible == true && m_blocks[i].block_isTextEffect == true)
        {
            effectTextNum++;
        }
    }

    cout<<"初始化最终值"<<effectTextNum;

}
//——————————————————————————————————————从文件读行转INT————————————————————————————————————
//读取一行文件，输出INT
int Game_Scene::readLineInt(QFile &file)
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
//——————————————————————————————————————初始化词条属性————————————————————————————————————
//初始化词条属性和图片（词条属性和图片初始化后不会变了）
void Game_Scene::iniText()
{
    for(int i=0;i<BLOCK_NUM;i++)
    {
        if(m_blocks[i].block_type == TY_PREDICATE || m_blocks[i].block_type == TY_NAME || m_blocks[i].block_type == TY_ADJ )
        {
            m_blocks[i].block_isPush = true;
            m_blocks[i].block_isTouch = true;
            m_blocks[i].loadPix(m_blocks[i].block_type,m_blocks[i].block_name,openAni);
        }
    }
}


