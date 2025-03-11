#ifndef SEARCH_H
#define SEARCH_H

#include"config.h"
#include <QWidget>
#include<QPainter>
#include <QCompleter>
#include <QStringList>
namespace Ui {
class search;
}

class search : public QWidget
{
    Q_OBJECT

public:
    explicit search(QWidget *parent = 0);
    ~search();
    QString stext;
    void paintEvent(QPaintEvent *event);
signals:
    void sback();
    void sok();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::search *ui;
};

#endif // SEARCH_H
