/********************************************************************************
** Form generated from reading UI file 'registerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterDialog
{
public:
    QWidget *widget;
    QFormLayout *formLayout_2;
    QFormLayout *formLayout;
    QLineEdit *line_account;
    QSpacerItem *horizontalSpacer;
    QLabel *label_9;
    QLineEdit *line_psw;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_10;
    QLineEdit *line_psw2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_7;
    QLineEdit *line_question;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_8;
    QLineEdit *line_answer;
    QLabel *label_6;
    QPushButton *btn_ok;
    QPushButton *btn_cancel;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QWidget *RegisterDialog)
    {
        if (RegisterDialog->objectName().isEmpty())
            RegisterDialog->setObjectName(QStringLiteral("RegisterDialog"));
        RegisterDialog->resize(603, 479);
        widget = new QWidget(RegisterDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(80, 30, 481, 406));
        widget->setMinimumSize(QSize(200, 50));
        formLayout_2 = new QFormLayout(widget);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        line_account = new QLineEdit(widget);
        line_account->setObjectName(QStringLiteral("line_account"));
        line_account->setMinimumSize(QSize(200, 40));
        line_account->setMaximumSize(QSize(160, 40));
        QFont font;
        font.setPointSize(12);
        line_account->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, line_account);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(1, QFormLayout::FieldRole, horizontalSpacer);

        label_9 = new QLabel(widget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(200, 40));
        label_9->setMaximumSize(QSize(100, 40));
        QFont font1;
        font1.setPointSize(14);
        label_9->setFont(font1);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_9);

        line_psw = new QLineEdit(widget);
        line_psw->setObjectName(QStringLiteral("line_psw"));
        line_psw->setMinimumSize(QSize(200, 40));
        line_psw->setMaximumSize(QSize(160, 40));
        line_psw->setFont(font);

        formLayout->setWidget(3, QFormLayout::FieldRole, line_psw);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(4, QFormLayout::FieldRole, horizontalSpacer_4);

        label_10 = new QLabel(widget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(200, 40));
        label_10->setMaximumSize(QSize(100, 40));
        label_10->setFont(font1);

        formLayout->setWidget(5, QFormLayout::LabelRole, label_10);

        line_psw2 = new QLineEdit(widget);
        line_psw2->setObjectName(QStringLiteral("line_psw2"));
        line_psw2->setMinimumSize(QSize(200, 40));
        line_psw2->setMaximumSize(QSize(160, 40));
        line_psw2->setFont(font);

        formLayout->setWidget(5, QFormLayout::FieldRole, line_psw2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(6, QFormLayout::FieldRole, horizontalSpacer_3);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(200, 40));
        label_7->setMaximumSize(QSize(100, 40));
        label_7->setFont(font1);

        formLayout->setWidget(7, QFormLayout::LabelRole, label_7);

        line_question = new QLineEdit(widget);
        line_question->setObjectName(QStringLiteral("line_question"));
        line_question->setMinimumSize(QSize(200, 40));
        line_question->setMaximumSize(QSize(160, 40));
        line_question->setFont(font);

        formLayout->setWidget(7, QFormLayout::FieldRole, line_question);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(8, QFormLayout::FieldRole, horizontalSpacer_2);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(200, 40));
        label_8->setMaximumSize(QSize(100, 40));
        label_8->setFont(font1);

        formLayout->setWidget(9, QFormLayout::LabelRole, label_8);

        line_answer = new QLineEdit(widget);
        line_answer->setObjectName(QStringLiteral("line_answer"));
        line_answer->setMinimumSize(QSize(200, 40));
        line_answer->setMaximumSize(QSize(160, 40));
        line_answer->setFont(font);

        formLayout->setWidget(9, QFormLayout::FieldRole, line_answer);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(200, 40));
        label_6->setMaximumSize(QSize(100, 40));
        label_6->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_6);


        formLayout_2->setLayout(0, QFormLayout::SpanningRole, formLayout);

        btn_ok = new QPushButton(widget);
        btn_ok->setObjectName(QStringLiteral("btn_ok"));
        btn_ok->setMinimumSize(QSize(200, 50));
        btn_ok->setMaximumSize(QSize(160, 30));
        btn_ok->setFont(font1);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, btn_ok);

        btn_cancel = new QPushButton(widget);
        btn_cancel->setObjectName(QStringLiteral("btn_cancel"));
        btn_cancel->setMinimumSize(QSize(200, 50));
        btn_cancel->setMaximumSize(QSize(160, 30));
        btn_cancel->setFont(font1);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, btn_cancel);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout_2->setItem(1, QFormLayout::LabelRole, horizontalSpacer_5);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout_2->setItem(1, QFormLayout::FieldRole, horizontalSpacer_6);


        retranslateUi(RegisterDialog);

        QMetaObject::connectSlotsByName(RegisterDialog);
    } // setupUi

    void retranslateUi(QWidget *RegisterDialog)
    {
        RegisterDialog->setWindowTitle(QApplication::translate("RegisterDialog", "Form", Q_NULLPTR));
        label_9->setText(QApplication::translate("RegisterDialog", "\345\257\206\347\240\201", Q_NULLPTR));
        line_psw->setText(QString());
        label_10->setText(QApplication::translate("RegisterDialog", "\345\206\215\346\254\241\347\241\256\350\256\244\345\257\206\347\240\201", Q_NULLPTR));
        label_7->setText(QApplication::translate("RegisterDialog", "\345\257\206\344\277\235\351\227\256\351\242\230", Q_NULLPTR));
        label_8->setText(QApplication::translate("RegisterDialog", "\347\255\224\346\241\210", Q_NULLPTR));
        label_6->setText(QApplication::translate("RegisterDialog", "\350\264\246\345\217\267", Q_NULLPTR));
        btn_ok->setText(QApplication::translate("RegisterDialog", "\347\241\256\350\256\244", Q_NULLPTR));
        btn_cancel->setText(QApplication::translate("RegisterDialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RegisterDialog: public Ui_RegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
