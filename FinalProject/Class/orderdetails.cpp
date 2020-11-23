#include "orderdetails.h"

OrderDetails::OrderDetails()
{

}
OrderDetails::OrderDetails(int details_id, int order_id, int product_id, int quantity){
    this->OderDetails_ID = details_id;
    this->Order_ID = order_id;
    this->Product_ID = product_id;
    this->OderDetails_Quantity = quantity;
}
