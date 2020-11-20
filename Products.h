#include "Common.h"
enum prodInfoType{ProductID = 0, Name, SupplierID, CategoryID, Unit, Price};


typedef std::map<prodInfoType, std::variant<int,std::string,double >> Product;
class Products {
    
    std::map<int, Product> _prodData;
public:
    std::map<int, Product> searchProductInfo(const prodInfoType, Product); // Search by Column Type and search Value
    int addProduct(Product);
    //void removeProduct(Product);
    //void logProductTransaction();
};

template<class T, class U, class Unique>
class testCast{
    Unique ID;
    std::map<int, T> _data;
public:
    std::map<int, T> searchInfo(U, T);
    int addRow(T);
};

template<class T, class U, class Unique>
std::map<int, T> testCast<T, U, Unique>::searchInfo(U info, T searchValue){
    std::map<int, T> ret;
    ret.clear();
    if(info = ID){
        auto id = seachValue[info];
    }
};