#include "set_level_name.h"
#include "ui_set_level_name.h"
#include<QDebug>

Set_Level_Name::Set_Level_Name(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Set_Level_Name)
{
    ui->setupUi(this);

//    edit.setParent(this);
//    edit.hide();

    //窗口初始化
    setFixedSize(SCENE_M_WIDTH,SCENE_M_HEIGHT);
    setWindowTitle("请输入");

}

Set_Level_Name::~Set_Level_Name()
{
    delete ui;
}

void Set_Level_Name::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);
    painter->fillRect(this->rect(),QColor(116,120,159));
}

void Set_Level_Name::on_pushButton_clicked()
{

    name=ui->lineEdit->text();
    emit getname();

    hide();
}


void Set_Level_Name::on_pushButton_2_clicked()
{
    emit return_to_level();
    hide();
}
