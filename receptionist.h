#ifndef RECEPTIONIST_H
#define RECEPTIONIST_H

#include "person.h"

class Receptionist : public Person
{
private:
    string username;
    string password;
    string pin;

public:

    // Default constructor
    Receptionist();

    // Parameterized constructor
    Receptionist(
        string i,
        string n,
        string c,
        string ct,
        string co,
        string u,
        string p,
        string pi
    );

    // Login
    bool login(
        string receptionistId,
        string u,
        string p,
        string enteredPin
    );

    // Getters
    string getUsername();
    string getPassword();
    string getPin();

    // Update details
    void updateDetails(
        string n,
        string c,
        string ct,
        string co,
        string u,
        string p,
        string pi
    );

    // Display details
    void show();
};

#endif