#ifndef DIALOGSUSPENDED_H
#define DIALOGSUSPENDED_H

#include "pcb.h"

#include <QDialog>

namespace Ui {
class DialogSuspended;
}

class DialogSuspended : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSuspended(QWidget *parent = nullptr);
    ~DialogSuspended();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::DialogSuspended *ui;

signals:
    void getPid(QString tmp);
};

#endif // DIALOGSUSPENDED_H
