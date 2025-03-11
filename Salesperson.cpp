#include "SalesPerson.h"

SalesPerson::SalesPerson(const std::string& title, const std::string& name, const std::string& salesPersonID, const std::string& bossID)
    : title(title), name(name), salesPersonID(salesPersonID), bossID(bossID), personalSales(0) {}

SalesPerson::~SalesPerson() {}

double SalesPerson::calculateCommission() const {
    return 0;  
}

const std::string& SalesPerson::getName() const {
    return name;
}

const std::string& SalesPerson::getSalesPersonID() const {
    return salesPersonID;
}

const std::string& SalesPerson::getBossID() const {
    return bossID;
}

const std::string& SalesPerson::getTitle() const {
    return title;
}

double SalesPerson::getPersonalSales() const {
    return personalSales;
}

void SalesPerson::setPersonalSales(double sales) {
    personalSales = sales;
}

double SalesPerson::getCommission() const {
    return calculateCommission();
}
