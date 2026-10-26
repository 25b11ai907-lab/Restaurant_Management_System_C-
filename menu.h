#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>

using namespace std;

class Menu
{
private:
    string id;
    string foodId;
    string category;

public:

    // Default constructor
    Menu();

    // Parameterized constructor
    Menu(
        string i,
        string fId,
        string c
    );

    // Getters
    string getId();
    string getFoodId();
    string getCategory();

    // Update menu
    void updateMenu(
        string fId,
        string c
    );

    // Display menu
    void showMenu();
};

#endif