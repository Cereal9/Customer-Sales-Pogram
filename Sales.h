#ifndef SALES_H
#define SALES_H

#include "Salesperson.h"

class Sales : public SalesPerson {
public:
    using SalesPerson::SalesPerson;

    double calculateCommission() const override;
};

#endif // SALES_H
