#ifndef PROCEDUCEPRODUCT_H
#define PROCEDUCEPRODUCT_H
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
#include "table.h"

class ProceduceProduct
{
private:
public:
    ProceduceProduct();
    QString PrintfReport(QString, QVariant, Table);
};

QString combine(int, QString, int, int, QString, double);

#endif // PROCEDUCEPRODUCT_H
