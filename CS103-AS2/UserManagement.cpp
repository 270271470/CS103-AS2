#include <iostream>
#include <fstream>
#include <vector>
#include "UserManagement.h"
#include "AdminManagement.h"
#include "OrderManagement.h"
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

    ofstream file("userdb.csv", ios_base::app);
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

    ifstream file("userdb.csv");
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
