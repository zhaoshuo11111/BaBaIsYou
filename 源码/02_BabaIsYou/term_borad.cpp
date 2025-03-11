#include "term_borad.h"
#include "ui_term_borad.h"
Term_Borad::Term_Borad(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Term_Borad)
{
    ui->setupUi(this);
    setFixedSize(SCENE_E_WIDTH,SCENE_E_HEIGHT);


    //设立父子关系
    tsearch.setParent(this);
    tsearch.hide();
    //搜索功能相关变量初始化
    searchword=" ";
    issearch=false;


    bl_num=0;
    typeb=4;//默认显示所有类型图标
    //初始化可供选择的图标
    initoptions();
    //初始化allname，把所有方块名字写入
    iniallname();
    emittype=-1;
    emitname=-1;
    //初始化计时器【刷新速率】*
    m_timer.setInterval(GAME_RATE);

    //开始计时
    m_timer.start();
    //开始刷新
    connect(&m_timer,&QTimer::timeout,
            [=]()
            {
            //updateblocks();
            //绘图刷新
            update();
            }
            );
    connect(&tsearch,&search::sok,
            [=]()
            {
            issearch=true;
            searchword=tsearch.stext;
            //searchword=searchword.toUpper();
            cout<<"this is searchword"<<searchword<<"没了";
            updateblocks();
            tsearch.hide();
            }
            );
    connect(&tsearch,&search::sback,
            [=]()
            {

            tsearch.hide();
            }
            );
}

Term_Borad::~Term_Borad()
{
    delete ui;
}

void Term_Borad::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    //绘制背景图
    m_background.load(EBACKGROUND);
    painter.drawPixmap(0,0,SCENE_E_WIDTH,SCENE_E_HEIGHT,m_background);
    m_background.load(BACKGROUND_PATH);
    painter.drawPixmap(0,LENGTH_OF_SIDE,SCENE_M_WIDTH,SCENE_M_HEIGHT,m_background);
    //绘制方块
    for(int i=0;i<BLOCK_NUM;i++)
    {
        if(m_blocks[i].block_isVisible == true)
        {
            painter.drawPixmap(m_blocks[i].block_x,m_blocks[i].block_y,m_blocks[i].block_pix);
        }
    }
}

void Term_Borad::initoptions()//block资源更新后要手动改
{
    for(int i=0;i<=18;i++)
    {
        m_blocks[2*i].loadPix(TY_NAME,i,false);
        m_blocks[2*i+1].loadPix(TY_BLOCK,i,false);
    }
        m_blocks[38].loadPix(TY_NAME,19,false);
    for(int i=20;i<=31;i++)
    {
        m_blocks[i+19].loadPix(TY_ADJ,i,false);
    }
    for(int i=32;i<=33;i++)
    {
        m_blocks[i+19].loadPix(TY_PREDICATE,i,false);
    }
    bl_num=53;
    updateblocks();
}

void Term_Borad::updateblocks()
{
    //按类型筛选
    if(!issearch)
    {
        for(int i=0;i<bl_num;i++)
        {
            if(typeb==ALL_SHOW)//填入类型判断
                m_blocks[i].block_isVisible=true;
            else if(typeb==m_blocks[i].block_type)
                m_blocks[i].block_isVisible=true;
            else
                m_blocks[i].block_isVisible=false;
        }
    }
    //按名称筛选
    else
    {
        //cout<<"doing";
        for(int i=0;i<bl_num;i++)
        {
            m_blocks[i].block_isVisible=false;
        }
        QString judgename=SEARCH_BLOCK;

        bool test_is_contain;
        for(int i=0;!QString(allname[i]).isNull();i++)
        {
            test_is_contain=allname[i].contains(searchword,Qt::CaseInsensitive);
            if(test_is_contain)
            {
                //cout<<allname[i]<<"包括"<<searchword;
                for(int j=0;j<bl_num;j++)
                {

                    QString x=switch_num_to_name(m_blocks[j].block_name);
                    QString y=judgename.arg(allname[i]);
                    //cout<<x<<"等于";
                    //cout<<y;
                    if(x==y)
                    {
                        m_blocks[j].block_isVisible=true;
                    }
                }
            }
        }
    }
    //坐标
    int k=0;
    for(int i=0;i<12;i++)
    {
        for(int j=0;j<25;j++)
        {
            while(!m_blocks[k].block_isVisible)
            {
                k++;
                if(k>=bl_num)
                    return;
            }
            m_blocks[k].block_x=j*40;
            m_blocks[k].block_y=i*40+40;
            k++;
        }
    }
}

