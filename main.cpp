#include "include/mainwindow.h"
#include <QApplication>
#include "include/global.h"

int main(int argc, char *argv[])
{
    try{
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

    // 获取当前应用程序的路径
    QString app_path = QCoreApplication::applicationDirPath();
    // 拼接文件名
    QString fileName = "config.ini";
    QString config_path = QDir::toNativeSeparators(app_path +
                                                   QDir::separator() + fileName);

    QSettings settings(config_path, QSettings::IniFormat);
    QString gate_host = settings.value("GateServer/host").toString();
    QString gate_port = settings.value("GateServer/port").toString();
    gate_url_prefix = "http://"+gate_host+":"+gate_port;

    w.show();
    return a.exec();
    }catch(const std::exception& ec){
        qDebug()<<"error "<<ec.what();
    }
}
