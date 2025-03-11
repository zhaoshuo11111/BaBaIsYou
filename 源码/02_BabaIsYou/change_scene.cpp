#include "change_scene.h"
#include "ui_change_scene.h"

Change_Scene::Change_Scene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Change_Scene)
{
    ui->setupUi(this);

    //窗口初始化
    setFixedSize(SCENE_M_WIDTH,SCENE_M_HEIGHT);

    //背景颜色初始化
    QPalette palette(this->palette());
    palette.setColor(QPalette::Background, QColor(0x00,0xff,0x00,0x00));    //采用RGBA（A为alpha透明度）
    setAutoFillBackground(true);
    setPalette(palette);

    //初始化动画类型
    m_aniType=ANI_TYPE_1;

    //初始化计时器【刷新速率】*
    m_timer.setInterval(GAME_RATE);
    //初始化单次计数器
    m_singelTimer.setSingleShot(true);

    //音乐
    musicChange.setSource(QUrl::fromLocalFile(":/music/changePage.wav"));
    musicChange.setLoopCount(1);
    musicChange.setVolume(1);

    //开始刷新
    connect(&m_timer,&QTimer::timeout,
            [=]()
            {
            if(m_aniType == ANI_TYPE_1)
            {
                times+=4;
            }else if(m_aniType == ANI_TYPE_2)
            {
                times+=2;
            }else if(m_aniType == ANI_TYPE_3)
            {
                times+=4;
            }
            //绘图刷新
            update();
            }

    );

    //动画结束信号发出
    connect(&m_singelTimer,&QTimer::timeout,
            [=]()
            {
                //发出动画结束信号
                emit endAni_signal();
                //计时结束
                m_timer.stop();
                m_singelTimer.stop();
            }

    );

}

Change_Scene::~Change_Scene()
{
    delete ui;
}

