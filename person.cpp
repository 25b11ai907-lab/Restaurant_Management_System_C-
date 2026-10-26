#include "person.h"

Person::Person(string i,
               string n,
               string c,
               string ct,
               string co)
{
    id = i;
    name = n;
    contact = c;
    city = ct;
    country = co;
}

string Person::getId() const
{
    return id;
}

string Person::getName() const
{
    return name;
}

string Person::getContact() const
{
    return contact;
}

string Person::getCity() const
{
    return city;
}

string Person::getCountry() const
{
    return country;
}

void Person::showPerson() const
{
    cout << "ID       : " << id << endl;
    cout << "Name     : " << name << endl;
    cout << "Contact  : " << contact << endl;
    cout << "City     : " << city << endl;
    cout << "Country  : " << country << endl;
}