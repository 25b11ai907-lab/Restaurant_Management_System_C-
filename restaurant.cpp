#include "restaurant.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <filesystem>
#include <limits>

using namespace std;

const string DATA_PATH = []()
{
    filesystem::path projectDirectory = filesystem::current_path();

    if (!filesystem::exists(projectDirectory / "restaurant.cpp") &&
        filesystem::exists(projectDirectory.parent_path() / "restaurant.cpp"))
    {
        projectDirectory = projectDirectory.parent_path();
    }

    return (projectDirectory / "data").string() + "/";
}();

// --------------------------------------------------
// Helper function
// --------------------------------------------------

vector<string> splitLine(string line)
{
    vector<string> result;
    string value;
    stringstream ss(line);

    while (getline(ss, value, '|'))
    {
        result.push_back(value);
    }

    // getline removes '\n' but keeps the '\r' from Windows CRLF files.
    for (string &field : result)
    {
        if (!field.empty() && field.back() == '\r')
            field.pop_back();
    }

    return result;
}

// ==================================================
// CONSTRUCTOR
// ==================================================

Restaurant::Restaurant()
{
    std::filesystem::create_directories(DATA_PATH);
    loadData();
}

// ==================================================
// DESTRUCTOR
// ==================================================

Restaurant::~Restaurant()
{
    saveData();
}

// ==================================================
// VALIDATION FUNCTIONS
// ==================================================

bool Restaurant::isDigits(string value)
{
    if (value.empty())
        return false;

    for (char c : value)
    {
        if (!isdigit(c))
            return false;
    }

    return true;
}

// --------------------------------------------------

bool Restaurant::validUsername(string username)
{
    if (username.empty())
        return false;

    for (char c : username)
    {
        if (c < 'a' || c > 'z')
            return false;
    }

    return true;
}

// --------------------------------------------------

bool Restaurant::validPassword(string password)
{
    if (password.empty() || password.length() > 9)
        return false;

    int digitCount = 0;

    for (char c : password)
    {
        if ((c >= 'a' && c <= 'z'))
        {
            continue;
        }
        else if (c >= '0' && c <= '9')
        {
            digitCount++;
        }
        else
        {
            return false;
        }
    }

    if (digitCount != 4)
        return false;

    return true;
}

// --------------------------------------------------

bool Restaurant::validContact(string country, string contact)
{
    if (!isDigits(contact))
        return false;

    if (country == "India")
    {
        if (contact.length() != 10)
            return false;

        if (contact[0] < '6' || contact[0] > '9')
            return false;

        return true;
    }

    if (country == "USA" || country == "Canada")
    {
        return contact.length() == 10;
    }

    if (country == "UK")
    {
        return contact.length() == 10 ||
               contact.length() == 11;
    }

    if (country == "Australia")
    {
        if (contact.length() != 9)
            return false;

        return contact[0] == '4';
    }

    return false;
}

// --------------------------------------------------

string Restaurant::getValidUsername()
{
    string username;

    while (true)
    {
        cout << "Enter username: ";
        cin >> username;

        if (!validUsername(username))
        {
            cout << "Invalid username. Use lowercase letters only.\n";
            continue;
        }

        if (usernameExists(username))
        {
            cout << "Username already exists. Enter another username.\n";
            continue;
        }

        return username;
    }
}

// --------------------------------------------------

string Restaurant::getValidPassword()
{
    string password;

    while (true)
    {
        cout << "Enter password: ";
        cin >> password;

        if (!validPassword(password))
        {
            cout << "Invalid password. Enter another password.\n";
            continue;
        }

        if (passwordExists(password))
        {
            cout << "Password already exists. Enter another password.\n";
            continue;
        }

        return password;
    }
}

// --------------------------------------------------

string Restaurant::getValidPin()
{
    string pin;

    while (true)
    {
        cout << "Enter PIN: ";
        cin >> pin;

        if (!isDigits(pin) || pin.length() != 4)
        {
            cout << "Invalid PIN. PIN must contain exactly 4 digits.\n";
            continue;
        }

        if (pinExists(pin))
        {
            cout << "PIN already exists. Enter another PIN.\n";
            continue;
        }

        return pin;
    }
}

// --------------------------------------------------

string Restaurant::getValidCountry()
{
    string country;

    while (true)
    {
        cout << "Enter country (India, USA, Canada, UK, Australia): ";
        cin >> country;

        if (country == "India" || country == "USA" ||
            country == "Canada" || country == "UK" ||
            country == "Australia")
        {
            return country;
        }

        cout << "Invalid country. Enter one of the listed country names.\n";
    }
}

// --------------------------------------------------

