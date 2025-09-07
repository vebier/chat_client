#include "include/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _login(new login_Dialog(this))
    , _register(new register_Dialog(this))
{
    ui->setupUi(this);
    setCentralWidget(_login);
    connect(_login,&login_Dialog::switchRegister,this,&MainWindow::RegisterShow);
    _login->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    _register->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::RegisterShow()
{
    setCentralWidget(_register);
    _register->show();
}
