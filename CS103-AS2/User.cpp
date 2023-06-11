#include "User.h"

using namespace std;

User::User(string firstName, string lastName, string id, string password, string userType)
    : firstName(firstName), lastName(lastName), id(id), password(password), userType(userType) {}

string User::getFirstName() {
    return firstName;
}

string User::getLastName() {
    return lastName;
}

string User::getId() {
    return id;
}

string User::getPassword() {
    return password;
}

string User::getUserType() {
    return userType;
}
