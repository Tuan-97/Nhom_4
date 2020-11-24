#ifndef TABLEHELPER_H
#define TABLEHELPER_H
#include "table.h"

enum ColType{INT, REAL, TEXT, UNKNOWN};

class TableHelper
{
Table*   _Table;
QString& _Name;         // associate table name
QString _PrimaryCol;    // name of column set as primary key

// TODO: set _PrimaryCol if possible;
TableInfo _Info;        // info about table;
bool owned;
bool isValidCall(Table*);
std::vector<QString> _FieldName;
void setFieldNameFromInfo();    // use to set _FieldName;
//void getFilterData(QSqlQuery& qry); // execute data from prepared query and get data from it;
void prepareSelectQuery(QSqlQuery& qry, QString Col, QVariant Value);
void prepareSelectQuery(QSqlQuery& qry, QString Col, QVariant Lower, QVariant Upper);
public:
    TableHelper(QString);

    TableData FilterByValue(QString Col, QVariant Value); // find by value

    TableData FilterByRange(QString Col, QVariant Lower, QVariant Upper); // find by range

    TableData getFullData();

    int Insert(Row&);   // Insert Row& into database;

    int UpdateRow(Row&); // Change row that has ID = ROW[_PrimaryCol] in DATABASE

    int RemoveFromTable(int, QString);

    static TableInfo getInfo(QString);
    static QString   getPrimaryField(TableInfo); // not implemented
};

ColType checkType(QString);
QString quoteSql(const QString&);
#endif // TABLEHELPER_H
