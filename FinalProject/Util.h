#ifndef UTIL_H
#define UTIL_H
#include "CommonDef.h"

enum ColType{INT, REAL, TEXT, UNKNOWN};

ColType checkType(QString);
QString quoteSql(QString const& orgStr);
void SaveData(QString orgFPath, QString path, QString filename);
void BackupData(QString orgFPath, QString path, QString filename);
int OpenData(bool useTemp);
int closeDataBase(bool useTemp, QString path);
#endif // UTIL_H
