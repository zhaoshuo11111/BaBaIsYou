#include "editor.h"
#include "ui_editor.h"
#include"config.h"
editor::editor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::editor)
{
    ui->setupUi(this);
    //窗口初始化
    setFixedSize(SCENE_E_WIDTH,SCENE_E_HEIGHT);
    //初始化文件路径
    //设置父子
    term.setParent(this);
    term.hide();

    //初始化暂停界面
        Game_Testlevel.sce_pause.returnType=1;

    ui->spinBox->setValue(25);
    ui->spinBox_2->setValue(12);
    ui->spinBox_3->setValue(40);


    filepath=FILE_PATH_EDITOR;
//    filepath=filepath.arg(level_name);
//    cout<<filepath;
    //初始化方块数量
    bl_num=0;

    //把将要处理的方块设为nothing
    now_b_pos=0;
    now_type=TY_BLOCK;
    now_name=NAME_NOTHING;

    place_method=many_per_time;
    for(int i=0;i<25;i++)
    {
        for(int j=0;j<12;j++)
        {
            place_map[i][j]=0;
        }
    }
    ismove=false;

    //初始化右上角可供选择的图标
    initoptions();
    //readmap(filepath);
    //初始化计时器【刷新速率】*
    m_timer.setInterval(GAME_RATE);

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
    //测试成功切回
    connect(&Game_Testlevel,&Game_Scene::win_signal,
            [=]()
    {
        Game_Testlevel.hide();
        show();
    });



    connect(&term,&Term_Borad::back_to_editor,
            [=]()
    {

        term.hide();
    });

    connect(&term,&Term_Borad::have_chosen,
            [=]()
    {
        this->show();
        term.hide();
        now_name=term.emitname;
        now_type=term.emittype;
        m_blocks[now_b_pos].block_type=now_type;
        m_blocks[now_b_pos].block_name=now_name;
        m_blocks[bl_num].loadPix(now_type,now_name,false);
        m_blocks[now_b_pos].loadPix(now_type,now_name,false);
    });

}

editor::~editor()
{
    delete ui;
}

void editor::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);


    //绘制背景图
    painter.fillRect(this->rect(),QColor(116,120,159));
    m_background.load(BACKGROUND_PATH);
    painter.drawPixmap(0,LENGTH_OF_SIDE,SCENE_M_WIDTH-40,SCENE_M_HEIGHT-40,m_background);

    //绘制方块
    for(int i=0;i<BLOCK_NUM;i++)
    {
        if(m_blocks[i].block_isVisible == true&&(i!=10)&&(i!=11))
        {
            painter.drawPixmap(m_blocks[i].block_x,m_blocks[i].block_y,m_blocks[i].block_pix);
        }
    }
    painter.drawPixmap(m_blocks[10].block_x-2,m_blocks[10].block_y,44,40,m_blocks[10].block_pix);//要改
    if(m_blocks[11].block_isVisible)
    {
        painter.drawPixmap(m_blocks[11].block_x,m_blocks[11].block_y,40,40,m_blocks[11].block_pix);
    }


}

void editor::initoptions()
{
    //坐标
    for(bl_num=0;bl_num<10;bl_num++)
    {
        m_blocks[bl_num].block_x=640+bl_num*40;
        m_blocks[bl_num].block_y=0;
        m_blocks[bl_num].block_isVisible=true;
    }
    m_blocks[10].block_x=640;
    m_blocks[10].block_y=0;
    m_blocks[10].block_isVisible=true;
    //设置类型（图片）
    //#define TY_BLOCK 0
    //#define TY_PREDICATE 1
    //#define TY_NAME 2
    //#define TY_ADJ 3
    m_blocks[0].loadPix(TY_BLOCK,NAME_NOTHING,false);
    m_blocks[1].loadPix(TY_BLOCK,NAME_WALL,false);
    m_blocks[2].loadPix(TY_ADJ,NAME_PUSH,false);
    m_blocks[3].loadPix(TY_ADJ,NAME_STOP,false);
    m_blocks[4].loadPix(TY_PREDICATE,NAME_AND,false);
    m_blocks[5].loadPix(TY_ADJ,NAME_WIN,false);
    m_blocks[6].loadPix(TY_BLOCK,NAME_FLAG,false);
    m_blocks[7].loadPix(TY_ADJ,NAME_YOU,false);//YOU算ADJ？orPREDICATE?
    m_blocks[8].loadPix(TY_BLOCK,NAME_BABA,false);
    m_blocks[9].loadPix(TY_PREDICATE,NAME_IS,false);

    m_blocks[10].block_pix.load(LBLOCK_MOVE_PATH);//选中状态
    m_blocks[11].block_pix.load(LBLOCK_MOVE_PATH);//选中状态
    m_blocks[10].block_pix.scaled(LENGTH_OF_SIDE,LENGTH_OF_SIDE,Qt::KeepAspectRatio);    //设定图像大小
    m_blocks[10].block_pix.scaled(LENGTH_OF_SIDE,LENGTH_OF_SIDE,Qt::KeepAspectRatio);
    bl_num+=2;
    m_blocks[bl_num].loadPix(now_type,now_name,false);

}

