#include "receptionist.h"

using namespace std;

// ==================================================
// DEFAULT CONSTRUCTOR
// ==================================================

Receptionist::Receptionist()
    : Person()
{
    username = "";
    password = "";
    pin = "";
}

// ==================================================
// PARAMETERIZED CONSTRUCTOR
// ==================================================

Receptionist::Receptionist(
    string i,
    string n,
    string c,
    string ct,
    string co,
    string u,
    string p,
    string pi
)
    : Person(i, n, c, ct, co)
{
    username = u;
    password = p;
    pin = pi;
}

// ==================================================
// LOGIN
// ==================================================

bool Receptionist::login(
    string receptionistId,
    string u,
    string p,
    string enteredPin
)
{
    if (id == receptionistId &&
        username == u &&
        password == p &&
        pin == enteredPin)
    {
        return true;
    }

    return false;
}

// ==================================================
// GET USERNAME
// ==================================================

string Receptionist::getUsername()
{
    return username;
}

// ==================================================
// GET PASSWORD
// ==================================================

string Receptionist::getPassword()
{
    return password;
}

// ==================================================
// GET PIN
// ==================================================

string Receptionist::getPin()
{
    return pin;
}

// ==================================================
// UPDATE DETAILS
// ==================================================

void Receptionist::updateDetails(
    string n,
    string c,
    string ct,
    string co,
    string u,
    string p,
    string pi
)
{
    name = n;
    contact = c;
    city = ct;
    country = co;

    username = u;
    password = p;
    pin = pi;
}

// ==================================================
// SHOW DETAILS
// ==================================================

void Receptionist::show()
{
    cout << "\n========== RECEPTIONIST DETAILS ==========\n";

    showPerson();

    // Username, password and PIN are intentionally
    // not displayed.
}