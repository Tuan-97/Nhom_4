#include "supplier.h"

Supplier::Supplier()
{

}
/*
 * int Supplier_ID;
    string Supplier_Name, Supplier_Contact, Supplier_Address, Supplier_City, Supplier_PostalCode, Supplier_Country, Supplier_Phone;
    */
Supplier::Supplier(int id, string name, string contact, string address, string city, string postalcode, string country, string phone){
    this -> Supplier_ID = id;
    this -> Supplier_Name = name;
    this -> Supplier_Contact = contact;
    this -> Supplier_Address = address;
    this -> Supplier_City = city;
    this -> Supplier_PostalCode = postalcode;
    this -> Supplier_Country = country;
    this -> Supplier_Phone = phone;
}
