#ifndef EMPLOYEES_H
#define EMPLOYEES_H
#include <string>
using namespace std;

class Employees
{
private:
    int Employee_ID;
    string Employee_LastName, Employee_FirstName, Employee_BirthDate, Employee_Photo, Employee_Note;
public:
    Employees();
    Employees(int, string, string, string, string, string);
};

#endif // EMPLOYEES_H
