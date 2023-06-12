// CS103-AS2.cpp : School Lunch Ordering System

#include <iostream>
#include <iomanip>

int main() {
    char userChoice;
    const int consoleWidth = 80; // Assuming console is 80 characters wide

    std::string welcomeText = "Welcome to our School Lunch Ordering System!";
    int padding = (consoleWidth - welcomeText.length()) / 2;
    std::cout << std::setw(padding) << "" << welcomeText << std::endl;

    std::string roleText = "Please select your role:";
    padding = (consoleWidth - roleText.length()) / 2;
    std::cout << std::setw(padding) << "" << roleText << std::endl;

    std::string studentText = "Press 'k' for Student";
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

    return 0;
}