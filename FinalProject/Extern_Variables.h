#ifndef EXTERN_VARIABLES_H
#define EXTERN_VARIABLES_H

#include <map>

#include "Class/soldproduct.h"
/*#include "Class/categories.h"
#include "Class/customer.h"
#include "Class/employees.h"
#include "Class/order.h"
#include "Class/orderdetails.h"
#include "Class/products.h"
#include "Class/shipper.h"
#include "Class/supplier.h"*/

/*
 *  Purpose: Define Variables out side method in mainwindow.cpp
 *  Author: Ha Xuan Tuan
 */

extern map <int, SoldProduct> Product_Sold;
extern SoldProduct Order_Temp;
extern int SoldProductID;

#endif // EXTERN_VARIABLES_H
