#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "pcb.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;

signals:
    void getNewPcb(PCB* tmp);
};

#endif // DIALOG_H
