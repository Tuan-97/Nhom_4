#include "table.h"
#include <QDebug>
int Table::insertRow(Row& newRow){
    _Helper.Insert(newRow);
    _Data[newRow[_PrmField].toInt()] = newRow;
    return 0;
}
int Table::removeRow(int key){
    _Helper.RemoveFromTable(key, _PrmField);
    _Data.remove(key);
    return 0;
}
int Table::updateRow(Row& mRow){
    int key = mRow[_PrmField].toInt();
    if(_Data.find(key) != _Data.end()){
        _Data[key] = mRow;
        return 0;
    }
    _Helper.UpdateRow(mRow);
    return 1;
}
const QString& Table::getTableName(){
    return _Name;
};

TableData Table::filterByValue(QString Col, QVariant Value) {

    return _Helper.filterByValue(Col, Value);
}
TableData Table::filterByRange(QString Col, QVariant Lower, QVariant Upper) {
    return _Helper.filterByRange(Col, Lower, Upper);
};

Table::Table(QString Name)
    : _Helper(Name), _Name(Name), _Data(_Helper.getFullData()),
      _Info(TableHelper::getInfo(Name))
{
};

