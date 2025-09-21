#ifndef REGISTER_DIALOG_H
#define REGISTER_DIALOG_H

#include "include/global.h"
#include <QDialog>
namespace Ui {
class register_Dialog;
}

class register_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit register_Dialog(QWidget *parent = nullptr);
    ~register_Dialog();

signals:
    void signal_close_dialog();

private slots:
    void on_get_code_clicked();
    void slot_reg_mod_finish(ReqId,QString,ErrorCodes);
    void on_cancel_btn_clicked();

private:
    void InitHttpHandlers();
    void showTip(QString str,bool flag);
    Ui::register_Dialog *ui;
    QMap<ReqId,std::function<void(const QJsonObject&&)>> _handlers;
};

#endif // REGISTER_DIALOG_H
