// this is where the main function and various other non-member functions are defined

#include "Account.h"
#include "BobaOrder.h"
#include "DeliveryOrder.h"
#include "FoodOrder.h"
#include "InvalidInput.h"
#include <iostream>
#include <iomanip>

// check if Account gets a discount with thier status
float applyDiscount(DeliveryOrder* order, const Account& acct) {
    if(acct.getStatus() == "Owner") {
        return order->getTotalBalance() * 0.1;
    }
    else if(acct.getStatus() == "VIP") {
        return order->getTotalBalance() * order->VIPdiscount();
    }
    else {
        return order->getTotalBalance();
    }
}

// functions to throw exception if input is invalid
std::string drinkTest(std::string name) {
    if(name == "Green Tea Latte") {
        return name;
    }
    else if(name == "Brown Sugar Boba Milk") {
        return name;
    }
    else if(name == "Brown Sugar Pearl Milk") {
        return name;
    }
    else {
        throw InvalidInput(name);
    }
}

std::string foodTest(std::string name) {
    if(name == "Thick Cauliflower Steaks") {
        return name;
    }
    else if(name == "Rack of Lamb") {
        return name;
    }
    else if(name == "Organic Scottish Salmon") {
        return name;
    }
    else if(name == "Grilled Lobster Risotto") {
        return name;
    }
    else {
        throw InvalidInput(name);
    }
}

int main() {
    // initialize three minion accounts
    const Account Stuart("Stuart", "Owner");
    Account Kevin("Kevin", "VIP");
    Account Bob("Bob");

    // create DeliveryOrder pointer for polymorphism demonstration
    DeliveryOrder* orderPTR;

    // begin first Boba order
    std::cout << std::setprecision(2) << std::fixed;
    std::cout << "Kevin is placing order.\n";
    BobaOrder order1("Kevin", "04/20/2024", "123-456-0000", 10.4, "M Tea");
    try {
        order1.addDrink(drinkTest("Green Tea Latte"));
        order1.addDrink(drinkTest("Brown Sugar Pearl Milk"), false);
        order1.addDrink(drinkTest("Brown Sugar Boba Milk"), false, 2);
        order1.addDrink(drinkTest("Iron Goddess"));
    }
    catch(InvalidInput& exp) {
        exp.reason();
        std::cout << "Not serving requested drinks. Drink order ignored.\n\n";
    }
    // print receipt and balances
    order1.receipt();
    std::cout << "Balance: $" << order1.getTotalBalance() << std::endl;
    orderPTR = &order1;
    std::cout << "Discounted Balance: $" << applyDiscount(orderPTR, Kevin) << "\n\n\n";

    // start the second order
    std::cout << "Stuart is placing order.\n";
    FoodOrder order2("Stuart", "04/20/2024", "123-456-1111", 25.5, "Tavern Green");
    try {
        order2.addFood(foodTest("Thick Cauliflower Steaks"), 1, true);
        order2.addFood(foodTest("Organic Scottish Salmon"));
        order2.addFood(foodTest("Rack of Lamb"), 0, true);
    }
    catch(InvalidInput& exp) {
        exp.reason();
        std::cout << "Not serving requested food. Food order ignored.\n\n";
    }
    // print receipt and balances
    order2.receipt();
    std::cout << "Balance: $" << order2.getTotalBalance() << std::endl;
    orderPTR = &order2;
    std::cout << "Discounted Balance: $" << applyDiscount(orderPTR, Stuart) << "\n\n\n";

    // start potential third order 
    std::cout << "Bob decided to log in to his account and see whether he can afford ordering the same order as Stuart.\n";
    order2.receipt();
    std::cout << "Balance: $" << order2.getTotalBalance() << std::endl;
    orderPTR = &order2;
    std::cout << "Discounted Balance: $" << applyDiscount(orderPTR, Bob) << std::endl;
    std::cout << "Bob upset, cancelling order :(\n\n";

    // print total orders placed
    std::cout << "Total order placed: " << DeliveryOrder::getOrderCount() << std::endl << std::endl;

    // terminate program
    return 0;
}