string Restaurant::getValidContact(string country)
{
    string contact;

    while (true)
    {
        cout << "Enter contact number: ";
        cin >> contact;

        if (validContact(country, contact))
            return contact;

        cout << "Invalid contact number. Enter again.\n";
    }
}

// ==================================================
// DUPLICATE CHECKING
// ==================================================

bool Restaurant::idExists(string id)
{
    for (Manager &manager : managers)
    {
        if (manager.getId() == id)
            return true;
    }

    for (Receptionist &receptionist : receptionists)
    {
        if (receptionist.getId() == id)
            return true;
    }

    for (Customer &customer : customers)
    {
        if (customer.getId() == id)
            return true;
    }

    return false;
}

// --------------------------------------------------

bool Restaurant::usernameExists(string username)
{
    for (Manager &m : managers)
    {
        if (m.getUsername() == username)
            return true;
    }

    for (Receptionist &r : receptionists)
    {
        if (r.getUsername() == username)
            return true;
    }

    for (Customer &c : customers)
    {
        if (c.getUsername() == username)
            return true;
    }

    return false;
}

// --------------------------------------------------

bool Restaurant::passwordExists(string password)
{
    for (Manager &m : managers)
    {
        if (m.getPassword() == password)
            return true;
    }

    for (Receptionist &r : receptionists)
    {
        if (r.getPassword() == password)
            return true;
    }

    for (Customer &c : customers)
    {
        if (c.getPassword() == password)
            return true;
    }

    return false;
}

// --------------------------------------------------

bool Restaurant::pinExists(string pin)
{
    for (Manager &m : managers)
    {
        if (m.getPin() == pin)
            return true;
    }

    for (Receptionist &r : receptionists)
    {
        if (r.getPin() == pin)
            return true;
    }

    return false;
}

// ==================================================
// MANAGER
// ==================================================

void Restaurant::showManagerDetails()
{
    cout << "\n========== MANAGER DETAILS ==========\n";

    for (Manager &m : managers)
    {
        m.show();
        cout << "-------------------------------------\n";
    }
}

// --------------------------------------------------

void Restaurant::updateManager()
{
    string id;

    cout << "Enter Manager ID: ";
    cin >> id;

    for (Manager &m : managers)
    {
        if (m.getId() == id)
        {
            string name;
            string contact;
            string city;
            string country;
            string username;
            string password;
            string pin;

            cout << "Enter name: ";
            getline(cin >> ws, name);

            country = getValidCountry();

            contact = getValidContact(country);

            cout << "Enter city: ";
            getline(cin >> ws, city);

            username = getValidUsername();
            password = getValidPassword();
            pin = getValidPin();

            m.updateDetails(
                name,
                contact,
                city,
                country,
                username,
                password,
                pin
            );

            cout << "Manager details updated successfully.\n";
            return;
        }
    }

    cout << "Manager not found.\n";
}

// ==================================================
// RECEPTIONIST
// ==================================================

void Restaurant::addReceptionist()
{
    string id;
    string name;
    string contact;
    string city;
    string country;

    cout << "Enter Receptionist ID: ";
    cin >> id;

    if (idExists(id))
    {
        int number = 1;
        do
        {
            ostringstream idBuilder;
            idBuilder << "R" << setw(3) << setfill('0') << number++;
            id = idBuilder.str();
        } while (idExists(id));

        cout << "That ID was already used. Assigned unique ID: " << id << "\n";
    }

    cout << "Enter name: ";
    getline(cin >> ws, name);

    country = getValidCountry();

    contact = getValidContact(country);

    cout << "Enter city: ";
    getline(cin >> ws, city);

    string username = getValidUsername();
    string password = getValidPassword();
    string pin = getValidPin();

    receptionists.push_back(
        Receptionist(
            id,
            name,
            contact,
            city,
            country,
            username,
            password,
            pin
        )
    );

    cout << "Receptionist added successfully.\n";
}

// --------------------------------------------------

void Restaurant::updateReceptionist()
{
    string id;

    cout << "Enter Receptionist ID: ";
    cin >> id;

    for (Receptionist &r : receptionists)
    {
        if (r.getId() == id)
        {
            string name;
            string country;
            string contact;
            string city;

            cout << "Enter name: ";
            getline(cin >> ws, name);

            country = getValidCountry();

            contact = getValidContact(country);

            cout << "Enter city: ";
            getline(cin >> ws, city);

            string username = getValidUsername();
            string password = getValidPassword();
            string pin = getValidPin();

            r.updateDetails(
                name,
                contact,
                city,
                country,
                username,
                password,
                pin
            );

            cout << "Receptionist updated successfully.\n";
            return;
        }
    }

    cout << "Receptionist not found.\n";
}

// --------------------------------------------------

