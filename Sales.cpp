
#include "Sales.h"

double Sales::calculateCommission() const {
    return 0.05 * getPersonalSales();
}