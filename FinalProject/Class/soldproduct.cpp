#include "soldproduct.h"

SoldProduct::SoldProduct()
{

}

//string name, int quantity, double price, int customer_id, string date
/*
 *  We need to create an object of class SoldProduct. In first, this object only need Customer ID and Date.
 *  The other attributes like Name, Quantity, Price of Product will be added later.
 *  Author: Ha Xuan Tuan
 */
SoldProduct::SoldProduct(int customer_id, string date){
    Sold_Customer_ID = customer_id;
    Sold_Date = date;
}

/*
 *  In case Customer only buy one type of Product, we will use this constuctor to create an object of class SoldProduct
 *  Author: Ha Xuan Tuan
 */
SoldProduct::SoldProduct(string name, int quantity, double price, int customer_id, string date){
    Sold_Product_Name.push_back(name);
    Sold_Product_Quantity.push_back(quantity);
    Sold_Product_Price.push_back(price);
    Sold_Customer_ID = customer_id;
    Sold_Date = date;
}

/*
 *  Create a method get Customer ID because Customer ID is private.
 *  Author: Ha Xuan Tuan
 */
int SoldProduct::GetCustomerID(){
    return this->Sold_Customer_ID;
}

/*
 *  After we create an object of class SoldProduct by constructor SoldProduct(int customer_id, string date).
 *  We use this method to add each property of each Product which Customer bought.
 *  Author: Ha Xuan Tuan
 */
void SoldProduct::AddProduct(string name, int quantity, double price){
    this->Sold_Product_Name.push_back(name);
    this->Sold_Product_Quantity.push_back(quantity);
    this->Sold_Product_Price.push_back(price);
}
