#include "include/register_dialog.h"
#include "ui_register_dialog.h"
#include "include/global.h"
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

