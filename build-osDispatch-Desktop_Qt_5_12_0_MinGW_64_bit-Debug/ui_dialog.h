/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *lineEditPriority;
    QLabel *label_2;
    QLineEdit *lineEditPid;
    QLineEdit *lineEditRequiredRunningTime;
    QLabel *label;
    QLineEdit *lineEditArrivalTime;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_4;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(400, 300);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setPointSize(10);
        label_3->setFont(font);
        label_3->setMargin(10);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        lineEditPriority = new QLineEdit(Dialog);
        lineEditPriority->setObjectName(QString::fromUtf8("lineEditPriority"));
        lineEditPriority->setFont(font);

        gridLayout->addWidget(lineEditPriority, 3, 3, 1, 1);

        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setMargin(10);

        gridLayout->addWidget(label_2, 2, 0, 1, 2);

        lineEditPid = new QLineEdit(Dialog);
        lineEditPid->setObjectName(QString::fromUtf8("lineEditPid"));
        lineEditPid->setFont(font);

        gridLayout->addWidget(lineEditPid, 0, 3, 1, 1);

        lineEditRequiredRunningTime = new QLineEdit(Dialog);
        lineEditRequiredRunningTime->setObjectName(QString::fromUtf8("lineEditRequiredRunningTime"));
        lineEditRequiredRunningTime->setFont(font);

        gridLayout->addWidget(lineEditRequiredRunningTime, 1, 3, 1, 1);

        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setMargin(10);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditArrivalTime = new QLineEdit(Dialog);
        lineEditArrivalTime->setObjectName(QString::fromUtf8("lineEditArrivalTime"));
        lineEditArrivalTime->setFont(font);

        gridLayout->addWidget(lineEditArrivalTime, 2, 3, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QFont font1;
        font1.setPointSize(13);
        pushButton->setFont(font1);

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font1);

        horizontalLayout->addWidget(pushButton_2);


        gridLayout->addLayout(horizontalLayout, 4, 1, 1, 3);

        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setMargin(10);

        gridLayout->addWidget(label_4, 1, 0, 1, 2);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        label_3->setText(QApplication::translate("Dialog", "\344\274\230\345\205\210\347\272\247\357\274\232", nullptr));
        label_2->setText(QApplication::translate("Dialog", "\345\210\260\350\276\276\346\227\266\351\227\264\357\274\232", nullptr));
        label->setText(QApplication::translate("Dialog", "\344\275\234\344\270\232\345\217\267\357\274\232", nullptr));
        pushButton->setText(QApplication::translate("Dialog", "\347\241\256\350\256\244", nullptr));
        pushButton_2->setText(QApplication::translate("Dialog", "\345\217\226\346\266\210", nullptr));
        label_4->setText(QApplication::translate("Dialog", "\346\211\200\351\234\200\350\277\220\350\241\214\346\227\266\351\227\264\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