void Restaurant::deleteReceptionist(string loggedReceptionistId)
{
    string id;

    cout << "Enter Receptionist ID to delete: ";
    cin >> id;

    if (id == loggedReceptionistId)
    {
        cout << "Logged-in receptionist cannot be deleted.\n";
        return;
    }

    for (int i = 0; i < receptionists.size(); i++)
    {
        if (receptionists[i].getId() == id)
        {
            receptionists.erase(receptionists.begin() + i);

            cout << "Receptionist deleted successfully.\n";
            return;
        }
    }

    cout << "Receptionist not found.\n";
}

// --------------------------------------------------

void Restaurant::receptionistDetails()
{
    cout << "\n======= RECEPTIONIST DETAILS =======\n";

    for (Receptionist &r : receptionists)
    {
        r.show();
        cout << "-----------------------------------\n";
    }
}

void Restaurant::myReceptionistDetails(string receptionistId)
{
    for (Receptionist &r : receptionists)
    {
        if (r.getId() == receptionistId)
        {
            cout << "\n======= MY RECEPTIONIST DETAILS =======\n";
            r.show();
            return;
        }
    }

    cout << "Logged-in receptionist details not found.\n";
}

// ==================================================
// CUSTOMER
// ==================================================

string Restaurant::generateCustomerId()
{
    for (int number = 1; ; ++number)
    {
        ostringstream idBuilder;
        idBuilder << "C" << setw(3) << setfill('0') << number;
        string candidate = idBuilder.str();

        if (!idExists(candidate))
            return candidate;
    }
}

void Restaurant::addCustomer()
{
    string id = generateCustomerId();
    string name;
    string country;
    string city;

    cout << "Assigned Customer ID: " << id << "\n";

    cout << "Enter name: ";
    getline(cin >> ws, name);

    country = getValidCountry();

    string contact = getValidContact(country);

    cout << "Enter city: ";
    getline(cin >> ws, city);

    string username = getValidUsername();
    string password = getValidPassword();

    customers.push_back(
        Customer(
            id,
            name,
            contact,
            city,
            country,
            username,
            password
        )
    );

    cout << "Customer added successfully.\n";
}

// --------------------------------------------------

void Restaurant::updateCustomer()
{
    string id;

    cout << "Enter Customer ID: ";
    cin >> id;

    for (Customer &c : customers)
    {
        if (c.getId() == id)
        {
            string name;
            string country;
            string city;

            cout << "Enter name: ";
            getline(cin >> ws, name);

            country = getValidCountry();

            string contact = getValidContact(country);

            cout << "Enter city: ";
            getline(cin >> ws, city);

            string username = getValidUsername();
            string password = getValidPassword();

            c.updateDetails(
                name,
                contact,
                city,
                country,
                username,
                password
            );

            cout << "Customer updated successfully.\n";
            return;
        }
    }

    cout << "Customer not found.\n";
}

// --------------------------------------------------

void Restaurant::deleteCustomer()
{
    string id;

    cout << "Enter Customer ID: ";
    cin >> id;

    for (int i = 0; i < customers.size(); i++)
    {
        if (customers[i].getId() == id)
        {
            customers.erase(customers.begin() + i);

            cout << "Customer deleted successfully.\n";
            return;
        }
    }

    cout << "Customer not found.\n";
}

// --------------------------------------------------

void Restaurant::customerDetails()
{
    cout << "\n========== CUSTOMER DETAILS ==========\n";

    if (customers.empty())
    {
        cout << "No customer records found.\n";
        return;
    }

    for (Customer &c : customers)
    {
        c.show();
        cout << "--------------------------------------\n";
    }
}

// --------------------------------------------------

void Restaurant::myCustomerDetails(string customerId)
{
    for (Customer &c : customers)
    {
        if (c.getId() == customerId)
        {
            c.show();
            return;
        }
    }

    cout << "Customer details not found.\n";
}

// ==================================================
// FOOD
// ==================================================

void Restaurant::foodInformation()
{
    cout << "\n========== FOOD INFORMATION ==========\n";

    for (Food &f : foods)
    {
        f.showFood();
    }
}

// --------------------------------------------------

void Restaurant::addFood()
{
    string id;
    string name;
    string status;
    double price;

    cout << "Enter new Food ID: ";
    cin >> id;

    for (Food &food : foods)
    {
        if (food.getId() == id)
        {
            cout << "Food ID already exists.\n";
            return;
        }
    }

    cout << "Enter food name: ";
    cin >> name;
    cout << "Enter status: ";
    cin >> status;
    cout << "Enter price: ";
    cin >> price;

    if (!cin || price < 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid price. Food was not added.\n";
        return;
    }

    foods.emplace_back(id, name, status, price);
    cout << "Food added successfully.\n";
}

// --------------------------------------------------

