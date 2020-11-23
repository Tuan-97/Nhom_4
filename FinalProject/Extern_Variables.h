#ifndef EXTERN_VARIABLES_H
#define EXTERN_VARIABLES_H

#include "Class/soldproduct.h"
#include "Class/categories.h"
#include "Class/customer.h"
#include "Class/employees.h"
#include "Class/order.h"
#include "Class/orderdetails.h"
#include "Class/products.h"
#include "Class/shipper.h"
#include "Class/supplier.h"
//#include "GetDataClass/categoriesdata.h"

extern vector <SoldProduct> Product_Sold;
extern vector <Categories> Category_Buy;
extern vector <Customer> Customer_Buy;
extern vector <Order> Order_Buy;
extern vector <OrderDetails> OrderDetails_Buy;
extern vector <Products> Products_Buy;
extern vector <Shipper> Shipper_Buy;
extern vector <Supplier> Supplier_Buy;

#endif // EXTERN_VARIABLES_H
