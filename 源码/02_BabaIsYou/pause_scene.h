#ifndef PAUSE_SCENE_H
#define PAUSE_SCENE_H

#include "config.h"
#include "change_scene.h"

#include <QWidget>
#include <QPalette>

namespace Ui {
class Pause_Scene;
}

class Pause_Scene : public QWidget
{
    Q_OBJECT
//函数
public:
    explicit Pause_Scene(QWidget *parent = 0);
    ~Pause_Scene();

    void iniName();

    void quickRestart();

//对象
public:
    //切换界面
    Change_Scene sce_change;
    //向上返回标记
    int mark;
    //当前名
    QString nowName;
    //返回窗口类型
    int returnType;
private:
    Ui::Pause_Scene *ui;

//信号
signals:
    void gameToChoose_signal();
    void exitToGame_signal();
    void gameToGuide_signal();
    void restart_signal();
    void testLevelToEdit_signal();

private slots:
    void on_b2_exitToChoose_released();
    void on_b1_start_released();
    void on_b5_exitToGuide_released();
    void on_b3_reStart_released();
};

#endif // PAUSE_SCENE_H
