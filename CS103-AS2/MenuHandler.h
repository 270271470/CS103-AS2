#pragma once

// Our MenuHandler class is responsible for the user interactions of the menu. 
// It asks the user whether they want to log in, register, or exit, and calls the corresponding 
// LoginHandler functions based on the user's choice.

#include <string>
#include "LoginHandler.h"

class MenuHandler {
public:
    MenuHandler(LoginHandler& lh);
    void start();
private:
    LoginHandler& lh;
};
