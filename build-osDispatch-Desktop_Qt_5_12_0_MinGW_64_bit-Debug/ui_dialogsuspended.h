/********************************************************************************
** Form generated from reading UI file 'dialogsuspended.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSUSPENDED_H
#define UI_DIALOGSUSPENDED_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogSuspended
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *DialogSuspended)
    {
        if (DialogSuspended->objectName().isEmpty())
            DialogSuspended->setObjectName(QString::fromUtf8("DialogSuspended"));
        DialogSuspended->resize(400, 150);
        verticalLayout = new QVBoxLayout(DialogSuspended);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, -1, 10, -1);
        label = new QLabel(DialogSuspended);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(DialogSuspended);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setFont(font);

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(100, -1, -1, -1);
        pushButton = new QPushButton(DialogSuspended);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(DialogSuspended);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(DialogSuspended);

        QMetaObject::connectSlotsByName(DialogSuspended);
    } // setupUi

    void retranslateUi(QDialog *DialogSuspended)
    {
        DialogSuspended->setWindowTitle(QApplication::translate("DialogSuspended", "Dialog", nullptr));
        label->setText(QApplication::translate("DialogSuspended", "\344\275\234\344\270\232\345\217\267\357\274\232", nullptr));
        lineEdit->setText(QString());
        pushButton->setText(QApplication::translate("DialogSuspended", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QApplication::translate("DialogSuspended", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSuspended: public Ui_DialogSuspended {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSUSPENDED_H
