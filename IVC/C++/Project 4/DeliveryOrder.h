// DeliveryOrder.h
//
// This is the declaration of the abstract DeliveryOrder class,
// which has a name, date, phone, order count, tax rate, delivery rate, and order balance
// Member functions get balances and counts, print receipt, and and apply a discount

#ifndef DELIVERYORDER_H
#define DELIVERYORDER_H

#include <iostream>
#include <string>

class DeliveryOrder {
    private:
        std::string name, date, phone; // date in format of month/day/year
        float miles;
        static int orderCount;
        static const float taxRate;
        static const float deliveryRate;

    protected:
        float orderBalance;

    public:
        // constructor
        DeliveryOrder(std::string name, std::string date, std::string phone, float miles);

        // functions
        void receipt() const;
        float getTotalBalance() const;
        static int getOrderCount();
        virtual float VIPdiscount() const = 0;

        // destructor
        ~DeliveryOrder();
};

#endif // DELIVERYORDER_H