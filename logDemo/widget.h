#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QString>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

private:
    ///测试函数
    void doWhat();

    void addLog(const QString& logText);

private:
    Ui::Widget *ui;
    int num;
};

#endif // WIDGET_H
