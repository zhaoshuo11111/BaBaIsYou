#include "edit_level.h"
#include "ui_edit_level.h"


Edit_Level::Edit_Level(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Edit_Level)
{
    ui->setupUi(this);
    //窗口初始化
    setFixedSize(SCENE_M_WIDTH,SCENE_M_HEIGHT);

    ui->lineEdit->setText("\0");
    edit.setParent(this);
    edit.hide();

    //ui->pushButton_2->hide();

    levelnum=0;
    levelnummax=0;
    judge=false;
    set_level_name.setParent(this);
    set_level_name.hide();

    levelpix.load(":/res/BIY_title_3.png");

    getpath();
    connect(&set_level_name,&Set_Level_Name::return_to_level,
            [=]()
    {
        set_level_name.hide();
    });
    connect(&set_level_name,&Set_Level_Name::return_to_guide_scene,
            [=]()
    {
        emit exit_signal();
    });
    //新建关卡
    connect(&set_level_name,&Set_Level_Name::getname,
            [=]()
    {
        //获取内容
        QString newlevelname=set_level_name.name;
        qDebug()<<newlevelname;//????????????why编辑不了
        //切换界面
        //hide();
        edit.setWindowTitle(newlevelname);
        edit.level_name=newlevelname;


        edit.filepath=edit.filepath.arg(edit.level_name);
        cout<<edit.filepath;
        edit.readmap(edit.filepath);
        edit.show();
        //edit.setFocus();
    });
    connect(&edit,&editor::return_to_guide_scene,
            [=]()
    {
        getpath();
        emit exit_signal();

    });
    connect(&edit,&editor::return_to_level,
            [=]()
    {
        getpath();
        //update();

    });

                    connect(ui->pushButton_2,&QPushButton::clicked,
                            [=]()
                            {
                                returnname=ui->pushButton_2->text();
                                cout<<"你选择"<<returnname;
                                //hide();
                                //edit.setWindowTitle(returnname);
                                edit.level_name=returnname;
                                edit.filepath=edit.filepath.arg(edit.level_name);
                                cout<<edit.filepath;
                                edit.readmap(edit.filepath);
                                edit.show();
                            }
                            );

}

Edit_Level::~Edit_Level()
{
    delete ui;
}

void Edit_Level::getpath()
{


    levelnum=0;
    levelnummax=0;
    QString epath="../02_BabaIsYou/level/editor";
    QDir dir(epath);
    QStringList filters;
    filters << "*.txt";

    QString searchword=ui->lineEdit->text();
    dir.setNameFilters(filters);

    QFileInfoList list = dir.entryInfoList(QDir::Files);	//获取所有文件


            foreach (QFileInfo file, list)                  			//遍历只加载.txt到文件列表
            {
                levelname=file.baseName();
                if(levelname.contains(searchword))
                {
                    cout<<levelname;
                    level[levelnum]=levelname;
                    levelnum++;
                    levelnummax++;
                }


            }


        levelnum=0;

    ui->pushButton_2->setText(level[levelnum]);
}

void Edit_Level::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    //painter.fillRect(this->rect(),QColor(116,120,159));
    //painter.drawPixmap(1,1);
    QPixmap temp;
    temp.load(":/res/editLevelBack_2.png");
    painter.drawPixmap(0,0,SCENE_M_WIDTH,SCENE_M_HEIGHT,temp);
    QString temp_str;
    temp_str=QString(IMAGE_PATH).arg(ui->pushButton_2->text());
    cout<<temp_str;
    levelpix.load(temp_str);
    int x=levelpix.width();
    int y=levelpix.height();
    if(x == 0)
    {
        x=1;
        cout<<"报错";
    }
    int t=500*y/x;
    painter.drawPixmap(80,240-t/2,500,t,levelpix);
}

void Edit_Level::on_pushButton_clicked()
{
    emit exit_signal();
}

void Edit_Level::on_pushButton_3_clicked()
{
    //hide();
    set_level_name.show();
}

void Edit_Level::on_pushButton_4_clicked()//搜索
{
    getpath();
    update();
}

void Edit_Level::on_pushButton_5_clicked()
{
    ui->lineEdit->setText("\0");
    getpath();
    update();
}

void Edit_Level::on_pushButton_2_clicked()//启动
{

}

void Edit_Level::on_pushButton_6_clicked()//上一关
{
    if(levelnum==0)
        return;
    levelnum--;
    ui->pushButton_2->setText(level[levelnum]);
    update();
}

void Edit_Level::on_pushButton_7_clicked()//下一关
{
    if(levelnum>=levelnummax-1)
        return;
    levelnum++;
    ui->pushButton_2->setText(level[levelnum]);
    cout<<levelnum<<"and"<<levelnummax;
    update();
}
