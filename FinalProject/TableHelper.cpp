#include "TableHelper.h"

TableHelper::TableHelper(Table * ptr): _tablePtr(ptr), _Name(ptr->getTableName())
{

};

TableData TableHelper::FilterByValue(QString Col, QVariant Value){

};

TableData TableHelper::FilterByRange(QString Col, QVariant Lower, QVariant Upper){
    TableData data;
    QSqlQuery qry;
    prepareSelectQuery(qry, Col, Lower, Upper);

    qry.exec();
    Row r;
    while(qry.next()){
        r.clear();
        for(auto i = 0; i < int(_FieldName.size()); i++){
            r[_FieldName[i]] = qry.value(i);
        }
        data[qry.value(0).toInt()] = r;
    }
    return data;
};

bool TableHelper::isValidCall(Table* ref){
    return ref == _tablePtr;
};

TableInfo TableHelper::getTableInfo(){
    TableInfo Info;
    QSqlQuery qry(QString("PRAGMA table_info(%1)").arg(_Name));
    while(qry.next()){
        Info[qry.value(1).toString()]
                = std::vector<QVariant>({qry.value(2), qry.value(3), qry.value(5)});
    }
    return Info;
}

void TableHelper::prepareSelectQuery(QSqlQuery& qry, QString Col, QVariant Value){
    // Clear a String in format " COL1, COL2, COL3, ..."
    QString colList = "";
    for(auto i = _FieldName.begin(); i !=_FieldName.end(); ++i){
        colList += QString(" %1,").arg(*i);
    }
    colList.chop(1); // remove the last , letter
    qry.prepare(QString("SELECT %1 FROM %2 WHERE %3 = : ?").arg(colList, _Name, Col));
    switch (checkType(_Info[Col][0].toString())) { // convert to true type;
    case INT:
        qry.bindValue(0, Value.toInt());
        break;
    case REAL:
        qry.bindValue(0, Value.toDouble());
        break;
    case TEXT:
        qry.bindValue(0, Value.toString());
    default: // can't compare;
        break;
    }
};

void TableHelper::prepareSelectQuery(QSqlQuery& qry, QString Col, QVariant Lower, QVariant Upper){
    // Clear a String in format " COL1, COL2, COL3, ..."
    QString colList = "";
    for(auto i = _FieldName.begin(); i !=_FieldName.end(); ++i){
        colList += QString(" %1,").arg(*i);
    }
    colList.chop(1); // remove the last ',' letter
    qry.prepare(QString("SELECT %1 FROM %2 WHERE %3 BETWEEN ? AND ?").arg(colList, _Name, Col));
    switch (checkType(_Info[Col][0].toString())) { // convert to true type;
    case INT:
        qry.bindValue(0, Lower.toInt());
        qry.bindValue(1, Upper.toInt());
        break;
    case REAL:
        qry.bindValue(0, Lower.toDouble());
        qry.bindValue(1, Upper.toDouble());
        break;
    default: // can't compare;
        break;
    }
};

void TableHelper::setFieldNameFromInfo(){
    _FieldName.clear();
    std::vector<QString> FieldName;
    for(auto i = _Info.begin(); i!= _Info.end(); i++){ // build the key list for table data;
        _FieldName.push_back(i.key());
    }
}
ColType checkType(QString typeStr){
    if(typeStr == "INTERGER") return INT;
    if(typeStr == "REAL") return REAL;
    if(typeStr == "TEXT") return TEXT;
    return UNKNOWN;
}