void Restaurant::updateFood()
{
    string id;

    cout << "Enter Food ID: ";
    cin >> id;

    for (Food &f : foods)
    {
        if (f.getId() == id)
        {
            string name;
            string status;
            double price;

            cout << "Enter food name: ";
            cin >> name;

            cout << "Enter status: ";
            cin >> status;

            cout << "Enter price: ";
            cin >> price;

            f.updateFood(name, status, price);

            cout << "Food updated successfully.\n";
            return;
        }
    }

    cout << "Food not found.\n";
}

// --------------------------------------------------

void Restaurant::deleteFood()
{
    string id;
    cout << "Enter Food ID to delete: ";
    cin >> id;

    for (Menu &menu : menus)
    {
        if (menu.getFoodId() == id)
        {
            cout << "Cannot delete this food while a menu entry references it. "
                 << "Delete the menu entry first.\n";
            return;
        }
    }

    for (auto it = foods.begin(); it != foods.end(); ++it)
    {
        if (it->getId() == id)
        {
            foods.erase(it);
            cout << "Food deleted successfully.\n";
            return;
        }
    }

    cout << "Food not found.\n";
}

// ==================================================
// MENU
// ==================================================

void Restaurant::menuInformation()
{
    cout << "\n========== MENU ==========\n";

    for (Menu &m : menus)
    {
        m.showMenu();
    }
}

// --------------------------------------------------

void Restaurant::addMenu()
{
    string id;
    string foodId;
    string category;

    cout << "Enter new Menu ID: ";
    cin >> id;

    for (Menu &menu : menus)
    {
        if (menu.getId() == id)
        {
            cout << "Menu ID already exists.\n";
            return;
        }
    }

    cout << "Enter Food ID for this menu: ";
    cin >> foodId;

    bool foodExists = false;
    for (Food &food : foods)
    {
        if (food.getId() == foodId)
        {
            foodExists = true;
            break;
        }
    }

    if (!foodExists)
    {
        cout << "Food not found. Add the food before creating its menu entry.\n";
        return;
    }

    cout << "Enter category: ";
    cin >> category;

    menus.emplace_back(id, foodId, category);
    cout << "Menu entry added successfully.\n";
}

// --------------------------------------------------

void Restaurant::updateMenu()
{
    string id;

    cout << "Enter Menu ID: ";
    cin >> id;

    for (Menu &m : menus)
    {
        if (m.getId() == id)
        {
            string foodId;
            string category;

            cout << "Enter Food ID: ";
            cin >> foodId;

            cout << "Enter category: ";
            cin >> category;

            m.updateMenu(foodId, category);

            cout << "Menu updated successfully.\n";
            return;
        }
    }

    cout << "Menu not found.\n";
}

// --------------------------------------------------

void Restaurant::deleteMenu()
{
    string id;
    cout << "Enter Menu ID to delete: ";
    cin >> id;

    for (auto it = menus.begin(); it != menus.end(); ++it)
    {
        if (it->getId() == id)
        {
            menus.erase(it);
            cout << "Menu entry deleted successfully.\n";
            return;
        }
    }

    cout << "Menu not found.\n";
}

// ==================================================
// ORDER
// ==================================================

void Restaurant::orderInformation()
{
    cout << "\n========== ORDER INFORMATION ==========\n";

    for (Order &o : orders)
    {
        o.showOrder();
    }
}

// --------------------------------------------------

void Restaurant::customerOrders(string customerId)
{
    cout << "\n========== MY ORDERS ==========\n";

    bool found = false;

    for (Order &o : orders)
    {
        if (o.getCustomerId() == customerId)
        {
            o.showOrder();
            found = true;
        }
    }

    if (!found)
    {
        cout << "No orders found.\n";
    }
}

// --------------------------------------------------

void Restaurant::updateOrder()
{
    string id;

    cout << "Enter Order ID: ";
    cin >> id;

    for (Order &o : orders)
    {
        if (o.getId() == id)
        {
            string status;

            cout << "Enter new status: ";
            cin >> status;

            o.updateOrder(status);

            cout << "Order updated successfully.\n";
            return;
        }
    }

    cout << "Order not found.\n";
}

// ==================================================
// PAYMENT
// ==================================================

void Restaurant::paymentDetails()
{
    cout << "\n========== PAYMENT DETAILS ==========\n";

    for (Payment &p : payments)
    {
        p.showPayment();
    }
}

// --------------------------------------------------

void Restaurant::customerPayment(string customerId)
{
    cout << "\n========== MY PAYMENT DETAILS ==========\n";

    bool found = false;

    for (Payment &p : payments)
    {
        if (p.getCustomerId() == customerId)
        {
            p.showPayment();
            found = true;
        }
    }

    if (!found)
    {
        cout << "No payment details found.\n";
    }
}

