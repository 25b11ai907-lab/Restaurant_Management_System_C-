#ifndef MANAGER_H
#define MANAGER_H

#include "person.h"

class Manager : public Person
{
private:
    string username;
    string password;
    string pin;

public:
    Manager();

    Manager(string i,
            string n,
            string c,
            string ct,
            string co,
            string u,
            string p,
            string pi);

    bool login(string managerId,
               string u,
               string p,
               string enteredPin);

    string getUsername() const;
    string getPassword() const;
    string getPin() const;

    void updateDetails(string n,
                       string c,
                       string ct,
                       string co,
                       string u,
                       string p,
                       string pi);

    void show() const;
};

#endif