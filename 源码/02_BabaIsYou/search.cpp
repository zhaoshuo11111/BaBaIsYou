#include "search.h"
#include "ui_search.h"

search::search(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::search)
{
    ui->setupUi(this);
    setFixedSize(SCENE_E_WIDTH,SCENE_E_HEIGHT);
    setWindowTitle("请输入");
}

search::~search()
{
    delete ui;
}

void search::paintEvent(QPaintEvent *event)
{

        QPainter *painter = new QPainter(this);
        painter->fillRect(this->rect(),QColor(116,120,159));

}

void search::on_pushButton_2_clicked()//back
{
    emit sback();
}

void search::on_pushButton_clicked()//ok
{
    stext=ui->lineEdit->text();
    emit sok();
    //获取内容

    //qDebug()<<stext;//????????????why编辑不了
    //切换界面
    hide();
}
