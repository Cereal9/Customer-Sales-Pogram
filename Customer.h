
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
public:
    Customer();
    Customer(const std::string& id, const std::string& firstName, const std::string& lastName,
        const std::string& address, const std::string& city,
        const std::string& state, const std::string& zipCode);

    // Getter and Setter methods for the member variables
    std::string getId() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getAddress() const;
    std::string getCity() const;
    std::string getState() const;
    std::string getZipCode() const;

private:
    std::string id;
    std::string firstName;
    std::string lastName;
    std::string address;
    std::string city;
    std::string state;
    std::string zipCode;
};

#endif //CUSTOMER_H