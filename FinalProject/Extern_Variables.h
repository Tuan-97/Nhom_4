#ifndef EXTERN_VARIABLES_H
#define EXTERN_VARIABLES_H

#include <map>

#include "Class/soldproduct.h"
#include "table.h"

/*
 *  Purpose: Define Variables out side method in mainwindow.cpp
 *  Author: Ha Xuan Tuan
 */

extern map <int, SoldProduct> Product_Sold;
extern SoldProduct Order_Temp;
extern int SoldProductID;
extern int LastOrderID;
extern int LastOrderDetailID;
extern Table TableCustomer("Customer");
extern Table TableCategories("Categories");
extern Table TableEmployees("Employees");
extern Table TableOrderDetails("OrderDetails");
extern Table TableOrders("Order");
extern Table TableProducts("Products");
extern Table TableShippers("Shippers");
extern Table TableSuppliers("Suppliers");

#endif // EXTERN_VARIABLES_H
