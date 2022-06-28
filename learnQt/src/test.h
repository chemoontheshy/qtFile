#ifndef TEST_H
#define TEST_H

#include "singleton.h"
#include <QObject>

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = 0);
    void init();
private slots:
    void Hello();
private:
    int m_iCount;


};

typedef QSingleTon<Test> test;

#endif // TEST_H
