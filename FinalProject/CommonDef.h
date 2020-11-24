#ifndef COMMONDEF_H
#define COMMONDEF_H
#include <QMap>
#include <vector>
#include <QString>
#include <QVariant>
#include <QtSql>
#include <QDebug>



typedef QMap<QString, QVariant>     Row;
typedef QMap<unsigned int, Row>     TableData;          //  just use int;
typedef QSet<unsigned int>          PrimaryValueList;
typedef QMap<QString, std::vector<QVariant>>      TableInfo; // by order: type, nullable, PK

#endif // COMMONDEF_H
