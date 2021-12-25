/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionregister;
    QAction *actionIP;
    QAction *actionfoget;
    QWidget *centralWidget;
    QPushButton *btn_send;
    QPushButton *btn_file;
    QPushButton *btn_off;
    QLabel *label_friend;
    QLabel *label_myname;
    QListWidget *list_friend;
    QPushButton *btn_getfriend;
    QTextEdit *file_show;
    QTextEdit *text_send;
    QPushButton *btn_img;
    QListWidget *msg_list;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *btn_close;
    QLineEdit *line_psw;
    QPushButton *btn_login;
    QLineEdit *line_account;
    QLabel *label_account;
    QLabel *label_psw;
    QMenuBar *menuBar;
    QMenu *menunew;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1134, 771);
        actionregister = new QAction(MainWindow);
        actionregister->setObjectName(QStringLiteral("actionregister"));
        actionIP = new QAction(MainWindow);
        actionIP->setObjectName(QStringLiteral("actionIP"));
        actionfoget = new QAction(MainWindow);
        actionfoget->setObjectName(QStringLiteral("actionfoget"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btn_send = new QPushButton(centralWidget);
        btn_send->setObjectName(QStringLiteral("btn_send"));
        btn_send->setGeometry(QRect(501, 659, 600, 40));
        btn_send->setMinimumSize(QSize(600, 40));
        btn_send->setMaximumSize(QSize(240, 40));
        QFont font;
        font.setPointSize(12);
        btn_send->setFont(font);
        btn_file = new QPushButton(centralWidget);
        btn_file->setObjectName(QStringLiteral("btn_file"));
        btn_file->setGeometry(QRect(265, 617, 200, 40));
        btn_file->setMinimumSize(QSize(200, 40));
        btn_file->setMaximumSize(QSize(200, 40));
        btn_file->setFont(font);
        btn_off = new QPushButton(centralWidget);
        btn_off->setObjectName(QStringLiteral("btn_off"));
        btn_off->setGeometry(QRect(265, 661, 200, 40));
        btn_off->setMinimumSize(QSize(200, 40));
        btn_off->setMaximumSize(QSize(100, 40));
        btn_off->setFont(font);
        label_friend = new QLabel(centralWidget);
        label_friend->setObjectName(QStringLiteral("label_friend"));
        label_friend->setGeometry(QRect(61, 11, 200, 40));
        label_friend->setMinimumSize(QSize(200, 40));
        label_friend->setMaximumSize(QSize(200, 40));
        label_friend->setFont(font);
        label_myname = new QLabel(centralWidget);
        label_myname->setObjectName(QStringLiteral("label_myname"));
        label_myname->setGeometry(QRect(265, 11, 200, 40));
        label_myname->setMinimumSize(QSize(200, 40));
        label_myname->setMaximumSize(QSize(200, 40));
        label_myname->setFont(font);
        list_friend = new QListWidget(centralWidget);
        list_friend->setObjectName(QStringLiteral("list_friend"));
        list_friend->setGeometry(QRect(61, 259, 400, 350));
        list_friend->setMinimumSize(QSize(400, 350));
        list_friend->setMaximumSize(QSize(200, 160));
        list_friend->setFont(font);
        btn_getfriend = new QPushButton(centralWidget);
        btn_getfriend->setObjectName(QStringLiteral("btn_getfriend"));
        btn_getfriend->setGeometry(QRect(61, 661, 200, 40));
        btn_getfriend->setMinimumSize(QSize(200, 40));
        btn_getfriend->setMaximumSize(QSize(100, 40));
        btn_getfriend->setFont(font);
        file_show = new QTextEdit(centralWidget);
        file_show->setObjectName(QStringLiteral("file_show"));
        file_show->setGeometry(QRect(61, 55, 400, 200));
        file_show->setMinimumSize(QSize(400, 200));
        file_show->setMaximumSize(QSize(100, 120));
        file_show->setFont(font);
        text_send = new QTextEdit(centralWidget);
        text_send->setObjectName(QStringLiteral("text_send"));
        text_send->setGeometry(QRect(501, 575, 600, 80));
        text_send->setMinimumSize(QSize(600, 80));
        text_send->setMaximumSize(QSize(600, 80));
        text_send->setFont(font);
        btn_img = new QPushButton(centralWidget);
        btn_img->setObjectName(QStringLiteral("btn_img"));
        btn_img->setGeometry(QRect(61, 617, 200, 40));
        btn_img->setMinimumSize(QSize(200, 40));
        btn_img->setMaximumSize(QSize(200, 40));
        btn_img->setFont(font);
        msg_list = new QListWidget(centralWidget);
        msg_list->setObjectName(QStringLiteral("msg_list"));
        msg_list->setGeometry(QRect(501, 11, 600, 560));
        msg_list->setMinimumSize(QSize(600, 560));
        msg_list->setFont(font);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(340, 190, 531, 301));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btn_close = new QPushButton(layoutWidget);
        btn_close->setObjectName(QStringLiteral("btn_close"));
        btn_close->setMinimumSize(QSize(160, 40));
        btn_close->setMaximumSize(QSize(100, 40));
        btn_close->setFont(font);

        gridLayout->addWidget(btn_close, 2, 1, 1, 1);

        line_psw = new QLineEdit(layoutWidget);
        line_psw->setObjectName(QStringLiteral("line_psw"));
        line_psw->setMinimumSize(QSize(200, 40));
        line_psw->setMaximumSize(QSize(200, 40));
        line_psw->setFont(font);

        gridLayout->addWidget(line_psw, 1, 1, 1, 1);

        btn_login = new QPushButton(layoutWidget);
        btn_login->setObjectName(QStringLiteral("btn_login"));
        btn_login->setMinimumSize(QSize(160, 40));
        btn_login->setMaximumSize(QSize(100, 40));
        btn_login->setFont(font);

        gridLayout->addWidget(btn_login, 2, 0, 1, 1);

        line_account = new QLineEdit(layoutWidget);
        line_account->setObjectName(QStringLiteral("line_account"));
        line_account->setMinimumSize(QSize(200, 40));
        line_account->setMaximumSize(QSize(200, 40));
        line_account->setFont(font);

        gridLayout->addWidget(line_account, 0, 1, 1, 1);

        label_account = new QLabel(layoutWidget);
        label_account->setObjectName(QStringLiteral("label_account"));
        label_account->setMinimumSize(QSize(200, 40));
        label_account->setMaximumSize(QSize(200, 40));
        QFont font1;
        font1.setPointSize(14);
        label_account->setFont(font1);

        gridLayout->addWidget(label_account, 0, 0, 1, 1);

        label_psw = new QLabel(layoutWidget);
        label_psw->setObjectName(QStringLiteral("label_psw"));
        label_psw->setMinimumSize(QSize(200, 40));
        label_psw->setMaximumSize(QSize(200, 40));
        label_psw->setFont(font1);

        gridLayout->addWidget(label_psw, 1, 0, 1, 1);

        btn_close->raise();
        line_psw->raise();
        line_account->raise();
        label_psw->raise();
        label_account->raise();
        btn_login->raise();
        MainWindow->setCentralWidget(centralWidget);
        layoutWidget->raise();
        msg_list->raise();
        file_show->raise();
        list_friend->raise();
        btn_send->raise();
        btn_file->raise();
        btn_off->raise();
        label_friend->raise();
        label_myname->raise();
        btn_getfriend->raise();
        text_send->raise();
        btn_img->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1134, 17));
        menunew = new QMenu(menuBar);
        menunew->setObjectName(QStringLiteral("menunew"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menunew->menuAction());
        menuBar->addAction(menu->menuAction());
        menunew->addAction(actionregister);
        menu->addAction(actionfoget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionregister->setText(QApplication::translate("MainWindow", "Register", Q_NULLPTR));
        actionIP->setText(QApplication::translate("MainWindow", "IP", Q_NULLPTR));
        actionfoget->setText(QApplication::translate("MainWindow", "Foget", Q_NULLPTR));
        btn_send->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\344\277\241\346\201\257", Q_NULLPTR));
        btn_file->setText(QApplication::translate("MainWindow", "\344\270\212\344\274\240\346\226\207\344\273\266", Q_NULLPTR));
        btn_off->setText(QApplication::translate("MainWindow", "\346\263\250\351\224\200", Q_NULLPTR));
        label_friend->setText(QApplication::translate("MainWindow", "\351\200\232\344\277\241\345\245\275\345\217\213", Q_NULLPTR));
        label_myname->setText(QApplication::translate("MainWindow", "Myname", Q_NULLPTR));
        btn_getfriend->setText(QApplication::translate("MainWindow", "\346\233\264\346\226\260\350\201\224\347\263\273\344\272\272", Q_NULLPTR));
        btn_img->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\350\241\250\346\203\205", Q_NULLPTR));
        btn_close->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255", Q_NULLPTR));
        line_psw->setText(QString());
        btn_login->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225", Q_NULLPTR));
        label_account->setText(QApplication::translate("MainWindow", "\350\264\246\345\217\267", Q_NULLPTR));
        label_psw->setText(QApplication::translate("MainWindow", "\345\257\206\347\240\201", Q_NULLPTR));
        menunew->setTitle(QApplication::translate("MainWindow", "\346\226\260\347\224\250\346\210\267\346\263\250\345\206\214", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\345\277\230\350\256\260\345\257\206\347\240\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
