#ifndef SETTING_SCENE_H
#define SETTING_SCENE_H

#include "config.h"
#include "block.h"

#include <QWidget>
#include <QPalette>
#include <QTimer>
#include <QPainter>
#include <QPixmap>

namespace Ui {
class Setting_Scene;
}

class Setting_Scene : public QWidget
{
    Q_OBJECT

//对象
public:
    Block showObject;

    //计时器对象*
    QTimer m_timer;

    bool openAni;

    bool shakeWin;

    QPixmap back;

//函数
public:
    explicit Setting_Scene(QWidget *parent = 0);
    ~Setting_Scene();

    //绘图事件*
    void paintEvent(QPaintEvent *event);
    //刷新
    void playAni();

signals:
    void openAniChange_signal();
    void shakeWin_signal();
    void eVolumeChange(int value);
    void mVolumeChange(int value);

private slots:
    void on_b6_exit_released();

    void on_b2_animation_released();


    void on_b3_shake_released();

    void on_s1_dffectVolum_sliderReleased();

    void on_s2_musicVolum_sliderReleased();

private:
    Ui::Setting_Scene *ui;
};

#endif // SETTING_SCENE_H
