// CS103-AS2.cpp : School Lunch Ordering System

// Include our header files for the different components we are creating.
#include "UserDatabase.h"
#include "LoginHandler.h"
#include "MenuHandler.h"

int main() {

    // Create a Database object with the filename of the CSV file that holds the user data.
    UserDatabase db("users.csv");

    // Create a LoginHandler object with this Database
    LoginHandler lh(db);

    // Create a MenuHandler object with the above LoginHandler.
    MenuHandler mh(lh);

    // Call the start() function of MenuHandler to start the menu.
    mh.start();

    return 0;
}