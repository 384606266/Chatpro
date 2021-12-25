#include "registerdialog.h"
#include "ui_registerdialog.h"

RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent), ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
    connect(this->ui->btn_ok,&QPushButton::clicked,this,&RegisterDialog::on_push_ok_clicked);
    connect(this->ui->btn_cancel,&QPushButton::clicked,this,&RegisterDialog::on_push_cancel_clicked);
}
RegisterDialog::~RegisterDialog(){
    delete ui;
}
void RegisterDialog::on_push_ok_clicked()
{
    psw = this->ui->line_psw->text();
    QString psw2 = this->ui->line_psw2->text();
    if(psw != psw2)
    {
         QMessageBox::about(this,"警告","两次输入密码不一致！！！");
         return;
    }
    account=this->ui->line_account->text();
    question=this->ui->line_question->text();
    answer=this->ui->line_answer->text();
    arr.clear();
    QDataStream dst(&arr,QIODevice::ReadWrite);
    dst<<QString("reg")<<account<<psw<<question<<answer;
    emit sendregmsg(arr);
}
void RegisterDialog::on_push_cancel_clicked()
{
    this->close();
    this->~RegisterDialog();
}
