#ifndef TABLEHELPER_H
#define TABLEHELPER_H
#include "table.h"
enum ColType{INT, REAL, TEXT, UNKNOWN};
class TableHelper
{
Table * const _tablePtr;
QString _Name;
TableInfo _Info;
bool isValidCall(Table*);
std::vector<QString> _FieldName;
void setFieldNameFromInfo();    // use to set _FieldName;
void getFilterData(QSqlQuery& qry); // execute data from
void prepareSelectQuery(QSqlQuery& qry, QString Col, QVariant Value);
void prepareSelectQuery(QSqlQuery& qry, QString Col, QVariant Lower, QVariant Upper);
public:
    TableHelper(Table*);
    TableData FilterByValue(QString Col, QVariant Value);
    TableData FilterByRange(QString Col, QVariant Lower, QVariant Upper);
    TableInfo getTableInfo();
};

ColType checkType(QString);
#endif // TABLEHELPER_H
