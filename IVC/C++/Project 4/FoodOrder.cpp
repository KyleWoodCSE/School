// FoodOrder class definition

#include "FoodOrder.h"
#include <iostream>

// constructor
FoodOrder::FoodOrder(std::string name, std::string date, std::string phone, float miles, std::string restaurantName)
            :DeliveryOrder(name, date, phone, miles) {
    this->restaurantName = restaurantName;
    this->foodCount = 0;
};

// function
void FoodOrder::addFood(std::string food, int sides, bool soup) {
    float foodCost = 0.0;
    float totalCost = 0.0;
    float soupCost = 0.0;
    if(soup) {
        soupCost = 5.0;
    }
    if(food == "Thick Cauliflower Steaks") {
        foodCost = 15.0;
    }
    else if(food == "Rack of Lamb") {
        foodCost = 38.0;
    }
    else if(food == "Organic Scottish Salmon") {
        foodCost = 23.0;
    }
    else if(food == "Grilled Lobster Risotto") {
        foodCost = 46.0;
    }
    totalCost = foodCost + soupCost + ((float)sides * 6.0);
    orderBalance+=totalCost;
    foodCount++;
};

// override base receipt function
void FoodOrder::receipt() const {
    DeliveryOrder::receipt();
    std::cout << "\tFood Count: " << foodCount << std::endl;
};

// override pure virtual function
float FoodOrder::VIPdiscount() const {
    if(orderBalance > 50) {
        return 0.8;
    }
    else if(orderBalance > 30) {
        return 0.9;
    }
    else if(orderBalance > 20) {
        return 0.95;
    }
    else {
        return 1.0;
    }
}; 

// destructor
FoodOrder::~FoodOrder() {
    std::cout << "FoodOrder destroyed" << std::endl;
};