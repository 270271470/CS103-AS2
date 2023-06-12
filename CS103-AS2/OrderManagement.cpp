#include <iostream>
#include <fstream>
#include <vector>
#include "UserManagement.h"
#include "AdminManagement.h"
#include "FileOps.h"

using namespace std;

void orderLunch(const User& user) {
    int choice;
    do {
        cout << "\nPlease choose an option:\n";
        cout << "1. Hamburger ($5)\n";
        cout << "2. Hotdog ($3)\n";
        cout << "3. Pizza ($7)\n";
        cout << "4. End Order\n";

        cout << "Enter your choice here: ";
        cin >> choice;

        string item;
        int price;
        switch (choice) {
        case 1:
            item = "Hamburger";
            price = 5;
            break;
        case 2:
            item = "Hotdog";
            price = 3;
            break;
        case 3:
            item = "Pizza";
            price = 7;
            break;
        default:
            cout << "Invalid option!\n";
            return;
        }

        ofstream file("orderdb.csv", ios::app);
        file << user.id << ',' << user.firstName << ',' << user.lastName << ',' << user.role << ',' << item << ',' << price << '\n';
        cout << "\nOrder placed for " << item << " for " << price << " dollars.\n";
    } while (choice != 4);
    
}

void userMenu(const User& user) {
    int choice;
    do {
        cout << "Welcome, " << user.firstName << "! Please choose an option:\n";
        cout << "1. Order Lunch\n";
        cout << "2. View Bill\n";
        cout << "3. Update Payment Method\n";
        cout << "4. Exit\n";

        cin >> choice;

        switch (choice) {
        case 1:
            orderLunch(user);
            break;
            // I haven't done the View Bill or Payment Method Yet, sorry John :)
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid option!\n";
            break;
        }
    } while (choice != 4);
}
