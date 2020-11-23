#include "Common.h"
#include "Table.h"

enum OrderProp{OrderID, CustomerID, EmployeeID, OrderDate, ShipperID};

std::vector<bool> BasicInternalPrimaryProp({true, true, false});
std::vector<bool> BasicForeignPrimaryProp({true, true, true});
std::vector<bool> BasicInternalNormalProp({false, false, false});
std::vector<bool> BasicForeignNormalProp({false, false, true});
std::vector<bool> BasicParentForeignProp({true, false, true});

gnrDetail OrderIdGnrDetail(
    "OrderID",
    "OrderID",
    "Unsigned Int",
    true);

PropDetail<OrderProp> OrderId(OrderID, OrderIdGnrDetail);

Constraints OrderIdConstraint(UINT, BasicInternalPrimaryProp, nullptr);

/*=================================================================================*/

gnrDetail CustomerIdGnrDetail(
    "Customer ID",
    "Customer ID",
    "Unsigned Int",
    true);

PropDetail<OrderProp> CustomerId(CustomerID, OrderIdGnrDetail);

Constraints CustomerIdConstraint(UINT, BasicForeignNormalProp, nullptr);

/*=================================================================================*/

gnrDetail EmployeeIdGnrDetail(
    "Employee ID",
    "Employee ID",
    "Unsigned Int",
    true);

PropDetail<OrderProp> EmployeeId(EmployeeID, EmployeeIdGnrDetail);

Constraints EmployeeIdConstraint(UINT, BasicForeignNormalProp, nullptr);

/*=================================================================================*/

gnrDetail OrderDateGnrDetail(
    "Employee ID",
    "Employee ID",
    "String with format dd-mm-yyyy",
    true);

PropDetail<OrderProp> OrderDate(EmployeeID, EmployeeIdGnrDetail);

Constraints OrderDateConstraint(UINT, BasicForeignNormalProp, nullptr);

/*=================================================================================*/

gnrDetail ShipperIdGnrDetail(
    "Shipper ID",
    "Shipper ID",
    "Unsigned Int",
    true);

PropDetail<OrderProp> ShipperId(EmployeeID, EmployeeIdGnrDetail);

Constraints ShipperIdConstraint(DATE, BasicForeignNormalProp, nullptr);

/*=================================================================================*/


