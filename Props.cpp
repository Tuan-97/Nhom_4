#include "Props.h"

gnrDetail::gnrDetail(std::vector<std::string> Description, bool Foreign)
    : About(Description[0]), plName(Description[1]), plType(Description[2]), isForeign(Foreign){};

gnrDetail::gnrDetail(std::string sAbout, std::string sName, std::string sType, bool Foreign)
    : About(sAbout), plName(sName), plType(sType), isForeign(Foreign){};

gnrDetail::gnrDetail(const gnrDetail& ref) 
    : gnrDetail(ref.About, ref.plName, ref.plType, ref.isForeign){};

Constraints::Constraints(IntrinsicType Type, std::vector<bool> bList, const Foreign* Foreign = nullptr)
    : PropType(Type), _isUnique(bList[0]), _isPrimary(bList[1]), _isForeign(Foreign){};

Constraints::Constraints(const Constraints& ref)
    : Constraints(
            ref.iType, 
            std::vector<bool>({
                ref.isPrimary(), 
                ref.isUnique(), 
                ref.isForeignKey()}), 
            ref.getFrgDetail()) {};

bool Constraints::isPrimary() const{
    return _isPrimary;
}

bool Constraints::isUnique() const{
    return _isUnique;
}

bool Constraints::isForeignKey() const{
    return _isForeign;
}

bool Constraints::checkInputLogic(const Constraints& obj){
    if(obj.isPrimary()){
        if(!obj.isUnique()) return false;
    }
    if(obj.isForeignKey()){
        if(obj.getFrgDetail() == nullptr)
        return false;
    }
    return true;
}
