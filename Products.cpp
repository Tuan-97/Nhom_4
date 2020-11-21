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
    for(auto const& itProd : _prodData){
        // Use info to get the right type in Product
        // variant will auto compare if both has same type index
        // TODO: rewite it to use std accumulate
        if(itProd.second.at(info) == searchValue.at(info)){
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