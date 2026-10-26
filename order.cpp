#include "order.h"

using namespace std;

// ==================================================
// DEFAULT CONSTRUCTOR
// ==================================================

Order::Order()
{
    id = "";
    crewId = "";
    customerId = "";
    foodId = "";
    quantity = 0;
    status = "";
}

// ==================================================
// PARAMETERIZED CONSTRUCTOR
// ==================================================

Order::Order(
    string i,
    string cId,
    string cuId,
    string fId,
    int q,
    string s
)
{
    id = i;
    crewId = cId;
    customerId = cuId;
    foodId = fId;
    quantity = q;
    status = s;
}

// ==================================================
// GET ID
// ==================================================

string Order::getId()
{
    return id;
}

// ==================================================
// GET CREW ID
// ==================================================

string Order::getCrewId()
{
    return crewId;
}

// ==================================================
// GET CUSTOMER ID
// ==================================================

string Order::getCustomerId()
{
    return customerId;
}

// ==================================================
// GET FOOD ID
// ==================================================

string Order::getFoodId()
{
    return foodId;
}

// ==================================================
// GET QUANTITY
// ==================================================

int Order::getQuantity()
{
    return quantity;
}

// ==================================================
// GET STATUS
// ==================================================

string Order::getStatus()
{
    return status;
}

// ==================================================
// UPDATE ORDER
// ==================================================

void Order::updateOrder(string s)
{
    status = s;
}

// ==================================================
// SHOW ORDER
// ==================================================

void Order::showOrder()
{
    cout << "\n-----------------------------\n";
    cout << "Order ID      : " << id << endl;
    cout << "Crew ID       : " << crewId << endl;
    cout << "Customer ID   : " << customerId << endl;
    cout << "Food ID       : " << foodId << endl;
    cout << "Quantity      : " << quantity << endl;
    cout << "Status        : " << status << endl;
    cout << "-----------------------------\n";
}