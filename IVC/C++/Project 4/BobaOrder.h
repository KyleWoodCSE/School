// BobaOrder.h
//
// This is the declaration of the derived BobaOrder class,
// which inherits from DeliveryOrder
// has functions for adding drinks, applying discount, and printing a receipt

#ifndef BOBAORDER_H
#define BOBAORDER_H

#include "DeliveryOrder.h"
#include <iostream>
#include <string>

class BobaOrder : public DeliveryOrder {
    private:
        std::string shopName;
        int drinksCount;

    public:
        // constructor
        BobaOrder(std::string name, std::string date, std::string phone, float miles, std::string shopName);

        // function
        void addDrink(std::string drink, bool boba = true, int count = 1);

        // override base receipt function
        void receipt() const;

        // override pure virtual function
        float VIPdiscount() const; 

        // destructor
        ~BobaOrder();
};

#endif // BOBAORDER_H