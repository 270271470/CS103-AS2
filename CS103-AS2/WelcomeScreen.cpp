// System Includes
#include <iostream>
#include <Windows.h>

using namespace std;

// Function - Diplay Welcome 1 of 3
void displayWelcomeTo() {

    cout << R"(
__      __        _                                _____       
\ \    / /  ___  | |  __   ___   _ __    ___      |_   _|  ___ 
 \ \/\/ /  / -_) | | / _| / _ \ | '  \  / -_)       | |   / _ \
  \_/\_/   \___| |_| \__| \___/ |_|_|_| \___|       |_|   \___/
)";
}

// Function - Diplay Welcome 2 of 3
void displayLunchBytes() {

    cout << R"(
 _                          _      ____          _             
| |                        | |    |  _ \        | |            
| |     _   _  _ __    ___ | |__  | |_) | _   _ | |_  ___  ___ 
| |    | | | || '_ \  / __|| '_ \ |  _ < | | | || __|/ _ \/ __|
| |____| |_| || | | || (__ | | | || |_) || |_| || |_|  __/\__ \
|______|\__,_||_| |_| \___||_| |_||____/  \__, | \__|\___||___/
                                           __/ |               
                                          |___/
)";
}

// Function - Diplay Welcome 3 of 3
void displayInitSystem() {

    cout << R"(
===============================================================
=                   Initialising System...                    =
===============================================================                                                
)";
}

// Function - Combine all 3 above to simulate some animation.

void displayWelcome() {
        displayWelcomeTo();
        Sleep(1000);
        displayLunchBytes();
        Sleep(1000);
        displayInitSystem();
        Sleep(1000);
}

// Function to display Welcome Screen
void userWelcome() {

    cout << R"(
 _                          _      ____          _             
| |                        | |    |  _ \        | |            
| |     _   _  _ __    ___ | |__  | |_) | _   _ | |_  ___  ___ 
| |    | | | || '_ \  / __|| '_ \ |  _ < | | | || __|/ _ \/ __|
| |____| |_| || | | || (__ | | | || |_) || |_| || |_|  __/\__ \
|______|\__,_||_| |_| \___||_| |_||____/  \__, | \__|\___||___/
                                           __/ |               
                                          |___/

================================================================
=                          USER MENU                           =
================================================================
)";
}