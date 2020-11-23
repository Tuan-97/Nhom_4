#include "employees.h"

Employees::Employees()
{

}
Employees::Employees(int id, string lastname, string firstname, string birthdate, string photo, string note){
    this->Employee_ID = id;
    this->Employee_LastName = lastname;
    this->Employee_FirstName = firstname;
    this->Employee_BirthDate = birthdate;
    this->Employee_Photo = photo;
    this->Employee_Note = note;
}