// ==================================================
// TRANSACTION
// ==================================================

void Restaurant::transactionReport()
{
    cout << "\n========== TRANSACTION REPORT ==========\n";

    for (Transaction &t : transactions)
    {
        t.showTransaction();
    }
}

// ==================================================
// RESERVATION
// ==================================================

void Restaurant::tableAvailability()
{
    const int TOTAL_TABLES = 20;

    int reservedTables = reservations.size();

    if (reservedTables >= TOTAL_TABLES)
    {
        cout << "\nNo tables available.\n";
        cout << "Total tables: " << TOTAL_TABLES << endl;
        cout << "Reserved tables: " << reservedTables << endl;
        cout << "Available tables: 0\n";
    }
    else
    {
        cout << "\n========== TABLE AVAILABILITY ==========\n";
        cout << "Total tables: " << TOTAL_TABLES << endl;
        cout << "Reserved tables: " << reservedTables << endl;
        cout << "Available tables: "
             << TOTAL_TABLES - reservedTables << endl;
    }
}

// --------------------------------------------------

void Restaurant::reservationDetails()
{
    cout << "\n========== TABLE RESERVATION ==========\n";

    tableAvailability();

    cout << "\nReservation Details:\n";

    for (Reservation &r : reservations)
    {
        r.showReservation();
    }
}

// --------------------------------------------------

void Restaurant::customerReservation(string customerId)
{
    cout << "\n========== MY TABLE RESERVATION ==========\n";

    bool found = false;

    for (Reservation &r : reservations)
    {
        if (r.getCustomerId() == customerId)
        {
            r.showReservation();
            found = true;
        }
    }

    if (!found)
    {
        cout << "No reservation found.\n";
    }
}

// --------------------------------------------------

void Restaurant::customerReserveTable(string customerId)
{
    int persons;
    cout << "Enter number of guests: ";
    if (!(cin >> persons) || persons < 1)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter a valid number of guests.\n";
        return;
    }

    string date;
    string time;
    cout << "Enter reservation date (YYYY-MM-DD): ";
    cin >> date;
    cout << "Enter reservation time (HH:MM): ";
    cin >> time;

    int tableNo = 1;
    for (; tableNo <= 20; ++tableNo)
    {
        bool occupied = false;
        for (Reservation &reservation : reservations)
        {
            if (reservation.getTableNo() == tableNo &&
                reservation.getDate() == date &&
                reservation.getTime() == time)
            {
                occupied = true;
                break;
            }
        }

        if (!occupied)
            break;
    }

    if (tableNo > 20)
    {
        cout << "No tables are available at that date and time.\n";
        return;
    }

    int number = 1;
    string reservationId;
    while (true)
    {
        ostringstream idBuilder;
        idBuilder << "RS" << setw(3) << setfill('0') << number;
        reservationId = idBuilder.str();

        bool alreadyUsed = false;
        for (Reservation &reservation : reservations)
        {
            if (reservation.getId() == reservationId)
            {
                alreadyUsed = true;
                break;
            }
        }

        if (!alreadyUsed)
            break;
        ++number;
    }

    reservations.emplace_back(
        reservationId,
        customerId,
        tableNo,
        persons,
        date,
        time,
        "Confirmed"
    );

    cout << "Table reserved successfully.\n";
    cout << "Reservation ID: " << reservationId << "\n";
    cout << "Table number: " << tableNo << "\n";
}

// ==================================================
// LOGIN FUNCTIONS
// ==================================================

bool Restaurant::managerLogin(
    string id,
    string username,
    string password,
    string pin,
    int &index)
{
    for (int i = 0; i < managers.size(); i++)
    {
        if (managers[i].login(
                id,
                username,
                password,
                pin))
        {
            index = i;
            return true;
        }
    }

    return false;
}

// --------------------------------------------------

bool Restaurant::receptionistLogin(
    string id,
    string username,
    string password,
    string pin,
    int &index)
{
    for (int i = 0; i < receptionists.size(); i++)
    {
        if (receptionists[i].login(
                id,
                username,
                password,
                pin))
        {
            index = i;
            return true;
        }
    }

    return false;
}

// --------------------------------------------------

bool Restaurant::customerLogin(
    string id,
    string username,
    string password,
    int &index)
{
    for (int i = 0; i < customers.size(); i++)
    {
        if (customers[i].login(
                id,
                username,
                password))
        {
            index = i;
            return true;
        }
    }

    return false;
}

// ==================================================
// LOAD DATA
// ==================================================

