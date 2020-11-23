#ifndef SUPPLIER_H
#define SUPPLIER_H
#include <string>
using namespace std;

class Supplier
{
private:
    int Supplier_ID;
    string Supplier_Name, Supplier_Contact, Supplier_Address, Supplier_City, Supplier_PostalCode, Supplier_Country, Supplier_Phone;
public:
    Supplier();
    Supplier(int, string, string, string, string, string, string, string);
};

#endif // SUPPLIER_H
