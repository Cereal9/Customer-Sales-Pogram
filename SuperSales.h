
#ifndef SUPERSALES_H
#define SUPERSALES_H

#include "Salesperson.h"

class SuperSales : public SalesPerson {
public:
    using SalesPerson::SalesPerson;

    double calculateCommission() const override;
};

#endif // SUPERSALES_H