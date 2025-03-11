#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include <string>

class Transactions {
public:
    Transactions(const std::string& CustID, const std::string& salespersonID, const std::string& orderID);
        

    const std::string& getCustID() const;
    const std::string& getSalesPersonID() const;
    const std::string& getOrderID() const;

private:
    std::string CustID;
    std::string orderID;
    std::string salespersonID;
};

#endif // TRANSACTIONS_H