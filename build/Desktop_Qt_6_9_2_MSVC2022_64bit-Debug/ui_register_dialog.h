/********************************************************************************
** Form generated from reading UI file 'register_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_DIALOG_H
#define UI_REGISTER_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_register_Dialog
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QWidget *widget_7;
    QGridLayout *gridLayout_5;
    QLabel *err_tip;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLineEdit *user_edit;
    QLabel *label;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QLineEdit *email_edit;
    QLabel *label_2;
    QWidget *widget_3;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QLineEdit *pass_edit;
    QWidget *widget_4;
    QGridLayout *gridLayout_4;
    QLabel *label_4;
    QLineEdit *confirm_edit;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLineEdit *verification_edit;
    QPushButton *get_code;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *confirm_btn;
    QPushButton *cancel_btn;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *register_Dialog)
    {
        if (register_Dialog->objectName().isEmpty())
            register_Dialog->setObjectName("register_Dialog");
        register_Dialog->resize(300, 500);
        register_Dialog->setMinimumSize(QSize(300, 500));
        verticalLayout = new QVBoxLayout(register_Dialog);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        widget_7 = new QWidget(register_Dialog);
        widget_7->setObjectName("widget_7");
        gridLayout_5 = new QGridLayout(widget_7);
        gridLayout_5->setObjectName("gridLayout_5");
        err_tip = new QLabel(widget_7);
        err_tip->setObjectName("err_tip");
        err_tip->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_5->addWidget(err_tip, 0, 0, 1, 1);


        verticalLayout->addWidget(widget_7);

        widget = new QWidget(register_Dialog);
        widget->setObjectName("widget");
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        user_edit = new QLineEdit(widget);
        user_edit->setObjectName("user_edit");

        gridLayout->addWidget(user_edit, 0, 1, 1, 1);

        label = new QLabel(widget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(register_Dialog);
        widget_2->setObjectName("widget_2");
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        email_edit = new QLineEdit(widget_2);
        email_edit->setObjectName("email_edit");

        gridLayout_2->addWidget(email_edit, 0, 1, 1, 1);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(register_Dialog);
        widget_3->setObjectName("widget_3");
        gridLayout_3 = new QGridLayout(widget_3);
        gridLayout_3->setObjectName("gridLayout_3");
        label_3 = new QLabel(widget_3);
        label_3->setObjectName("label_3");

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        pass_edit = new QLineEdit(widget_3);
        pass_edit->setObjectName("pass_edit");

        gridLayout_3->addWidget(pass_edit, 0, 1, 1, 1);


        verticalLayout->addWidget(widget_3);

        widget_4 = new QWidget(register_Dialog);
        widget_4->setObjectName("widget_4");
        gridLayout_4 = new QGridLayout(widget_4);
        gridLayout_4->setObjectName("gridLayout_4");
        label_4 = new QLabel(widget_4);
        label_4->setObjectName("label_4");

        gridLayout_4->addWidget(label_4, 0, 0, 1, 1);

        confirm_edit = new QLineEdit(widget_4);
        confirm_edit->setObjectName("confirm_edit");

        gridLayout_4->addWidget(confirm_edit, 0, 1, 1, 1);


        verticalLayout->addWidget(widget_4);

        widget_5 = new QWidget(register_Dialog);
        widget_5->setObjectName("widget_5");
        horizontalLayout = new QHBoxLayout(widget_5);
        horizontalLayout->setObjectName("horizontalLayout");
        label_5 = new QLabel(widget_5);
        label_5->setObjectName("label_5");

        horizontalLayout->addWidget(label_5);

        verification_edit = new QLineEdit(widget_5);
        verification_edit->setObjectName("verification_edit");
        verification_edit->setMinimumSize(QSize(50, 0));

        horizontalLayout->addWidget(verification_edit);

        get_code = new QPushButton(widget_5);
        get_code->setObjectName("get_code");

        horizontalLayout->addWidget(get_code);


        verticalLayout->addWidget(widget_5);

        widget_6 = new QWidget(register_Dialog);
        widget_6->setObjectName("widget_6");
        horizontalLayout_2 = new QHBoxLayout(widget_6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        confirm_btn = new QPushButton(widget_6);
        confirm_btn->setObjectName("confirm_btn");

        horizontalLayout_2->addWidget(confirm_btn);

        cancel_btn = new QPushButton(widget_6);
        cancel_btn->setObjectName("cancel_btn");

        horizontalLayout_2->addWidget(cancel_btn);


        verticalLayout->addWidget(widget_6);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(register_Dialog);

        QMetaObject::connectSlotsByName(register_Dialog);
    } // setupUi

    void retranslateUi(QDialog *register_Dialog)
    {
        register_Dialog->setWindowTitle(QCoreApplication::translate("register_Dialog", "Dialog", nullptr));
        err_tip->setText(QCoreApplication::translate("register_Dialog", "\351\224\231\350\257\257\346\217\220\347\244\272", nullptr));
        label->setText(QCoreApplication::translate("register_Dialog", "\347\224\250\346\210\267\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("register_Dialog", "\351\202\256\347\256\261\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("register_Dialog", "\345\257\206\347\240\201\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("register_Dialog", "\347\241\256\350\256\244\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("register_Dialog", "\351\252\214\350\257\201\347\240\201\357\274\232", nullptr));
        get_code->setText(QCoreApplication::translate("register_Dialog", "\350\216\267\345\217\226", nullptr));
        confirm_btn->setText(QCoreApplication::translate("register_Dialog", "\347\241\256\350\256\244", nullptr));
        cancel_btn->setText(QCoreApplication::translate("register_Dialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class register_Dialog: public Ui_register_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_DIALOG_H
