#include "customer.h"

Customer::Customer()
{

}
Customer::Customer(int id, string name, string contact, string address, string city, string postalcode, string country){
    this->Customer_ID = id;
    this->Customer_Name = name;
    this->Customer_Contact = contact;
    this->Customer_Address = address;
    this->Customer_City = city;
    this->Customer_PostalCode = postalcode;
    this->Customer_Country = country;
}
