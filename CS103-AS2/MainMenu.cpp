#include <iostream>
#include <iomanip>
#include "MainMenu.h"
#include "UserManagement.h"
#include "AdminManagement.h"

#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

void displayMainMenu() {
    int choice;
    string errorMsg;
    do {
        system(CLEAR);
        if (!errorMsg.empty()) {
            cout << errorMsg << "\n";
            errorMsg = "";
        }

        cout << "Please choose an option:\n";
        cout << "1. Login\n";
        cout << "2. Register as New User\n";
        cout << "3. Administrator Login\n";
        cout << "4. Exit\n";

        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
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
        case 4:
            cout << "Exiting the program...\n";
            break;
        default:
            errorMsg = "Invalid option!";
            break;
        }
    } while (choice != 4);
}