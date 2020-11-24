#include "proceduceproduct.h"
#include <QString>
#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

ProceduceProduct::ProceduceProduct()
{
}

QString combine(int a, QString b, int c, int d, QString e, double f){
    QString temp = "ProductID: " + QString::number(a) + "---ProductName: " + b + "---SupplierID: " + QString::number(c)
             + "---CategoryID: " + QString::number(d) + "---Unit: " + e + "---Price: " + QString::number(f);
    return temp;
}

QString ProceduceProduct::PrintfReport(QString whatfind, QVariant value, Table tabelproduct){
    int ProductID;
    QString ProductName;
    int SupplierID;
    int CategoryID;
    QString Unit;
    double Price;

    bool find = true;

    if (whatfind == "ProductID"){
        unsigned int id = (unsigned int) value.toInt();

        auto it{ tabelproduct._Data.find(id) };
        if (it != std::end( tabelproduct._Data ) ){
            ProductName = tabelproduct._Data[id]["ProductName"].toString();
            SupplierID = tabelproduct._Data[id]["SupplierID"].toInt();
            CategoryID = tabelproduct._Data[id]["CategoryID"].toInt();
            Unit = tabelproduct._Data[id]["Unit"].toString();
            Price = tabelproduct._Data[id]["Price"].toDouble();
        } else {
            //Not found
            find = false;
        }



    } else {
        if(whatfind == "ProductName"){
            ProductName = value.toString();

            for(unsigned int i; i < (unsigned int)tabelproduct._Data.size(); i++){
                if(ProductName == tabelproduct._Data[i]["ProductName"].toString()){
                    ProductID = (int)i;
                    SupplierID = tabelproduct._Data[i]["SupplierID"].toInt();
                    CategoryID = tabelproduct._Data[i]["CategoryID"].toInt();
                    Unit = tabelproduct._Data[i]["Unit"].toString();
                    Price = tabelproduct._Data[i]["Price"].toDouble();
                    break;
                } else {
                    //Not found
                    find = false;
                }
            }
        } else {
            if(whatfind == "SupplierID"){
                SupplierID = value.toInt();

                for(unsigned int i; i < (unsigned int)tabelproduct._Data.size(); i++){
                    if(SupplierID == tabelproduct._Data[i]["SupplierID"].toInt()){
                        ProductID = (int)i;
                        ProductName = tabelproduct._Data[i]["ProductName"].toString();
                        CategoryID = tabelproduct._Data[i]["CategoryID"].toInt();
                        Unit = tabelproduct._Data[i]["Unit"].toString();
                        Price = tabelproduct._Data[i]["Price"].toDouble();
                        break;
                    } else {
                        //Not found
                        find = false;
                    }
                }
            } else {
                if(whatfind == "CategoryID"){
                    CategoryID = value.toInt();

                    for(unsigned int i; i < (unsigned int)tabelproduct._Data.size(); i++){
                        if(CategoryID == tabelproduct._Data[i]["ProductName"].toInt()){
                            ProductID = (int)i;
                            ProductName = tabelproduct._Data[i]["ProductName"].toString();
                            SupplierID = tabelproduct._Data[i]["SupplierID"].toInt();
                            Unit = tabelproduct._Data[i]["Unit"].toString();
                            Price = tabelproduct._Data[i]["Price"].toDouble();
                            break;
                        } else {
                            //Not found
                            find = false;
                        }
                    }
                } else {
                    if(whatfind == "Unit"){
                        Unit = value.toString();

                        for(unsigned int i; i < (unsigned int)tabelproduct._Data.size(); i++){
                            if(Unit == tabelproduct._Data[i]["Unit"].toString()){
                                ProductID = (int)i;
                                ProductName = tabelproduct._Data[i]["ProductName"].toString();
                                SupplierID = tabelproduct._Data[i]["SupplierID"].toInt();
                                CategoryID = tabelproduct._Data[i]["CategoryID"].toInt();
                                Price = tabelproduct._Data[i]["Price"].toDouble();
                                break;
                            } else {
                                //Not found
                                find = false;
                            }
                        }
                    } else {
                        if(whatfind == "Price"){
                            Price = value.toDouble();

                            for(unsigned int i; i < (unsigned int)tabelproduct._Data.size(); i++){
                                if(Price == tabelproduct._Data[i]["Price"].toDouble()){
                                    ProductID = (int)i;
                                    ProductName = tabelproduct._Data[i]["ProductName"].toString();
                                    SupplierID = tabelproduct._Data[i]["SupplierID"].toInt();
                                    CategoryID = tabelproduct._Data[i]["CategoryID"].toInt();
                                    Unit = tabelproduct._Data[i]["Unit"].toString();
                                    break;
                                } else {
                                    //Not found
                                    find = false;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if (find == true){
        //Found
        return combine(ProductID, ProductName, SupplierID, CategoryID, Unit, Price);
    } else {
        //Not Found
        return "Not Found!";
    }
}
