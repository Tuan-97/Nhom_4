#ifndef TABLE_H
#define TABLE_H

#include <QObject>
#include <QtSql>
#include <QSet>
#include <QVariant>
#include <QString>
#include <vector>
#include <map>
#include "TableHelper.h"


class Table;
class TableHelper;
typedef QMap<QString, QVariant>     Row;
typedef QMap<unsigned int, Row>     TableData;          //  just use int;
typedef QSet<unsigned int>          PrimaryValueList;
typedef QMap<QString, std::vector<QVariant>>      TableInfo; // by order: type, nullable, PK
typedef QMap<QString, Table*>        TableList;

class Table : public QObject
{
    Q_OBJECT
public:

    explicit Table(QObject *parent = nullptr);
    Table(QString);
    virtual const QString& getTableName();              // return _TableName;
    virtual int insertRow(Row&);                        // add New Row to Table;
    virtual int removeRow(int);
    virtual int updateRow(Row&);
    virtual const TableData filterByValue(QString, QVariant) const;    // SELECT * FROM _TableName WHERE <QString> = <QVariant>
    virtual const TableData& filterByRange(QString, QVariant, QVariant) const;  // WHERE QString >= LowerBound AND QString <= Upper Bound
                                                                                // May have function to make closed set an open set
                                                                                // There is no clopen set
signals:
protected:
    QString             _Name;          // Table Name;
    TableData           _Data;          // Data get from database
    QString             _PrmField;      // Name of column that is set as Primary
    //PrimaryValueList    _PmrValues;
    TableInfo           _Info;          // Info about each columns of Table;
    TableHelper         _Helper;

};



#endif // TABLE_H
