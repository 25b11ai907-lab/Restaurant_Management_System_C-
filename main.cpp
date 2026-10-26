#include <iostream>
#include <string>
#include <limits>
#include "restaurant.h"

using namespace std;

bool readMenuChoice(int &choice)
{
    if (cin >> choice)
        return true;

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid input. Enter a number shown in the menu.\n";
    return false;
}

int main()
{
    Restaurant restaurant;

    int choice;

    while (true)
    {
        cout << "\n\n";
        cout << "============================================\n";
        cout << "       RESTAURANT MANAGEMENT SYSTEM\n";
        cout << "============================================\n";
        cout << "1. Manager Login\n";
        cout << "2. Receptionist Login\n";
        cout << "3. Customer Login\n";
        cout << "4. Exit\n";
        cout << "============================================\n";

        cout << "Enter choice: ";
        if (!readMenuChoice(choice))
            continue;

        // ====================================================
        // MANAGER LOGIN
        // ====================================================

        if (choice == 1)
        {
            string id;
            string username;
            string password;
            string pin;

            int index;

            cout << "\n========== MANAGER LOGIN ==========\n";

            cout << "Enter Manager ID: ";
            cin >> id;

            cout << "Enter Username: ";
            cin >> username;

            cout << "Enter Password: ";
            cin >> password;

            cout << "Enter PIN: ";
            cin >> pin;

            if (restaurant.managerLogin(
                    id,
                    username,
                    password,
                    pin,
                    index))
            {
                cout << "\nManager login successful.\n";

                int managerChoice;

                while (true)
                {
                    cout << "\n============================================\n";
                    cout << "              MANAGER MENU\n";
                    cout << "============================================\n";

                    cout << "1. Show Manager Details\n";
                    cout << "2. Update Manager Details\n";
                    cout << "3. Add Receptionist\n";
                    cout << "4. View Receptionists\n";
                    cout << "5. Update Receptionist\n";
                    cout << "6. Delete Receptionist\n";
                    cout << "7. Add Customer\n";
                    cout << "8. View Customers\n";
                    cout << "9. Update Customer\n";
                    cout << "10. Delete Customer\n";
                    cout << "11. Food Information\n";
                    cout << "12. Update Food\n";
                    cout << "13. Menu Information\n";
                    cout << "14. Update Menu\n";
                    cout << "15. Order Information\n";
                    cout << "16. Update Order\n";
                    cout << "17. Payment Details\n";
                    cout << "18. Transaction Report\n";
                    cout << "19. Table Availability\n";
                    cout << "20. Reservation Details\n";
                    cout << "21. Add Food\n";
                    cout << "22. Delete Food\n";
                    cout << "23. Add Menu\n";
                    cout << "24. Delete Menu\n";
                    cout << "25. Logout\n";

                    cout << "============================================\n";
                    cout << "Enter choice: ";
                    if (!readMenuChoice(managerChoice))
                        continue;

                    switch (managerChoice)
                    {
                        case 1:
                            restaurant.showManagerDetails();
                            break;

                        case 2:
                            restaurant.updateManager();
                            break;

                        case 3:
                            restaurant.addReceptionist();
                            break;

                        case 4:
                            restaurant.receptionistDetails();
                            break;

                        case 5:
                            restaurant.updateReceptionist();
                            break;

                        case 6:
                        {
                            string loggedId = id;
                            restaurant.deleteReceptionist(loggedId);
                            break;
                        }

                        case 7:
                            restaurant.addCustomer();
                            break;

                        case 8:
                            restaurant.customerDetails();
                            break;

                        case 9:
                            restaurant.updateCustomer();
                            break;

                        case 10:
                            restaurant.deleteCustomer();
                            break;

                        case 11:
                            restaurant.foodInformation();
                            break;

                        case 12:
                            restaurant.updateFood();
                            break;

                        case 13:
                            restaurant.menuInformation();
                            break;

                        case 14:
                            restaurant.updateMenu();
                            break;

                        case 15:
                            restaurant.orderInformation();
                            break;

                        case 16:
                            restaurant.updateOrder();
                            break;

                        case 17:
                            restaurant.paymentDetails();
                            break;

                        case 18:
                            restaurant.transactionReport();
                            break;

                        case 19:
                            restaurant.tableAvailability();
                            break;

                        case 20:
                            restaurant.reservationDetails();
                            break;

                        case 21:
                            restaurant.addFood();
                            break;

                        case 22:
                            restaurant.deleteFood();
                            break;

                        case 23:
                            restaurant.addMenu();
                            break;

                        case 24:
                            restaurant.deleteMenu();
                            break;

                        case 25:
                            cout << "\nManager logged out.\n";
                            break;

                        default:
                            cout << "\nInvalid choice.\n";
                    }

                    if (managerChoice == 25)
                        break;
                }
            }
            else
            {
                cout << "\nInvalid manager login details.\n";
            }
        }

        // ====================================================
        // RECEPTIONIST LOGIN
        // ====================================================

        else if (choice == 2)
        {
            string id;
            string username;
            string password;
            string pin;

            int index;

            cout << "\n========== RECEPTIONIST LOGIN ==========\n";

            cout << "Enter Receptionist ID: ";
            cin >> id;

            cout << "Enter Username: ";
            cin >> username;

            cout << "Enter Password: ";
            cin >> password;

            cout << "Enter PIN: ";
            cin >> pin;

            if (restaurant.receptionistLogin(
                    id,
                    username,
                    password,
                    pin,
                    index))
            {
                cout << "\nReceptionist login successful.\n";

                int receptionistChoice;

                while (true)
                {
                    cout << "\n============================================\n";
                    cout << "           RECEPTIONIST MENU\n";
                    cout << "============================================\n";

                    cout << "1. My Details\n";
                    cout << "2. Add Customer\n";
                    cout << "3. View Customers\n";
                    cout << "4. Update Customer\n";
                    cout << "5. Delete Customer\n";
                    cout << "6. Food Information\n";
                    cout << "7. Menu Information\n";
                    cout << "8. Order Information\n";
                    cout << "9. Update Order\n";
                    cout << "10. Payment Details\n";
                    cout << "11. Transaction Report\n";
                    cout << "12. Table Availability\n";
                    cout << "13. Reservation Details\n";
                    cout << "14. Logout\n";

                    cout << "============================================\n";
                    cout << "Enter choice: ";
                    if (!readMenuChoice(receptionistChoice))
                        continue;

                    switch (receptionistChoice)
                    {
                        case 1:
                            restaurant.myReceptionistDetails(id);
                            break;

                        case 2:
                            restaurant.addCustomer();
                            break;

                        case 3:
                            restaurant.customerDetails();
                            break;

                        case 4:
                            restaurant.updateCustomer();
                            break;

                        case 5:
                            restaurant.deleteCustomer();
                            break;

                        case 6:
                            restaurant.foodInformation();
                            break;

                        case 7:
                            restaurant.menuInformation();
                            break;

                        case 8:
                            restaurant.orderInformation();
                            break;

                        case 9:
                            restaurant.updateOrder();
                            break;

                        case 10:
                            restaurant.paymentDetails();
                            break;

                        case 11:
                            restaurant.transactionReport();
                            break;

                        case 12:
                            restaurant.tableAvailability();
                            break;

                        case 13:
                            restaurant.reservationDetails();
                            break;

                        case 14:
                            cout << "\nReceptionist logged out.\n";
                            break;

                        default:
                            cout << "\nInvalid choice.\n";
                    }

                    if (receptionistChoice == 14)
                        break;
                }
            }
            else
            {
                cout << "\nInvalid receptionist login details.\n";
            }
        }

        // ====================================================
        // CUSTOMER LOGIN
        // ====================================================

        else if (choice == 3)
        {
            string id;
            string username;
            string password;

            int index;

            cout << "\n========== CUSTOMER LOGIN ==========\n";

            cout << "Enter Customer ID: ";
            cin >> id;

            cout << "Enter Username: ";
            cin >> username;

            cout << "Enter Password: ";
            cin >> password;

            if (restaurant.customerLogin(
                    id,
                    username,
                    password,
                    index))
            {
                cout << "\nCustomer login successful.\n";

                int customerChoice;

                while (true)
                {
                    cout << "\n============================================\n";
                    cout << "             CUSTOMER MENU\n";
                    cout << "============================================\n";

                    cout << "1. My Details\n";
                    cout << "2. View Food Information\n";
                    cout << "3. View Menu\n";
                    cout << "4. My Orders\n";
                    cout << "5. My Payment Details\n";
                    cout << "6. Table Availability\n";
                    cout << "7. Reserve a Table\n";
                    cout << "8. My Reservations\n";
                    cout << "9. Logout\n";

                    cout << "============================================\n";
                    cout << "Enter choice: ";
                    if (!readMenuChoice(customerChoice))
                        continue;

                    switch (customerChoice)
                    {
                        case 1:
                            restaurant.myCustomerDetails(id);
                            break;

                        case 2:
                            restaurant.foodInformation();
                            break;

                        case 3:
                            restaurant.menuInformation();
                            break;

                        case 4:
                            restaurant.customerOrders(id);
                            break;

                        case 5:
                            restaurant.customerPayment(id);
                            break;

                        case 6:
                            restaurant.tableAvailability();
                            break;

                        case 7:
                            restaurant.customerReserveTable(id);
                            break;

                        case 8:
                            restaurant.customerReservation(id);
                            break;

                        case 9:
                            cout << "\nCustomer logged out.\n";
                            break;

                        default:
                            cout << "\nInvalid choice.\n";
                    }

                    if (customerChoice == 9)
                        break;
                }
            }
            else
            {
                cout << "\nInvalid customer login details.\n";
            }
        }

        // ====================================================
        // EXIT
        // ====================================================

        else if (choice == 4)
        {
            cout << "\nThank you for using Restaurant Management System.\n";
            break;
        }

        else
        {
            cout << "\nInvalid choice. Please try again.\n";
        }
    }

    return 0;
}


