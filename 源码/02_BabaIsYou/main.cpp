#include "guide_scene.h"
#include "setting_scene.h"
#include "game_scene.h"
#include "pause_scene.h"
#include "change_scene.h"
#include "config.h"

#include <QFile>


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //加载QSS文件
    QFile file(QSS_PATH_1);
    file.open(QFile::ReadOnly);
    QTextStream fileText(&file);
    QString stylesheet = fileText.readAll();
    qApp->setStyleSheet(stylesheet);


    Guide_Scene w;
    w.show();

    return a.exec();
}
