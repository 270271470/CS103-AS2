#pragma once

// Our User class holds the user data.
// Contains the user's first name, last name, ID number, password, and user type (Teacher/Student).
// There are getter functions to retrieve these fields.

#include <string>

using namespace std;

class User {
public:
    User(string firstName, string lastName, string id, string password, string userType);
    string getFirstName();
    string getLastName();
    string getId();
    string getPassword();
    string getUserType();

private:
    string firstName;
    string lastName;
    string id;
    string password;
    string userType;
};