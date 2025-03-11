#include "Supervisor.h"
#include <iostream>




Supervisor::~Supervisor() {}



double Supervisor::getEmployeeSales() const {

    return employeeSales;
}

double Supervisor::calculateCommission() const {
    
    return 0.03 * getEmployeeSales() + (0.065 * getPersonalSales());
}

void Supervisor::setEmployeeSales(double sales) {
    
    employeeSales = sales;

}

