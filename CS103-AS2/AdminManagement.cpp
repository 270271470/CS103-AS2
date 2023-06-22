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
    while (getline(file, line)) {
        cout << line << "\n";
    }
}

void addUser() {
    registerUser();
}

void modifyUser() {

    system(CLEAR);
    // Display Admin Welcome Screen
    adminMenuModifyNav();

    string id;
    cout << "Enter the ID of the user to modify: ";
    cin >> id;

    vector<User> users;
    ifstream file("userdb.csv");
    string line;
    while (getline(file, line)) {
        vector<string> fields = split(line, ',');
        if (fields[2] == id) {
            User user;
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

void adminMenu() {

    system(CLEAR);
    // Display Admin Welcome Screen
    adminMenuNav();

    int choice;
    do {

        setConsoleColor(FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
        cout << "\nAdmin Menu:\n";
        setConsoleColor(7 | BACKGROUND_BLUE);
        cout << "1. View all records\n";
        cout << "2. Add a new user\n";
        cout << "3. Modify an existing user\n";
        cout << "4. Delete a user\n";
        cout << "0. Exit\n";
        // Capture the user's selection
        cout << "================================================================" << endl;
        setConsoleColor(FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
        cout << "Enter Your Selection:";
        setConsoleColor(7 | BACKGROUND_BLUE);
        cin >> choice;

        switch (choice) {
        case 0:
            cout << "Exiting the admin menu...\n";
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
        default:
            cout << "Invalid option!\n";
            break;
        }
    } while (choice != 0);
}