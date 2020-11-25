#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QSql>
#include <QSqlError>
#include <QDir>
#include <QFile>
#include <QDebug>
#include <QSqlQuery>
#include <QString>
#include <iostream>
#include <fstream>
#include <string>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Extern_Variables.h"
#include "date.h"
#include "table.h"
#include "ProceduceCustomer.h"
#include "proceduceproduct.h"
#include "proceduceorder.h"
#include "proceduceorderdetails.h"

map <int, SoldProduct> Product_Sold;
int SoldProductID = 0;
int LastOrderID = 10444;
int LastOrderDetailID = 518;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      TableCustomer("Customer"),
      TableCategories("Categories"),
      TableEmployees("Employees"),
      TableOrderDetails("OrderDetails"),
      TableOrders("Orders"),
      TableProducts("Products"),
      TableShippers("Shippers"),
      TableSuppliers("Suppliers"),
      ui(new Ui::MainWindow)
{

    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

SoldProduct Order_Temp;

void MainWindow::on_CreateOrder_clicked()
{
    int date = convertdate(ui->Date->text().toStdString());
    int customerid = ui->CustomerID->text().toInt();
    int shipperid = ui->Shipper->text().toInt();
    int employeeid = ui->Employee->text().toInt();
//Table* tabledata, int orderid, int customerid, int employeeid, int date, int shipperid){
    ProceduceOrder add;
    add.AddData(&TableOrders, LastOrderID, customerid, employeeid, date, shipperid);
}

void MainWindow::on_AddProduct_clicked()
{
    //Add Product chosen into object Order_Temp;
    /*Order_Temp.AddProduct(name, quantity, price);*/

    int productid = ui->ProductID->text().toInt();
    int quantity = - (ui->Quantity->text().toInt());

    ProceduceOrderDetails add;
    add.AddData(&TableOrderDetails, LastOrderDetailID, LastOrderID, productid, quantity);

    // clear editLine Name, Quantity, Price, Original Price of Product
    ui->ProductID->clear();
    ui->Quantity->clear();
}

void MainWindow::on_DoneOrder_clicked()
{
    /*string name = ui->ProductName->currentText().toStdString();
    int quantity = ui->Quantity->text().toInt();
    double price = ui->Price->text().toDouble();

    //Add Product chosen into object Order_Temp;
    Order_Temp.AddProduct(name, quantity, price);

    //Insert a element of map Product_Sold which has first key was SoldProductID
    //and second key was an object Order_Temp of class SoldProduct
    Product_Sold.insert(make_pair(SoldProductID, Order_Temp));

    //Increae first key SoldProductID for next element of map Product_Sold
    SoldProductID++;*/

    LastOrderID ++;
    LastOrderDetailID++;

    // clear editLine Name, Quantity, Price, Original Price of Product, Customer ID and Date of OrderSold
    ui->Quantity->clear();
    ui->CustomerID->clear();
    ui->Date->clear();
    ui->Shipper->clear();
    ui->Employee->clear();
}

void MainWindow::on_Try_clicked()
{
}

void MainWindow::on_Change_12_clicked()
{
}

void MainWindow::on_Delete_clicked()
{
    int id = ui->CustomerID_2->text().toInt();

    ProceduceCustomer del;
    del.DeleteData(&TableCustomer, id);


}

void MainWindow::on_Delete_6_clicked()
{
}

void MainWindow::on_Change_clicked()
{
    int id = ui->CustomerID_2->text().toInt();

    string name = ui->CustomerID_3->text().toStdString();
    string contact = ui->CustomerID_4->text().toStdString();
    string address = ui->CustomerID_5->text().toStdString();
    string postalcode = ui->CustomerID_6->text().toStdString();
    string country = ui->CustomerID_8->text().toStdString();
    string city = ui->CustomerID_7->text().toStdString();

    ProceduceCustomer update;

    update.UpdateData(&TableCustomer, id, name, contact, address,city,country, postalcode);
}

void MainWindow::on_Add_clicked()
{
    int id = ui->CustomerID_2->text().toInt();
    string name = ui->CustomerID_3->text().toStdString();
    string contact = ui->CustomerID_4->text().toStdString();
    string address = ui->CustomerID_5->text().toStdString();
    string postalcode = ui->CustomerID_5->text().toStdString();
    string country = ui->CustomerID_8->text().toStdString();
    string city = ui->CustomerID_7->text().toStdString();

    ProceduceCustomer add;
    add.AddData(&TableCustomer, id, name, contact, address, postalcode, country, city);
}

void MainWindow::on_ReportStoreWeek_clicked()
{

}

void MainWindow::on_Store_clicked()
{
    StoreData("F:/LG_Training/Exercise/Nhom_4/FinalProject/data.db", "F:/LG_Training/Exercise/Nhom_4/FinalProject/StoreData/data.db");
}

void MainWindow::on_Change_4_clicked()
{

}

void MainWindow::on_Store_2_clicked()
{
    QString temp = "";
    ProceduceProduct reportproduct;
    ProceduceOrder reportorder;
    qDebug() << ui->radioButton_2->isCheckable();
    if(ui->radioButton->isChecked()){

        QString whatfind = QString::fromStdString(ui->comboBox->currentText().toStdString());
        QVariant value = ui->lineEdit_3->text();
        temp = reportproduct.PrintfReport(whatfind, value, TableProducts);

        ui->lineEdit->setText(temp);
    } else if(ui->radioButton_2->isChecked()){
        cout << "print order";
        int first = ui->lineEdit_4->text().toInt();
        int second = ui->lineEdit_5->text().toInt();

        temp = reportorder.PrintfReport(TableOrders ,first, second);
        ui->lineEdit->setText(temp);
    }
}

void MainWindow::on_Store_3_clicked()
{
    if(ui->Customer->isChecked()){
        ProceduceCustomer customer;
        int id = ui->lineEdit_6->text().toInt();
        QString temp = customer.PrintfReport(id, TableCustomer);
        ui->lineEdit_2->setText(temp);
    } else if(ui->radioButton_3->isChecked()){
        ProceduceOrder order;
        int id = ui->lineEdit_6->text().toInt();
        QString temp = order.PrintfReport(id, TableOrders);
        ui->lineEdit_2->setText(temp);
    } else if(ui->radioButton_4->isChecked()){
        ProceduceOrderDetails orderdetails;
        int id = ui->lineEdit_6->text().toInt();
        QString temp = orderdetails.PrintfReport(id, TableOrderDetails);
        ui->lineEdit_2->setText(temp);
    }
}

void MainWindow::on_Change_9_clicked()
{

    /*ProceduceOrder update;

    update.UpdateData(&TableCustomer, id, name, contact, address,city,country, postalcode);*/
}

void MainWindow::on_Add_4_clicked()
{

}
