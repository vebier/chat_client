#include "include/httpmgr.h"

HttpMgr::~HttpMgr()
{

}

HttpMgr::HttpMgr()
{
    connect(this,&HttpMgr::singal_http_finish,this,&HttpMgr::slot_http_finish);
}

void HttpMgr::PostHttpReq(QUrl url, QJsonObject json, ReqId id, Modules modules)
{
    auto data=QJsonDocument(json).toJson();
    QNetworkRequest req(url);
    req.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    req.setHeader(QNetworkRequest::ContentLengthHeader, QVariant(data.length()));
    auto self=shared_from_this();
    QNetworkReply * reply=_manager.post(req,data);
    connect(reply,&QNetworkReply::finished,[self,&reply,&id,&modules](){
        if(reply->error()!=QNetworkReply::NoError){
            qDebug()<<reply->errorString();
            emit self->singal_http_finish(id,"",ErrorCodes::ERR_NETWORK,modules);
        }

        auto res=reply->readAll();
        emit self->singal_http_finish(id,res,ErrorCodes::SUCCESS,modules);
        reply->deleteLater();
        return;
    });
}

void HttpMgr::slot_http_finish(ReqId id, QByteArray res, ErrorCodes code , Modules mod)
{
    if(mod==Modules::REGISTERMOD){
        emit sig_reg_mod_finish(id,res,code);
    }
}
