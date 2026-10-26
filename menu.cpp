#include "menu.h"

using namespace std;

// ==================================================
// DEFAULT CONSTRUCTOR
// ==================================================

Menu::Menu()
{
    id = "";
    foodId = "";
    category = "";
}

// ==================================================
// PARAMETERIZED CONSTRUCTOR
// ==================================================

Menu::Menu(
    string i,
    string fId,
    string c
)
{
    id = i;
    foodId = fId;
    category = c;
}

// ==================================================
// GET ID
// ==================================================

string Menu::getId()
{
    return id;
}

// ==================================================
// GET FOOD ID
// ==================================================

string Menu::getFoodId()
{
    return foodId;
}

// ==================================================
// GET CATEGORY
// ==================================================

string Menu::getCategory()
{
    return category;
}

// ==================================================
// UPDATE MENU
// ==================================================

void Menu::updateMenu(
    string fId,
    string c
)
{
    foodId = fId;
    category = c;
}

// ==================================================
// SHOW MENU
// ==================================================

void Menu::showMenu()
{
    cout << "\n-----------------------------\n";
    cout << "Menu ID     : " << id << endl;
    cout << "Food ID     : " << foodId << endl;
    cout << "Category    : " << category << endl;
    cout << "-----------------------------\n";
}