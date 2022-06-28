#ifndef SINGLETON_H
#define SINGLETON_H

#include <QAtomicPointer>
#include <stdlib.h>
#include <QMutex>
#include <memory>

using namespace std;

template <class T>
class QSingleTon
{
public:
    static T* instance()
    {
#ifdef Q_ATOMIC_POINTER_TEST_AND_SET_IS_ALWAYS_NATIVE
        if(!QAtomicPointer<T>::isTestAndSetNative()) //运行时间检测
#endif
        {
            QMutexLocker locker(&m_pMutex);
            if(m_pInstance.testAndSetOrdered(0,0)) // 第一次检查
            {
                m_pInstance.testAndSetOrdered(0,new T()); // 第二此检测
                atexit(deinstance);
            }

        }
        return m_pInstance;
    }
    static void deinstance()
    {
        QMutexLocker locker(&m_pMutex);
        if(m_pInstance != NULL)
        {
            delete m_pInstance;
            m_pInstance = NULL;
        }
    }

private:
    QSingleTon(){}
    QSingleTon(const QSingleTon&);
    QSingleTon& operator = (const QSingleTon&);

private:
    static QMutex m_pMutex;
    static QAtomicPointer<T> m_pInstance;
};

template <class T> QMutex QSingleTon<T>::m_pMutex;
template <class T> QAtomicPointer<T> QSingleTon<T>::m_pInstance = NULL;

#endif // SINGLETON_H
