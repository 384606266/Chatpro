#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include <QMainWindow>
#include <QTcpSocket>
#include <QDataStream>
#include <QByteArray>
#include <QString>
#include <QMessageBox>

namespace Ui {
class RegisterDialog;
}
class RegisterDialog : public QDialog//,public virtual message
{
    Q_OBJECT
public:
    explicit RegisterDialog(QWidget *parent = 0);
    ~RegisterDialog();
    QString account, psw,question,answer;
    QByteArray arr;
signals:
    void sendregmsg(QByteArray &arr);
private slots:
    void on_push_ok_clicked();
    void on_push_cancel_clicked();
private:
    Ui::RegisterDialog *ui;
};

#endif // REGISTERDIALOG_H
