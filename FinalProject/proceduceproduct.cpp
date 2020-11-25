/*
 *  Purpose: Using object of this class to manage method of data Table Product
 *  Author: Ha Xuan Tuan
 */

#include "proceduceproduct.h"
#include <QString>
#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

ProceduceProduct::ProceduceProduct()
{
}

/*
 * It return a temp of combination from all parameter input
 */
QString combine(int a, QString b, int c, int d, QString e, double f){
    QString temp = "ProductID: " + QString::number(a) + "\n---ProductName: " + b + "\n---SupplierID: " + QString::number(c)
             + "\n---CategoryID: " + QString::number(d) + "\n---Unit: " + e + "\n---Price: " + QString::number(f);
    return temp;
}

/*
 * Get all property data of Product.
 * Depend of what we get, find all products have that property.
 * Return QString include information about what product found.
 */
QString ProceduceProduct::PrintfReport(QString whatfind, QVariant value, Table tableproduct){
    int ProductID;
    QString ProductName;
    int SupplierID;
    int CategoryID;
    QString Unit;
    double Price;

    bool find = true;
    // Nghia : rewrite to be shorter
    auto& tableProduct = tableproduct;
        // filterByValue only need string (Column Name) and Variant that suppose to contain the right type to filter
        auto result = tableProduct.filterByValue(whatfind, value);
        if(!result.empty()){
            auto it = result.begin().value();
            ProductID =     it["ProductID"].toInt();
            ProductName =   it["ProductName"].toString();
            SupplierID =    it["SupplierID"].toInt();
            CategoryID =    it["CategoryID"].toInt();
            Unit =  it["CategoryID"].toString();
            Price = it["Price"].toDouble();
        }else{
            find = false;
        }

    if (find == true){
        //Found
        return combine(ProductID, ProductName, SupplierID, CategoryID, Unit, Price);
    } else {
        //Not Found
        return "Not Found!";
    }
}
