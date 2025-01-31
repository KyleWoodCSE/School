// definition of DeliveryOrder abstract class

#include "DeliveryOrder.h"
#include <iostream>

int DeliveryOrder::orderCount = 0;
const float DeliveryOrder::taxRate = 0.09;
const float DeliveryOrder::deliveryRate = 2.0;

// constructor
DeliveryOrder::DeliveryOrder(std::string name, std::string date, std::string phone, float miles) {
    this->name = name;
    this->date = date;
    this->phone = phone;
    this->miles = miles;
    orderBalance = 0.0;
    orderCount++;
};

// functions
void DeliveryOrder::receipt() const {
    std::cout << "Order Detail:" << "\n";
    std::cout << "\tName: " << name << "\n";
    std::cout << "\tDate: " << date << "\n";
    std::cout << "\tPhone: " << phone << "\n";
    std::cout << "\tOrder Balance: $" << orderBalance << std::endl;
};

float DeliveryOrder::getTotalBalance() const {
    return orderBalance * (1 + taxRate) + miles * deliveryRate;
};

// static function
int DeliveryOrder::getOrderCount() {
    return DeliveryOrder::orderCount;
};

// destructor
DeliveryOrder::~DeliveryOrder() {
    std::cout << "DeliveryOrder destroyed." << std::endl;
};