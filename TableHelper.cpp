#include "TableHelper.h"

TableHelper::TableHelper(QString ref)
    : _Name(ref)
{

};

int TableHelper::Insert(Row & row){
    QSqlQuery qry;
    QString ColList;
    QString fValList;
    // getting ColumnList and Value list;
    for(auto field = _FieldName.begin(); field != _FieldName.end(); field++){
        ColList += QString(" %1,").arg(*field);
        fValList += "? ,";
    }
    ColList.chop(1); fValList.chop(1);
// INSERT INTO _Table_ (Col1, Col2, ... ) VALUE (Val1, Val2,...)
    qry.prepare(QString("INSERT INTO %1 (%2) VALUE (%3)").arg(_Name, ColList, fValList));
    int i = 0;
    for(auto field = _FieldName.begin(); field != _FieldName.end(); field++){

        switch (checkType(_Info[*field][0].toString())) {
        case INT:
            qry.bindValue(i, row[*field].toInt());
            break;
        case REAL:
            qry.bindValue(i, row[*field].toInt());
            break;
        case TEXT:
            qry.bindValue(i, quoteSql(row[*field].toString()));
            break;
        default:
            break;
        }
        i++;
    }
    qry.exec();
    return 0;
}

// Row r = new item to update; QString Col = name of Column that contain new Value in row;
int TableHelper::UpdateRow(Row& row){
    int ID = row[_PrimaryCol].toInt(); // get the Primary key's value;
    QString updateStr;
    std::vector<QVariant> updateValue;
    for(auto i = _FieldName.begin(); i !=_FieldName.end(); ++i){
        if (*i == _PrimaryCol) continue;
        updateStr = QString(" %1 = %2,").arg(*i);

    }
    QSqlQuery qry;
    // UDATE _Table_ SET _Column_ = _Value_ WHERE <CONDITION>
    qry.prepare(QString("UPDATE %1 SET %2 WHERE %3 = ?").arg(_Name, updateStr, _PrimaryCol));

    int i = 0;
    for(auto field = _FieldName.begin(); field != _FieldName.end(); field++){

        switch (checkType(_Info[*field][0].toString())) {
        case INT:
            qry.bindValue(i, row[*field].toInt());
            break;
        case REAL:
            qry.bindValue(i, row[*field].toInt());
            break;
        case TEXT:
            qry.bindValue(i, quoteSql(row[*field].toString()));
            break;
        default:
            break;
        }
        i++;
    }
    qry.bindValue(i, ID);
    qry.exec();
    return 0;
}
int TableHelper::RemoveFromTable(int ID, QString prmKey ){
    QSqlQuery qry;
    qry.prepare(QString("DELETE FROM %1 WHERE %2 = ?").arg(_Name, prmKey));
    qry.bindValue(0, ID);
    qry.exec();
    return 0;
}

TableData TableHelper::FilterByValue(QString Col, QVariant Value){
    TableData data;
    QSqlQuery qry;
    prepareSelectQuery(qry, Col, Value);    // prepare query;

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

TableInfo TableHelper::getInfo(QString TableName){
    TableInfo Info;
    QSqlQuery qry(QString("PRAGMA table_info(%1)").arg(TableName));
    // PRAGMA table_info will return a table with these rows by order
    // cid, name (column's name), type, notnull, dflt_value, pk (primarykey)
    // only get name, type, notnull and pk;
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

QString quoteSql(QString& orgStr) {
    return QString("'%1'").arg(orgStr);
};

