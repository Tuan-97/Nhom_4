#include "table.h"
QMap<QString, int> Table::valueType["INTEGER"] = 0;
Table::Table(QString Name, TableData Data, TableInfo)
    :  _Name(Name), _Data(Data){
}

int Table::insertRow(Row& newRow){
    _Data[newRow[_PrmField].toInt()] = newRow;
    return 0;
}
int Table::removeRow(int key){
    _Data.remove(key);
    return 0;
}
int Table::updateRow(Row& mRow){
    int key = mRow[_PrmField].toInt();
    if(_Data.find(key) != _Data.end()){
        _Data[key] = mRow;
        return 0;
    }
    return 1;
}
const QString& Table::getTableName(){
    return _Name;
};

const TableData Table::filterByValue(QString Col, QVariant Value) const{
    QString Type = _Info[Col][3].toString();


}
