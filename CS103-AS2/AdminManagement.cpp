// System Includes
#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>

// Our Includes
#include "MainMenu.h"
#include "UserManagement.h"
#include "AdminManagement.h"
#include "OrderManagement.h"
#include "FileOps.h"
#include "WelcomeScreen.h"

using namespace std;

#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

bool adminUser() {

    system(CLEAR);
    // Display Admin Welcome Screen
    adminMenuNav();

    string id, password;

    cout << endl;
    cout << "Enter Admin ID Number: ";
    cin >> id;
    cout << "Enter Admin Password: ";
    password = getPasswordInput();

    system(CLEAR);

    ifstream file("userdb.csv");
    string line;
    while (getline(file, line)) {
        vector<string> fields = split(line, ',');
        if (fields[2] == id && (decryptPassword(fields[3]) == password) && fields[4] == "Admin") {
            // Display Admin Welcome Screen
            adminMenuNav();
            adminMenu();
            return true;
        }
    }
    return false;
}

void viewRecords() {

    system(CLEAR);

    adminMenuURecords();

    ifstream file("userdb.csv");
    string line;
    setConsoleColor(FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);

    cout << endl;
    while (getline(file, line)) {
        cout << line << "\n";
    }
    setConsoleColor(1 | 3);
}

void addUser() {
    registerUser();
}

void modifyUser() {

    system(CLEAR);
    // Display Admin Welcome Screen
    adminMenuModifyNav();

    string id;
    cout << endl;
    cout << "Enter the ID of the user to modify: ";
    cin >> id;

    vector<User> users;
    ifstream file("userdb.csv");
    string line;
    while (getline(file, line)) {
        vector<string> fields = split(line, ',');
        if (fields[2] == id) {
            User user;
            cout << endl;
            cout << "Enter new First Name (current is " << fields[0] << "): ";
            cin >> user.firstName;
            cout << "Enter new Last Name (current is " << fields[1] << "): ";
            cin >> user.lastName;
            user.id = id;
            cout << "Enter new Password: ";
            user.password = getPasswordInput();
            user.password = encryptPassword(user.password);
            cout << endl;
            cout << "Enter new role (current is " << fields[4] << "): ";
            cin >> user.role;
            users.push_back(user);
        }
        else {
            User user = { fields[0], fields[1], fields[2], fields[3], fields[4] };
            users.push_back(user);
        }
    }

    ofstream fileOut("userdb.csv");
    for (const auto& user : users) {
        fileOut << user.firstName << ","
            << user.lastName << ","
            << user.id << ","
            << user.password << ","
            << user.role << "\n";
    }
}

void deleteUser() {

    string id;
    cout << "Enter the ID of the user to delete: ";
    cin >> id;

    vector<User> users;
    ifstream file("userdb.csv");
    string line;
    while (getline(file, line)) {
        vector<string> fields = split(line, ',');
        if (fields[2] != id) {
            User user = { fields[0], fields[1], fields[2], fields[3], fields[4] };
            users.push_back(user);
        }
    }

    ofstream fileOut("userdb.csv");
    for (const auto& user : users) {
        fileOut << user.firstName << ","
            << user.lastName << ","
            << user.id << ","
            << user.password << ","
            << user.role << "\n";
    }
}
void viewOrders() {

    system(CLEAR);

    adminMenuOrders();

    ifstream file("orderdb.csv");
    string line;
    setConsoleColor(FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);

    cout << endl;
    while (getline(file, line)) {
        cout << line << "\n";
    }
    setConsoleColor(1 | 3);
}

void adminMenu() {

    system(CLEAR);
    // Display Admin Welcome Screen
    adminMenuNav();

    int choice;
    do {

        cout << endl;
        cout << "1. View All Users\n";
        cout << "2. Add New User\n";
        cout << "3. Update User Information\n";
        cout << "4. Delete User\n";
        cout << "------------------------------\n";
        cout << "5. View Orders\n";
        cout << "6. Update Order\n";
        cout << "7. Delete Order\n";
        cout << endl;
        cout << "0. Exit\n";
        // Capture the user's selection
        cout << endl;
        setConsoleColor(0 | BACKGROUND_GREEN | BACKGROUND_BLUE);
        cout << "================================================================";
        setConsoleColor(1 | 3);
        cout << endl;
        cout << endl;
        setConsoleColor(1 | 3);
        cout << "Please Enter Your Selection: ";
        cin >> choice;

        switch (choice) {
        case 0:
            cout << "Exiting the Admin Menu...\n";
            break;
        case 1:
            viewRecords();
            break;
        case 2:
            addUser();
            break;
        case 3:
            modifyUser();
            break;
        case 4:
            deleteUser();
            break;
        case 5:
            viewOrders();
            break;
        case 6:
            deleteUser();
            break;
        case 7:
            deleteUser();
            break;
        default:
            cout << "Invalid option!\n";
            break;
        }
    } while (choice != 0);
}