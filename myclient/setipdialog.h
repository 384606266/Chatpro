#ifndef SETIPDIALOG_H
#define SETIPDIALOG_H

#include <QDialog>

namespace Ui {
class SetIPDialog;
}

class SetIPDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetIPDialog(QWidget *parent = 0);
    ~SetIPDialog();

private slots:
    void on_pushButton_clicked();
signals:
    void emitIP(QString &);
private:
    Ui::SetIPDialog *ui;
};

#endif // SETIPDIALOG_H
