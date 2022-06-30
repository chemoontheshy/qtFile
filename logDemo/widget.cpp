#include "widget.h"
#include "ui_widget.h"
#include "QListWidgetItem"
#include <QThread>
#include <QThreadPool>
#include <QDebug>
#include "vsingleton.h"
#include "loopwhat.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    num=0;
    ui->setupUi(this);
    //自动颜色
    ui->listWidget->setAlternatingRowColors(true);
    ui->listWidget->setStyleSheet("QListWidget{alternate-background-color: rgb(231, 231, 0);}" //黄白相间的颜色
                                        "QListWidget::Item:hover{background:skyblue;}"               //鼠标悬浮天蓝色
                                        "QListWidget::item:selected{background:pink; color:red; }"   //选中时粉红色,字体大红色
                                       );

    //默认情况下，当可运行对象结束时，线程池会自动将其删除，这也正是我们想要的效果。
    //在某些情况下，如果必须由我们自己负责删除可运行的对象时，可以通过调用 QRunnable::setAutoDelete(false) 来阻止自动删除的发生。
    auto loopPtr = new loopWhat();
    QThreadPool::globalInstance()->start(loopPtr);
    doWhat();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::doWhat()
{
    for(int i = 0; i <= 50; i++)
    {

        QString logInfo = "Log item "+QString::number(i);
        addLog (logInfo);
    }
    auto temp = hskj::tool::Singleton<hskj::tool::Print>::instance();
    temp->puPrint();
    temp->setPrint("We");
    auto temp2 = hskj::tool::Singleton<hskj::tool::Print>::instance();
    temp2->puPrint();
    auto temp3 = hskj::tool::Singleton<hskj::tool::Print>::instance();
    temp3->puPrint();
}

void Widget::addLog(const QString &logText)
{
    QListWidgetItem* pItem = new QListWidgetItem(logText);
    ///正常不变色，错误红色
    //pItem->setForeground(QBrush(type == 1 ? QColor(255,0,0) : QColor(0,0,0)));
    ui->listWidget->addItem(pItem);
    //最大显示数量
    if(ui->listWidget->count() > 40)
    {
        QListWidgetItem* pTempItem = ui->listWidget->takeItem(0);
        delete pTempItem;
        pTempItem = NULL;
    }
}

void Widget::on_pushButton_clicked()
{
    auto logText = ui->lineEdit->text();
    if(logText.size()!=0)
    {
        addLog(logText);
        ui->lineEdit->clear();
    }
    else
    {
        std::cout<<"input is empty"<<std::endl;
    }

}
