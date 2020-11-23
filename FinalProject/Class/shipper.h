#ifndef SHIPPER_H
#define SHIPPER_H
#include <string>
using namespace std;

class Shipper
{
private:
    int Shipper_ID;
    string Shipper_Name, Shipper_Phone;
public:
    Shipper();
    Shipper(int, string, string);
};

#endif // SHIPPER_H
