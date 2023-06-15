// CS103-AS2.cpp : School Lunch Ordering System

// This is our driver code.
// Because we are using a modular approach, the code in this file is kept to a minimum.
#include <Windows.h>

#include "WelcomeScreen.h"
#include "MainMenu.h"

int main() {

    // Display Welcome Screen
    displayWelcome();
    Sleep(3000);


    // Call displayMainMenu declared in MainMenu.h
    displayMainMenu();
    
    return 0;
}