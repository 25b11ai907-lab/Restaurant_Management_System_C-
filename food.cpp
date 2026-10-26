#include "food.h"

using namespace std;

// ==================================================
// DEFAULT CONSTRUCTOR
// ==================================================

Food::Food()
{
    id = "";
    name = "";
    status = "";
    price = 0;
}

// ==================================================
// PARAMETERIZED CONSTRUCTOR
// ==================================================

Food::Food(
    string i,
    string n,
    string s,
    double p
)
{
    id = i;
    name = n;
    status = s;
    price = p;
}

// ==================================================
// GET ID
// ==================================================

string Food::getId()
{
    return id;
}

// ==================================================
// GET NAME
// ==================================================

string Food::getName()
{
    return name;
}

// ==================================================
// GET STATUS
// ==================================================

string Food::getStatus()
{
    return status;
}

// ==================================================
// GET PRICE
// ==================================================

double Food::getPrice()
{
    return price;
}

// ==================================================
// UPDATE FOOD
// ==================================================

void Food::updateFood(
    string n,
    string s,
    double p
)
{
    name = n;
    status = s;
    price = p;
}

// ==================================================
// SHOW FOOD
// ==================================================

void Food::showFood()
{
    cout << "\n-----------------------------\n";
    cout << "Food ID     : " << id << endl;
    cout << "Food Name   : " << name << endl;
    cout << "Status      : " << status << endl;
    cout << "Price       : " << price << endl;
    cout << "-----------------------------\n";
}