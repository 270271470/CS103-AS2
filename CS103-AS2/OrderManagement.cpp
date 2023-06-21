#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "UserManagement.h"
#include "AdminManagement.h"
#include "FileOps.h"
#include <Windows.h>
#include "WelcomeScreen.h"

#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

using namespace std;

struct order {
    string item[5] = { "Hamburger","Hotdog","Pizza","Sandwich","Rice Meal" };
    int price[5] = { 5,3,7,4,7 };
    int quantity[5] = { 0,0,0,0,0 };
}; //order placed in array, along with prices and quantity. The idea is that if the order item is 0, it won't be added to the list

order ord;
int orderamount = 0; //sum of the order
string timeofpickup[2] = { "10am","12nn" };

bool existingOrder = false; //to check if there is a current order

ofstream file("orderdb.csv", ios::app);

void viewBill() {

    for (int x = 0; x < 5; x++) {
        if (ord.quantity[x] < 0) {
            ord.quantity[x] = 0;
        }
    }

    std::cout << "*======== Order List ========*\n" << endl;
    for (int x = 0; x < 5; x++) {
        if (ord.quantity[x] > 0) {
            std::cout << ord.quantity[x] << " = " << ord.item[x] << " - $" << ord.price[x] << " each" << endl;
        }
    }
    std::cout << "Total Amount: " << orderamount << endl;
    std::cout << "\n*============================*" << endl;
}

void resetbill() {
    for (int x = 0; x < 5; x++) {
        ord.quantity[x] = 0;
        orderamount = 0;
    }
}

void printBill(const User& user) {
    for (int x = 0; x < 5; x++) {
        if (ord.quantity != 0) {
            file << user.id << ',' << user.firstName << ',' << user.lastName << ',' << user.role << ',' << ord.item[x] << ',' << ord.price[x] << '\n';
        }
    }

    ofstream bill("bill.txt");
    if (bill.is_open()) {
        for (int x = 0; x < 5; x++) {
            if (ord.quantity != 0) {
                bill << ord.item[x] << " - $" << ord.price[x] << endl;
            }
        }
    }
    bill << "=============================" << endl;
    bill << "Total Amount: " << orderamount << endl;
}

void orderLunch(const User& user) {
    int choice;
    int amount;

    if (existingOrder) {
        int choiceOrder;
        orderWelcome();
        std::cout << "There is an existing order, Do you want to reset all orders?\n";
        std::cout << "1. Yes\n";
        std::cout << "2. No\n";
        cout << "================================================================" << endl;
        std::cout << "Enter your input here: ";
        cin >> choiceOrder;

        if (choiceOrder == 1) {
            resetbill();
        }
    }

    do {
        system(CLEAR);
        viewBill();

        std::cout << "\nPlease choose an option:\n";
        for (int x = 0; x < 5; x++) {
            std::cout << x + 1 << ". " << ord.item[x] << " ($" << ord.price[x] << ")" << endl;
        }
        std::cout << "0. End Order\n";

        std::cout << "=================================\n";
        std::cout << "Enter your choice here: ";
        cin >> choice;
        if (choice != 0) {
            std::cout << "Enter quantity of item here: ";
            cin >> amount;
        }

        switch (choice) {
        case 1:
            ord.quantity[0] += amount;
            orderamount += (ord.price[0] * amount);
            break;
        case 2:
            ord.quantity[1] += amount;
            orderamount += (ord.price[1] * amount);
            break;
        case 3:
            ord.quantity[2] += amount;
            orderamount += (ord.price[2] * amount);
            break;
        case 4:
            ord.quantity[3] += amount;
            orderamount += (ord.price[3] * amount);
            break;
        case 5:
            ord.quantity[4] += amount;
            orderamount += (ord.price[4] * amount);
            break;
        default:
            std::cout << "Invalid option!\n";
            return;
        case 0:
            system(CLEAR);
            break;
        }

    } while (choice != 0);

}

void checkoutOrder(const User& user) {

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

void editBill() {
    int choice;
    int amount;

    do {
        system(CLEAR);
        viewBill();
        Sleep(1000);

        cout << "\nIf you wish to reduce your order,\nPlease choose an option:\n";
        for (int x = 0; x < 5; x++) {
            if (ord.quantity[x] != 0) {
                cout << x + 1 << ". " << ord.quantity[x] << " = " << ord.item[x] << " - $" << ord.price[x] << " each\n";
            }
        }
        cout << "0. Exit\n";

        std::cout << "=================================\n";
        std::cout << "Enter your choice here: ";
        cin >> choice;
        if (choice != 0) {
            std::cout << "Enter quantity to reduce: ";
            cin >> amount;
        }

            switch (choice) {
            case 1:
                if (ord.quantity[0] > 0) {
                    ord.quantity[0] -= amount;
                    orderamount -= (ord.price[0] * amount);
                }
                break;
            case 2:
                if (ord.quantity[1] > 0) {
                    ord.quantity[1] -= amount;
                    orderamount -= (ord.price[1] * amount);
                }
                break;
            case 3:
                if (ord.quantity[2] > 0) {
                    ord.quantity[2] -= amount;
                    orderamount -= (ord.price[2] * amount);
                }
                break;
            case 4:
                if (ord.quantity[3] > 0) {
                    ord.quantity[3] -= amount;
                    orderamount -= (ord.price[3] * amount);
                }
                break;
            case 5:
                if (ord.quantity[4] > 0) {
                    ord.quantity[4] -= amount;
                    orderamount -= (ord.price[4] * amount);
                }
                break;
            default:
                std::cout << "Invalid option!\n";
                return;
            case 0:
                system(CLEAR);
                break;
            }
    } while (choice != 0);

}

void userMenu(const User& user) {
    int choice;
    do {
        system(CLEAR);
        orderWelcome();
        std::cout << "\nWelcome, " << user.firstName << "! Please choose an option:\n";
        std::cout << "1. Order Lunch\n";
        std::cout << "2. View Bill / Edit Bill\n";
        std::cout << "3. Checkout Order\n";
        std::cout << "0. Exit\n";

        cout << "==========================" << endl;
        cout << "Enter Your Selection: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system(CLEAR);
            orderLunch(user);
            existingOrder = true;
            break;
        case 2:
            system(CLEAR);
            editBill();
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
