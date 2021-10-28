/********************************************************************************
** Form generated from reading UI file 'dialogresult.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGRESULT_H
#define UI_DIALOGRESULT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogResult
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;

    void setupUi(QDialog *DialogResult)
    {
        if (DialogResult->objectName().isEmpty())
            DialogResult->setObjectName(QString::fromUtf8("DialogResult"));
        DialogResult->setEnabled(true);
        DialogResult->resize(400, 300);
        DialogResult->setMinimumSize(QSize(400, 300));
        DialogResult->setMaximumSize(QSize(400, 300));
        verticalLayout = new QVBoxLayout(DialogResult);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(9);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(15, -1, 50, -1);
        label = new QLabel(DialogResult);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(DialogResult);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setMaximumSize(QSize(150, 16777215));
        lineEdit->setFont(font);

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(9);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(15, -1, 50, -1);
        label_2 = new QLabel(DialogResult);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(DialogResult);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        lineEdit_2->setMaximumSize(QSize(150, 16777215));
        lineEdit_2->setFont(font);

        horizontalLayout_2->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(9);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(15, -1, 50, -1);
        label_3 = new QLabel(DialogResult);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_3);

        lineEdit_3 = new QLineEdit(DialogResult);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setEnabled(false);
        lineEdit_3->setMaximumSize(QSize(150, 16777215));
        lineEdit_3->setFont(font);

        horizontalLayout_3->addWidget(lineEdit_3);


        verticalLayout->addLayout(horizontalLayout_3);

        pushButton = new QPushButton(DialogResult);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton->setFont(font1);

        verticalLayout->addWidget(pushButton);


        retranslateUi(DialogResult);

        QMetaObject::connectSlotsByName(DialogResult);
    } // setupUi

    void retranslateUi(QDialog *DialogResult)
    {
        DialogResult->setWindowTitle(QApplication::translate("DialogResult", "Dialog", nullptr));
        label->setText(QApplication::translate("DialogResult", "\345\271\263\345\235\207\345\221\250\350\275\254\346\227\266\351\227\264\357\274\232", nullptr));
        label_2->setText(QApplication::translate("DialogResult", "\345\271\263\345\235\207\345\270\266\346\235\203\345\221\250\350\275\254\346\227\266\351\227\264\357\274\232", nullptr));
        label_3->setText(QApplication::translate("DialogResult", "\345\271\263\345\235\207\347\255\211\345\276\205\346\227\266\351\227\264\357\274\232", nullptr));
        pushButton->setText(QApplication::translate("DialogResult", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogResult: public Ui_DialogResult {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGRESULT_H
