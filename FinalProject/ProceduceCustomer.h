#ifndef PROCEDUCE_H
#define PROCEDUCE_H
#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QSql>
#include <QSqlError>
#include <QDir>
#include <QFile>
#include <QDebug>
#include <QSqlQuery>
#include <QString>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "table.h"

using namespace std;

class ProceduceCustomer
{
private:
public:
    ProceduceCustomer();
    void UpdateData(Table*, int, string, string, string, string, string , string);
    void AddData(Table*, int, string, string, string, string, string, string);
    void DeleteData(Table*, int);
};

#endif // PROCEDUCE_H
