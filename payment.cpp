#include "payment.h"

using namespace std;

// ==================================================
// DEFAULT CONSTRUCTOR
// ==================================================

Payment::Payment()
{
    id = "";
    customerId = "";
    orderId = "";
    deliveryId = "";
    date = "";
    amount = 0;
}

// ==================================================
// PARAMETERIZED CONSTRUCTOR
// ==================================================

Payment::Payment(
    string i,
    string cId,
    string oId,
    string dId,
    string dt,
    double a
)
{
    id = i;
    customerId = cId;
    orderId = oId;
    deliveryId = dId;
    date = dt;
    amount = a;
}

// ==================================================
// GET ID
// ==================================================

string Payment::getId()
{
    return id;
}

// ==================================================
// GET CUSTOMER ID
// ==================================================

string Payment::getCustomerId()
{
    return customerId;
}

// ==================================================
// GET ORDER ID
// ==================================================

string Payment::getOrderId()
{
    return orderId;
}

// ==================================================
// GET DELIVERY ID
// ==================================================

string Payment::getDeliveryId()
{
    return deliveryId;
}

// ==================================================
// GET DATE
// ==================================================

string Payment::getDate()
{
    return date;
}

// ==================================================
// GET AMOUNT
// ==================================================

double Payment::getAmount()
{
    return amount;
}

// ==================================================
// SHOW PAYMENT
// ==================================================

void Payment::showPayment()
{
    cout << "\n-----------------------------\n";
    cout << "Payment ID    : " << id << endl;
    cout << "Customer ID   : " << customerId << endl;
    cout << "Order ID      : " << orderId << endl;
    cout << "Delivery ID   : " << deliveryId << endl;
    cout << "Date          : " << date << endl;
    cout << "Amount        : " << amount << endl;
    cout << "-----------------------------\n";
}