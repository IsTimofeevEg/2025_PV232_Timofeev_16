/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *directoryEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton;
    QPushButton *removeButton;
    QLabel *label_2;
    QLineEdit *logFileEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *setLogButton;
    QPushButton *showLogButton;
    QLabel *label_3;
    QListWidget *directoryList;
    QLabel *label_4;
    QTextEdit *logTextEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(600, 500);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        directoryEdit = new QLineEdit(centralwidget);
        directoryEdit->setObjectName("directoryEdit");

        verticalLayout->addWidget(directoryEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");

        horizontalLayout->addWidget(addButton);

        removeButton = new QPushButton(centralwidget);
        removeButton->setObjectName("removeButton");

        horizontalLayout->addWidget(removeButton);


        verticalLayout->addLayout(horizontalLayout);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        logFileEdit = new QLineEdit(centralwidget);
        logFileEdit->setObjectName("logFileEdit");

        verticalLayout->addWidget(logFileEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        setLogButton = new QPushButton(centralwidget);
        setLogButton->setObjectName("setLogButton");

        horizontalLayout_2->addWidget(setLogButton);

        showLogButton = new QPushButton(centralwidget);
        showLogButton->setObjectName("showLogButton");

        horizontalLayout_2->addWidget(showLogButton);


        verticalLayout->addLayout(horizontalLayout_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        directoryList = new QListWidget(centralwidget);
        directoryList->setObjectName("directoryList");

        verticalLayout->addWidget(directoryList);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        logTextEdit = new QTextEdit(centralwidget);
        logTextEdit->setObjectName("logTextEdit");
        logTextEdit->setReadOnly(true);

        verticalLayout->addWidget(logTextEdit);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Directory Monitor", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Directory to monitor:", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Add Directory", nullptr));
        removeButton->setText(QCoreApplication::translate("MainWindow", "Remove Directory", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Log file path:", nullptr));
        setLogButton->setText(QCoreApplication::translate("MainWindow", "Set Log File", nullptr));
        showLogButton->setText(QCoreApplication::translate("MainWindow", "Show Log", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Monitored directories:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Change log:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
