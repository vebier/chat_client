#ifndef HTTPMGR_H
#define HTTPMGR_H

#include <QUrl>
#include <QString>
#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include "include/global.h"
#include "include/singleton.h"


class HttpMgr : public QObject,public Singleton<HttpMgr>,public std::enable_shared_from_this<HttpMgr>
{
    Q_OBJECT
    friend class Singleton<HttpMgr>;
public:
    ~HttpMgr();
private:
    HttpMgr();
    void PostHttpReq(QUrl url,QJsonObject json,ReqId id,Modules modules);
public slots:
    void slot_http_finish(ReqId,QByteArray,ErrorCodes,Modules);
signals:
    void singal_http_finish(ReqId,QByteArray,ErrorCodes,Modules);
    void sig_reg_mod_finish(ReqId,QByteArray,ErrorCodes);
private:
    QNetworkAccessManager _manager;
};

#endif // HTTPMGR_H
