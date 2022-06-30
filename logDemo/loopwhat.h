#ifndef LOOPWHAT_H
#define LOOPWHAT_H
#include <QRunnable>

class loopWhat : public QRunnable
{
public:
    loopWhat();
protected:
    void run();
private:
    int m_iCount;
};

#endif // LOOPWHAT_H
