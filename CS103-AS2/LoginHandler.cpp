#include <iostream>
#include "LoginHandler.h"
#include "User.h"

using namespace std;

LoginHandler::LoginHandler(UserDatabase& db) : db(db) {}

bool LoginHandler::handleLogin() {
    string id, password;
    cout << "Enter ID Number: ";
    cin >> id;
    cout << "Enter Password: ";
    cin >> password;
    return db.loginUser(id, password);
}

bool LoginHandler::handleRegistration() {
    string firstName, lastName, id, password, userType;
    cout << "Enter First Name: ";
    cin >> firstName;
    cout << "Enter Last Name: ";
    cin >> lastName;
    cout << "Enter ID Number: ";
    cin >> id;
    cout << "Enter Password: ";
    cin >> password;
    cout << "Enter User Type (Teacher/Student): ";
    cin >> userType;
    User user(firstName, lastName, id, password, userType);
    return db.registerUser(user);
}