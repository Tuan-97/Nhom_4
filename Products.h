#include "Common.h"
enum prodInfoType{ProductID = 0, Name, SupplierID, CategoryID, Unit, Price}; //Type
typedef std::map<prodInfoType, std::variant<int,std::string,double >> Product;

class Products {
    
    std::map<int, Product> _prodData;
public:
    std::map<int, Product> searchProductInfo(const prodInfoType, Product); // Search by Column Type and search Value
    int addProduct(Product);
    //void removeProduct(Product);
    //void logProductTransaction();
};

