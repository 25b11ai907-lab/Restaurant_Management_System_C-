#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string id;
    string name;
    string contact;
    string city;
    string country;

public:
    Person(string i = "",
           string n = "",
           string c = "",
           string ct = "",
           string co = "");

    string getId() const;
    string getName() const;
    string getContact() const;
    string getCity() const;
    string getCountry() const;

    void showPerson() const;
};
#endif
