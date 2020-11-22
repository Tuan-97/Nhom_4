#include "Common.h"

typedef std::vector<TypeVariant> unqFrgKeyValue;     // Currently can't think of anything better than vector
/* Props to use inside Table*/
// Describe Prop's General Detail
enum    IntrinsicType{UINT, INT, STR, UDOUBLE, DOUBLE , DATE, BOOL};
typedef std::variant<unsigned int, int, std::string, double, time_t, bool> TypeVariant; 

struct gnrDetail{
    std::string About;      // what props represent
    std::string plName;     // Name of the props to user
    std::string plType;     // Name of type represented to user
    bool    isForeign;      // is props Foreign Key?   
};

template<typename prpType> 
class PropDetail{

public:
    PropDetail(prpType, gnrDetail);
    const gnrDetail GeneralDetail;      // General Detail 
    const prpType Type;                 // enum variable define type of this props, this is supplied by Model
};

template<typename prpType> 
PropDetail<prpType>::PropDetail(prpType type, gnrDetail gDetail) 
    : Type(type), GeneralDetail(gDetail){
};

struct PropType{
    const IntrinsicType iType;
    PropType(IntrinsicType type) : iType(type){} ;
};

class Constraint : public PropType{   //Constraint of Props;
    bool    isUnique;       //
    bool    isPrimary;
    bool    isForeign;
    Foreign* frgDetail;
    bool checkForeignType();
public:
    Constraint(IntrinsicType, std::vector<bool>, Foreign*);
};


class Foreign{  //use inside Constraint if props is Foreign Key;
    IntrinsicType                   ParentType;         // underlying Type that Parent use
    bool                            isParent;           // is Table parent Table;
    const unqFrgKeyValue&           unqValues;          // List of distinct value, get from Parent;
};

template<typename prpType> 
using PropList = std::map<prpType, PropDetail<prpType>>; // List of Props each Props is corresponding to a PropDetail Object

template<typename prpType> 
using PropPtrList = std::map<prpType, const PropDetail<prpType>&>; // List of Pointer to Props that is set to be Foreign Key