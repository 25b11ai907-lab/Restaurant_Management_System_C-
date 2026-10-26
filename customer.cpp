#include "customer.h"

using namespace std;

// ==================================================
// DEFAULT CONSTRUCTOR
// ==================================================

Customer::Customer()
    : Person()
{
    username = "";
    password = "";
}

// ==================================================
// PARAMETERIZED CONSTRUCTOR
// ==================================================

Customer::Customer(
    string i,
    string n,
    string c,
    string ct,
    string co,
    string u,
    string p
)
    : Person(i, n, c, ct, co)
{
    username = u;
    password = p;
}

// ==================================================
// LOGIN
// ==================================================

bool Customer::login(
    string customerId,
    string u,
    string p
)
{
    if (id == customerId &&
        username == u &&
        password == p)
    {
        return true;
    }

    return false;
}

// ==================================================
// GET USERNAME
// ==================================================

string Customer::getUsername()
{
    return username;
}

// ==================================================
// GET PASSWORD
// ==================================================

string Customer::getPassword()
{
    return password;
}

void Customer::setId(string newId)
{
    id = newId;
}

// ==================================================
// UPDATE DETAILS
// ==================================================

void Customer::updateDetails(
    string n,
    string c,
    string ct,
    string co,
    string u,
    string p
)
{
    name = n;
    contact = c;
    city = ct;
    country = co;

    username = u;
    password = p;
}

// ==================================================
// SHOW DETAILS
// ==================================================

void Customer::show()
{
    cout << "\n========== CUSTOMER DETAILS ==========\n";

    showPerson();

    // Username and password are not displayed.
}
