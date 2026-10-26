#ifndef PAYMENT_H
#define PAYMENT_H

#include <iostream>
#include <string>

using namespace std;

class Payment
{
private:
    string id;
    string customerId;
    string orderId;
    string deliveryId;
    string date;
    double amount;

public:

    // Default constructor
    Payment();

    // Parameterized constructor
    Payment(
        string i,
        string cId,
        string oId,
        string dId,
        string dt,
        double a
    );

    // Getters
    string getId();
    string getCustomerId();
    string getOrderId();
    string getDeliveryId();
    string getDate();
    double getAmount();

    // Display payment
    void showPayment();
};

#endif