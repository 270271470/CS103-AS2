#pragma once

// Our LoginHandler class is responsible for the user interactions of logging in and registering.
// handleLogin() asks for user input of ID and password and attempts to log in with these credentials 
// using the Database's loginUser() function. handleRegistration() asks for user input of first name, 
// last name, ID, password, and user type, creates a User object with this data, and attempts to register 
// this user using the Database's registerUser() function.

#include <string>
#include "UserDatabase.h"

using namespace std;

class LoginHandler {
public:
    LoginHandler(UserDatabase& db);
    bool handleLogin();
    bool handleRegistration();
private:
    UserDatabase& db;
};