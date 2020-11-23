#ifndef SOLDPRODUCT_H
#define SOLDPRODUCT_H

#include <string>
#include <vector>

using namespace std;

/*
 *  SoldProduct class is create to store Sale Orders of Store
 *  It includes Properties like ID of Customer, Date of Order,
 *  Name, Quantity, Price of Product.
 *  Author: Ha Xuan Tuan
 */
class SoldProduct
{
private:
    /*
     *  Add 2 Attributes include Name of Customer and Date
     */
    int Sold_Customer_ID;
    string Sold_Date;
    /*
     *  Add 3 Properties of Product Sold include Name, Quantity and Price.
     *  Because it is possible that one Customer buy more than one Product so we create container vector for properties of Product
     */
    vector <string> Sold_Product_Name;
    vector <int> Sold_Product_Quantity;
    vector <double> Sold_Product_Price;

public:
    SoldProduct();
    SoldProduct(int, string);
    //string name, int quantity, double price, int customer_id, string date
    SoldProduct(string, int, double, int, string);
    void AddProduct(string, int, double);
    int GetCustomerID();
};

#endif // SOLDPRODUCT_H
