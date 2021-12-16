#ifndef FINDPSWDIALOG_H
#define FINDPSWDIALOG_H

#include <QDialog>

namespace Ui {
class findpswDialog;
}

class findpswDialog : public QDialog
{
    Q_OBJECT

public:
    explicit findpswDialog(QWidget *parent = 0);
    ~findpswDialog();
    QString account, psw,question,answer;
    QByteArray arr;
signals:
    void sendfindmsg(QByteArray &arr);
private slots:
    void on_btn_cancel_clicked();
    void on_btn_ok_clicked();
private:
    Ui::findpswDialog *ui;
};

#endif // FINDPSWDIALOG_H
