#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "person.h"

class Customer : public Person
{
private:
    string username;
    string password;

public:

    // Default constructor
    Customer();

    // Parameterized constructor
    Customer(
        string i,
        string n,
        string c,
        string ct,
        string co,
        string u,
        string p
    );

    // Login
    bool login(
        string customerId,
        string u,
        string p
    );

    // Getters
    string getUsername();
    string getPassword();
    void setId(string newId);

    // Update details
    void updateDetails(
        string n,
        string c,
        string ct,
        string co,
        string u,
        string p
    );

    // Display details
    void show();
};

#endif
