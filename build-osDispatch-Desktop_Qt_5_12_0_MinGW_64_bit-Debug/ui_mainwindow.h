/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QPushButton *pushButton_7;
    QRadioButton *radioButtonFCFS;
    QSpacerItem *verticalSpacer;
    QRadioButton *radioButtonSJF;
    QSpacerItem *verticalSpacer_4;
    QRadioButton *radioButtonPriority;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_9;
    QLabel *labelCurrentTime;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QPushButton *pushButton_8;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QTableView *tableViewArrival;
    QLabel *label;
    QVBoxLayout *verticalLayout_5;
    QTableView *tableViewFinish;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_4;
    QTableView *tableViewSuspended;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_7;
    QTableView *tableViewRunningOne;
    QProgressBar *progressBar;
    QVBoxLayout *verticalLayout_8;
    QTableView *tableViewRunningTwo;
    QProgressBar *progressBar_2;
    QVBoxLayout *verticalLayout_9;
    QTableView *tableViewRunningThree;
    QProgressBar *progressBar_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_10;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *addPushButton;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_9;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_3;
    QPushButton *runOneSecond;
    QPushButton *pushButton;
    QPushButton *pushButton_10;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1400, 800);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);
        label_4->setMargin(10);
        label_4->setIndent(-1);

        verticalLayout_2->addWidget(label_4);

        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setEnabled(false);

        verticalLayout_2->addWidget(pushButton_7);

        radioButtonFCFS = new QRadioButton(centralWidget);
        radioButtonFCFS->setObjectName(QString::fromUtf8("radioButtonFCFS"));
        QFont font1;
        font1.setPointSize(10);
        radioButtonFCFS->setFont(font1);

        verticalLayout_2->addWidget(radioButtonFCFS);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        radioButtonSJF = new QRadioButton(centralWidget);
        radioButtonSJF->setObjectName(QString::fromUtf8("radioButtonSJF"));
        radioButtonSJF->setFont(font1);

        verticalLayout_2->addWidget(radioButtonSJF);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        radioButtonPriority = new QRadioButton(centralWidget);
        radioButtonPriority->setObjectName(QString::fromUtf8("radioButtonPriority"));
        radioButtonPriority->setFont(font1);
        radioButtonPriority->setChecked(true);

        verticalLayout_2->addWidget(radioButtonPriority);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QFont font2;
        font2.setPointSize(15);
        label_9->setFont(font2);
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_9);

        labelCurrentTime = new QLabel(centralWidget);
        labelCurrentTime->setObjectName(QString::fromUtf8("labelCurrentTime"));
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setWeight(75);
        labelCurrentTime->setFont(font3);
        labelCurrentTime->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(labelCurrentTime);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font4;
        font4.setPointSize(24);
        font4.setBold(true);
        font4.setWeight(75);
        label_5->setFont(font4);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_5);

        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setEnabled(false);

        verticalLayout->addWidget(pushButton_8);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, -1, 10, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tableViewArrival = new QTableView(centralWidget);
        tableViewArrival->setObjectName(QString::fromUtf8("tableViewArrival"));
        tableViewArrival->setMinimumSize(QSize(0, 250));
        tableViewArrival->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableViewArrival->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableViewArrival->setSortingEnabled(false);

        verticalLayout_3->addWidget(tableViewArrival);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setSizeIncrement(QSize(0, 0));
        label->setBaseSize(QSize(0, 0));
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(true);
        font5.setItalic(false);
        font5.setWeight(75);
        label->setFont(font5);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);
        label->setMargin(0);

        verticalLayout_3->addWidget(label);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        tableViewFinish = new QTableView(centralWidget);
        tableViewFinish->setObjectName(QString::fromUtf8("tableViewFinish"));
        tableViewFinish->setMinimumSize(QSize(0, 250));
        tableViewFinish->setLineWidth(1);
        tableViewFinish->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);

        verticalLayout_5->addWidget(tableViewFinish);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font5);
        label_3->setAlignment(Qt::AlignCenter);
        label_3->setMargin(0);

        verticalLayout_5->addWidget(label_3);


        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        tableViewSuspended = new QTableView(centralWidget);
        tableViewSuspended->setObjectName(QString::fromUtf8("tableViewSuspended"));
        tableViewSuspended->setMinimumSize(QSize(0, 250));

        verticalLayout_4->addWidget(tableViewSuspended);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font5);
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setMargin(0);

        verticalLayout_4->addWidget(label_2);


        horizontalLayout_2->addLayout(verticalLayout_4);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_4->setContentsMargins(10, 0, 10, -1);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        tableViewRunningOne = new QTableView(centralWidget);
        tableViewRunningOne->setObjectName(QString::fromUtf8("tableViewRunningOne"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableViewRunningOne->sizePolicy().hasHeightForWidth());
        tableViewRunningOne->setSizePolicy(sizePolicy1);
        tableViewRunningOne->setMaximumSize(QSize(16777215, 16777215));
        tableViewRunningOne->setLayoutDirection(Qt::LeftToRight);
        tableViewRunningOne->setAutoFillBackground(false);
        tableViewRunningOne->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableViewRunningOne->setAlternatingRowColors(true);
        tableViewRunningOne->setTextElideMode(Qt::ElideLeft);

        verticalLayout_7->addWidget(tableViewRunningOne);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);
        progressBar->setAlignment(Qt::AlignCenter);
        progressBar->setTextDirection(QProgressBar::TopToBottom);

        verticalLayout_7->addWidget(progressBar);


        horizontalLayout_4->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        tableViewRunningTwo = new QTableView(centralWidget);
        tableViewRunningTwo->setObjectName(QString::fromUtf8("tableViewRunningTwo"));
        sizePolicy1.setHeightForWidth(tableViewRunningTwo->sizePolicy().hasHeightForWidth());
        tableViewRunningTwo->setSizePolicy(sizePolicy1);
        tableViewRunningTwo->setMaximumSize(QSize(16777215, 16777215));
        tableViewRunningTwo->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableViewRunningTwo->setAlternatingRowColors(true);

        verticalLayout_8->addWidget(tableViewRunningTwo);

        progressBar_2 = new QProgressBar(centralWidget);
        progressBar_2->setObjectName(QString::fromUtf8("progressBar_2"));
        progressBar_2->setValue(0);
        progressBar_2->setAlignment(Qt::AlignCenter);
        progressBar_2->setTextDirection(QProgressBar::TopToBottom);

        verticalLayout_8->addWidget(progressBar_2);


        horizontalLayout_4->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        tableViewRunningThree = new QTableView(centralWidget);
        tableViewRunningThree->setObjectName(QString::fromUtf8("tableViewRunningThree"));
        sizePolicy1.setHeightForWidth(tableViewRunningThree->sizePolicy().hasHeightForWidth());
        tableViewRunningThree->setSizePolicy(sizePolicy1);
        tableViewRunningThree->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableViewRunningThree->setAlternatingRowColors(true);

        verticalLayout_9->addWidget(tableViewRunningThree);

        progressBar_3 = new QProgressBar(centralWidget);
        progressBar_3->setObjectName(QString::fromUtf8("progressBar_3"));
        progressBar_3->setValue(0);
        progressBar_3->setAlignment(Qt::AlignCenter);
        progressBar_3->setTextDirection(QProgressBar::TopToBottom);

        verticalLayout_9->addWidget(progressBar_3);


        horizontalLayout_4->addLayout(verticalLayout_9);


        verticalLayout_6->addLayout(horizontalLayout_4);


        verticalLayout->addLayout(verticalLayout_6);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, -1, 500, -1);
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        QFont font6;
        font6.setPointSize(15);
        font6.setBold(true);
        font6.setWeight(75);
        label_10->setFont(font6);
        label_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_10->setMargin(30);

        horizontalLayout_6->addWidget(label_10);

        radioButton_2 = new QRadioButton(centralWidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setFont(font6);

        horizontalLayout_6->addWidget(radioButton_2);

        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setFont(font6);

        horizontalLayout_6->addWidget(radioButton);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(10);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(5, 0, 5, 10);
        addPushButton = new QPushButton(centralWidget);
        addPushButton->setObjectName(QString::fromUtf8("addPushButton"));
        addPushButton->setMinimumSize(QSize(0, 50));
        QFont font7;
        font7.setPointSize(13);
        font7.setBold(true);
        font7.setWeight(75);
        addPushButton->setFont(font7);

        horizontalLayout_5->addWidget(addPushButton);

        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(0, 50));
        pushButton_6->setFont(font7);

        horizontalLayout_5->addWidget(pushButton_6);

        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(0, 50));
        pushButton_5->setFont(font7);

        horizontalLayout_5->addWidget(pushButton_5);

        pushButton_9 = new QPushButton(centralWidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(0, 50));
        pushButton_9->setFont(font7);

        horizontalLayout_5->addWidget(pushButton_9);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(5, 0, 5, 25);
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 50));
        pushButton_3->setFont(font7);

        horizontalLayout_3->addWidget(pushButton_3);

        runOneSecond = new QPushButton(centralWidget);
        runOneSecond->setObjectName(QString::fromUtf8("runOneSecond"));
        runOneSecond->setMinimumSize(QSize(0, 50));
        runOneSecond->setFont(font7);

        horizontalLayout_3->addWidget(runOneSecond);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 50));
        pushButton->setFont(font7);

        horizontalLayout_3->addWidget(pushButton);

        pushButton_10 = new QPushButton(centralWidget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setEnabled(false);
        pushButton_10->setMinimumSize(QSize(0, 50));
        pushButton_10->setFont(font7);

        horizontalLayout_3->addWidget(pushButton_10);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\350\260\203\345\272\246\347\256\227\346\263\225", nullptr));
        pushButton_7->setText(QString());
        radioButtonFCFS->setText(QApplication::translate("MainWindow", "\345\205\210\346\235\245\345\205\210\346\234\215\345\212\241\350\260\203\345\272\246", nullptr));
        radioButtonSJF->setText(QApplication::translate("MainWindow", "\347\237\255\344\275\234\344\270\232\344\274\230\345\205\210\350\260\203\345\272\246", nullptr));
        radioButtonPriority->setText(QApplication::translate("MainWindow", "\345\212\250\346\200\201\344\274\230\345\205\210\346\235\203\350\260\203\345\272\246", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\345\267\262\346\211\247\350\241\214\346\227\266\351\227\264", nullptr));
        labelCurrentTime->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "\350\260\203\345\272\246\346\274\224\347\244\272", nullptr));
        pushButton_8->setText(QString());
        label->setText(QApplication::translate("MainWindow", "\345\260\261\347\273\252\347\255\211\345\276\205\351\230\237\345\210\227", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\345\256\214\346\210\220\351\230\237\345\210\227", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\346\214\202\350\265\267\351\230\237\345\210\227", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "CPU:", nullptr));
        radioButton_2->setText(QApplication::translate("MainWindow", "\345\215\225\346\240\270", nullptr));
        radioButton->setText(QApplication::translate("MainWindow", "\345\244\232\346\240\270", nullptr));
        addPushButton->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "\351\232\217\346\234\272\347\224\237\346\210\220", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "\346\214\202\350\265\267", nullptr));
        pushButton_9->setText(QApplication::translate("MainWindow", "\345\217\226\346\266\210\346\214\202\350\265\267", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\346\211\247\350\241\214", nullptr));
        runOneSecond->setText(QApplication::translate("MainWindow", "\346\211\247\350\241\214", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\351\207\215\347\275\256", nullptr));
        pushButton_10->setText(QApplication::translate("MainWindow", "\350\216\267\345\276\227\347\273\223\346\236\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
