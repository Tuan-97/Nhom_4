#ifndef TABLEMANAGEMENT_H
#define TABLEMANAGEMENT_H
#include "table.h"

class TableManagement{
// Connect modify operations of Table to SQL Query execution
public:
    //TableManagement(); use default constructor;
    Table& getTable(QString);
    int createTable(QString);
    int updateTable(Table*);
private:
    TableList _TableList;
    QSqlQuery& _Query;
    TableInfo getTableInfo(QString& );
    TableData getTableData(QString, TableInfo);
};

#endif // TABLEMANAGEMENT_H

