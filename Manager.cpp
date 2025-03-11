#include "Manager.h"
#include <iostream>
using namespace std;

double Manager::calculateCommission() const {
    return 0.03 * getEmployeeSales() + (0.065 * getPersonalSales());
}

void Manager::setEmployeeSales(double sales) {
    employeeSales = sales;
    
}

double Manager::getEmployeeSales() const {
    return employeeSales;
}