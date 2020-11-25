/*
 *  Purpose: Using object of this class to manage method of data Table Customer
 *  Author: Ha Xuan Tuan
 */
#include "ProceduceCustomer.h"
#include <QString>

ProceduceCustomer::ProceduceCustomer()
{
}

/*
 * Get data from UI, after then.
 * Insert a row data into Table Data of Customer.
 * Using a pointer point into an object of Table Customer
 */
void ProceduceCustomer::AddData(Table* tabledata, int id, string name, string contact, string address, string city, string country, string postalcode){
    Row temp;

    temp.insert("CustomerID", id);
    temp.insert("CustomerName", QString::fromStdString(name));
    temp.insert("ContactName", QString::fromStdString(contact));
    temp.insert("Address", QString::fromStdString(address));
    temp.insert("City", QString::fromStdString(city));
    temp.insert("Country", QString::fromStdString(country));
    temp.insert("PostalCode", QString::fromStdString(postalcode));

    int err = tabledata->insertRow(temp);
    if(err == 0){
        //There is no error

    } else {
        //Error occured!
    }
}

/*
 * Get ID of Customer from UI, after then.
 * Delete Row data corresponding CustomerID
 */
void ProceduceCustomer::DeleteData(Table* tabledata, int id){
    int err = tabledata->removeRow(id);

    if (err == 0){
        // No error
    } else {
        // There is error
    }
}

/*
 * Get all property data of Customer.
 * If any data is not emty. Modify the data of Table Customer which has first key is CustomerID(is not allowed emty)
 * Which data is emty, not changed.
 */
void ProceduceCustomer::UpdateData(Table *tabledata, int id, string name, string contact, string address, string city, string country, string postalcode){
    TableData tempdata;
    Row temp;
    QString tempstr = "postal code is" + QString::fromStdString(postalcode);
    qDebug() << tempstr;
    //Find Row has same id in Table TableCustomer, it return into map TableData
    tempdata = tabledata->filterByValue("CustomerID", id);

    //Assign second key of first element of map TableData to a element of map Row
    temp = tempdata[0];

    if (name != ""){
        temp["CustomerName"] = QString::fromStdString(name);
    }
    if (contact != ""){
        temp["ContactName"] = QString::fromStdString(contact);
    }
    if (address != ""){
        temp["Address"] = QString::fromStdString(address);
    }
    if (postalcode != ""){
        temp["PostalCode"] = QString::fromStdString(postalcode);
    }
    if (country != ""){
        temp["Country"] = QString::fromStdString(country);
    }
    if (city != ""){
        temp["City"] = QString::fromStdString(city);
    }

    int err = tabledata->updateRow(temp);

    if(err == 0){
        //There is no error

    } else {
        //Error occured!
    }
}

/*
 * Get all property data of Customer.
 * Depend of what we get, find all Customer have that property.
 * Return QString include information about what product found.
 */
QString ProceduceCustomer::PrintfReport(int id, Table tablecustomer){
    int CustomerID;
    QString CustomerName;
    QString ContactName;
    QString Address;
    QString City;
    QString PostalCode;
    QString Country;

    CustomerID = id;
    bool find = true;
    // Nghia : rewrite to be shorter
    auto& tableCustomer = tablecustomer;
        // filterByValue only need string (Column Name) and Variant that suppose to contain the right type to filter
        auto result = tableCustomer.filterByValue("CustomerID", CustomerID);

        if(!result.empty()){
            auto it = result.begin().value();
            CustomerName =     it["CustomerName"].toString();
            ContactName =   it["ContactName"].toString();
            Address =    it["Address"].toString();
            City =    it["City"].toString();
            PostalCode =  it["PostalCode"].toString();
            Country = it["Country"].toString();
        }else{
            find = false;
        }
    QString temp = "CustomerID: " + QString::number(CustomerID) + "\n---ProductName: " + CustomerName +
            "\n---ContactName: " + ContactName + "\n---Address: " + Address + "\n---City: " + City +
            "\n---PostalCode: " + PostalCode + "\n---Country: " + Country;
    if (find == true){
        //Found
        return (temp);
    } else {
        //Not Found
        return "Not Found!";
    }
}

