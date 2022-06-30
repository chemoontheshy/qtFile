#include "widget.h"
#include <QApplication>
#include <QScreen>
#include <QRect>
#include <QList>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //获取显示器的宽高
    QList<QScreen*> lstScreen = QGuiApplication::screens();
    QRect wh = lstScreen.at(0)->geometry();
    int dWidth = wh.width();
    int dHeight = wh.height();
    qDebug()<<"width: "<<dWidth<<" dHeight: "<<dHeight;
    Widget w;
    w.setMinimumSize(wh.width()*0.75,wh.height()*0.75);
    w.setMaximumSize(wh.width(),wh.height());
    w.show();

    return a.exec();
}
