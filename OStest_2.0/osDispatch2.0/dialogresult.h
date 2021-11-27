#ifndef DIALOGRESULT_H
#define DIALOGRESULT_H

#include "pcb.h"

#include <QDialog>

namespace Ui {
class DialogResult;
}

class DialogResult : public QDialog
{
    Q_OBJECT

public:
    explicit DialogResult(QWidget *parent = nullptr);
    ~DialogResult();
    void getResult(QList<PCB> finish);

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogResult *ui;
};

#endif // DIALOGRESULT_H
