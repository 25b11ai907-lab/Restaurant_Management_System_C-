#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>
#include <string>

using namespace std;

class Reservation
{
private:
    string id;
    string customerId;
    int tableNo;
    int persons;
    string date;
    string time;
    string status;

public:

    // Default constructor
    Reservation();

    // Parameterized constructor
    Reservation(
        string i,
        string cId,
        int tNo,
        int p,
        string d,
        string tm,
        string s
    );

    // Getters
    string getId();
    string getCustomerId();
    int getTableNo();
    int getPersons();
    string getDate();
    string getTime();
    string getStatus();

    // Display reservation
    void showReservation();
};

#endif