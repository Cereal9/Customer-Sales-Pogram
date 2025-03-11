

#ifndef SUPERVISOR_H
#define SUPERVISOR_H

#include "Salesperson.h"

class Supervisor : public SalesPerson {
public:
    
    using SalesPerson::SalesPerson;

    ~Supervisor();
    
    

    double calculateCommission() const override;
    void setEmployeeSales(double sales);
    double getEmployeeSales() const;

private:
    double employeeSales = 0;
};

#endif // SUPERVISOR_H