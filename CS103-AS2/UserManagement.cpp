#include <iostream>
#include <fstream>
#include <vector>
#include "UserManagement.h"
#include "AdminManagement.h"
#include "FileOps.h"

using namespace std;

#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

void registerUser() {
    User newUser;
    cout << "Enter First Name: ";
    cin >> newUser.firstName;
    cout << "Enter Last Name: ";
    cin >> newUser.lastName;
    cout << "Enter ID Number: ";
    cin >> newUser.id;
    cout << "Enter Password: ";
    cin >> newUser.password;
    string confirmPassword;
    cout << "Confirm Password: ";
    cin >> confirmPassword;

    if (newUser.password != confirmPassword) {
        cout << "Passwords do not match!\n";
        return;
    }

    cout << "Are you a Teacher or Student?: ";
    cin >> newUser.role;

    ofstream file("database.csv", ios_base::app);
    file << newUser.firstName << ","
        << newUser.lastName << ","
        << newUser.id << ","
        << newUser.password << ","
        << newUser.role << "\n";
}

bool loginUser() {
    string id, password;
    cout << "Enter ID Number: ";
    cin >> id;
    cout << "Enter Password: ";
    cin >> password;

    ifstream file("database.csv");
    string line;
    while (getline(file, line)) {
        vector<string> fields = split(line, ',');
        if (fields[2] == id && fields[3] == password) {
            cout << "Login successful!\n";
            User user{ fields[0], fields[1], fields[2], fields[3], fields[4] };
            system(CLEAR);
            if (user.role == "Admin") {
                adminMenu();
            }
            else {
                userMenu(user);
            }
            return true;
        }
    }
    return false;
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

void orderLunch(const User& user) {
    cout << "Please choose an option:\n";
    cout << "1. Hamburger ($5)\n";
    cout << "2. Hotdog ($3)\n";
    cout << "3. Pizza ($7)\n";

    int choice;
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

    ofstream file("orders.csv", ios::app);
    file << user.id << ',' << user.firstName << ',' << user.lastName << ',' << user.role << ',' << item << ',' << price << '\n';
    cout << "Order placed for " << item << " for " << price << " dollars.\n";
}