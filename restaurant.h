#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "manager.h"
#include "receptionist.h"
#include "customer.h"
#include "food.h"
#include "menu.h"
#include "order.h"
#include "payment.h"
#include "transaction.h"
#include "reservation.h"

using namespace std;

class Restaurant
{
private:

    vector<Manager> managers;
    vector<Receptionist> receptionists;
    vector<Customer> customers;

    vector<Food> foods;
    vector<Menu> menus;
    vector<Order> orders;
    vector<Payment> payments;
    vector<Transaction> transactions;
    vector<Reservation> reservations;

    // Validation functions
    bool usernameExists(string username);
    bool passwordExists(string password);
    bool pinExists(string pin);
    bool idExists(string id);

    bool isDigits(string value);
    bool validUsername(string username);
    bool validPassword(string password);
    bool validContact(string country, string contact);

    string getValidUsername();
    string getValidPassword();
    string getValidPin();
    string getValidCountry();
    string getValidContact(string country);
    string generateCustomerId();

    // File handling
    void loadData();
    void saveData();

public:

    Restaurant();
    ~Restaurant();

    // Manager
    void showManagerDetails();
    void updateManager();

    // Receptionist
    void addReceptionist();
    void updateReceptionist();
    void deleteReceptionist(string loggedReceptionistId);
    void receptionistDetails();
    void myReceptionistDetails(string receptionistId);

    // Customer
    void addCustomer();
    void updateCustomer();
    void deleteCustomer();

    void customerDetails();
    void myCustomerDetails(string customerId);

    // Food
    void foodInformation();
    void addFood();
    void updateFood();
    void deleteFood();

    // Menu
    void menuInformation();
    void addMenu();
    void updateMenu();
    void deleteMenu();

    // Order
    void orderInformation();
    void customerOrders(string customerId);
    void updateOrder();

    // Payment
    void paymentDetails();
    void customerPayment(string customerId);

    // Transaction
    void transactionReport();

    // Reservation
    void tableAvailability();
    void reservationDetails();
    void customerReservation(string customerId);
    void customerReserveTable(string customerId);

    // Login
    bool managerLogin(
        string id,
        string username,
        string password,
        string pin,
        int &index
    );

    bool receptionistLogin(
        string id,
        string username,
        string password,
        string pin,
        int &index
    );

    bool customerLogin(
        string id,
        string username,
        string password,
        int &index
    );
};

#endif
