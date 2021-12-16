#include "setipdialog.h"
#include "ui_setipdialog.h"

SetIPDialog::SetIPDialog(QWidget *parent) :
    QDialog(parent), ui(new Ui::SetIPDialog)
{
    ui->setupUi(this);
    connect(this->ui->pushButton,&QPushButton::clicked,this,&SetIPDialog::on_pushButton_clicked);
}
SetIPDialog::~SetIPDialog()
{
    delete ui;
}
void SetIPDialog::on_pushButton_clicked()
{
    QString ip = this->ui->lineEdit->text();
    emit emitIP(ip);
}
