#include "Orders.h"

Orders::Orders(const std::string& orderID, const std::string& date, int quantity, double amountPaid)
    : orderID(orderID), date(date), quantity(quantity), amountPaid(amountPaid) {}

 std::string Orders::getOrderID() const {
    return orderID;
}

const std::string& Orders::getDate() const {
    return date;
}

int Orders::getQuantity() const {
    return quantity;
}

double Orders::getAmountPaid() const {
    return amountPaid;
}
