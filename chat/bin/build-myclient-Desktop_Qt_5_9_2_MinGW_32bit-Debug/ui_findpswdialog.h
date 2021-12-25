/********************************************************************************
** Form generated from reading UI file 'findpswdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDPSWDIALOG_H
#define UI_FINDPSWDIALOG_H

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

class Ui_findpswDialog
{
public:
    QWidget *layoutWidget;
    QFormLayout *formLayout_2;
    QPushButton *btn_ok;
    QPushButton *btn_cancel;
    QWidget *layoutWidget1;
    QFormLayout *formLayout;
    QLineEdit *line_account;
    QSpacerItem *horizontalSpacer;
    QLabel *label_4;
    QLineEdit *line_question;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_5;
    QLineEdit *line_answer;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QLineEdit *line_psw;
    QLabel *label;

    void setupUi(QWidget *findpswDialog)
    {
        if (findpswDialog->objectName().isEmpty())
            findpswDialog->setObjectName(QStringLiteral("findpswDialog"));
        findpswDialog->resize(537, 401);
        layoutWidget = new QWidget(findpswDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(140, 320, 286, 66));
        layoutWidget->setMinimumSize(QSize(140, 40));
        formLayout_2 = new QFormLayout(layoutWidget);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setHorizontalSpacing(4);
        formLayout_2->setVerticalSpacing(0);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        btn_ok = new QPushButton(layoutWidget);
        btn_ok->setObjectName(QStringLiteral("btn_ok"));
        btn_ok->setMinimumSize(QSize(140, 40));
        btn_ok->setMaximumSize(QSize(80, 30));
        QFont font;
        font.setPointSize(14);
        btn_ok->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, btn_ok);

        btn_cancel = new QPushButton(layoutWidget);
        btn_cancel->setObjectName(QStringLiteral("btn_cancel"));
        btn_cancel->setMinimumSize(QSize(140, 40));
        btn_cancel->setMaximumSize(QSize(80, 30));
        btn_cancel->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, btn_cancel);

        layoutWidget1 = new QWidget(findpswDialog);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(100, 30, 371, 281));
        layoutWidget1->setMinimumSize(QSize(180, 0));
        formLayout = new QFormLayout(layoutWidget1);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        line_account = new QLineEdit(layoutWidget1);
        line_account->setObjectName(QStringLiteral("line_account"));
        line_account->setMinimumSize(QSize(160, 40));
        line_account->setMaximumSize(QSize(160, 40));
        QFont font1;
        font1.setPointSize(12);
        line_account->setFont(font1);

        formLayout->setWidget(0, QFormLayout::FieldRole, line_account);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(1, QFormLayout::FieldRole, horizontalSpacer);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(180, 40));
        label_4->setMaximumSize(QSize(100, 40));
        label_4->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        line_question = new QLineEdit(layoutWidget1);
        line_question->setObjectName(QStringLiteral("line_question"));
        line_question->setMinimumSize(QSize(160, 40));
        line_question->setMaximumSize(QSize(160, 40));
        line_question->setFont(font1);

        formLayout->setWidget(2, QFormLayout::FieldRole, line_question);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(3, QFormLayout::FieldRole, horizontalSpacer_2);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(180, 40));
        label_5->setMaximumSize(QSize(100, 40));
        label_5->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        line_answer = new QLineEdit(layoutWidget1);
        line_answer->setObjectName(QStringLiteral("line_answer"));
        line_answer->setMinimumSize(QSize(160, 40));
        line_answer->setMaximumSize(QSize(160, 40));
        line_answer->setFont(font1);

        formLayout->setWidget(4, QFormLayout::FieldRole, line_answer);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(5, QFormLayout::FieldRole, horizontalSpacer_3);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(180, 40));
        label_2->setMaximumSize(QSize(100, 40));
        label_2->setFont(font);

        formLayout->setWidget(6, QFormLayout::LabelRole, label_2);

        line_psw = new QLineEdit(layoutWidget1);
        line_psw->setObjectName(QStringLiteral("line_psw"));
        line_psw->setMinimumSize(QSize(160, 40));
        line_psw->setMaximumSize(QSize(160, 40));
        line_psw->setFont(font1);

        formLayout->setWidget(6, QFormLayout::FieldRole, line_psw);

        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(180, 40));
        label->setMaximumSize(QSize(100, 40));
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);


        retranslateUi(findpswDialog);

        QMetaObject::connectSlotsByName(findpswDialog);
    } // setupUi

    void retranslateUi(QWidget *findpswDialog)
    {
        findpswDialog->setWindowTitle(QApplication::translate("findpswDialog", "Form", Q_NULLPTR));
        btn_ok->setText(QApplication::translate("findpswDialog", "\347\241\256\350\256\244", Q_NULLPTR));
        btn_cancel->setText(QApplication::translate("findpswDialog", "\345\217\226\346\266\210", Q_NULLPTR));
        label_4->setText(QApplication::translate("findpswDialog", "\345\257\206\344\277\235\351\227\256\351\242\230", Q_NULLPTR));
        label_5->setText(QApplication::translate("findpswDialog", "\347\255\224\346\241\210", Q_NULLPTR));
        label_2->setText(QApplication::translate("findpswDialog", "\350\257\267\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201", Q_NULLPTR));
        line_psw->setText(QString());
        label->setText(QApplication::translate("findpswDialog", "\350\264\246\345\217\267", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class findpswDialog: public Ui_findpswDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDPSWDIALOG_H
