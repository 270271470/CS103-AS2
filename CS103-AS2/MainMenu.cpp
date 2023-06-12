// Including standard IO
#include <iostream>
#include <iomanip>
// Including our modular header files

#include "MainMenu.h"
#include "UserManagement.h"
#include "AdminManagement.h"

// To clear the screen after a user makes a selection
#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

// Function to display our MainMenu
void displayMainMenu() {

    int choice;
    string errorMsg;

    do {

        system(CLEAR);
        if (!errorMsg.empty()) {
            cout << errorMsg << "\n";
            errorMsg = "";
        }

        // Display menu selection to user
        cout << "Please choose an option:\n";
        cout << "1. Login\n";
        cout << "2. Register as New User\n";
        cout << "3. Administrator Login\n";
        cout << "4. Exit\n";

        // Capture the user's selection
        cout << "Your choice: ";
        cin >> choice;

        // Here we are using a simple switch case and check if the user has enetered valid details
        // If no valid details are found in the userdb.csv file, we throw an error
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