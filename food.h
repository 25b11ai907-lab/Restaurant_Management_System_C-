#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <string>

using namespace std;

class Food
{
private:
    string id;
    string name;
    string status;
    double price;

public:

    // Default constructor
    Food();

    // Parameterized constructor
    Food(
        string i,
        string n,
        string s,
        double p
    );

    // Getter
    string getId();

    // Other getters
    string getName();
    string getStatus();
    double getPrice();

    // Update food
    void updateFood(
        string n,
        string s,
        double p
    );

    // Display food
    void showFood();
};

#endif