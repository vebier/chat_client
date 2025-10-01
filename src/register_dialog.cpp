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
    InitHttpHandlers();
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
        QJsonObject json_obj;
        json_obj["email"] = email;
        HttpMgr::GetInstance()->PostHttpReq(QUrl(gate_url_prefix+"/get_varifycode"),json_obj,ReqId::ID_GET_VARIFY_CODE,Modules::REGISTERMOD);
        showTip(tr("验证码已发送，请查收"),true);
    }else{
        showTip(tr("邮箱地址不正确"),false);
    }
}

void register_Dialog::slot_reg_mod_finish(ReqId id, QString res, ErrorCodes code)
{
    if(code!=ErrorCodes::SUCCESS){
        showTip(tr("网络错误"),false);
        qDebug()<<"网络请求错误"<<static_cast<int>(code);
        return;
    }
    //打印json字符串
    //qDebug() << "Raw response:" << res;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(res.toUtf8());
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
    _handlers[ReqId::ID_GET_VARIFY_CODE]=[this](QJsonObject&& JsonObject){
        auto error=JsonObject["code"].toInt();
        if(error!=static_cast<int>(ErrorCodes::SUCCESS)){
            showTip(tr("参数错误"),false);
            qDebug()<<"获取验证码不成功";
            return;
        }
        auto email=JsonObject["email"].toString();
        showTip(tr("验证码已发送，请查收"),true);
        qDebug()<<"验证码发送邮箱 : "<<email;

        // auto verifyCode=JsonObject["verifyCode"].toString();
        // showTip(tr("验证码已发送，请查收"),true);
        // qDebug()<<"验证码 ： "<<verifyCode;
        return;
    };

    _handlers[ReqId::ID_REG_USER]=[this](QJsonObject&& JsonObject){
        auto error=JsonObject["code"].toInt();
        //qDebug()<<"error"<<error;
        if(error!=static_cast<int>(ErrorCodes::SUCCESS)){
            showTip(tr("参数错误"),false);
            qDebug()<<"注册用户失败,失败原因 : "<<error;
            return;
        }
        auto email = JsonObject["email"].toString();
        showTip(tr("用户注册成功"), true);
        qDebug()<< "注册邮箱 : " << email ;
    };

}

PasswordResult register_Dialog::validatePassword(const std::string &password)
{
    // 规则1：长度至少8位
    if (password.length() < 8) {
        return PasswordResult(false, "密码长度不能少于8位");
    }

    // 规则2：必须包含大写字母
    bool hasUpper = false;
    // 规则3：必须包含小写字母
    bool hasLower = false;
    // 规则4：必须包含数字
    bool hasDigit = false;
    // 规则5：必须包含特殊字符
    bool hasSpecial = false;

    // 常见特殊字符集合
    const std::unordered_set<char> specialChars = {
        '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=',
        '[', ']', '{', '}', '\\', '|', ';', ':', '\'', '"', ',', '.', '<', '>', '/', '?', '~', '`'
    };

    for (char c : password) {
        if (std::isupper(c)) hasUpper = true;
        else if (std::islower(c)) hasLower = true;
        else if (std::isdigit(c)) hasDigit = true;
        else if (specialChars.find(c) != specialChars.end()) hasSpecial = true;
        // 如果所有条件都满足，提前退出
        if (hasUpper && hasLower && hasDigit && hasSpecial) break;
    }

    if (!hasUpper) {
        return PasswordResult(false, "密码必须包含至少一个大写字母（A-Z）");
    }
    if (!hasLower) {
        return PasswordResult(false, "密码必须包含至少一个小写字母（a-z）");
    }
    if (!hasDigit) {
        return PasswordResult(false, "密码必须包含至少一个数字（0-9）");
    }
    if (!hasSpecial) {
        return PasswordResult(false, "密码必须包含至少一个特殊字符（如 !@#$%^&* 等）");
    }

    return PasswordResult(true, "密码符合要求");
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


void register_Dialog::on_confirm_btn_clicked()
{
    if(ui->user_edit->text()==""){
        showTip(tr("用户名为空"),false);
        return;
    }

    QRegularExpression regex(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
    if(!regex.match(ui->email_edit->text()).hasMatch()){
        showTip(tr("邮箱地址不正确"),false);
        return;
    }

    // auto res=validatePassword(ui->pass_edit->text().toStdString());
    // if(!res.valid){
    //     showTip(tr(res.message.c_str()),false);
    //     return;
    // }

    if(ui->confirm_edit->text()!=ui->pass_edit->text()){
        showTip(tr("两次密码输入不一样"),false);
        return;
    }

    if(ui->verification_edit->text()==""){
        showTip(tr("验证码为空"),false);
        return;
    }

    QJsonObject json_obj;
    json_obj["user"]=ui->user_edit->text();
    json_obj["email"]=ui->email_edit->text();
    json_obj["pass"]=ui->pass_edit->text();
    json_obj["confirm"]=ui->confirm_edit->text();
    json_obj["verification"]=ui->verification_edit->text();

    HttpMgr::GetInstance()->PostHttpReq(QUrl(gate_url_prefix+"/user_register"),json_obj,ReqId::ID_REG_USER,Modules::REGISTERMOD);
}

