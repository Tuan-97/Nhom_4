#ifndef TABLE_H
#define TABLE_H

#include "CommonDef.h"
#include "TableHelper.h"

class Table
{

public:
    Table(QString);
    virtual const QString& getTableName();              // return _TableName;
    virtual int insertRow(Row&);                        // add New Row to Table;
    virtual int removeRow(int);
    virtual int updateRow(Row&);
    TableData filterByValue(QString, QVariant);    // SELECT * FROM _TableName WHERE <QString> = <QVariant>
    TableData filterByRange(QString, QVariant, QVariant);  // WHERE QString >= LowerBound AND QString <= Upper Bound
                                                                                // May have function to make closed set an open set
                                                                                // There is no clopen set
protected:
    TableHelper         _Helper;
    QString             _Name;          // Table Name;
    TableData           _Data;          // Data get from database
    QString             _PrmField;      // Name of column that is set as Primary
    //PrimaryValueList    _PmrValues;
    TableInfo           _Info;          // Info about each columns of Table;


};


#endif // TABLE_H
