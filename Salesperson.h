#ifndef SALESPERSON_H
#define SALESPERSON_H

#include <string>

class SalesPerson {
public:
    SalesPerson(const std::string& title, const std::string& name, const std::string& salesPersonID, const std::string& bossID);
    virtual ~SalesPerson();

    virtual double calculateCommission() const;
    const std::string& getName() const;
    const std::string& getSalesPersonID() const;
    const std::string& getBossID() const;
    const std::string& getTitle() const;
    virtual double getPersonalSales() const;
    virtual void setPersonalSales(double sales);
    virtual double getCommission() const;

private:
    std::string title;
    std::string name;
    std::string salesPersonID;
    std::string bossID;
    double personalSales;
};

#endif // SALESPERSON_H