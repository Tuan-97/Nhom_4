#include "Common.h"
#include "Props.h"


/*
    Props = enum that represent all possible columns or all props of an entity in database
    prpValue = a variant that can hold data that match the type of a props

    Each Row/Entity is represent by a map whose key is a Props that is unique.
    That props is used to represent unique columns

    Entire Database is represent by a map whose key is the unique Props as sad above
    and the value is the entity whose unique props must match the key

    searchInfo = filter base on one of Props in database
    addRow = add new entity to the database
*/

template<typename Props, typename prpValue>
class Table {
    PropList<Props>         _PropsList;         // List of Props each Props is corresponding to a PropDetail Object
    PropPtrList<Props>      _ForeignPropsList;   // List of Pointer to Props that is set to be Foreign Key
    std::map<Props, unqFrgKeyValue> _FrnUnqValuesList;   // list of unique foreign key value;
    const Props             _Primary;           // Unique key used to distinguise each row, assume an int;
    std::map<int, std::map<Props, prpValue>>    _Data;
public:
    Table(PropList<Props>, int);       // The List of Props and index of Primary Key in the List;
/*  some function that return info about table, may implement if possible*/
    PropDetail getPropDetail(Prop);         // get detail about specific props
    const unqFrgKeyValue& getUnqValByFrgProp(Props);
    PropsList<Props> listProps();           // list all props;
    int getNoRow();                         // Number of Row;

/*========================================================================*/
    std::map<int, std::map<Props, prpValue>> searchInfo(Props, std::map<Props, prpValue>);
    int addRow(std::map<Props, prpValue>);
    const PropPtrList<Props>& getFrgList()  const   // return _ForeignPropList;
    const unqFrgKeyValue& getUnqOfProp(Props) const // retrieve value from _FrnUnqValuesList, Props must be foreign;
};

template<typename Props, typename prpValue>
Table<Props, prpValue>::Table(PropList<Props> List, int PrIndx)
    : _PropsList(List), _Primary(_PropsList[PrIndx].Type){

};

template<typename Props, typename prpValue>
std::map<int, std::map<Props, prpValue>> Table<Props, prpValue>::searchInfo(Props info, std::map<Props, prpValue> searchValue) {

    std::map<int, std::map<Props, Type>> ret;
    ret.clear();
    if (info == _Primary) {
        int ID = std::get<int>(_Data.find(searchValue[info]));
        auto it = _Data.find(ID);
        if (it != _Data.end()) {
            ret[ID] = it->second;
        }
        return ret;
    }
    for (const auto itData : _Data) {
        if (itData.second.at(info) == searchValue.at(info)) {
            ret[itData.first] = itData.second;
        }
    }
    return ret;
};

template<typename Props, typename prpValue>
int Table<Props, prpValue>::addRow(std::map<Props, prpValue> newRow) {
    if(!seachInfo(_Primary, newRow).empty()) {
        return 1;
    }
    _Data[std::get<int>(newRow[_Primary])] = newRow;
    return 0;

};

/* 
Description: Class which supply data to Table constructor.

A table need to have the list of column and detail, constraints come with it. The constraint
is requirement that value must fit certain type or its possible value must come from other 
table or all row/entity must be distinct, i.e unique .There is other custom constraint such 
as value must belong to a certain set , ex [10, -10] but such thing is not considered in this 
case

Object of this class is responsible for management of those Data
It also 
*/
template<typename Props, typename prpValue>
struct TableInitData{
    /*==============Getter Methots==================*/
    const PropList<Props>& getDetailList();         // return _DetailList;
    const PropPtrList<Props>& getFrgProps();        // return _ForeignPropsList
    /*==============================================*/
    void addNewProps(Props, PropDetail<Props>);     // addNewProps to _DetailList;
    void removeProps(Props);
    void updateDetail(Props, PropDetai);
    
private:
    PropList<Props> _DetailList;
    PropPtrList<Props> _ForeignPropsList
    PropPtrList<Props> gatherForeignProps();        // construct a List (map) of Foreign Key from _DetailList
};
