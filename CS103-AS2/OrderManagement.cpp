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

struct discount {
    string code[5] = { "chrispbacn","tentickles","tacoboutit","iamonaroll" };
    bool used[5] = { 0,0,0,0 };
    int damount[5] = { 5,10,20,25 };
}; // discount

order ord;
discount dis;
int orderamount = 0; //sum of the order
int discountnumber;
bool discounton = false;

bool existingOrder = false; //to check if there is a current order
bool paidOrder = false; //to check if previous order was already paid. If that was the case the bill should be reset and there should be no existing order

std::fstream orderFile("orderdb.csv", std::ios::in | std::ios::out | std::ios::app);

void discountapplied() {
    if (dis.used[discountnumber]) {
        std::cout << "\n*============================*\n" << endl;
        std::cout << "Discount applied: " << dis.code[discountnumber] << " - $" << dis.damount[discountnumber] << " off" << endl;
    }
}

void discountcode(const User& user) {
    string discode;

    cout << "Please enter your discount code: ";
    std::cin >> discode;

    for (int x = 0; x < 5; x++) {
        if (discode == dis.code[x]) {
            if (dis.used[x] == 0) {
                if (dis.damount[x] <= orderamount) {
                    orderamount -= dis.damount[x];
                    dis.used[x] = 1;
                    discountnumber = x;

                    discounton = true;

                    cout << "Discount applied.\nRefreshing...\n";
                    Sleep(2000);
                    break;
                }
                else {
                    cout << "Discount amount shoudld be less than or equal to total amount." << endl;
                    Sleep(1000);
                    break;
                }
            }
            else {
                cout << "Discount code has already been used.\n";
                Sleep(1000);
                break;
            }
        }
    }
    if (discode != dis.code[0] && discode != dis.code[1] && discode != dis.code[2] && discode != dis.code[3] && discode != dis.code[0]) {
        std::cout << "Not a valid discount code." << endl;
        Sleep(1000);
    }
}

void viewBill() {

    for (int x = 0; x < 5; x++) {
        if (ord.quantity[x] < 0) {
            ord.quantity[x] = 0;
        }
    }

    std::cout << "*======== Order List ========*\n" << endl;
    for (int x = 0; x < 5; x++) {
        if (ord.quantity[x] > 0) {
            std::cout << ord.item[x] << " - $" << ord.price[x] << " each = " << ord.quantity[x] << " orders total: $" << ord.quantity[x]*ord.price[x] << endl;
        }
    }
    discountapplied();
    std::cout << "\n*============================*\n" << endl;
    std::cout << "Total Amount: $" << orderamount << endl;
    std::cout << "\n*============================*" << endl;
}

void resetbill() {
    for (int x = 0; x < 5; x++) {
        ord.quantity[x] = 0;
        orderamount = 0;
        discounton = false;
    }
}

void printBill(const User& user) {
    // Check if orderFile is empty
    orderFile.seekg(0, std::ios::end);
    bool isEmpty = !orderFile.tellg();
    if (isEmpty) {
        orderFile << "OrderNumber,UserID,FirstName,LastName,Role,OrderItem,OrderPrice,OrderQnty,OrderTotal\n";
    }



    // Get current order number
    int orderNumber = 0;
    orderFile.seekg(0, std::ios::beg);
    std::string line;
    while (std::getline(orderFile, line)) ++orderNumber;



    orderFile.clear(); // Clear EOF flag to allow writing



    // Write orders
    for (int x = 0; x < 5; x++) {
        if (ord.quantity[x] > 0) {
            orderFile << orderNumber++ << ','
                << user.id << ','
                << user.firstName << ','
                << user.lastName << ','
                << user.role << ','
                << ord.item[x] << ','
                << ord.price[x] << ','
                << ord.quantity[x] << ','
                << orderamount << '\n';
        }
    }



    orderFile.close();

}

