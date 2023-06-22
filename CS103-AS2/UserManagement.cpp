#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>
// Using this library to mask the user password
#include <conio.h>

// Our custom header files.
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

string getPasswordInput() {

    string password;
    char ch;

    while ((ch = _getch()) != '\r') {
        if (ch == 8 || ch == 127) {  // BACKSPACE key
            if (password.length() != 0) {
                cout << "\b \b"; // \b is backspace - moves cursor back one space
                password.erase(password.size() - 1);
            }
        }
        else if (ch == '\n' || ch == '\r') {
            cout << "\n";
            break;
        }
        else {
            password += ch;
            cout << '*';
        }
    }
    return password;
}

// Function - Takes input from password and generates encrypted string.
string encryptPassword(const string& password) {
    string encrypted = "";
    for (char c : password) {
        if (c >= 'a' && c <= 'z') encrypted += (c - 'a' + 3) % 26 + 'a';
        else if (c >= 'A' && c <= 'Z') encrypted += (c - 'A' + 3) % 26 + 'A';
        else encrypted += c;
    }
    return encrypted;
}

// Function - Takes input from password and reverse encrypted string.
string decryptPassword(const string& password) {
    string decrypted = "";
    for (char c : password) {
        if (c >= 'a' && c <= 'z') decrypted += (c - 'a' - 3 + 26) % 26 + 'a';
        else if (c >= 'A' && c <= 'Z') decrypted += (c - 'A' - 3 + 26) % 26 + 'A';
        else decrypted += c;
    }
    return decrypted;
}

void registerUser() {

    system(CLEAR);
    // Display User Registration Nav Screen
    userRegNav();

    User newUser;
    cout << "Enter First Name: ";
    cin >> newUser.firstName;

    cout << "Enter Last Name: ";
    cin >> newUser.lastName;

    cout << "Enter ID Number: ";
    cin >> newUser.id;

    cout << "Enter Password: ";
    newUser.password = getPasswordInput();

    cout << endl;

    string confirmPassword;
    cout << "Confirm Password: ";
    confirmPassword = getPasswordInput();

    while (newUser.password != confirmPassword) {
        cout << "Passwords do not match, please enter again.\n";
        cout << "Enter Password: ";
        newUser.password = getPasswordInput();

        cout << "Confirm Password: ";
        confirmPassword = getPasswordInput();
    }

    newUser.password = encryptPassword(newUser.password);

    cout << endl;

    cout << "Are you a Teacher or Student?: ";
    cin >> newUser.role;

    ofstream file("userdb.csv", ios_base::app);
    file << newUser.firstName << ","
        << newUser.lastName << ","
        << newUser.id << ","
        << newUser.password << ","
        << newUser.role << "\n";

    cout << "Registration Successful. Redirecting To Main Menu...";
    Sleep(2500);
}

bool loginUser() {

        system(CLEAR);
        // Display User Registration Nav Screen
        userLoginNav();

        string id, password;
        cout << "User ID Number: ";
        cin >> id;
        cout << "Enter Password: ";
        password = getPasswordInput();

        ifstream file("userdb.csv");
        string line;

        while (getline(file, line)) {

            vector<string> fields = split(line, ',');

            if (fields[2] == id && decryptPassword(fields[3]) == password) {
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