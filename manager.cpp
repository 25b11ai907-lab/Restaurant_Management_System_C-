#include "manager.h"

Manager::Manager()
    : Person()
{
}

Manager::Manager(string i, string n, string c, string ct, string co,
                 string u, string p, string pi)
    : Person(i, n, c, ct, co)
{
    username = u;
    password = p;
    pin = pi;
}

bool Manager::login(string managerId,
                    string u,
                    string p,
                    string enteredPin)
{
    if (id == managerId &&
        username == u &&
        password == p &&
        pin == enteredPin)
    {
        return true;
    }

    return false;
}

string Manager::getUsername() const
{
    return username;
}

string Manager::getPassword() const
{
    return password;
}

string Manager::getPin() const
{
    return pin;
}

void Manager::updateDetails(string n,
                            string c,
                            string ct,
                            string co,
                            string u,
                            string p,
                            string pi)
{
    name = n;
    contact = c;
    city = ct;
    country = co;

    username = u;
    password = p;
    pin = pi;
}

void Manager::show() const
{
    cout << "\n===== MANAGER DETAILS =====\n";

    showPerson();
}