void Restaurant::loadData()
{
    managers.clear();
    receptionists.clear();
    customers.clear();
    foods.clear();
    menus.clear();
    orders.clear();
    payments.clear();
    transactions.clear();
    reservations.clear();

    // ------------------------------------------------
    // MANAGERS
    // ------------------------------------------------

    ifstream managerFile(DATA_PATH + "managers.txt");

    string line;

    while (getline(managerFile, line))
    {
        if (line.empty())
            continue;

        vector<string> data = splitLine(line);

        if (data.size() >= 8)
        {
            managers.push_back(
                Manager(
                    data[0],
                    data[1],
                    data[2],
                    data[3],
                    data[4],
                    data[5],
                    data[6],
                    data[7]
                )
            );
        }
    }

    // Provide a starter account when this is a fresh installation.
    if (managers.empty())
    {
        managers.emplace_back(
            "M001", "Sample Manager", "7685143485", "Sample City", "India",
            "manager", "manager123", "4582"
        );
    }
    else if (managers.size() == 1 &&
             managers[0].getId() == "M001" &&
             managers[0].getName() == "Administrator")
    {
        // Fill profile fields for the starter account saved by earlier versions.
        managers[0].updateDetails(
            "Sample Manager", "7685143485", "Sample City", "India",
            managers[0].getUsername(),
            managers[0].getPassword(),
            managers[0].getPin()
        );
    }

    managerFile.close();

    // ------------------------------------------------
    // RECEPTIONISTS
    // ------------------------------------------------

    ifstream receptionistFile(
        DATA_PATH + "receptionists.txt"
    );

    while (getline(receptionistFile, line))
    {
        if (line.empty())
            continue;

        vector<string> data = splitLine(line);

        if (data.size() >= 8)
        {
            string receptionistId = data[0];
            if (idExists(receptionistId))
            {
                int number = 1;
                do
                {
                    ostringstream idBuilder;
                    idBuilder << "R" << setw(3) << setfill('0') << number++;
                    receptionistId = idBuilder.str();
                } while (idExists(receptionistId));
            }

            receptionists.push_back(
                Receptionist(
                    receptionistId,
                    data[1],
                    data[2],
                    data[3],
                    data[4],
                    data[5],
                    data[6],
                    data[7]
                )
            );
        }
    }

    receptionistFile.close();

    // Add sample receptionist accounts when none exist yet.
    if (receptionists.empty())
    {
        receptionists.emplace_back(
            "R001", "Meena Rao", "9876501234", "Delhi", "India",
            "meena", "meena1234", "2468"
        );
        receptionists.emplace_back(
            "R002", "Arjun Das", "9876505678", "Mumbai", "India",
            "arjun", "arjun1234", "1357"
        );
    }

    // ------------------------------------------------
    // CUSTOMERS
    // ------------------------------------------------

    ifstream customerFile(
        DATA_PATH + "customers.txt"
    );

    while (getline(customerFile, line))
    {
        if (line.empty())
            continue;

        vector<string> data = splitLine(line);

        if (data.size() >= 7)
        {
            string customerId = data[0];
            if (idExists(customerId))
                customerId = generateCustomerId();

            string country = data[4];
            if (country != "India" && country != "USA" &&
                country != "Canada" && country != "UK" &&
                country != "Australia")
            {
                country = validContact("India", data[2]) ? "India" : "Unknown";
            }

            customers.push_back(
                Customer(
                    customerId,
                    data[1],
                    data[2],
                    data[3],
                    country,
                    data[5],
                    data[6]
                )
            );
        }
    }

    customerFile.close();

    // Add sample customer accounts when no customer records exist yet.
    if (customers.empty())
    {
        customers.emplace_back(
            "C001", "Alice Sharma", "9876543210", "Delhi", "India",
            "alice", "alice1234"
        );
        customers.emplace_back(
            "C002", "Rahul Kumar", "9123456789", "Mumbai", "India",
            "rahul", "rahul1234"
        );
        customers.emplace_back(
            "C003", "Priya Patel", "9988776655", "Chennai", "India",
            "priya", "priya1234"
        );
    }

    // ------------------------------------------------
    // FOOD
    // ------------------------------------------------

    ifstream foodFile(DATA_PATH + "foods.txt");

    while (getline(foodFile, line))
    {
        if (line.empty())
            continue;

        vector<string> data = splitLine(line);

        if (data.size() >= 4)
        {
            foods.push_back(
                Food(
                    data[0],
                    data[1],
                    data[2],
                    stod(data[3])
                )
            );
        }
    }

    foodFile.close();

    // Add editable sample items when no food records exist yet.
    if (foods.empty())
    {
        foods.emplace_back("F001", "Burger", "Available", 100.0);
        foods.emplace_back("F002", "Pizza", "Available", 250.0);
        foods.emplace_back("F003", "Pasta", "Available", 180.0);
        foods.emplace_back("F004", "FrenchFries", "Available", 90.0);
        foods.emplace_back("F005", "Sandwich", "Available", 120.0);
    }

    // ------------------------------------------------
    // MENU
    // ------------------------------------------------

    ifstream menuFile(DATA_PATH + "menus.txt");

    while (getline(menuFile, line))
    {
        if (line.empty())
            continue;

        vector<string> data = splitLine(line);

        if (data.size() >= 3)
        {
            string category = data[2];
            if (category == "MainCourse")
            {
                const vector<string> cuisines = {"Indian", "Italian", "Chinese"};
                category = cuisines[menus.size() % cuisines.size()];
            }

            menus.push_back(
                Menu(
                    data[0],
                    data[1],
                    category
                )
            );
        }
    }

    menuFile.close();

    // Add one menu entry for each food when no menu records exist yet.
    if (menus.empty())
    {
        const vector<string> cuisines = {"Indian", "Italian", "Chinese"};
        for (size_t i = 0; i < foods.size(); ++i)
        {
            menus.emplace_back(
                "MN" + to_string(i + 1),
                foods[i].getId(),
                cuisines[i % cuisines.size()]
            );
        }
    }

    // ------------------------------------------------
    // ORDER
    // ------------------------------------------------

    ifstream orderFile(DATA_PATH + "orders.txt");

    while (getline(orderFile, line))
    {
        if (line.empty())
            continue;

        vector<string> data = splitLine(line);

        if (data.size() >= 6)
        {
            orders.push_back(
                Order(
                    data[0],
                    data[1],
                    data[2],
                    data[3],
                    stoi(data[4]),
                    data[5]
                )
            );
        }
    }

    orderFile.close();

    if (orders.empty())
    {
        for (size_t i = 0; i < customers.size() && !foods.empty(); ++i)
        {
            ostringstream idBuilder;
            idBuilder << "O" << setw(3) << setfill('0') << i + 1;
            string crewId = receptionists.empty()
                ? ""
                : receptionists[i % receptionists.size()].getId();

            orders.emplace_back(
                idBuilder.str(),
                crewId,
                customers[i].getId(),
                foods[i % foods.size()].getId(),
                1,
                "Completed"
            );
        }
    }

    // ------------------------------------------------
    // PAYMENT
    // ------------------------------------------------

    ifstream paymentFile(DATA_PATH + "payments.txt");

    while (getline(paymentFile, line))
    {
        if (line.empty())
            continue;

        vector<string> data = splitLine(line);

        if (data.size() >= 6)
        {
            payments.push_back(
                Payment(
                    data[0],
                    data[1],
                    data[2],
                    data[3],
                    data[4],
                    stod(data[5])
                )
            );
        }
    }

    paymentFile.close();

    if (payments.empty())
    {
        for (size_t i = 0; i < orders.size(); ++i)
        {
            double amount = 0.0;
            for (Food &food : foods)
            {
                if (food.getId() == orders[i].getFoodId())
                {
                    amount = food.getPrice() * orders[i].getQuantity();
                    break;
                }
            }

            ostringstream idBuilder;
            idBuilder << "P" << setw(3) << setfill('0') << i + 1;
            ostringstream deliveryBuilder;
            deliveryBuilder << "D" << setw(3) << setfill('0') << i + 1;
            payments.emplace_back(
                idBuilder.str(),
                orders[i].getCustomerId(),
                orders[i].getId(),
                deliveryBuilder.str(),
                "2026-09-24",
                amount
            );
        }
    }

    // ------------------------------------------------
    // TRANSACTION
    // ------------------------------------------------

    ifstream transactionFile(
        DATA_PATH + "transactions.txt"
    );

    while (getline(transactionFile, line))
    {
        if (line.empty())
            continue;

        vector<string> data = splitLine(line);

        if (data.size() >= 6)
        {
            transactions.push_back(
                Transaction(
                    data[0],
                    data[1],
                    data[2],
                    data[3],
                    data[4],
                    data[5]
                )
            );
        }
    }

    transactionFile.close();

    if (transactions.empty())
    {
        for (size_t i = 0; i < orders.size(); ++i)
        {
            ostringstream idBuilder;
            idBuilder << "T" << setw(3) << setfill('0') << i + 1;
            transactions.emplace_back(
                idBuilder.str(),
                "2026-09-24",
                orders[i].getCustomerId(),
                orders[i].getCrewId(),
                orders[i].getId(),
                "2026-09-24"
            );
        }
    }

    // ------------------------------------------------
    // RESERVATION
    // ------------------------------------------------

    ifstream reservationFile(
        DATA_PATH + "reservations.txt"
    );

    while (getline(reservationFile, line))
    {
        if (line.empty())
            continue;

        vector<string> data = splitLine(line);

        if (data.size() >= 7)
        {
            reservations.push_back(
                Reservation(
                    data[0],
                    data[1],
                    stoi(data[2]),
                    stoi(data[3]),
                    data[4],
                    data[5],
                    data[6]
                )
            );
        }
    }

    reservationFile.close();

    if (reservations.empty())
    {
        for (size_t i = 0; i < customers.size() && i < 20; ++i)
        {
            ostringstream idBuilder;
            idBuilder << "RS" << setw(3) << setfill('0') << i + 1;
            ostringstream timeBuilder;
            timeBuilder << (18 + static_cast<int>(i)) << ":00";
            reservations.emplace_back(
                idBuilder.str(),
                customers[i].getId(),
                static_cast<int>(i + 1),
                2,
                "2026-09-25",
                timeBuilder.str(),
                "Confirmed"
            );
        }
    }
}

