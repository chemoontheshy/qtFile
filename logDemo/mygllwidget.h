#ifndef MYGLLWIDGET_H
#define MYGLLWIDGET_H
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_2_Core>

class MyGLlWidget : public QOpenGLWidget,protected Qop
{
public:
    MyGLlWidget();
};

#endif // MYGLLWIDGET_H
