// Account.h
//
// This is the declaration of the Account class,
// which has string variables for username and status
// and a getter function to access the user status

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

class Account {
    private:
        std::string username, status;

    public:
        // constructor
        Account(std::string username, std::string status = "Regular");

        // getter function
        std::string getStatus() const;

        // destructor
        ~Account();
};

#endif // ACCOUNT_H