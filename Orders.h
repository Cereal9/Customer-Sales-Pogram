#ifndef ORDERS_H
#define ORDERS_H

#include <string>

class Orders {
public:
    Orders(const std::string& orderID, const std::string& date, int quantity, double amountPaid);
    

    std::string getOrderID() const;
    const std::string& getDate() const;
    int getQuantity() const;
    double getAmountPaid() const;

private:
    std::string orderID;
    std::string date;
    int quantity;
    double amountPaid;
};

#endif // ORDERS_H