void Term_Borad::on_pushButton_4_clicked()
{
    emit back_to_editor();
}
void Term_Borad::on_pushButton_3_clicked()
{
    typeb++;
    typeb%=5;
    updateblocks();

}
void Term_Borad::mousePressEvent(QMouseEvent *event)//用于快速选择方块种类
{

    int i=event->x();
    int j=event->y();
    cout<<i<<"and"<<j<<"按下";
    //选择方块种类
    if(i>0&&i<1000&&j>40&&j<=520)
    {
       for(int k=0;k<bl_num;k++)
       {
           if(m_blocks[k].block_isVisible)
           {
               int xm=i/40;
               int xb=m_blocks[k].block_x/40;
               if(xm==xb)
               {
                   int ym=j/40;
                   int yb=m_blocks[k].block_y/40;
                   if(ym==yb)
                   {
                       //改变现在选择的方块（暂时不会写）
                       emittype=m_blocks[k].block_type;
                       emitname=m_blocks[k].block_name;
                       emit have_chosen();
                   }
               }
           }
       }
    }


}
void Term_Borad::iniallname()
{

    allname[0]="BABA";
    allname[1]="FLAG";
    allname[2]="KEKE";
    allname[3]="CRAB";
    allname[4]="ROCK";
    allname[5]="WALL";
    allname[6]="WATER";
    allname[7]="LAVA";
    allname[8]="SKULL";
    allname[9]="GRASS";
    allname[10]="JELLY";
    allname[11]="STAR";
    allname[12]="ALGAE";
    allname[13]="LOVE";
    allname[14]="PILLAR";
    allname[15]="DOOR";
    allname[16]="KEY";
    allname[17]="HEDGE";
    allname[18]="COG";
    allname[19]="TEXT";
    allname[20]="MELT";
    allname[21]="YOU";
    allname[22]="STOP";
    allname[23]="WIN";
    allname[24]="PUSH";
    allname[25]="DEFEAT";
    allname[26]="SINK";
    allname[27]="MOVE";
    allname[28]="SHUT";
    allname[29]="OPEN";
    allname[30]="FLOAT";
    allname[31]="HOT";
    allname[32]="IS";
    allname[33]="AND";
}

QString Term_Borad::switch_num_to_name(int a)
{
    switch (a) {
    case 0:
        return "NAME_BABA";


case 1:
        return  "NAME_FLAG";
case 2:
        return  "NAME_KEKE";
case 3:
        return  "NAME_CRAB";
case 4:
        return  "NAME_ROCK";
case 5:
                return  "NAME_WALL";
case 6:
        return  "NAME_WATER";

case 7:
        return 	"NAME_LAVA";
case 8:
        return 	"NAME_SKULL";
case 9:
            return 	"NAME_GRASS";
case 10:
        return 	"NAME_JELLY";
case 11:
        return 	"NAME_STAR";
case 12:
        return 	"NAME_ALGAE";
case 13:
        return 	"NAME_LOVE";
case 14:
        return 	"NAME_PILLAR";
case 15:
        return 	"NAME_DOOR";
case 16:
        return 	"NAME_KEY";
case 17:
        return 	"NAME_HEDGE";
case 18:
        return 	"NAME_COG";

case 19:
        return 	"NAME_TEXT";
//ADJ
case 20:
        return 	"NAME_MELT";
case 21:
        return  "NAME_YOU";
case 22:
        return  "NAME_STOP";
case 23:
        return  "NAME_WIN";
case 24:
        return  "NAME_PUSH";
case 25:
        return  "NAME_DEFEAT";
case 26:
        return  "NAME_SINK";
case 27:
        return 	"NAME_MOVE";
case 28:
        return 	"NAME_SHUT";
case 29:
        return 	"NAME_OPEN";
case 30:
        return 	"NAME_FLOAT";
    case 31:
        return "NAME_IS";
    case 32:
        return "NAME_AND";
    default:
        break;
    }
}
void Term_Borad::on_pushButton_clicked()//搜索
{


    tsearch.show();
}
void Term_Borad::on_pushButton_2_clicked()//移除搜索词
{
    issearch=false;

    //cout<<"youzuo";
    updateblocks();
}
