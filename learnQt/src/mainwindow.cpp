#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qfile.h"
#include "qbytearray.h"
#include "qdebug.h"
#include <QDomDocument>
#include <QDomElement>
#include "test.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QByteArray hoshingdir = qgetenv("HOSHINGDIR");
    QFile filePath(tr(hoshingdir)+tr("/config/HS8000Config.xml"));
    if(filePath.exists())
    {
        QDomDocument doc;
        QString errStr;
        int errLine,errCol;
        if(doc.setContent(&filePath,true,&errStr,&errLine,&errCol))
        {
            QDomElement root = doc.documentElement();
            QDomElement DATABASE = root.firstChildElement("DATABASE");
            QDomElement DBNAME = DATABASE.firstChildElement("DBNAME");
            qDebug()<<"filePath exists : "<<DBNAME.attribute("value","");
        }
    }
    else
    {
        qDebug()<<"filePath no exists";
    }
    Test* test = test::instance();
    test->init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }

}
