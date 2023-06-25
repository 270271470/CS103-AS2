#pragma once

#include <string>

using namespace std;

struct Order {
    string orderID;
    string userID;
    string firstName;
    string lastName;
    string role;
    string foodItem;
    string itemPrice;
    string  itemQnty;
    string totalPrice;
};

bool adminUser();
void adminMenu();