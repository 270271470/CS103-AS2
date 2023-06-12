#include <iostream>
#include <fstream>
#include <vector>
#include "UserManagement.h"
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
    std::string id, password;
    std::cout << "Enter ID Number: ";
    std::cin >> id;
    std::cout << "Enter Password: ";
    std::cin >> password;

    std::ifstream file("database.csv");
    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> fields = split(line, ',');
        if (fields[2] == id && fields[3] == password) {
            std::cout << "Login successful!\n";
            User user{ fields[0], fields[1], fields[2], fields[3], fields[4] };
            std::system(CLEAR);
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

void viewRecords() {
    ifstream file("database.csv");
    string line;
    while (getline(file, line)) {
        cout << line << "\n";
    }
}

void addUser() {
    registerUser();
}

void modifyUser() {
    string id;
    cout << "Enter the ID of the user to modify: ";
    cin >> id;

    vector<User> users;
    ifstream file("database.csv");
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
            cout << "Enter new Password (current is " << fields[3] << "): ";
            cin >> user.password;
            cout << "Enter new role (current is " << fields[4] << "): ";
            cin >> user.role;
            users.push_back(user);
        }
        else {
            User user = { fields[0], fields[1], fields[2], fields[3], fields[4] };
            users.push_back(user);
        }
    }

    ofstream fileOut("database.csv");
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
    ifstream file("database.csv");
    string line;
    while (getline(file, line)) {
        vector<string> fields = split(line, ',');
        if (fields[2] != id) {
            User user = { fields[0], fields[1], fields[2], fields[3], fields[4] };
            users.push_back(user);
        }
    }

    ofstream fileOut("database.csv");
    for (const auto& user : users) {
        fileOut << user.firstName << ","
            << user.lastName << ","
            << user.id << ","
            << user.password << ","
            << user.role << "\n";
    }
}

void adminMenu() {
    int choice;
    do {
        cout << "\nAdmin Menu:\n";
        cout << "1. View all records\n";
        cout << "2. Add a new user\n";
        cout << "3. Modify an existing user\n";
        cout << "4. Delete a user\n";
        cout << "5. Exit\n";
        cin >> choice;

        switch (choice) {
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
            cout << "Exiting the admin menu...\n";
            break;
        default:
            cout << "Invalid option!\n";
            break;
        }
    } while (choice != 5);
}

bool adminUser() {
    string id, password;
    cout << "Enter Admin ID Number: ";
    cin >> id;
    cout << "Enter Password: ";
    cin >> password;

    ifstream file("database.csv");
    string line;
    while (getline(file, line)) {
        vector<string> fields = split(line, ',');
        if (fields[2] == id && fields[3] == password && fields[4] == "Admin") {
            adminMenu();
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