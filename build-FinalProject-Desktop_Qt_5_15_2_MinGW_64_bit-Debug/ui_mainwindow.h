/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *Date;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *Quantity;
    QPushButton *CreateOrder;
    QComboBox *ProductName;
    QPushButton *CreateOrder_2;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *Price;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *OriginalPrice;
    QPushButton *Original_Price;
    QPushButton *AddProduct;
    QLineEdit *Try_In;
    QLineEdit *Try_Out;
    QPushButton *Try;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *CustomerID;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 100, 217, 24));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        Date = new QLineEdit(layoutWidget);
        Date->setObjectName(QString::fromUtf8("Date"));

        horizontalLayout_2->addWidget(Date);

        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(240, 150, 217, 24));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        Quantity = new QLineEdit(layoutWidget_2);
        Quantity->setObjectName(QString::fromUtf8("Quantity"));

        horizontalLayout_3->addWidget(Quantity);

        CreateOrder = new QPushButton(centralwidget);
        CreateOrder->setObjectName(QString::fromUtf8("CreateOrder"));
        CreateOrder->setGeometry(QRect(250, 50, 93, 71));
        ProductName = new QComboBox(centralwidget);
        ProductName->setObjectName(QString::fromUtf8("ProductName"));
        ProductName->setGeometry(QRect(20, 150, 191, 21));
        CreateOrder_2 = new QPushButton(centralwidget);
        CreateOrder_2->setObjectName(QString::fromUtf8("CreateOrder_2"));
        CreateOrder_2->setGeometry(QRect(20, 250, 701, 41));
        layoutWidget_3 = new QWidget(centralwidget);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(510, 200, 217, 24));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        Price = new QLineEdit(layoutWidget_3);
        Price->setObjectName(QString::fromUtf8("Price"));

        horizontalLayout_4->addWidget(Price);

        layoutWidget_4 = new QWidget(centralwidget);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(510, 70, 217, 24));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        OriginalPrice = new QLineEdit(layoutWidget_4);
        OriginalPrice->setObjectName(QString::fromUtf8("OriginalPrice"));

        horizontalLayout_5->addWidget(OriginalPrice);

        Original_Price = new QPushButton(centralwidget);
        Original_Price->setObjectName(QString::fromUtf8("Original_Price"));
        Original_Price->setGeometry(QRect(510, 120, 211, 51));
        AddProduct = new QPushButton(centralwidget);
        AddProduct->setObjectName(QString::fromUtf8("AddProduct"));
        AddProduct->setGeometry(QRect(20, 200, 441, 31));
        Try_In = new QLineEdit(centralwidget);
        Try_In->setObjectName(QString::fromUtf8("Try_In"));
        Try_In->setGeometry(QRect(460, 360, 113, 22));
        Try_Out = new QLineEdit(centralwidget);
        Try_Out->setObjectName(QString::fromUtf8("Try_Out"));
        Try_Out->setGeometry(QRect(460, 420, 113, 22));
        Try = new QPushButton(centralwidget);
        Try->setObjectName(QString::fromUtf8("Try"));
        Try->setGeometry(QRect(600, 370, 101, 51));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 50, 217, 24));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        CustomerID = new QLineEdit(widget);
        CustomerID->setObjectName(QString::fromUtf8("CustomerID"));

        horizontalLayout->addWidget(CustomerID);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Quantity", nullptr));
        CreateOrder->setText(QCoreApplication::translate("MainWindow", "Create Order", nullptr));
        CreateOrder_2->setText(QCoreApplication::translate("MainWindow", "Create Order", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Price", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Original Price", nullptr));
        Original_Price->setText(QCoreApplication::translate("MainWindow", "Show Original Price", nullptr));
        AddProduct->setText(QCoreApplication::translate("MainWindow", "Add More Product", nullptr));
        Try->setText(QCoreApplication::translate("MainWindow", "Try", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Customer ID", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
