/********************************************************************************
** Form generated from reading UI file 'login_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_DIALOG_H
#define UI_LOGIN_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login_Dialog
{
public:
    QGridLayout *gridLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QWidget *widget_3;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QLineEdit *user_edit;
    QLabel *label_2;
    QLineEdit *pass_edit;
    QWidget *widget_4;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer;
    QLabel *label_4;
    QWidget *widget_5;
    QGridLayout *gridLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *login_btn;
    QPushButton *register_btn;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *label;

    void setupUi(QDialog *login_Dialog)
    {
        if (login_Dialog->objectName().isEmpty())
            login_Dialog->setObjectName("login_Dialog");
        login_Dialog->resize(300, 500);
        login_Dialog->setMinimumSize(QSize(300, 500));
        gridLayout = new QGridLayout(login_Dialog);
        gridLayout->setObjectName("gridLayout");
        widget_2 = new QWidget(login_Dialog);
        widget_2->setObjectName("widget_2");
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName("verticalLayout");
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName("widget_3");
        gridLayout_3 = new QGridLayout(widget_3);
        gridLayout_3->setObjectName("gridLayout_3");
        label_3 = new QLabel(widget_3);
        label_3->setObjectName("label_3");

        gridLayout_3->addWidget(label_3, 1, 0, 1, 1);

        user_edit = new QLineEdit(widget_3);
        user_edit->setObjectName("user_edit");

        gridLayout_3->addWidget(user_edit, 0, 1, 1, 1);

        label_2 = new QLabel(widget_3);
        label_2->setObjectName("label_2");

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        pass_edit = new QLineEdit(widget_3);
        pass_edit->setObjectName("pass_edit");

        gridLayout_3->addWidget(pass_edit, 1, 1, 1, 1);

        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName("widget_4");
        gridLayout_4 = new QGridLayout(widget_4);
        gridLayout_4->setObjectName("gridLayout_4");
        horizontalSpacer = new QSpacerItem(142, 3, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 0, 0, 1, 1);

        label_4 = new QLabel(widget_4);
        label_4->setObjectName("label_4");

        gridLayout_4->addWidget(label_4, 0, 1, 1, 1);


        gridLayout_3->addWidget(widget_4, 2, 0, 1, 2);


        verticalLayout->addWidget(widget_3);

        widget_5 = new QWidget(widget_2);
        widget_5->setObjectName("widget_5");
        gridLayout_5 = new QGridLayout(widget_5);
        gridLayout_5->setObjectName("gridLayout_5");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        login_btn = new QPushButton(widget_5);
        login_btn->setObjectName("login_btn");

        gridLayout_5->addWidget(login_btn, 0, 1, 1, 1);

        register_btn = new QPushButton(widget_5);
        register_btn->setObjectName("register_btn");

        gridLayout_5->addWidget(register_btn, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_5->addItem(verticalSpacer, 2, 1, 1, 1);


        verticalLayout->addWidget(widget_5);


        gridLayout->addWidget(widget_2, 1, 0, 1, 1);

        widget = new QWidget(login_Dialog);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 0));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName("gridLayout_2");
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label->setPixmap(QPixmap(QString::fromUtf8(":/resource/OIP.png")));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(login_Dialog);

        QMetaObject::connectSlotsByName(login_Dialog);
    } // setupUi

    void retranslateUi(QDialog *login_Dialog)
    {
        login_Dialog->setWindowTitle(QCoreApplication::translate("login_Dialog", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("login_Dialog", "\345\257\206\347\240\201\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("login_Dialog", "\347\224\250\346\210\267\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("login_Dialog", "\345\277\230\350\256\260\345\257\206\347\240\201", nullptr));
        login_btn->setText(QCoreApplication::translate("login_Dialog", "\347\231\273\345\275\225", nullptr));
        register_btn->setText(QCoreApplication::translate("login_Dialog", "\346\263\250\345\206\214", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class login_Dialog: public Ui_login_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_DIALOG_H
