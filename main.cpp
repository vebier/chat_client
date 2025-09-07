#include "include/mainwindow.h"
#include <QFile>
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QFile qss(":/style/stylesheet.qss");
    if(qss.open(QFile::ReadOnly)){
        qDebug()<<"stylesheet open success !";
        QString style=QLatin1String(qss.readAll());
        w.setStyleSheet(style);
        qss.close();
    }else{
        qDebug()<<"stylesheet open failed !";
    }
    w.show();
    return a.exec();
}
