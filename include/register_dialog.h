#ifndef REGISTER_DIALOG_H
#define REGISTER_DIALOG_H

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

private slots:
    void on_get_code_clicked();

private:
    void showTip(QString str,bool flag);
    Ui::register_Dialog *ui;
};

#endif // REGISTER_DIALOG_H
