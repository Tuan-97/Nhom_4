#ifndef UTIL_H
#define UTIL_H
#include "CommonDef.h"

enum ColType{INT, REAL, TEXT, UNKNOWN};

ColType checkType(QString);
QString quoteSql(QString const& orgStr);
#endif // UTIL_H
