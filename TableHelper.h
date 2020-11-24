#ifndef TABLEHELPER_H
#define TABLEHELPER_H
#include "CommonDef.h"
#include "Util.h"


QString quoteSql(const QString&);
class TableHelper
{
QString _Name;         // associate table name



TableInfo _Info;        // info about table;
std::vector<QString> _FieldName; // name of column set as primary key
QString _PrimaryCol;
bool owned;


std::vector<QString> setFieldNameFromInfo();    // use to set _FieldName;
QString setPrmCol();
//void getFilterData(QSqlQuery& qry); // execute data from prepared query and get data from it;
void prepareSelectQuery(QSqlQuery& qry, QString Col, QVariant Value);
void prepareSelectQuery(QSqlQuery& qry, QString Col, QVariant Lower, QVariant Upper);
public:
    TableHelper(QString);

    TableData filterByValue(QString Col, QVariant Value); // find by value

    TableData filterByRange(QString Col, QVariant Lower, QVariant Upper); // find by range

    TableData getFullData();

    int Insert(Row&);   // Insert Row& into database;

    int UpdateRow(Row&); // Change row that has ID = ROW[_PrimaryCol] in DATABASE

    int RemoveFromTable(int);

    static TableInfo getInfo(QString);
    static QString   getPrimaryField(TableInfo); // not implemented
};



#endif // TABLEHELPER_H
