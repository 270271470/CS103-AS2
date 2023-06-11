#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include "MenuHandler.h"

using namespace std;

MenuHandler::MenuHandler(LoginHandler& lh) : lh(lh) {}

void MenuHandler::start() {

    const int consoleWidth = 150; // Set console width

    string asciiArt = R"(
 _                      _     ____        _            
| |                    | |   |  _ \      | |           
| |    _   _ _ __   ___| |__ | |_) |_   _| |_ ___  ___ 
| |   | | | | '_ \ / __| '_ \|  _ <| | | | __/ _ \/ __|
| |___| |_| | | | | (__| | | | |_) | |_| | ||  __/\__ \
|______\__,_|_| |_|\___|_| |_|____/ \__, |\__\___||___/
                                     __/ |             
                                    |___/                                    
)";

    // Calculate max line length
    istringstream ss(asciiArt);
    string line;
    int maxLength = 0;
    while (getline(ss, line)) {
        maxLength = max(maxLength, static_cast<int>(line.size()));
    }

    // Calc left padding
    int leftPadding = (consoleWidth - maxLength) / 2;

    // Display ASCII art with padding
    istringstream ss2(asciiArt);
    while (getline(ss2, line)) {
        cout << string(leftPadding, ' ') << line << endl;
    }

    cout << endl << endl;;

    string choice;

    while (true) {
        string menu = "Are you an existing user?\n1. Login\n2. Register\n3. Exit";
        int padding = (consoleWidth - menu.length()) / 2;
        menu = string(padding, ' ') + menu;

        cout << menu << endl;
        cin >> choice;

        if (choice == "2") {
            if (lh.handleRegistration())
                cout << string((consoleWidth - 23) / 2, ' ') << "Registration Successful!" << endl;
            else
                cout << string((consoleWidth - 51) / 2, ' ') << "Registration Failed. User with the same ID already exists." << endl;
        }
        else if (choice == "1") {
            if (lh.handleLogin())
                cout << string((consoleWidth - 18) / 2, ' ') << "Login Successful!" << endl;
            else
                cout << string((consoleWidth - 37) / 2, ' ') << "Login Failed. Incorrect ID or Password." << endl;
        }
        else if (choice == "3") {
            break;
        }
    }
}