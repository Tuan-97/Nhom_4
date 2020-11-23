#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
using namespace std;

class Customer
{
private:
    int Customer_ID;
    string Customer_Name, Customer_Contact, Customer_Address, Customer_City, Customer_PostalCode, Customer_Country;
public:
    Customer();
    Customer(int, string, string, string, string, string, string);
};

#endif // CUSTOMER_H
