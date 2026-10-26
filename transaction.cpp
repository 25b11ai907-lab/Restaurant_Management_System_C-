#include "transaction.h"

using namespace std;

// ==================================================
// DEFAULT CONSTRUCTOR
// ==================================================

Transaction::Transaction()
{
    id = "";
    date = "";
    customerId = "";
    crewId = "";
    orderId = "";
    reportDate = "";
}

// ==================================================
// PARAMETERIZED CONSTRUCTOR
// ==================================================

Transaction::Transaction(
    string i,
    string d,
    string cId,
    string crId,
    string oId,
    string rd
)
{
    id = i;
    date = d;
    customerId = cId;
    crewId = crId;
    orderId = oId;
    reportDate = rd;
}

// ==================================================
// GET ID
// ==================================================

string Transaction::getId()
{
    return id;
}

// ==================================================
// GET DATE
// ==================================================

string Transaction::getDate()
{
    return date;
}

// ==================================================
// GET CUSTOMER ID
// ==================================================

string Transaction::getCustomerId()
{
    return customerId;
}

// ==================================================
// GET CREW ID
// ==================================================

string Transaction::getCrewId()
{
    return crewId;
}

// ==================================================
// GET ORDER ID
// ==================================================

string Transaction::getOrderId()
{
    return orderId;
}

// ==================================================
// GET REPORT DATE
// ==================================================

string Transaction::getReportDate()
{
    return reportDate;
}

// ==================================================
// SHOW TRANSACTION
// ==================================================

void Transaction::showTransaction()
{
    cout << "\n-----------------------------\n";
    cout << "Transaction ID : " << id << endl;
    cout << "Date           : " << date << endl;
    cout << "Customer ID    : " << customerId << endl;
    cout << "Crew ID        : " << crewId << endl;
    cout << "Order ID       : " << orderId << endl;
    cout << "Report Date    : " << reportDate << endl;
    cout << "-----------------------------\n";
}