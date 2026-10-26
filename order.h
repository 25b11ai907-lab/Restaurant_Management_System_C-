#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>

using namespace std;

class Order
{
private:
    string id;
    string crewId;
    string customerId;
    string foodId;
    int quantity;
    string status;

public:

    // Default constructor
    Order();

    // Parameterized constructor
    Order(
        string i,
        string cId,
        string cuId,
        string fId,
        int q,
        string s
    );

    // Getters
    string getId();
    string getCrewId();
    string getCustomerId();
    string getFoodId();
    int getQuantity();
    string getStatus();

    // Update order
    void updateOrder(
        string s
    );

    // Display order
    void showOrder();
};

#endif