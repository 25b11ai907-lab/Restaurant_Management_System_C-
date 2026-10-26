#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>

using namespace std;

class Transaction
{
private:
    string id;
    string date;
    string customerId;
    string crewId;
    string orderId;
    string reportDate;

public:

    // Default constructor
    Transaction();

    // Parameterized constructor
    Transaction(
        string i,
        string d,
        string cId,
        string crId,
        string oId,
        string rd
    );

    // Getters
    string getId();
    string getDate();
    string getCustomerId();
    string getCrewId();
    string getOrderId();
    string getReportDate();

    // Display transaction
    void showTransaction();
};

#endif