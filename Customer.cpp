#include "customer.h"

Customer::Customer() {
    
}

Customer::Customer(const std::string& id, const std::string& firstName, const std::string& lastName,
    const std::string& address, const std::string& city,
    const std::string& state, const std::string& zipCode)
    : id(id), firstName(firstName), lastName(lastName), address(address),
    city(city), state(state), zipCode(zipCode) {
    // Constructor with parameters to set member variables.
}

std::string Customer::getId() const {
    return id;
}

std::string Customer::getFirstName() const {
    return firstName;
}

std::string Customer::getLastName() const {
    return lastName;
}

std::string Customer::getAddress() const {
    return address;
}

std::string Customer::getCity() const {
    return city;
}

std::string Customer::getState() const {
    return state;
}

std::string Customer::getZipCode() const {
    return zipCode;
}