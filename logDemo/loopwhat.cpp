#include "loopwhat.h"
#include <QDebug>
#include <QThread>

loopWhat::loopWhat():
    m_iCount(0)
{

}

void loopWhat::run()
{
    while (m_iCount<100) {
         qDebug()<<QString::number(m_iCount++);
         QThread::msleep(1000);
    }
    qDebug()<<"end!";

}
