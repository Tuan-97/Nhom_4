/*
 *  Purpose: Using object of this class to manage method of data Table Order
 *  Author: Ha Xuan Tuan
 */

#include "proceduceorder.h"

/*
 * Get Fist Date and Second Date value (integer).
 * Find in Table Order, which object have Date property inside Fist Date and Second Date
 * return Qstring about information of Orders that happened inside that time
 */

QString ProceduceOrder::PrintfReport(Table& _data, int first, int second){
    QString temp = "";
    auto ret = _data.filterByRange("OrderDate", first , second);
    int OrderID, CustomerID, EmployeeID, OrderDate, ShipperID;
    for(auto i = ret.begin(); i!=ret.end(); ++i){
        Row r = i.value();
        CustomerID  = r["CustomerID"].toInt();
        EmployeeID = r["EmployeeID"].toInt();
        OrderDate = r["OrderDate"].toInt();
        ShipperID = r["ShipperID"].toInt();
        temp = temp + "OrderID: " + QString::number(OrderID) + "\n---CustomerID: " + QString::number(CustomerID) +
        "\n---EmployeeID: " + QString::number(EmployeeID) + "\n---OrderDate: " + QString::number(OrderDate) +
        "\n---ShipperID: " + QString::number(ShipperID) + "\n" ;
   }
    return temp;
}


QString ProceduceOrder::PrintfReport(int id, Table _data){
    QString temp = "";
    auto ret = _data.filterByValue("OrderID", id);
    int OrderID, CustomerID, EmployeeID, OrderDate, ShipperID;
    for(auto i = ret.begin(); i!=ret.end(); ++i){
        Row r = i.value();
        CustomerID  = r["CustomerID"].toInt();
        EmployeeID = r["EmployeeID"].toInt();
        OrderDate = r["OrderDate"].toInt();
        ShipperID = r["ShipperID"].toInt();
        temp = temp + "OrderID: " + QString::number(OrderID) + "\n---CustomerID: " + QString::number(CustomerID) +
        "\n---EmployeeID: " + QString::number(EmployeeID) + "\n---OrderDate: " + QString::number(OrderDate) +
        "\n---ShipperID: " + QString::number(ShipperID) + "\n" ;
   }
    return temp;
}


void ProceduceOrder::UpdateData(Table* tabledata, int orderid, int customerid, int employeeid, int date, int shipperid){
    TableData tempdata;
    Row temp;

    //Find Row has same id in Table TableOrder, it return into map TableData
    tempdata = tabledata->filterByValue("OrderID", orderid);

    //Assign second key of first element of map TableData to a element of map Row
    temp = tempdata[0];

    temp["CustomerID"] = customerid;
    temp["EmployeeID"] = employeeid;
    temp["OrderDate"] = date;
    temp["ShipperID"] = shipperid;


    int err = tabledata->updateRow(temp);

    if(err == 0){
        //There is no error

    } else {
        //Error occured!
    }
}
void ProceduceOrder::AddData(Table* tabledata,int orderid, int customerid, int employeeid, int date, int shipperid){
    Row temp;

    temp.insert("OrderID", orderid);
    temp.insert("CustomerID", customerid);
    temp.insert("EmployeeID", employeeid);
    temp.insert("OrderDate", date);
    temp.insert("ShipperID", shipperid);

    int err = tabledata->insertRow(temp);
    if(err == 0){
        //There is no error

    } else {
        //Error occured!
    }
}
void ProceduceOrder::DeleteData(Table* tabledata, int orderid){
    int err = tabledata->removeRow(orderid);

    if (err == 0){
        // No error
    } else {
        // There is error
    }
}
