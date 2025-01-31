// FoodOrder.h
//
// This is the declaration of the derived FoodOrder class,
// which inherits from DeliveryOrder
// has functions for adding food, applying discount, and printing a receipt

#ifndef FOODORDER_H
#define FOODORDER_H

#include "DeliveryOrder.h"
#include <iostream>
#include <string>

class FoodOrder : public DeliveryOrder {
    private:
        std::string restaurantName;
        int foodCount;

    public:
        // constructor
        FoodOrder(std::string name, std::string date, std::string phone, float miles, std::string restaurantName);

        // function
        void addFood(std::string food, int sides = 0, bool soup = false);

        // override base receipt function
        void receipt() const;

        // override pure virtual function
        float VIPdiscount() const; 

        // destructor
        ~FoodOrder();
};

#endif // FOODORDER_H