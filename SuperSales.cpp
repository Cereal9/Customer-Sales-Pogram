

#include "SuperSales.h"

double SuperSales::calculateCommission() const {
    return 0.065 * getPersonalSales();
}