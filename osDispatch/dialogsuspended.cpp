#include "dialogsuspended.h"
#include "ui_dialogsuspended.h"

#include <QMessageBox>

DialogSuspended::DialogSuspended(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSuspended)
{
    ui->setupUi(this);
}

DialogSuspended::~DialogSuspended()
{
    delete ui;
}

void DialogSuspended::on_pushButton_clicked()
{
    if(ui->lineEdit->text()==""){
        QMessageBox::critical(0 , "错误警告" , "输入为空！", QMessageBox::Ok | QMessageBox::Default , 0 );
        return;
    }
    QString tmp=ui->lineEdit->text();
    emit(getPid(tmp));
    this->close();
}

void DialogSuspended::on_pushButton_2_clicked()
{
    this->close();
}
