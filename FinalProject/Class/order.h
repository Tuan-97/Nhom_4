#ifndef ORDER_H
#define ORDER_H
#include <string>
using namespace std;

class Order
{
private:
    int Order_ID, Customer_ID, Employee_ID, Shipper_ID;
    string Order_Date;
public:
    Order();
};

#endif // ORDER_H
