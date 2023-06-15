#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "UserManagement.h"
#include "AdminManagement.h"
#include "FileOps.h"
#include <Windows.h>

#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

using namespace std;

string orderitems[5];
string item[5] = { "a", "a", "a", "a", "a" };
int price[5] = { 0,0,0,0,0 };
int orderamount = 0; //sum of the order
int orderlist = 0; //count for the orderitem

bool existingOrder = false; //to check if there is a current order

ofstream file("orderdb.csv", ios::app);

void viewBill() {
    std::cout << "*======== Order List ========*\n" << endl;
    for (int x = 0; x < 5; x++) {
        if (item[x] != "a") {
            std::cout << orderitems[x] << endl;
        }
    }
    std::cout << "Total Amount: " << orderamount << endl;
    std::cout << "\n*============================*" << endl;
}

void resetbill() {
    for (int x = 0; x < 5; x++) {
        orderitems[x] = "";
        item[x] = "a";
        price[x] = 0;
        orderamount = 0;
    }
}

void printBill(const User& user) {
        for (int x = 0; x < 5; x++) {
            if (item[x] != "a") {
                file << user.id << ',' << user.firstName << ',' << user.lastName << ',' << user.role << ',' << item[x] << ',' << price[x] << '\n';
            }
        }

    ofstream bill("bill.txt");
    if (bill.is_open()) {
        for (int x = 0; x < 5; x++) {
            if (item[x] != "a") {
                bill << orderitems[x] << endl;
            }
        }
    }
    bill << "Total Amount: " << orderamount << endl;
}

void orderLunch(const User& user) {
    int choice;

    if (existingOrder) {
        int choiceOrder;

        std::cout << "There is an existing order, Do you want to reset all orders?\n";
        std::cout << "1. Yes\n";
        std::cout << "2. No\n";
        std::cout << "Enter your input here: ";
        cin >> choiceOrder;

        if (choiceOrder == 1) {
            resetbill();
            orderlist = 0; //count for the orderitem
        }
    }

    do {
        system(CLEAR);
        viewBill();

        std::cout << "\nPlease choose an option:\n";
        std::cout << "1. Hamburger ($5)\n";
        std::cout << "2. Hotdog ($3)\n";
        std::cout << "3. Pizza ($7)\n";
        std::cout << "4. Sandwich ($4)\n";
        std::cout << "5. Rice Meal ($7)\n";
        std::cout << "0. End Order\n";

        std::cout << "\nMinimum of 5 orders per customer.\n";
        std::cout << "Enter your choice here: ";
        cin >> choice;
        
        switch (choice) {
        case 1:
            item[orderlist] = "Hamburger";
            price[orderlist] = 5;
            orderitems[orderlist] = "Hamburger - $5";
            break;
        case 2:
            item[orderlist] = "Hotdog";
            price[orderlist] = 3;
            orderitems[orderlist] = "Hotdog - $3";
            break;
        case 3:
            item[orderlist] = "Pizza";
            price[orderlist] = 7;
            orderitems[orderlist] = "Pizza - $7";
            break;
        case 4:
            item[orderlist] = "Sandwich";
            price[orderlist] = 4;
            orderitems[orderlist] = "Sandwich - $4";
            break;
        case 5:
            item[orderlist] = "Rice Meal";
            price[orderlist] = 7;
            orderitems[orderlist] = "Rice Meal - $7";
            break;
        default:
            std::cout << "Invalid option!\n";
            return;
        case 0:
            system(CLEAR);
            break;
        }

        orderamount += price[orderlist];
        orderlist++;

    } while (choice != 0);

}

void checkoutOrder(const User& user) {
    viewBill();
    std::cout << "Press Enter to confirm your order...";
    cin.ignore();

    int money;
    int choice;
    int change;

    system(CLEAR);
    viewBill();
    std::cout << "Choose Payment Method:\n";
    std::cout << "1. Card\n";
    std::cout << "2. Cash\n";
    std::cout << "Enter your choice here: ";
    cin >> choice;

    system(CLEAR);
    viewBill();
    if (choice == 1) {
        string confirm;

        std::cout << "Payment Method: Card\n";
        do {
            std::cout << "\nInput CARD to confirm: ";
            cin >> confirm;

            if (confirm == "Card" || confirm == "card") {
                std::cout << "Please type CARD in all capital letters." << endl;
            }
        } while (confirm != "CARD");
        
    }
    else if (choice == 2) {
        std::cout << "Payment Method: Cash\n";
        std::cout << "Place amount of cash: ";
        cin >> money;
        if (money != orderamount) {
            do {

                change = orderamount - money;

                std::cout << "Received money is $" << change << " short\n";
                std::cout << "Place amount of cash: ";
                cin >> money;
            } while (money < orderamount);
            if (money > orderamount) {
                change = money - orderamount;
                std::cout << "Change: $" << change << endl;
            }
        }
    }

    printBill(user);

    std::cout << "\nThank you for ordering at LunchBytes!\n";
    std::cout << "Please take your receipt.\n";
    std::cout << "\nExiting...\n";
    Sleep(3000);

}

void userMenu(const User& user) {
    int choice;
    do {
        std::cout << "\nWelcome, " << user.firstName << "! Please choose an option:\n";
        std::cout << "1. Order Lunch\n";
        std::cout << "2. View Bill\n";
        std::cout << "3. Checkout Order\n";
        std::cout << "0. Exit\n";

        cin >> choice;

        switch (choice) {
        case 1:
            system(CLEAR);
            orderLunch(user);
            existingOrder = true;
            break;
        case 2:
            system(CLEAR);
            viewBill();
            break;
        case 3:
            checkoutOrder(user);
            choice = 0;
            break;
        case 0:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid option!\n";
            break;
        }
    } while (choice != 0);
}