void editor::place(int tpos_x,int tpos_y)
{
    m_blocks[bl_num].block_x=tpos_x*40;
    m_blocks[bl_num].block_y=tpos_y*40+40;
    cout<<"做了";
    //特殊情况（当前处理为nothing方块，
    //即删除（隐藏）当前位置最上层显示方块（因为要存在撤销再次显示，所以置为不可见））
    if(m_blocks[bl_num].block_name==NAME_NOTHING)
    {
        \
        for(int tempf=bl_num-1;tempf>=10;tempf--)
        {
            if((m_blocks[tempf].block_x==tpos_x*40)&&(m_blocks[tempf].block_y==tpos_y*40+40)&&(m_blocks[tempf].block_isVisible==true))
            {
                m_blocks[tempf].block_isVisible=false;
                break;
            }
        }
    }
    else
    {
        m_blocks[bl_num].block_isVisible=true;
    }
    bl_num++;
    m_blocks[bl_num].loadPix(now_type,now_name,false);
}

void editor::mousePressEvent(QMouseEvent *event)//用于快速选择方块种类
{

    int i=event->x();
    int j=event->y();
    cout<<i<<"and"<<j<<"按下";
    //选择方块种类
    if(i>=640&&i<1040&&j>0&&j<=40)
    {
        now_b_pos=(i-640)/40;//tempposition,临时记录方块为第几个
        now_type=m_blocks[now_b_pos].block_type;
        now_name=m_blocks[now_b_pos].block_name;
        m_blocks[10].block_x=m_blocks[now_b_pos].block_x;
        m_blocks[10].block_y=m_blocks[now_b_pos].block_y;
        m_blocks[bl_num].loadPix(now_type,now_name,false);
    }
    if(i>=0&&i<1000&&j>40&&j<520)
        place_method=many_per_time;
    else
        place_method=one_per_time;
    ismove=false;

}

void editor::mouseReleaseEvent(QMouseEvent *event)//用于放置方块
{
    for(int i=0;i<25;i++)
    {
        for(int j=0;j<12;j++)
        {
            place_map[i][j]=0;
        }
    }
    cout<<"有抬起哦";
    if(place_method==many_per_time&&ismove==true)
        return;
    int i=event->x();
    int j=event->y();
    cout<<i<<"and"<<j<<"抬起";
    //选择放置方块位置
    if(i>=0&&i<1000&&j>40&&j<520)
    {
        //int tpos_x=i/40;
        //int tpos_y=(j-40)/40;
        cout<<"暂时没问题";
        place(i/40,(j-40)/40);
    }

}

void editor::mouseMoveEvent(QMouseEvent *event)
{

    ismove=true;
    if(place_method==one_per_time)
        return;
    int i=event->x()/40;
    int j=(event->y()-40)/40;
    cout<<i<<" "<<j;
    if(i>=0&&i<25&&j>=0&&j<12)
    {
        if(place_map[i][j]==1)//经过该路径过直接return
            return;
        place_map[i][j]=1;
        place(i,j);
    }

}

int editor::readLineInt(QFile &file)
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

bool editor::readmap(QString str)
{
    for(int i=0;i<bl_num;i++)
    {
        m_blocks[i].block_isVisible=false;
        m_blocks[i].loadPix(0,999,true);

        //初始化坐标
        m_blocks[i].block_x=-LENGTH_OF_SIDE;
        m_blocks[i].block_y=-LENGTH_OF_SIDE;
    }

    initoptions();
    now_b_pos=0;
    now_type=TY_BLOCK;
    now_name=NAME_NOTHING;

    QFile file(str);
    bool isOk=file.open(QIODevice::ReadOnly);
    cout<<"文件正常打开："<<isOk;
    if(isOk == true)
    {
        int t_type;
        int t_name;
        int t_num;
        int t_blocks=12;
        cout<<"文件正常读取："<<file.atEnd();
        ui->spinBox->setValue(readLineInt(file));
        ui->spinBox_2->setValue(readLineInt(file));
        ui->spinBox_3->setValue(readLineInt(file));


        //cout<<"动态屏幕"<<originX<<" "<<originY;
    while(file.atEnd() == false)
    {
        //读类型
        t_type=readLineInt(file);
        //读名字
        t_name=readLineInt(file);
        //读数量
        t_num=readLineInt(file);
        bl_num+=t_num;
        //cout<<t_type<<t_name<<t_num;
        for(int i=0;i<t_num;i++)
        {
            //对文档输入方块初始化isVisble,type,name,x,y
            m_blocks[t_blocks].block_isVisible = true;
            m_blocks[t_blocks].block_type = t_type;
            m_blocks[t_blocks].block_name = t_name;
            //m_blocks[t_blocks].sideLength = sideLength;
            m_blocks[t_blocks].loadPix(m_blocks[t_blocks].block_type,m_blocks[t_blocks].block_name,false);

            //读x坐标
            m_blocks[t_blocks].block_x = readLineInt(file)*40;
            //读y坐标
            m_blocks[t_blocks].block_y = readLineInt(file)*40+40;
            t_blocks++;
        }
    }
    }
    m_blocks[bl_num].loadPix(now_type,now_name,false);
}


