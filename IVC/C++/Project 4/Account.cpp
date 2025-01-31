// definition of the Account class

#include "Account.h"
#include <iostream>

Account::Account(std::string username, std::string status) {
    this->username = username;
    this->status = status;
};

// getter function
std::string Account::getStatus() const {
    return Account::status;
};

// destructor
Account::~Account() {
    std::cout << "Account removed.\n";
};