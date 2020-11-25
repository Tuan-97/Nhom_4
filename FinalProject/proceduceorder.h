#ifndef PROCEDUCEORDER_H
#define PROCEDUCEORDER_H
#include <QString>
#include "table.h"


class ProceduceOrder
{
public:
    QString PrintfReport(Table&, int, int );
    void UpdateData(Table*, int, int, int, int, int);
    void AddData(Table*, int, int, int, int, int);
    void DeleteData(Table*, int);
    QString PrintfReport(int, Table);
};

#endif // PROCEDUCEORDER_H
