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
string getPasswordInput();
string encryptPassword(const string& password);
string decryptPassword(const string& password);