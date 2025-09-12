#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "include/login_dialog.h"
#include "include/register_dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void RegisterShow();
    void RegisterClose();
private:
    Ui::MainWindow *ui;
    login_Dialog* _login;
    register_Dialog* _register;
};
#endif // MAINWINDOW_H
