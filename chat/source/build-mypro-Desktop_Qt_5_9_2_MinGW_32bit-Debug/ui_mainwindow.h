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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *btn_exit;
    QPushButton *btn_save;
    QListWidget *list_online;
    QPushButton *btn_update;
    QListWidget *list_off;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(650, 550);
        MainWindow->setMinimumSize(QSize(650, 550));
        MainWindow->setMaximumSize(QSize(650, 550));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btn_exit = new QPushButton(centralWidget);
        btn_exit->setObjectName(QStringLiteral("btn_exit"));
        btn_exit->setGeometry(QRect(273, 451, 100, 40));
        btn_exit->setMinimumSize(QSize(100, 40));
        btn_exit->setMaximumSize(QSize(100, 40));
        QFont font;
        font.setPointSize(12);
        btn_exit->setFont(font);
        btn_save = new QPushButton(centralWidget);
        btn_save->setObjectName(QStringLiteral("btn_save"));
        btn_save->setGeometry(QRect(135, 451, 100, 40));
        btn_save->setMinimumSize(QSize(100, 40));
        btn_save->setMaximumSize(QSize(100, 40));
        btn_save->setFont(font);
        list_online = new QListWidget(centralWidget);
        list_online->setObjectName(QStringLiteral("list_online"));
        list_online->setGeometry(QRect(20, 40, 300, 400));
        list_online->setMinimumSize(QSize(300, 400));
        list_online->setMaximumSize(QSize(16777215, 400));
        btn_update = new QPushButton(centralWidget);
        btn_update->setObjectName(QStringLiteral("btn_update"));
        btn_update->setGeometry(QRect(400, 450, 100, 40));
        btn_update->setMinimumSize(QSize(100, 40));
        btn_update->setMaximumSize(QSize(100, 40));
        btn_update->setFont(font);
        list_off = new QListWidget(centralWidget);
        list_off->setObjectName(QStringLiteral("list_off"));
        list_off->setGeometry(QRect(340, 40, 300, 400));
        list_off->setMinimumSize(QSize(300, 400));
        list_off->setMaximumSize(QSize(16777215, 400));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 0, 160, 40));
        label->setMinimumSize(QSize(160, 40));
        label->setMaximumSize(QSize(100, 40));
        label->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(410, 0, 160, 40));
        label_2->setMinimumSize(QSize(160, 40));
        label_2->setMaximumSize(QSize(100, 40));
        label_2->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 650, 17));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        btn_exit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
        btn_save->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", Q_NULLPTR));
        btn_update->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\345\234\250\347\272\277\347\224\250\346\210\267\345\210\227\350\241\250", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\347\246\273\347\272\277\347\224\250\346\210\267\345\210\227\350\241\250", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
