// CS103-AS2.cpp : School Lunch Ordering System

#include <iostream>
#include <iomanip>
#include <stdlib.h>

void clear() {
    system("cls");
}

void login() {
    char userChoice;
    const int consoleWidth = 120; // Assuming console is 120 characters wide

    std::string welcomeText = "Welcome to our School Lunch Ordering System!";
    int padding = (consoleWidth - welcomeText.length()) / 2;
    std::cout << std::setw(padding) << "" << welcomeText << std::endl;

    std::string roleText = "Please select your role:";
    padding = (consoleWidth - roleText.length()) / 2;
    std::cout << std::setw(padding) << "" << roleText << std::endl;

    std::string studentText = "Press 'S' for Student";
    padding = (consoleWidth - studentText.length()) / 2;
    std::cout << std::setw(padding) << "" << studentText << std::endl;

    std::string adminText = "Press 'A' for Administrator";
    padding = (consoleWidth - adminText.length()) / 2;
    std::cout << std::setw(padding) << "" << adminText << std::endl;

    std::cin >> userChoice;

    switch (userChoice) {
    case 'S':
    case 's':
        std::cout << "Student selected" << std::endl;
        // Call the function that handles Student's tasks
        break;
    case 'A':
    case 'a':
        std::cout << "Administrator selected" << std::endl;
        // Call the function that handles Administrator's tasks
        break;
    default:
        std::cout << "Invalid selection!" << std::endl;
        break;
    }

}

void ViewDiscounts() {

}

void BrowseMenu() {

}

void foodMenu() {
    int userchoice;

    clear();

    std::cout << "[1] Browse Menu\n[2] View Discounts\n[0] Exit\n" << std::endl;
    std::cout << "Enter your choice here: ";
    std::cin >> userchoice;

    switch (userchoice) {
    case 1:
        std::cout << "Browse Menu Selected" << std::endl;
        break;
    case 2:
        std::cout << "View Discounts selected" << std::endl;
        break;
    case 0:
        exit(0);
    }
}

int main() {
    login();
    foodMenu();
}