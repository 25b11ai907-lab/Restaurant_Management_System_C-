#include "reservation.h"

using namespace std;

// ==================================================
// DEFAULT CONSTRUCTOR
// ==================================================

Reservation::Reservation()
{
    id = "";
    customerId = "";
    tableNo = 0;
    persons = 0;
    date = "";
    time = "";
    status = "";
}

// ==================================================
// PARAMETERIZED CONSTRUCTOR
// ==================================================

Reservation::Reservation(
    string i,
    string cId,
    int tNo,
    int p,
    string d,
    string tm,
    string s
)
{
    id = i;
    customerId = cId;
    tableNo = tNo;
    persons = p;
    date = d;
    time = tm;
    status = s;
}

// ==================================================
// GET ID
// ==================================================

string Reservation::getId()
{
    return id;
}

// ==================================================
// GET CUSTOMER ID
// ==================================================

string Reservation::getCustomerId()
{
    return customerId;
}

// ==================================================
// GET TABLE NUMBER
// ==================================================

int Reservation::getTableNo()
{
    return tableNo;
}

// ==================================================
// GET NUMBER OF PERSONS
// ==================================================

int Reservation::getPersons()
{
    return persons;
}

// ==================================================
// GET DATE
// ==================================================

string Reservation::getDate()
{
    return date;
}

// ==================================================
// GET TIME
// ==================================================

string Reservation::getTime()
{
    return time;
}

// ==================================================
// GET STATUS
// ==================================================

string Reservation::getStatus()
{
    return status;
}

// ==================================================
// SHOW RESERVATION
// ==================================================

void Reservation::showReservation()
{
    cout << "\n-----------------------------\n";
    cout << "Reservation ID : " << id << endl;
    cout << "Customer ID    : " << customerId << endl;
    cout << "Table Number   : " << tableNo << endl;
    cout << "Persons        : " << persons << endl;
    cout << "Date           : " << date << endl;
    cout << "Time           : " << time << endl;
    cout << "Status         : " << status << endl;
    cout << "-----------------------------\n";
}