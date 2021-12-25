/********************************************************************************
** Form generated from reading UI file 'setipdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETIPDIALOG_H
#define UI_SETIPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetIPDialog
{
public:
    QPushButton *pushButton;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_9;
    QLineEdit *lineEdit;

    void setupUi(QWidget *SetIPDialog)
    {
        if (SetIPDialog->objectName().isEmpty())
            SetIPDialog->setObjectName(QStringLiteral("SetIPDialog"));
        SetIPDialog->resize(577, 300);
        pushButton = new QPushButton(SetIPDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(200, 180, 160, 40));
        pushButton->setMinimumSize(QSize(160, 40));
        pushButton->setMaximumSize(QSize(160, 40));
        QFont font;
        font.setPointSize(12);
        pushButton->setFont(font);
        widget = new QWidget(SetIPDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(60, 70, 431, 81));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(widget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(200, 40));
        label_9->setMaximumSize(QSize(100, 40));
        QFont font1;
        font1.setPointSize(14);
        label_9->setFont(font1);

        gridLayout->addWidget(label_9, 0, 0, 1, 1);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(200, 40));
        lineEdit->setMaximumSize(QSize(200, 40));
        lineEdit->setFont(font);

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);


        retranslateUi(SetIPDialog);

        QMetaObject::connectSlotsByName(SetIPDialog);
    } // setupUi

    void retranslateUi(QWidget *SetIPDialog)
    {
        SetIPDialog->setWindowTitle(QApplication::translate("SetIPDialog", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("SetIPDialog", "\346\217\220\344\272\244", Q_NULLPTR));
        label_9->setText(QApplication::translate("SetIPDialog", "\350\257\267\350\276\223\345\205\245IP", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SetIPDialog: public Ui_SetIPDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETIPDIALOG_H
