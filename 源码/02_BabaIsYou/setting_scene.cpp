#include "setting_scene.h"
#include "ui_setting_scene.h"

Setting_Scene::Setting_Scene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Setting_Scene)
{
    ui->setupUi(this);

    //窗口初始化
    setFixedSize(SCENE_S_WIDTH,SCENE_S_HEIGHT);
    //背景颜色初始化

    QPalette palette(this->palette());
    palette.setColor(QPalette::Background, QColor(0x00,0x00,0x00,0x6f));
    setAutoFillBackground(true);
    setPalette(palette);

    //控件
    ui->s1_dffectVolum->setSliderPosition(50);
    ui->s2_musicVolum->setSliderPosition(50);

    //背景图
    back.load(":/res/settingBack2.png");
    //样例展示
    openAni=true;
    showObject.loadPix(TY_BLOCK,NAME_FLAG,true);
    showObject.loadPix(TY_BLOCK,NAME_FLAG,false);
    showObject.block_x = SCENE_M_WIDTH*0.5-SCENE_S_WIDTH*0.5+10;
    showObject.block_y = SCENE_M_HEIGHT*0.5-SCENE_S_HEIGHT*0.5+10;

    shakeWin = true;
    //初始化计时器
    //初始化计时器【刷新速率】*
    m_timer.setInterval(GAME_RATE);

    playAni();


}

Setting_Scene::~Setting_Scene()
{
    delete ui;
}

void Setting_Scene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,SCENE_S_WIDTH,SCENE_S_HEIGHT,back);
    if(openAni == true)
    {
        Animation temp = showObject.block_animation;
        painter.drawPixmap(showObject.block_x,showObject.block_y,temp.ani_pixVector[temp.ani_index].width(),temp.ani_pixVector[temp.ani_index].height(),temp.ani_pixVector[temp.ani_index]);
        showObject.block_animation.updateIndex();
    }
    else
    {
        painter.drawPixmap(showObject.block_x,showObject.block_y,showObject.block_pix);
    }

}

void Setting_Scene::playAni()
{
    //开始计时
    m_timer.start();
    //开始刷新
    connect(&m_timer,&QTimer::timeout,
            [=]()
            {
            //绘图刷新
            update();
            }
            );
}

void Setting_Scene::on_b6_exit_released()
{
    this->hide();
}

void Setting_Scene::on_b2_animation_released()
{
    if(openAni == true)
    {
        ui->b2_animation->setText("闲置动画：关");
        openAni = false;
    }
    else
    {
        ui->b2_animation->setText("闲置动画：开");
        openAni = true;
    }
    emit openAniChange_signal();
}

void Setting_Scene::on_b3_shake_released()
{
    if(shakeWin == true)
    {
        ui->b3_shake->setText("屏幕抖动：关");
        shakeWin = false;
    }
    else
    {
        ui->b3_shake->setText("屏幕抖动：开");
        shakeWin = true;
    }
    emit shakeWin_signal();
}

void Setting_Scene::on_s1_dffectVolum_sliderReleased()
{
    emit eVolumeChange(ui->s1_dffectVolum->value());
}

void Setting_Scene::on_s2_musicVolum_sliderReleased()
{
    cout<<"改变音乐音量——槽";
    emit mVolumeChange(ui->s2_musicVolum->value());
}
