#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Extern_Variables.h"

/*#include "Class/soldproduct.h"
#include "Class/categories.h"
#include "Class/customer.h"
#include "Class/employees.h"
#include "Class/order.h"
#include "Class/orderdetails.h"
#include "Class/products.h"
#include "Class/shipper.h"
#include "Class/supplier.h"*/

vector <SoldProduct> Product_Sold;
vector <Categories> Category_Buy;
vector <Customer> Customer_Buy;
vector <Order> Order_Buy;
vector <OrderDetails> OrderDetails_Buy;
vector <Products> Products_Buy;
vector <Shipper> Shipper_Buy;
vector <Supplier> Supplier_Buy;

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

    Category_Buy = GetDataBase();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_CreateOrder_clicked()
{
    SoldProduct temp(ui->CustomerID->text().toInt(), ui->Date->text().toStdString());
    Product_Sold.push_back(temp);
}

void MainWindow::on_AddProduct_clicked()
{
    unsigned long last_element = (unsigned long)Product_Sold.size();
    string name = ui->ProductName->currentText().toStdString();
    int quantity = ui->Quantity->text().toInt();
    double price = ui->Price->text().toDouble();
    Product_Sold[last_element-1].AddProduct(name, quantity, price);
    ui->ProductName->clear();
    ui->Quantity->clear();
    ui->Price->clear();
    ui->OriginalPrice->clear();
}

void MainWindow::on_CreateOrder_2_clicked()
{
    unsigned long last_element = (unsigned long)Product_Sold.size();
    string name = ui->ProductName->currentText().toStdString();
    int quantity = ui->Quantity->text().toInt();
    double price = ui->Price->text().toDouble();
    Product_Sold[last_element-1].AddProduct(name, quantity, price);
    ui->ProductName->clear();
    ui->Quantity->clear();
    ui->Price->clear();
    ui->OriginalPrice->clear();
    ui->CustomerID->clear();
    ui->Date->clear();
}

void MainWindow::on_Try_clicked()
{
    QString i = QString::fromStdString(Category_Buy[0].Get_Name());
    ui->Try_In->setText(i);
    QString j = QString::fromStdString(Category_Buy[1].Get_Name());
    ui->Try_Out->setText(j);
}