void editor::on_pushButton_3_clicked()//切换
{
    //对于存在两种状态的方块进行状态转换
    if(now_type==TY_BLOCK)
        now_type=TY_NAME;
    else if(now_type==TY_NAME)
        now_type=TY_BLOCK;
    m_blocks[bl_num].loadPix(now_type,now_name,false);
    m_blocks[now_b_pos].loadPix(now_type,now_name,false);
    cout<<"success"<<now_type;
}

void editor::on_pushButton_5_clicked()//保存
{

    /*type          文件格式
前三行输入：
宽方块数
长方块数
指定的方块大小

之后：
类型
名字
数量n
之后2*n行：
x
y
x
y
...
    */

        QFile file;
        //QString filepath;


        file.setFileName(filepath);//路径怎么写~——~
        bool IsOk=file.open(QIODevice::WriteOnly);
        cout<<IsOk;
        cout<<filepath;
        if(true==IsOk)
        {
            QTextStream stream(&file);
            //stream<<250;
            //file.close();
            //先默认大小
            stream<<ui->spinBox->value()<<endl;
            stream<<ui->spinBox_2->value()<<endl;
            stream<<ui->spinBox_3->value()<<endl;
            bool record[BLOCK_NUM];//记录是否写过（要遍历两次，设两个组各走一遍）
            bool recordnum[BLOCK_NUM];
            for(int i=12;i<bl_num;i++)
            {
                record[i]=!(m_blocks[i].block_isVisible);//不可视算作记录过
                recordnum[i]=!(m_blocks[i].block_isVisible);
            }
            for(int i=12;i<bl_num;i++)
            {
                if(record[i]==false)
                {
                    stream<<m_blocks[i].block_type<<endl;
                    stream<<m_blocks[i].block_name<<endl;
                    int j=i;
                    int num=0;
                    for(;j<bl_num;j++)//记录数目
                    {
                        if(recordnum[j]==true)
                            continue;
                        if((m_blocks[j].block_name==m_blocks[i].block_name)&&(m_blocks[j].block_type==m_blocks[i].block_type))
                        {
                           num++;
                           recordnum[j]=true;
                        }
                    }
                    stream<<num<<endl;
                    for(j=i;j<bl_num;j++)//各位置坐标
                    {
                        if(record[j]==true)
                            continue;
                        if((m_blocks[j].block_name==m_blocks[i].block_name)&&(m_blocks[j].block_type==m_blocks[i].block_type))
                        {
                            stream<<m_blocks[j].block_x/40<<endl;
                            stream<<m_blocks[j].block_y/40-1<<endl;
                            record[j]=true;
                        }
                    }
                }
            }
        }
        //画图
        QPixmap pixMap_ = QPixmap::grabWidget(this);
        QPixmap m_pixmap=pixMap_.copy(0,40,40*ui->spinBox->value(),40*ui->spinBox_2->value());
        m_pixmap.save(QString(IMAGE_PATH).arg(level_name));
        //pixMap_.save("./level/image/2.png");
//        pixMap_.save("./level/myImage.png");
//        QPixmap m_pixmap = QPixmap(ui->widget_2->size());
}

void editor::on_pushButton_2_clicked()//测试
{
    this->hide();
    Game_Testlevel.iniMAP(MAP_ISLAND,0,level_name,1);    //注意看
    Game_Testlevel.iniText();
    Game_Testlevel.show();
    Game_Testlevel.playGame();
}

void editor::on_pushButton_6_clicked()//物件板
{
    //未选中可展示方块情况下不可启用物件板
    //后期加入提示
    if(now_name==NAME_NOTHING)
        return;

    term.show();
}



void editor::on_pushButton_clicked()//回关卡列表
{
    filepath=FILE_PATH_EDITOR;
    emit return_to_level();
    hide();
}

void editor::on_pushButton_4_clicked()
{
    filepath=FILE_PATH_EDITOR;
    emit return_to_guide_scene();
    hide();
}


