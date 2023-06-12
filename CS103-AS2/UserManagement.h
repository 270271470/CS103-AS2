#pragma once

#include <string>

using namespace std;

struct User {
    string firstName;
    string lastName;
    string id;
    string password;
    string role;
};

bool loginUser();
void registerUser();
bool adminUser();
void adminMenu();
void userMenu(const User& user);
void orderLunch(const User& user);