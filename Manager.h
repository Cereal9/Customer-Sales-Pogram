#ifndef MANAGER_H
#define MANAGER_H

#include "Salesperson.h"

class Manager : public SalesPerson {
public:
    using SalesPerson::SalesPerson;

    double calculateCommission() const override;
    void setEmployeeSales(double sales);
    double getEmployeeSales() const;

private:
    double employeeSales = 0;
};

#endif // MANAGER_H