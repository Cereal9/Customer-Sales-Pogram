#include "transactions.h"

#include <string>

Transactions::Transactions(const std::string& CustID, const std::string& salespersonID, const std::string& orderID)
    : CustID(CustID), salespersonID(salespersonID), orderID(orderID){}

const std::string& Transactions::getCustID() const {
    return CustID;
}

const std::string& Transactions::getSalesPersonID() const {
    return salespersonID;
}

const std::string& Transactions::getOrderID() const {
    return orderID;
}