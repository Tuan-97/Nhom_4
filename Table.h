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

template<typename Row, typename Props, typename prpValue>
class Table {
    PropList<Props>         _PropsList;         // List of Props each Props is corresponding to a PropDetail Object
    PropPtrList<Props>      _ForeignPropsList   // List of Pointer to Props that is set to be Foreign Key
    const Props             _Primary;           // Unique key used to distinguise each row, assume an int;
    std::map<int, std::map<Props, prpValue>>    _Data;
public:
    Table(PropList<Props>, int);       // The List of Props and index of Primary Key in the List;
/*  some function that return info about table, may implement if possible*/
    PropDetail getPropDetail(Prop);         // get detail about specific props
    PropsList<Props> listProps();           // list all props;
    int getNoRow();                         // Number of Row;
/*========================================================================*/
    std::map<int, std::map<Props, prpValue>> searchInfo(Props, std::map<Props, prpValue>);
    int addRow(std::map<Props, prpValue>);
};

template<typename Row, typename Props, typename prpValue>
Table<Row, Props, prpValue>::Table(PropList<Props> List, int PrIndx)
    : _PropsList(List), _Primary(_PropsList[PrIndx].Type){

};

template<typename Row, typename Props, typename prpValue>
std::map<int, std::map<Props, prpValue>> Table<Row, Props, prpValue>::searchInfo(Props info, std::map<Props, prpValue> searchValue) {

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

template<typename Row, typename Props, typename prpValue>
int Table<Row, Props, prpValue>::addRow(std::map<Props, prpValue> newRow) {
    if(!seachInfo(_Primary, newRow).empty()) {
        return 1;
    }
    _Data[std::get<int>(newRow[_Primary])] = newRow;
    return 0;

};


