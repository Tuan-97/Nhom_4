#include "products.h"

Products::Products()
{

}
/*
 * int Product_ID;
    string Product_Name, Product_Unit, Product_Supplier, Product_Category;
    double Product_Price;*/
Products::Products(int id, string name, string unit, string supplier, string category, double price){
    this->Product_ID = id;
    this->Product_Name = name;
    this->Product_Unit = unit;
    this->Product_Supplier = supplier;
    this->Product_Category = category;
    this->Product_Price = price;
}
