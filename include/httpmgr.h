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
    void PostHttpReq(QUrl url,QJsonObject json,ReqId id,Modules modules);
private:
    HttpMgr();
public slots:
    void slot_http_finish(ReqId,QString ,ErrorCodes,Modules);
signals:
    void singal_http_finish(ReqId,QString ,ErrorCodes,Modules);
    void sig_reg_mod_finish(ReqId,QString ,ErrorCodes);
private:
    QNetworkAccessManager _manager;
};

#endif // HTTPMGR_H
