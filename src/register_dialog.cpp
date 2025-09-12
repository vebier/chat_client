#include "include/register_dialog.h"
#include "ui_register_dialog.h"
#include "include/httpmgr.h"
#include <QRegularExpression>


register_Dialog::register_Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::register_Dialog)
{
    ui->setupUi(this);
    ui->pass_edit->setEchoMode(QLineEdit::Password);
    ui->confirm_edit->setEchoMode(QLineEdit::Password);
    ui->err_tip->setProperty("state","normal");
    repolish(ui->err_tip);

    connect(HttpMgr::GetInstance().get(),&HttpMgr::sig_reg_mod_finish,this,&register_Dialog::slot_reg_mod_finish);
}

register_Dialog::~register_Dialog()
{
    delete ui;
}

void register_Dialog::on_get_code_clicked()
{
    auto email=ui->email_edit->text();
    QRegularExpression regex(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
    if(regex.match(email).hasMatch()){
        //发送http请求获取验证码
        showTip(tr("验证码已发送，请查收"),true);
    }else{
        showTip(tr("邮箱地址不正确"),false);
    }
}

void register_Dialog::slot_reg_mod_finish(ReqId id, QByteArray res, ErrorCodes code)
{
    if(code!=ErrorCodes::SUCCESS){
        showTip(tr("网络错误"),false);
        qDebug()<<"网络请求错误";
        return;
    }

    QJsonDocument jsonDoc = QJsonDocument::fromJson(res);
    if(jsonDoc.isNull()){
        showTip(tr("JSON错误"),false);
        qDebug()<<"反序列化QJsonDocument失败";
        return;
    }

    if(!jsonDoc.isObject()){
        showTip(tr("JSON错误"),false);
        qDebug()<<"反序列化QJsonObject失败";
        return;
    }

    QJsonObject jsonObj = jsonDoc.object();
    _handlers[id](std::move(jsonObj));
    return;
}

void register_Dialog::InitHttpHandlers()
{
    _handlers[ReqId::ID_GET_VARIFY_CODE]=[this](const QJsonObject&& JsonObject){
        auto error=JsonObject["error"].toInt();
        if(error!=static_cast<int>(ErrorCodes::SUCCESS)){
            showTip(tr("参数错误"),false);
            qDebug()<<"获取验证码不成功";
            return;
        }
        auto verifyCode=JsonObject["verifyCode"].toString();
        showTip(tr("验证码已发送，请查收"),true);
        qDebug()<<"验证码 ： "<<verifyCode;
        return;
    };
}

void register_Dialog::showTip(QString str,bool flag)
{
    if(flag){
        ui->err_tip->setProperty("state","normal");
    }else{
        ui->err_tip->setProperty("state","err");
    }
    ui->err_tip->setText(str);
    repolish(ui->err_tip);
}


void register_Dialog::on_cancel_btn_clicked()
{
    emit signal_close_dialog();
}

