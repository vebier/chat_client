#include "include/login_dialog.h"
#include "ui_login_dialog.h"

login_Dialog::login_Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::login_Dialog)
{
    ui->setupUi(this);
    connect(ui->register_btn,&QPushButton::clicked,this,[this](){emit switchRegister();});
}

login_Dialog::~login_Dialog()
{
    delete ui;
}
