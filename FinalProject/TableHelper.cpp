#include "TableHelper.h"

TableHelper::TableHelper(QString ref)
    : _Name(ref), _Info(TableHelper::getInfo(ref)), _FieldName(setFieldNameFromInfo()),
      _PrimaryCol(setPrmCol())
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
// INSERT INTO _Table_ (Col1, Col2, ... ) VALUES (Val1, Val2,...)
    qry.prepare(QString("INSERT INTO %1 (%2) VALUES (%3)").arg(_Name, ColList, fValList));
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
    qDebug() << qry.lastError();
    return 0;
}

// Row r = new item to update; QString Col = name of Column that contain new Value in row;
int TableHelper::UpdateRow(Row& row){
    int ID = row[_PrimaryCol].toInt(); // get the Primary key's value;
    QString updateStr;
    std::vector<QVariant> updateValue;
    //ColType type
    for(auto i = _FieldName.begin(); i !=_FieldName.end(); ++i){
        if (*i == _PrimaryCol) continue;

        updateStr += QString(" %1 = %2,").arg(*i,"?");
    }
    updateStr.chop(1);
    QSqlQuery qry;
    // UDATE _Table_ SET _Column_ = _Value_ WHERE <CONDITION>
    qDebug() << QString("UPDATE %1 SET %2 WHERE %3 = ?").arg(_Name, updateStr, _PrimaryCol);
    qry.prepare(QString("UPDATE %1 SET %2 WHERE %3 = ?").arg(_Name, updateStr, _PrimaryCol));

    int i = 0;
    for(auto field = _FieldName.begin(); field != _FieldName.end(); field++){
        if (*field == _PrimaryCol) continue;

        switch (checkType(_Info[*field][0].toString())) {
        case INT:
            qry.bindValue(i, row[*field].toInt());
            break;
        case REAL:
            qry.bindValue(i, row[*field].toDouble());
            break;
        case TEXT:
            qry.bindValue(i, quoteSql(row[*field].toString()));
            qDebug() << i;
            break;
        default:
            qDebug() << "default";
            break;
        }
        i++;
    }
    qDebug() << i;
    qry.bindValue(i, ID);
    qry.exec();
    qDebug() << qry.lastError();
    return 0;
}
int TableHelper::RemoveFromTable(int ID){
    QSqlQuery qry;
    qry.prepare(QString("DELETE FROM %1 WHERE %2 = ?").arg(_Name, _PrimaryCol));
    qry.bindValue(0, ID);
    qry.exec();
    qDebug() << qry.lastError();
    return 0;
}

TableData TableHelper::filterByValue(QString Col, QVariant Value){
    TableData data;
    QSqlQuery qry;
    prepareSelectQuery(qry, Col, Value);    // prepare query;
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

TableData TableHelper::filterByRange(QString Col, QVariant Lower, QVariant Upper){
    TableData data;
    QSqlQuery qry;
    prepareSelectQuery(qry, Col, Lower, Upper);

    qry.exec();
    //qDebug() << qry.lastError();
    Row r;
    //int count = 0;
    while(qry.next()){
        //count++;
        for(auto i = 0; i < int(_FieldName.size()); i++){
            r[_FieldName[i]] = qry.value(i);
        }
        //qDebug() << r[_PrimaryCol].toInt();

        data[r[_PrimaryCol].toInt()] = r;
        //qDebug()  << qry.value(1).toInt();

    }
    //qDebug() << QString("Count = %1").arg(count);
    return data;
};

TableInfo TableHelper::getInfo(QString TableName){
    TableInfo Info;
    QSqlQuery qry(QString("PRAGMA table_info(%1)").arg(TableName));
    // PRAGMA table_info will return a table with these rows by order
    // cid, name (column's name), type, notnull, dflt_value, pk (primarykey)
    // only get name, type, notnull and pk. Name is used as key in map, the rest
    // are put into a vector;
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

    qry.prepare(QString("SELECT %1 FROM %2 WHERE %3 = ?").arg(colList, _Name, Col));
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
    // Create a String in format " COL1, COL2, COL3, ..."
    QString colList = "";
    for(auto i = _FieldName.begin(); i !=_FieldName.end(); ++i){
        colList += QString(" %1,").arg(*i);
    }
    colList.chop(1); // remove the last ',' letter
    if(Lower.isNull() && Upper.isNull()){
        qry.prepare(QString("SELECT %1 FROM %2").arg(colList, _Name));
        return;
    }
    bool low = true, high = true; // use to decide to bind value or not;
    int posH = 0; // change index when binding depend on different cases

    QString whereClause;
    if(Lower.isNull()){
        whereClause = QString("WHERE %3 >= ?").arg(Col);
        low = false;  posH =0;                  // no lower limit
    }else if (Upper.isNull()){
        whereClause = QString("WHERE %3 <= ?").arg(Col);
        high = false;                   // no upper limit
    }else{
        whereClause = QString("WHERE %3 BETWEEN ? AND ?").arg(Col);
        posH = 1;
    }
    auto Type = checkType(_Info[Col][0].toString());
    qry.prepare(QString("SELECT %1 FROM %2 %3").arg(colList, _Name, whereClause));
    switch (Type) { // convert to true type;
    case INT:
        if(low) qry.bindValue(0, Lower.toInt());
        if(high)qry.bindValue(posH, Upper.toInt()); // bind if have upper limit
        break;
    case REAL:
        if(low) qry.bindValue(0, Lower.toDouble());
        if(high)qry.bindValue(posH, Upper.toDouble());; // bind if have upper limit
        break;
    default: // can't compare;

        break;
    }
};

std::vector<QString> TableHelper::setFieldNameFromInfo(){
    std::vector<QString> fn;
    fn.clear();
    for(auto i = _Info.begin(); i!= _Info.end(); i++){ // build the key list for table data;
        fn.push_back(i.key());
    }
    return fn;
}

TableData TableHelper::getFullData(){
    QVariant x, y;
    return filterByRange(_PrimaryCol, x, y);
};

QString TableHelper::setPrmCol(){
    for(auto i = _Info.begin(); i!= _Info.end(); i++){ // build the key list for table data;
        if(i.value()[2].toInt() == 1) return  i.key(); // PrimaryKey have 3rd element = 1
    }
    return "";  // should never reach here
}

QVariant TableHelper::getSumOfCol(QString Col , QVariant Lower, QVariant Upper){
    QSqlQuery qry;
    bool low = true, high = true; // use to decide to bind value or not;
    int posH = 0;


    QString whereClause;
    if(Lower.isNull()){
        whereClause = QString("WHERE %3 >= ?").arg(Col);
        low = false;  posH =0;                  // no lower limit
    }else if (Upper.isNull()){
        whereClause = QString("WHERE %3 <= ?").arg(Col);
        high = false;                   // no upper limit
    }else{
        whereClause = QString("WHERE %3 BETWEEN ? AND ?").arg(Col);
        posH = 1;
    }
    qry.prepare(QString("SELECT SUM(%1) FROM %2 WHERE %3").arg(Col, _Name, whereClause));
    switch (checkType(_Info[Col][0].toString())){
    case INT:
        if(low) qry.bindValue(0, Lower.toInt());
        if(high)qry.bindValue(posH, Upper.toInt()); // bind if have upper limit
        break;
    case REAL:
        if(low) qry.bindValue(0, Lower.toDouble());
        if(high)qry.bindValue(posH, Upper.toDouble());; // bind if have upper limit
        break;
    default:
        break;
    }
    return qry.value(0);
}
