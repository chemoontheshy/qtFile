#include "test.h"
#include <QDebug>
#include <QTimer>
#include <QFile>

Test::Test(QObject *parent) :
    QObject(parent)
{
   m_iCount=0;
}

void Test::init()
{
    qDebug()<<"qt test";
    Hello();
    qDebug()<<"end test";
}

void Test::Hello()
{
    qDebug()<<"rer";
   // qDebug()<<"count "<<QString::number(m_iCount++);
   //    QFile file(("test.log"));
   //    if(file.open(QIODevice::WriteOnly|QIODevice::Append|QIODevice::Text))
   //    {
   //        file.write("tete");
   //        file.write("\n");
   //    }
    QTimer::singleShot(1000,this,SLOT(Hello()));
}
