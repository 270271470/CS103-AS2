#include <fstream>
#include <sstream>
#include "UserDatabase.h"

using namespace std;

UserDatabase::UserDatabase(string filename) : filename(filename) {
    loadUsers();
}

void UserDatabase::loadUsers() {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        istringstream ss(line);
        string firstName, lastName, id, password, userType;
        getline(ss, firstName, ',');
        getline(ss, lastName, ',');
        getline(ss, id, ',');
        getline(ss, password, ',');
        getline(ss, userType, ',');
        users.push_back(User(firstName, lastName, id, password, userType));
    }
    file.close();
}

void UserDatabase::saveUsers() {
    ofstream file(filename);
    for (auto& user : users) {
        file << user.getFirstName() << ","
            << user.getLastName() << ","
            << user.getId() << ","
            << user.getPassword() << ","
            << user.getUserType() << endl;
    }
    file.close();
}

bool UserDatabase::registerUser(User user) {
    for (auto& u : users) {
        if (u.getId() == user.getId())
            return false;
    }
    users.push_back(user);
    saveUsers();
    return true;
}

bool UserDatabase::loginUser(string id, string password) {
    for (auto& user : users) {
        if (user.getId() == id && user.getPassword() == password)
            return true;
    }
    return false;
}