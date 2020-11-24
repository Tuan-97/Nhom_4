#ifndef TABLE_H
#define TABLE_H

#include <QObject>
#include <QtSql>
#include <QSet>
#include <QVariant>
#include <QString>
#include <vector>
#include <map>

class Table;
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
    Table(QString, TableData, TableInfo);               // by order: _TableName, _Data, TableInfo;
    virtual QSet<QVariant>& getPrimaryKeys() const;     // return a set of all Primary key;
    virtual ~Table() = 0;
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
    QString             _Name;
    TableData           _Data;
    QString             _PrmField;
    PrimaryValueList    _PmrValues;
    TableInfo           _Info;
    static QMap<QString, int> valueType;

};



#endif // TABLE_H
