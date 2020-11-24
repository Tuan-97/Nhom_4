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
//#include "TableManagement.h"
#include "ProceduceCustomer.h"
#include "proceduceproduct.h"

map <int, SoldProduct> Product_Sold;
int SoldProductID = 0;

Table TableCustomer("Customer");
Table TableCategories("Categories");
Table TableEmployees("Employees");
Table TableOrderDetails("OrderDetails");
Table TableOrders("Order");
Table TableProducts("Products");
Table TableShippers("Shippers");
Table TableSuppliers("Suppliers");

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->ProductName->addItem("");
    ui->ProductName->addItem("Chais");
    ui->ProductName->addItem("Chang");
    ui->ProductName->addItem("Aniseed Syrup");
    ui->ProductName->addItem("Chef Anton's Cajun Seasoning");
    ui->ProductName->addItem("Chef Anton's Gumbo Mix");
    ui->ProductName->addItem("Grandma's Boysenberry Spread");
    ui->ProductName->addItem("Uncle Bob's Organic Dried Pears");
    ui->ProductName->addItem("Northwoods Cranberry Sauce");
    ui->ProductName->addItem("Mishi Kobe Niku");
    ui->ProductName->addItem("Ikura");
    ui->ProductName->addItem("Queso Cabrales");
    ui->ProductName->addItem("Queso Manchego La Pastora");
    ui->ProductName->addItem("Konbu");
    ui->ProductName->addItem("Tofu");
    ui->ProductName->addItem("Genen Shouyu");
    ui->ProductName->addItem("Pavlova");
    ui->ProductName->addItem("Alice Mutton");
    ui->ProductName->addItem("Carnarvon Tigers");
    ui->ProductName->addItem("Teatime Chocolate Biscuits");
    ui->ProductName->addItem("Sir Rodney's Marmalade");
    ui->ProductName->addItem("Sir Rodney's Scones");
    ui->ProductName->addItem("Gustaf's Knäckebröd");
    ui->ProductName->addItem("Tunnbröd");
    ui->ProductName->addItem("Guaraná Fantástica");
    ui->ProductName->addItem("NuNuCa Nuß-Nougat-Creme");
    ui->ProductName->addItem("Gumbär Gummibärchen");
    ui->ProductName->addItem("Schoggi Schokolade");
    ui->ProductName->addItem("Rössle Sauerkraut");
    ui->ProductName->addItem("Thüringer Rostbratwurst");
    ui->ProductName->addItem("Nord-Ost Matjeshering");
    ui->ProductName->addItem("Gorgonzola Telino");
    ui->ProductName->addItem("Mascarpone Fabioli");
    ui->ProductName->addItem("Geitost");
    ui->ProductName->addItem("Sasquatch Ale");
    ui->ProductName->addItem("Steeleye Stout");
    ui->ProductName->addItem("Inlagd Sill");
    ui->ProductName->addItem("Gravad lax");
    ui->ProductName->addItem("Côte de Blaye");
    ui->ProductName->addItem("Chartreuse verte");
    ui->ProductName->addItem("Boston Crab Meat");
    ui->ProductName->addItem("Jack's New England Clam Chowder");
    ui->ProductName->addItem("Singaporean Hokkien Fried Mee");
    ui->ProductName->addItem("Ipoh Coffee");
    ui->ProductName->addItem("Gula Malacca");
    ui->ProductName->addItem("Røgede sild");
    ui->ProductName->addItem("Spegesild");
    ui->ProductName->addItem("Zaanse koeken");
    ui->ProductName->addItem("Chocolade");
    ui->ProductName->addItem("Maxilaku");
    ui->ProductName->addItem("Valkoinen suklaa");
    ui->ProductName->addItem("Manjimup Dried Apples");
    ui->ProductName->addItem("Filo Mix");
    ui->ProductName->addItem("Perth Pasties");
    ui->ProductName->addItem("Tourtière");
    ui->ProductName->addItem("Pâté chinois");
    ui->ProductName->addItem("Gnocchi di nonna Alice");
    ui->ProductName->addItem("Ravioli Angelo");
    ui->ProductName->addItem("Escargots de Bourgogne");
    ui->ProductName->addItem("Raclette Courdavault");
    ui->ProductName->addItem("Camembert Pierrot");
    ui->ProductName->addItem("Sirop d'érable");
    ui->ProductName->addItem("Tarte au sucre");
    ui->ProductName->addItem("Vegie-spread");
    ui->ProductName->addItem("Wimmers gute Semmelknödel");
    ui->ProductName->addItem("Louisiana Fiery Hot Pepper Sauce");
    ui->ProductName->addItem("Louisiana Hot Spiced Okra");
    ui->ProductName->addItem("Laughing Lumberjack Lager");
    ui->ProductName->addItem("Scottish Longbreads");
    ui->ProductName->addItem("Gudbrandsdalsost");
    ui->ProductName->addItem("Outback Lager");
    ui->ProductName->addItem("Fløtemysost");
    ui->ProductName->addItem("Mozzarella di Giovanni");
    ui->ProductName->addItem("Röd Kaviar");
    ui->ProductName->addItem("Longlife Tofu");
    ui->ProductName->addItem("Rhönbräu Klosterbier");
    ui->ProductName->addItem("Lakkalikööri");
    ui->ProductName->addItem("Original Frankfurter grüne Soße");
}

