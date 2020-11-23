#ifndef PRODUCTS_H
#define PRODUCTS_H
#include <string>
using namespace std;

class Products
{
private:
    int Product_ID;
    string Product_Name, Product_Unit, Product_Supplier, Product_Category;
    double Product_Price;
public:
    Products();
    Products(int, string, string, string, string, double);
};

#endif // PRODUCTS_H
