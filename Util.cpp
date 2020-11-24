#include "Util.h"

ColType checkType(QString typeStr){

    if(typeStr == "INTEGER") return INT;
    if(typeStr == "REAL") return REAL;
    if(typeStr == "TEXT") return TEXT;
    return UNKNOWN;
}

QString quoteSql(QString const& orgStr) {
    return QString("'%1'").arg(orgStr);
};
