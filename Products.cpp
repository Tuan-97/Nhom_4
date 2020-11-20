#include "Products.h"

// function return empty map if no match found
std::map<int, Product> Products::searchProductInfo(const prodInfoType info, Product searchValue){
    std::map<int, Product> ret;
    ret.clear();
    // if product ID => unique, return if found right away;
    if(info == ProductID){
        int ID = std::get<int>(searchValue[info]);
        auto it = _prodData.find(ID);
        if(it != _prodData.end()){
            ret[ID] = it->second;
        }
        return ret;
    }
    
    bool found = false;
    for(auto const& itProd : _prodData){
        // Use info to get the right type to cast when compare
        // Stack all case with same data type into one

        switch(info){
        case SupplierID:
        case CategoryID:
            found = std::get<int>(itProd.second.at(info)) 
                    == std::get<int>(searchValue.at(info));
            break;
        case Unit:
        case Name:
            found = std::get<std::string>(itProd.second.at(info)) 
                    == std::get<std::string>(searchValue.at(info));
            break;
        case Price:
            found = std::get<double>(itProd.second.at(info)) 
                    == std::get<double>(searchValue.at(info));
            break;
        default:
            break;
        }
        if(found){
            ret[itProd.first] = itProd.second;
        }
    }
    return ret;
}

int Products::addProduct(Product newProd){ // Return 0 if no error
    
    // check if product already exist by product ID, use existing function to check
    if(searchProductInfo(ProductID ,newProd).empty()){
       return 1; 
    }
    // Check for data requirement i.e name not blank, unit not bank, etc;
    
    // add Product
    int newID = std::get<int>(newProd[ProductID]);
    _prodData[newID] = newProd;
    return 0;
}