// ==================================================
// SAVE DATA
// ==================================================

void Restaurant::saveData()
{
    // ------------------------------------------------
    // MANAGERS
    // ------------------------------------------------

    ofstream managerFile(
        DATA_PATH + "managers.txt"
    );

    for (Manager &m : managers)
    {
        managerFile
            << m.getId() << "|"
            << m.getName() << "|"
            << m.getContact() << "|"
            << m.getCity() << "|"
            << m.getCountry() << "|"
            << m.getUsername() << "|"
            << m.getPassword() << "|"
            << m.getPin()
            << "\n";
    }

    managerFile.close();

    // ------------------------------------------------
    // RECEPTIONISTS
    // ------------------------------------------------

    ofstream receptionistFile(
        DATA_PATH + "receptionists.txt"
    );

    for (Receptionist &r : receptionists)
    {
        receptionistFile
            << r.getId() << "|"
            << r.getName() << "|"
            << r.getContact() << "|"
            << r.getCity() << "|"
            << r.getCountry() << "|"
            << r.getUsername() << "|"
            << r.getPassword() << "|"
            << r.getPin()
            << "\n";
    }

    receptionistFile.close();

    // ------------------------------------------------
    // CUSTOMERS
    // ------------------------------------------------

    ofstream customerFile(
        DATA_PATH + "customers.txt"
    );

    for (Customer &c : customers)
    {
        customerFile
            << c.getId() << "|"
            << c.getName() << "|"
            << c.getContact() << "|"
            << c.getCity() << "|"
            << c.getCountry() << "|"
            << c.getUsername() << "|"
            << c.getPassword()
            << "\n";
    }

    customerFile.close();

    // ------------------------------------------------
    // FOODS
    // ------------------------------------------------

    ofstream foodFile(DATA_PATH + "foods.txt");

    for (Food &f : foods)
    {
        foodFile
            << f.getId() << "|"
            << f.getName() << "|"
            << f.getStatus() << "|"
            << f.getPrice()
            << "\n";
    }

    foodFile.close();

    // ------------------------------------------------
    // MENUS
    // ------------------------------------------------

    ofstream menuFile(DATA_PATH + "menus.txt");

    for (Menu &m : menus)
    {
        menuFile
            << m.getId() << "|"
            << m.getFoodId() << "|"
            << m.getCategory()
            << "\n";
    }

    menuFile.close();

    ofstream orderFile(DATA_PATH + "orders.txt");
    for (Order &o : orders)
    {
        orderFile
            << o.getId() << "|"
            << o.getCrewId() << "|"
            << o.getCustomerId() << "|"
            << o.getFoodId() << "|"
            << o.getQuantity() << "|"
            << o.getStatus()
            << "\n";
    }
    orderFile.close();

    ofstream paymentFile(DATA_PATH + "payments.txt");
    for (Payment &p : payments)
    {
        paymentFile
            << p.getId() << "|"
            << p.getCustomerId() << "|"
            << p.getOrderId() << "|"
            << p.getDeliveryId() << "|"
            << p.getDate() << "|"
            << p.getAmount()
            << "\n";
    }
    paymentFile.close();

    ofstream transactionFile(DATA_PATH + "transactions.txt");
    for (Transaction &t : transactions)
    {
        transactionFile
            << t.getId() << "|"
            << t.getDate() << "|"
            << t.getCustomerId() << "|"
            << t.getCrewId() << "|"
            << t.getOrderId() << "|"
            << t.getReportDate()
            << "\n";
    }
    transactionFile.close();

    ofstream reservationFile(DATA_PATH + "reservations.txt");
    for (Reservation &r : reservations)
    {
        reservationFile
            << r.getId() << "|"
            << r.getCustomerId() << "|"
            << r.getTableNo() << "|"
            << r.getPersons() << "|"
            << r.getDate() << "|"
            << r.getTime() << "|"
            << r.getStatus()
            << "\n";
    }
    reservationFile.close();
}
