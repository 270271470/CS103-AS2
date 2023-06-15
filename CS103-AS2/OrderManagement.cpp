#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "UserManagement.h"
#include "AdminManagement.h"
#include "FileOps.h"

#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

using namespace std;

string orderitems[5];
int orderamount = 0; //sum of the order

void viewBill() {
    system(CLEAR);
    std::cout << "*======== Order List ========*\n" << endl;
    for (int x = 0; x < 5; x++) {
        std::cout << orderitems[x] << endl;
    }
    std::cout << "Total Amount: " << orderamount << endl;
    std::cout << "\n*============================*" << endl;
}

void resetbill() {
    for (int x = 0; x < 5; x++) {
        orderitems[x] = "";
    }
}

void orderLunch(const User& user) {
    int choice;

    string item;
    int price = 0;
    resetbill();
    
    orderamount = 0; //sum of the order
    int orderlist = 0; //count for the orderitem

    ofstream file("orderdb.csv", ios::app);

    do {
        viewBill();

        std::cout << "\nPlease choose an option:\n";
        std::cout << "1. Hamburger ($5)\n";
        std::cout << "2. Hotdog ($3)\n";
        std::cout << "3. Pizza ($7)\n";
        std::cout << "0. End Order\n";

        std::cout << "Enter your choice here: ";
        cin >> choice;
        
        switch (choice) {
        case 1:
            item = "Hamburger";
            price = 5;
            orderitems[orderlist] = "Hamburger - $5";
            break;
        case 2:
            item = "Hotdog";
            price = 3;
            orderitems[orderlist] = "Hotdog - $3";
            break;
        case 3:
            item = "Pizza";
            price = 7;
            orderitems[orderlist] = "Pizza - $7";
            break;
        default:
            std::cout << "Invalid option!\n";
            return;
        case 0:
            break;
        }

        orderlist++;

        if (choice != 0) {
            file << user.id << ',' << user.firstName << ',' << user.lastName << ',' << user.role << ',' << item << ',' << price << '\n';
            std::cout << "\nOrder placed for " << item << " for " << price << " dollars.\n";
            orderamount += price;
        }

    } while (choice != 0);
    
    ofstream bill("bill.txt");
    if (bill.is_open()) {
        for (int x = 0; x < 5; x++) {
            bill << orderitems[x] << endl;
        }
    }
    bill << "Total Amount: " << orderamount << endl;

}

void userMenu(const User& user) {
    int choice;
    do {
        std::cout << "\nWelcome, " << user.firstName << "! Please choose an option:\n";
        std::cout << "1. Order Lunch\n";
        std::cout << "2. View Bill\n";
        std::cout << "3. Update Payment Method\n";
        std::cout << "0. Exit\n";

        cin >> choice;

        switch (choice) {
        case 1:
            orderLunch(user);
            break;
        case 2:
            viewBill();
            break;
            // Needs update payment, sorry me hehe
        case 0:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid option!\n";
            break;
        }
    } while (choice != 0);
}
