#include "pause_scene.h"
#include "ui_pause_scene.h"

Pause_Scene::Pause_Scene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pause_Scene)
{
    //返回类型
    returnType = 0;

    ui->setupUi(this);
    //本窗口初始化
    setFixedSize(SCENE_M_WIDTH,SCENE_M_HEIGHT);
    //背景颜色初始化
    QPalette palette(this->palette());
    palette.setColor(QPalette::Background, QColor(0x00,0x00,0x00,0x6f));    //采用RGBA（A为alpha透明度）
    setAutoFillBackground(true);
    setPalette(palette);

    //切换窗口初始化
    sce_change.setParent(this);
    sce_change.hide();
    sce_change.move(0,0);

    ui->label->setStyleSheet("font: bold; font-size:20px; color: rgb(255, 255, 255);");
}

Pause_Scene::~Pause_Scene()
{
    delete ui;
}

void Pause_Scene::iniName()
{
    QString temp = "当前关卡为："+nowName;
    cout<<temp<<" "<<nowName;
    ui->label->setText(temp);
}

void Pause_Scene::quickRestart()
{
    emit restart_signal();
}

void Pause_Scene::on_b2_exitToChoose_released()
{
    if(returnType == 1)
    {
        emit testLevelToEdit_signal();
    }
    else
        emit gameToChoose_signal();
    cout<<returnType<<"点击了";
}

void Pause_Scene::on_b1_start_released()
{
    emit exitToGame_signal();
}

void Pause_Scene::on_b5_exitToGuide_released()
{
    emit gameToGuide_signal();
}

void Pause_Scene::on_b3_reStart_released()
{
    emit restart_signal();
}


