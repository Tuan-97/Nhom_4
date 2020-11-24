#include "TableManagement.h"

// I realize that Qt also come with Table model but I realize it too late and it will take time to understand the documents so just stick with
// what I already write;

TableData TableManagement::getTableData(QString TableName, TableInfo Info){
    TableData data;
    QString col;
    std::vector<QString> FieldName;
    for(auto i = Info.begin(); i!= Info.end(); i++){ // build the key list for table data;
        FieldName.push_back(i.key());
        col += QString(" %1,").arg(i.key());
    }
    col.chop(1);

    QSqlQuery qry;
    qry.prepare(QString("SELECT %1 FROM %2").arg(col, TableName));
    qry.exec();
    Row r;
    while(qry.next()){                           // get data for table data;
        r.clear();
        for(auto i = 0; i < int(FieldName.size()); i++){
            r[FieldName[i]] = qry.value(i);
        }
        data[qry.value(0).toInt()] = r;
    }
    return data;
}

int TableManagement::createTable(QString TableName){
    TableInfo Info = getTableInfo(TableName);
    TableData Data= getTableData(TableName, Info);
    _TableList[TableName] = new Table(TableName, Data, Info);
    return 1;
};

Table& TableManagement::getTable(QString TableName){
    return *_TableList[TableName];
};

TableInfo TableManagement::getTableInfo(QString& TableName){ // get name and data type of each column;
    TableInfo Info;
    QSqlQuery qry(QString("PRAGMA table_info(%1)").arg(TableName));
    while(qry.next()){
        Info[qry.value(1).toString()]
                = std::vector<QVariant>({qry.value(2), qry.value(3), qry.value(5)});
    }
    return Info;
};
