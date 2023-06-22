// Including standard IO
#include <iostream>
#include <iomanip>
#include <windows.h>

// Including our modular header files

#include "MainMenu.h"
#include "UserManagement.h"
#include "AdminManagement.h"
#include "WelcomeScreen.h"

// To clear the screen after a user makes a selection
#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

// c = 7 for default color
void setConsoleColor(WORD c)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

// Function to display our MainMenu
void displayMainMenu() {

    int choice;
    string errorMsg;

    do {

        setConsoleColor(1 | 3);

        system(CLEAR);

        if (!errorMsg.empty()) {
            setConsoleColor(FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
            cout << errorMsg << "\n";
            errorMsg = "";
            setConsoleColor(1 | 3);
        }

        mainMenuNav();
        // Display menu selection to user
        cout << endl;
        cout << endl;
        cout << "1. User Login\n";
        cout << "2. Register as a New User\n";
        cout << "3. Administrator Login\n";
        cout << endl;
        cout << "0. Exit\n";
        cout << endl;

        // Capture the user's selection
        setConsoleColor(0 | BACKGROUND_GREEN | BACKGROUND_BLUE);
        cout << "================================================================" << endl;
        cout << endl;
        setConsoleColor(1 | 3);
        cout << "Please Enter Your Selection: ";
        cin >> choice;

        // Here we are using a simple switch case and check if the user has enetered valid details
        // If no valid details are found in the userdb.csv file, we throw an error
        switch (choice) {
        case 0:
            cout << "Exiting the program...\n";
            break;
        case 1:
            if (!loginUser()) {
                errorMsg = "Invalid credentials!";
            }
            break;
        case 2:
            registerUser();
            break;
        case 3:
            if (!adminUser()) {
                errorMsg = "Invalid admin credentials!";
            }
            break;
        default:
            errorMsg = "Invalid option!";
            break;
        }
    } while (choice != 0);
}