//——————————————————————————————绘图事件—————————————————————————————————————
//绘制动画
void Change_Scene::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    //笔刷
    painter.setBrush(QColor(8,9,50));
    //字体
    QFont font("微软雅黑",15,QFont::Bold,true);
    painter.setFont(font);
    //多边形
    QPolygon polygon;

    //收缩动画
    if(m_aniType == ANI_TYPE_1)
    {
        painter.setPen(QColor(8,9,50));
        //上1
        painter.drawEllipse(-200,-SCENE_M_WIDTH+times*0.5,SCENE_M_WIDTH,SCENE_M_WIDTH);
        //上2
        painter.drawEllipse(150,-SCENE_M_WIDTH+times*0.5-50,SCENE_M_WIDTH,SCENE_M_WIDTH);
        //下1
        painter.drawEllipse(-250,SCENE_M_HEIGHT-times*0.5,SCENE_M_WIDTH,SCENE_M_WIDTH);
        //下2
        painter.drawEllipse(200,SCENE_M_HEIGHT-times*0.5+50,SCENE_M_WIDTH,SCENE_M_WIDTH);
        //左1
        painter.drawEllipse(-SCENE_M_WIDTH+times*1+50,SCENE_M_HEIGHT*0.5-SCENE_M_WIDTH*0.5+200,SCENE_M_WIDTH,SCENE_M_WIDTH);
        //左2
        painter.drawEllipse(-SCENE_M_WIDTH+times*1,SCENE_M_HEIGHT*0.5-SCENE_M_WIDTH*0.5-200,SCENE_M_WIDTH,SCENE_M_WIDTH);
        //右1
        painter.drawEllipse(SCENE_M_WIDTH-times*1,SCENE_M_HEIGHT*0.5-SCENE_M_WIDTH*0.5-300,SCENE_M_WIDTH,SCENE_M_WIDTH);
        //右2
        painter.drawEllipse(SCENE_M_WIDTH-times*1-40,SCENE_M_HEIGHT*0.5-SCENE_M_WIDTH*0.5+300,SCENE_M_WIDTH,SCENE_M_WIDTH);
        //左上
        painter.drawEllipse(-SCENE_M_WIDTH+times*1.5,-SCENE_M_WIDTH+times*1,SCENE_M_WIDTH,SCENE_M_WIDTH);
        //右上
        painter.drawEllipse(SCENE_M_WIDTH-times*1.5,-SCENE_M_WIDTH+times*1,SCENE_M_WIDTH,SCENE_M_WIDTH);
        //左下
        painter.drawEllipse(-SCENE_M_WIDTH+times*1.5,SCENE_M_HEIGHT-times*1,SCENE_M_WIDTH,SCENE_M_WIDTH);
        //右下
        painter.drawEllipse(SCENE_M_WIDTH-times*1.5,SCENE_M_HEIGHT-times*1,SCENE_M_WIDTH,SCENE_M_WIDTH);

    }
    //胜利动画
    if(m_aniType == ANI_TYPE_2)
    {
        static int temp=0;
        //移动范围
        if(temp<40)
        {
            temp=times;
        }else if(times <= 10)
        {
            temp=times;
        }
        //中央菱形
        painter.setPen(QColor(8,9,50));
        polygon<<QPoint(SCENE_M_WIDTH*0.5,200-temp)<<QPoint(300-temp,SCENE_M_HEIGHT*0.5)<<QPoint(SCENE_M_WIDTH*0.5,SCENE_M_HEIGHT-200+temp)<<QPoint(SCENE_M_WIDTH-300+temp,SCENE_M_HEIGHT*0.5);
        painter.drawPolygon(polygon);
        //移动范围
        static int temps=0;
        if(temps<150)
        {
            temps=times;
        }else if(times <= 10)
        {
            temps=times;
        }
        //大
        painter.drawEllipse(380+35-temps/4,150+35-temps/4,200-70+temps/2,200-70+temps/2);
        painter.drawEllipse(440+70-temps/2,180+70-temps/2,200-140+temps,200-140+temps);
        painter.drawEllipse(530+70-temps/2,220+70-temps/2,200-140+temps,200-140+temps);
        painter.drawEllipse(590,150,120,120);
        painter.drawEllipse(310+35-temps/4,210+35-temps/4,180-70+temps/2,180-70+temps/2);
        painter.drawEllipse(620,190,180,180);
        //小
        painter.drawEllipse(280+15-temps/6,220+15-temps/6,60-30+temps/3,60-30+temps/3);
        painter.drawEllipse(230,250,80,80);
        painter.drawEllipse(420,380,60,60);
        painter.drawEllipse(480,360,60,60);
        painter.drawEllipse(540+15-temps/6,160+15-temps/6,60-30+temps/3,60-30+temps/3);
        painter.drawEllipse(280,320,60,60);


        //文本
        painter.setPen(Qt::white);
        painter.drawText(SCENE_M_WIDTH*0.5-50,SCENE_M_HEIGHT*0.5,tr("通过此关"));
        //覆盖
        painter.setPen(QColor(8,9,50));
        painter.drawEllipse(-SCENE_M_WIDTH*0.5,-SCENE_M_WIDTH*3+times*4,SCENE_M_WIDTH*2,SCENE_M_WIDTH*2);
    }
    //关卡显示
    if(m_aniType == ANI_TYPE_3)
    {
        int temp=times;
        if(temp > 1200)
        {
            temp=1200;
        }
        painter.setPen(QColor(8,9,50));
        //上1
        painter.drawEllipse(-200,-SCENE_M_WIDTH+temp*0.5,SCENE_M_WIDTH,SCENE_M_WIDTH);
        //上2
        painter.drawEllipse(150,-SCENE_M_WIDTH+temp*0.5-50,SCENE_M_WIDTH,SCENE_M_WIDTH);
        //下1
        painter.drawEllipse(-250,SCENE_M_HEIGHT-temp*0.5,SCENE_M_WIDTH,SCENE_M_WIDTH);
        //下2
        painter.drawEllipse(200,SCENE_M_HEIGHT-temp*0.5+50,SCENE_M_WIDTH,SCENE_M_WIDTH);
        //左1
        painter.drawEllipse(-SCENE_M_WIDTH+temp*1+50,SCENE_M_HEIGHT*0.5-SCENE_M_WIDTH*0.5+200,SCENE_M_WIDTH,SCENE_M_WIDTH);
        //左2
        painter.drawEllipse(-SCENE_M_WIDTH+temp*1,SCENE_M_HEIGHT*0.5-SCENE_M_WIDTH*0.5-200,SCENE_M_WIDTH,SCENE_M_WIDTH);
        //右1
        painter.drawEllipse(SCENE_M_WIDTH-temp*1,SCENE_M_HEIGHT*0.5-SCENE_M_WIDTH*0.5-300,SCENE_M_WIDTH,SCENE_M_WIDTH);
        //右2
        painter.drawEllipse(SCENE_M_WIDTH-temp*1-40,SCENE_M_HEIGHT*0.5-SCENE_M_WIDTH*0.5+300,SCENE_M_WIDTH,SCENE_M_WIDTH);
        //左上
        painter.drawEllipse(-SCENE_M_WIDTH+temp*1.5,-SCENE_M_WIDTH+temp*1,SCENE_M_WIDTH,SCENE_M_WIDTH);
        //右上
        painter.drawEllipse(SCENE_M_WIDTH-temp*1.5,-SCENE_M_WIDTH+temp*1,SCENE_M_WIDTH,SCENE_M_WIDTH);
        //左下
        painter.drawEllipse(-SCENE_M_WIDTH+temp*1.5,SCENE_M_HEIGHT-temp*1,SCENE_M_WIDTH,SCENE_M_WIDTH);
        //右下
        painter.drawEllipse(SCENE_M_WIDTH-temp*1.5,SCENE_M_HEIGHT-temp*1,SCENE_M_WIDTH,SCENE_M_WIDTH);


        //文本
        if(times>600)
        {
            painter.setPen(Qt::white);
            painter.drawText(SCENE_M_WIDTH*0.5-80,SCENE_M_HEIGHT*0.5,levelName);

        }
    }
}

//——————————————————————————————动画开始—————————————————————————————————————
//初始化移动倍率times，根据动画类型m_aniType设定动画结束时间
void Change_Scene::playAni(int type,QString name)
{
    musicChange.play();
    cout<<"切屏音效";
    //倍率初始化
    times=1;
    //类型选择
    m_aniType=type;
    if(m_aniType == ANI_TYPE_1)
    {
        m_singelTimer.setInterval(1200);
    }else if(m_aniType == ANI_TYPE_2)
    {
        m_singelTimer.setInterval(2500);
    }else if(m_aniType  == ANI_TYPE_3)
    {
        cout<<"动画三";
        m_singelTimer.setInterval(3500);
        levelName=name;
    }
    //开始计时
    m_timer.start();
    m_singelTimer.start();

}
