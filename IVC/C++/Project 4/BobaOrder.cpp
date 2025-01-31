// BobaOrder class definition

#include "BobaOrder.h"
#include <iostream>

// constructor
BobaOrder::BobaOrder(std::string name, std::string date, std::string phone, float miles, std::string shopName)
            :DeliveryOrder(name, date, phone, miles) {
    this->shopName = shopName;
    this->drinksCount = 0;
};

// function
void BobaOrder::addDrink(std::string drink, bool boba, int count) {
    float drinkCost;
    float totalCost = 0.0;
    float bobaCost = 0.0;
    if(boba) {
        bobaCost = 1.0;
    }
    if(drink == "Green Tea Latte") {
        drinkCost = 5.8;
    }
    else if(drink == "Brown Sugar Boba Milk") {
        drinkCost = 7.8;
    }
    else if(drink == "Brown Sugar Pearl Milk") {
        drinkCost = 9.8;
    }
    totalCost = (drinkCost + bobaCost) * count;
    orderBalance+=totalCost;
    drinksCount+=count;
};

// override base receipt function
void BobaOrder::receipt() const {
    DeliveryOrder::receipt();
    std::cout << "\tDrinks Count: " << drinksCount << std::endl;
};

// override pure virtual function
float BobaOrder::VIPdiscount() const {
    if(BobaOrder::drinksCount>10) {
        return 0.8;
    }
    else if(BobaOrder::drinksCount>5) {
        return 0.9;
    }
    else if(BobaOrder::drinksCount>2) {
        return 0.95;
    }
    else {
        return 1.0;
    }
}; 

// destructor
BobaOrder::~BobaOrder() {
    std::cout << "BobaOrder destroyed" << std::endl;
};