#include "findpswdialog.h"
#include "ui_findpswdialog.h"

findpswDialog::findpswDialog(QWidget *parent) :
    QDialog(parent), ui(new Ui::findpswDialog)
{
    ui->setupUi(this);

    connect(this->ui->btn_ok,&QPushButton::clicked,this,&findpswDialog::on_btn_ok_clicked);
    connect(this->ui->btn_cancel,&QPushButton::clicked,this,&findpswDialog::on_btn_cancel_clicked);
}

findpswDialog::~findpswDialog()
{
    delete ui;
}

void findpswDialog::on_btn_cancel_clicked()
{
    this->close();
    this->~findpswDialog();
}
void findpswDialog::on_btn_ok_clicked()
{
    account = this->ui->line_account->text();
    question = this->ui->line_question->text();
    answer = this->ui->line_answer->text();
    psw = this->ui->line_psw->text();
    arr.clear();
    QDataStream dst(&arr,QIODevice::ReadWrite);
    dst<<QString("find")<<account<<question<<answer<<psw;
    emit sendfindmsg(arr);
}
