#pragma once

// Our Database class handles user data.
// It reads the user data from a CSV file when it's initialised and stores it into a vector of User objects.
// We have 2 primary functions in this class - registerUser() and loginUser(). registerUser() takes a User object, 
// checks if a user with the same ID already exists in the database, if not, adds it to the user vector and updates 
// the CSV file. loginUser() takes an ID and password, checks if there's a user with the matching ID and password in the 
// database, then returns true if there is.

#include <vector>
#include <string>
#include "User.h"

using namespace std;

class UserDatabase {
public:
    UserDatabase(string filename);
    bool registerUser(User user);
    bool loginUser(string id, string password);

private:
    vector<User> users;
    string filename;
    void loadUsers();
    void saveUsers();
};