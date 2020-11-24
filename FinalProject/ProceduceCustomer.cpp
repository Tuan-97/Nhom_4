#include "ProceduceCustomer.h"

ProceduceCustomer::ProceduceCustomer()
{
}

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

void ProceduceCustomer::DeleteData(Table* tabledata, int id){
    int err = tabledata->removeRow(id);

    if (err == 0){
        // No error
    } else {
        // There is error
    }
}

void ProceduceCustomer::UpdateData(Table *tabledata, int id, string name, string contact, string address, string city, string country, string postalcode){
    TableData tempdata;
    Row temp;

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

