#ifndef PROCEDUCEORDERDETAILS_H
#define PROCEDUCEORDERDETAILS_H
#include <table.h>


class ProceduceOrderDetails
{
public:
    ProceduceOrderDetails();
    void UpdateData(Table*, int, int, int, int);
    void AddData(Table*, int, int, int, int);
    void DeleteData(Table*, int);
    QString PrintfReport(int, Table);
};

#endif // PROCEDUCEORDERDETAILS_H
