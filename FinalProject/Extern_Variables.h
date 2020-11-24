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

#endif // EXTERN_VARIABLES_H