MainWindow::~MainWindow()
{
    delete ui;
}

SoldProduct Order_Temp;

void MainWindow::on_CreateOrder_clicked()
{
    int date = convertdate(ui->Date->text().toStdString());
    Order_Temp.SetOrder(ui->CustomerID->text().toInt(), date);
}

void MainWindow::on_AddProduct_clicked()
{
    string name = ui->ProductName->currentText().toStdString();
    int quantity = ui->Quantity->text().toInt();
    double price = ui->Price->text().toDouble();

    //Add Product chosen into object Order_Temp;
    Order_Temp.AddProduct(name, quantity, price);

    // clear editLine Name, Quantity, Price, Original Price of Product
    ui->ProductName->clear();
    ui->Quantity->clear();
    ui->Price->clear();
    ui->OriginalPrice->clear();
}

void MainWindow::on_DoneOrder_clicked()
{
    string name = ui->ProductName->currentText().toStdString();
    int quantity = ui->Quantity->text().toInt();
    double price = ui->Price->text().toDouble();

    //Add Product chosen into object Order_Temp;
    Order_Temp.AddProduct(name, quantity, price);

    //Insert a element of map Product_Sold which has first key was SoldProductID
    //and second key was an object Order_Temp of class SoldProduct
    Product_Sold.insert(make_pair(SoldProductID, Order_Temp));

    //Increae first key SoldProductID for next element of map Product_Sold
    SoldProductID++;

    // clear editLine Name, Quantity, Price, Original Price of Product, Customer ID and Date of OrderSold
    ui->ProductName->clear();
    ui->Quantity->clear();
    ui->Price->clear();
    ui->OriginalPrice->clear();
    ui->CustomerID->clear();
    ui->Date->clear();
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
    string postalcode = ui->CustomerID_5->text().toStdString();
    string country = ui->CustomerID_8->text().toStdString();
    string city = ui->CustomerID_7->text().toStdString();

    ProceduceCustomer update;
    update.AddData(&TableCustomer, id, name, contact, address, postalcode, country, city);

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
    StoreData("data.db", "StoreData/data.db");
}

void MainWindow::on_Change_4_clicked()
{

}

void MainWindow::on_Store_2_clicked()
{
    QString whatfind = QString::fromStdString(ui->comboBox->currentText().toStdString());
    QVariant value = ui->lineEdit_3->text();

    ProceduceProduct report;

    QString temp = report.PrintfReport(whatfind, value, TableProducts);

    ui->lineEdit->setText(temp);
}

void MainWindow::on_FakeData_clicked()
{
    Row temp;
    temp.insert("ProductName","Chais");
    temp.insert("SupplierID",1);
    temp.insert("CategoryID",1);
    temp.insert("Unit","10 boxes x 20 bags");
    temp.insert("Price",18);
    TableProducts._Data.insert(1, temp);
    //TableProducts.insert(1, temp);
    temp.clear();

    temp.insert("ProductName","Chang");
    temp.insert("SupplierID",1);
    temp.insert("CategoryID",1);
    temp.insert("Unit","24 - 12 oz bottles");
    temp.insert("Price",19);
    TableProducts._Data.insert(2, temp);
    //TableProducts.insertRow(temp);
    temp.clear();

    temp.insert("ProductName","Aniseed Syrup");
    temp.insert("SupplierID",1);
    temp.insert("CategoryID",2);
    temp.insert("Unit","12 - 550 ml bottles");
    temp.insert("Price",10);
    TableProducts._Data.insert(3, temp);
    //TableProducts.insertRow(temp);
    temp.clear();

    temp.insert("ProductName","Chef Anton's Cajun Seasoning");
    temp.insert("SupplierID",2);
    temp.insert("CategoryID",2);
    temp.insert("Unit","48 - 6 oz jars");
    temp.insert("Price",22);
    TableProducts._Data.insert(4, temp);
    //TableProducts.insertRow(temp);
    temp.clear();
}
