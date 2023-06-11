#include <iostream>
#include "MenuHandler.h"

using namespace std;

MenuHandler::MenuHandler(LoginHandler& lh) : lh(lh) {}

void MenuHandler::start() {
    string choice;
    while (true) {
        cout << "Are you an existing user?" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;
        if (choice == "2") {
            if (lh.handleRegistration())
                cout << "Registration Successful!" << endl;
            else
                cout << "Registration Failed. User with the same ID already exists." << endl;
        }
        else if (choice == "1") {
            if (lh.handleLogin())
                cout << "Login Successful!" << endl;
            else
                cout << "Login Failed. Incorrect ID or Password." << endl;
        }
        else if (choice == "3") {
            break;
        }
    }
}
