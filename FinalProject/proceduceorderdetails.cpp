#include "proceduceorderdetails.h"

ProceduceOrderDetails::ProceduceOrderDetails()
{

}

void ProceduceOrderDetails::UpdateData(Table* tabledata,int orderdetailid, int orderid, int productid, int quantity){
    TableData tempdata;
    Row temp;

    //Find Row has same id in Table TableOrder, it return into map TableData
    tempdata = tabledata->filterByValue("OrderID", orderid);

    //Assign second key of first element of map TableData to a element of map Row
    temp = tempdata[0];

    temp["OrderDetailID"] = orderdetailid;
    temp["OrderID"] = orderid;
    temp["ProductID"] = productid;
    temp["Quantity"] = quantity;


    int err = tabledata->updateRow(temp);

    if(err == 0){
        //There is no error

    } else {
        //Error occured!
    }
}
void ProceduceOrderDetails::AddData(Table* tabledata,int orderdetailid, int orderid, int productid, int quantity){
    Row temp;

    temp.insert("OrderDetailID", orderdetailid);
    temp.insert("OrderID", orderid);
    temp.insert("ProductID", productid);
    temp.insert("Quantity", quantity);

    int err = tabledata->insertRow(temp);
    if(err == 0){
        //There is no error

    } else {
        //Error occured!
    }
}
void ProceduceOrderDetails::DeleteData(Table* tabledata,int orderdetailid){
    int err = tabledata->removeRow(orderdetailid);

    if (err == 0){
        // No error
    } else {
        // There is error
    }
}

QString ProceduceOrderDetails::PrintfReport(int id, Table _data){
    QString temp = "";
    auto ret = _data.filterByValue("OrderDetailID", id);
    int OrderDetailID, OrderID, ProductID, Quantity;
    for(auto i = ret.begin(); i!=ret.end(); ++i){
        Row r = i.value();
        OrderDetailID  = r["OrderDetailID"].toInt();
        OrderID = r["OrderID"].toInt();
        ProductID = r["ProductID"].toInt();
        Quantity = r["Quantity"].toInt();
        temp = temp + "OrderDetailID: " + QString::number(OrderDetailID) + "\n---OrderID: " + QString::number(OrderID) +
        "\n---ProductID: " + QString::number(ProductID) + "\n---Quantity: " + QString::number(Quantity);
   }
    return temp;
}
