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
    bool    isForeign;      // does props work Foreign Key?
    gnrDetail(std::vector<std::string>, bool);              // either supply a vector
    gnrDetail(const std::string, const std::string, const std::string, bool); // or each string individually
    gnrDetail(const gnrDetail&);
    
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

class Constraints : public PropType{   //Constraint of Props;
    bool    _isUnique;
    bool    _isPrimary;
    bool    _isForeign;
    const Foreign* frgDetail;
    static bool checkInputLogic(const Constraints&);
public:
    Constraints(IntrinsicType, std::vector<bool>, const Foreign*);
    Constraints(const Constraints&);
    bool isPrimary() const;
    bool isUnique() const;
    bool isForeignKey() const;
    const Foreign* getFrgDetail() const;
};


class Foreign{  //use inside Constraint if props is Foreign Key;
    IntrinsicType                   ParentType;         // underlying Type that Parent use
    bool                            isParent;           // is Table parent Table;
    const unqFrgKeyValue&           unqValues;          // List of distinct value, get from Parent;

public:
    Foreign(IntrinsicType, bool, const unqFrgKeyValue);
};

template<typename prpType> 
using PropList = std::map<prpType, PropDetail<prpType>>; // List of Props each Props is corresponding to a PropDetail Object

template<typename prpType> 
using PropPtrList = std::map<prpType, const PropDetail<prpType>&>; // List of Pointer to Props that is set to be Foreign Key