void orderLunch(const User& user) {
    int choice;
    int amount;

    if (paidOrder) {
        resetbill();
        existingOrder = false;
        paidOrder = false;
    }

    if (existingOrder) {
        int choiceOrder;
        orderMenuNav();
        std::cout << "There is an existing order, Do you want to reset all orders?\n";
        std::cout << "1. Yes\n";
        std::cout << "2. No\n";
        cout << "================================================================" << endl;
        std::cout << "Enter your input here: ";
        std::cin >> choiceOrder;

        if (choiceOrder == 1) {
            resetbill();
        }
    }

    do {
        system(CLEAR);
        orderMenuNav();
        viewBill();

        std::cout << "\nPlease choose an option:\n";
        for (int x = 0; x < 5; x++) {
            std::cout << x + 1 << ". " << ord.item[x] << " ($" << ord.price[x] << ")" << endl;
        }
        std::cout << "\n0. End Order\n";

        std::cout << "=================================\n";
        std::cout << "Enter your choice here: ";
        std::cin >> choice;
        if (choice != 0) {
            std::cout << "Enter quantity of item here: ";
            std::cin >> amount;
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

    do {
        system(CLEAR);
        orderMenuNav();
        viewBill();
        std::cout << "Choose Payment Method:\n";
        std::cout << "1. Card\n";
        std::cout << "2. Cash\n";
        if (discounton == false) {
            std::cout << "3. Input Discount\n";
        }
        std::cout << "\n0. Back\n";
        std::cout << "Enter your choice here: ";
        std::cin >> choice;

        system(CLEAR);
        orderMenuNav();
        viewBill();
        if (choice == 1) {
            string confirm;

            std::cout << "Payment Method: Card\n";
            do {
                std::cout << "\nInput CARD to confirm: ";
                std::cin >> confirm;

                if (confirm == "Card" || confirm == "card") {
                    std::cout << "Please type CARD in all capital letters." << endl;
                }
            } while (confirm != "CARD");
            paidOrder = true;

        }
        else if (choice == 2) {
            std::cout << "Payment Method: Cash\n";
            std::cout << "Place amount of cash: ";
            std::cin >> money;
            if (money != orderamount) {
                if (money > orderamount) {
                    change = money - orderamount;
                    std::cout << "Change: $" << change << endl;
                }
                else if (money < orderamount) {
                    do {

                        change = orderamount - money;

                        std::cout << "Received money is $" << change << " short\n";
                        std::cout << "Place amount of cash: ";
                        std::cin >> money;

                        if (money > orderamount) {
                            change = money - orderamount;
                            std::cout << "Change: $" << change << endl;
                        }
                    } while (money <= orderamount);
                }
            }
            paidOrder = true;
        }
        else if (choice == 3) {
            if ((discounton == false) && (orderamount > 0)) {
                discountcode(user);
            }
        }
        if (paidOrder) {
            printBill(user);

            std::cout << "\nThank you for ordering at LunchBytes!\n";
            std::cout << "Please take your receipt.\n";

            string take;
            do {
                std::cout << "\nInput TAKE to confirm: ";
                std::cin >> take;

                if (take == "Take" || take == "take") {
                    std::cout << "Please type TAKE in all capital letters." << endl;
                }
            } while (take != "TAKE");

            system(CLEAR);
            viewBill();
            std::cout << "\nExiting...\n";
            Sleep(3000);
        }
    } while ((choice != 0) && (paidOrder == false));
    
}

void editBill() {
    int choice;
    int amount;

    do {
        system(CLEAR);
        orderMenuNav();
        viewBill();
        Sleep(1000);

        cout << "\nIf you wish to reduce your order,\nPlease choose an option:\n";
        for (int x = 0; x < 5; x++) {
            if (ord.quantity[x] != 0) {
                cout << x + 1 << ". " << ord.item[x] << " - $" << ord.price[x] << " each, " << ord.quantity[x] << " orders total: $" << ord.quantity[x]*ord.price[x] << "\n";
            }
        }
        cout << "\n0. Exit\n";

        std::cout << "=================================\n";
        std::cout << "Enter your choice here: ";
        std::cin >> choice;
        if (choice != 0) {
            std::cout << "Enter quantity to reduce: ";
            std::cin >> amount;
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
        orderMenuNav();
        std::cout << "\nWelcome, " << user.firstName << "! Please choose an option:\n";
        std::cout << "1. Order Lunch\n";
        std::cout << "2. View Bill / Edit Bill\n";
        std::cout << "3. Checkout Order\n";
        std::cout << "\n0. Exit\n";

        cout << "==========================" << endl;
        cout << "Enter Your Selection: ";
        std::cin >> choice;

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
            if (paidOrder) { choice = 0; }
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
