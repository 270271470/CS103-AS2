// System Includes
#include <iostream>
#include <Windows.h>
#include "MainMenu.h"

using namespace std;

// Function - Diplay Welcome 1 of 3
void displayWelcomeTo() {

    setConsoleColor(1 | 3);
cout << R"(__      __        _                                _____       
\ \    / /  ___  | |  __   ___   _ __    ___      |_   _|  ___ 
 \ \/\/ /  / -_) | | / _| / _ \ | '  \  / -_)       | |   / _ \
  \_/\_/   \___| |_| \__| \___/ |_|_|_| \___|       |_|   \___/
)";
}

// Function - Diplay Welcome 2 of 3
void displayLunchBytes() {
    cout << R"( _                          _      ____          _             
| |                        | |    |  _ \        | |            
| |     _   _  _ __    ___ | |__  | |_) | _   _ | |_  ___  ___ 
| |    | | | || '_ \  / __|| '_ \ |  _ < | | | || __|/ _ \/ __|
| |____| |_| || | | || (__ | | | || |_) || |_| || |_|  __/\__ \
|______|\__,_||_| |_| \___||_| |_||____/  \__, | \__|\___||___/
                                           __/ |               
                                          |___/

                        (  )   (   )  )
                         ) (   )  (  (
                         ( )  (    ) )
                         _____________
                        <_____________> ___
                        |             |/ _ \
                        |               | | |
                        |               |_| |
                     ___|             |\___/
                    /    \___________/    \
                    \_____________________/)";
    cout << endl;
}

// Function - Diplay Welcome 3 of 3
void displayInitSystem() {

    cout << endl;
    setConsoleColor(0 | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << R"(===============================================================
=                   Initialising System...                    =
===============================================================)";
    setConsoleColor(7 | BACKGROUND_BLUE);
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

// Function to display User Welcome Screen
void mainMenuNav() {
    
    setConsoleColor(1 | 3);
cout << R"( _                          _      ____          _             
| |                        | |    |  _ \        | |            
| |     _   _  _ __    ___ | |__  | |_) | _   _ | |_  ___  ___ 
| |    | | | || '_ \  / __|| '_ \ |  _ < | | | || __|/ _ \/ __|
| |____| |_| || | | || (__ | | | || |_) || |_| || |_|  __/\__ \
|______|\__,_||_| |_| \___||_| |_||____/  \__, | \__|\___||___/
                                           __/ |               
                                          |___/               )";
cout << endl;
setConsoleColor(0 | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << R"(================================================================
=                          MAIN MENU                           =
================================================================)";
setConsoleColor(1 | 3);
}

// Function - User login nav
void userLoginNav() {
cout << R"( _                          _      ____          _             
| |                        | |    |  _ \        | |            
| |     _   _  _ __    ___ | |__  | |_) | _   _ | |_  ___  ___ 
| |    | | | || '_ \  / __|| '_ \ |  _ < | | | || __|/ _ \/ __|
| |____| |_| || | | || (__ | | | || |_) || |_| || |_|  __/\__ \
|______|\__,_||_| |_| \___||_| |_||____/  \__, | \__|\___||___/
                                           __/ |               
                                          |___/)";
cout << endl;
setConsoleColor(0 | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << R"(================================================================
=                          USER LOGIN                          =
================================================================
)";
setConsoleColor(1 | 3);
}

// Function - User Registration Nav
void userRegNav() {
cout << R"( _                          _      ____          _             
| |                        | |    |  _ \        | |            
| |     _   _  _ __    ___ | |__  | |_) | _   _ | |_  ___  ___ 
| |    | | | || '_ \  / __|| '_ \ |  _ < | | | || __|/ _ \/ __|
| |____| |_| || | | || (__ | | | || |_) || |_| || |_|  __/\__ \
|______|\__,_||_| |_| \___||_| |_||____/  \__, | \__|\___||___/
                                           __/ |               
                                          |___/)";
cout << endl;
setConsoleColor(0 | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << R"(================================================================
=                       USER REGISTRATION                      =
================================================================
)";
setConsoleColor(1 | 3);
}

// Function - Admin Menu
void adminMenuNav() {
cout << R"( _                          _      ____          _             
| |                        | |    |  _ \        | |            
| |     _   _  _ __    ___ | |__  | |_) | _   _ | |_  ___  ___ 
| |    | | | || '_ \  / __|| '_ \ |  _ < | | | || __|/ _ \/ __|
| |____| |_| || | | || (__ | | | || |_) || |_| || |_|  __/\__ \
|______|\__,_||_| |_| \___||_| |_||____/  \__, | \__|\___||___/
                                           __/ |               
                                          |___/)";
cout << endl;
setConsoleColor(0 | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << R"(================================================================
=                          ADMIN MENU                          =
================================================================
)";
setConsoleColor(1 | 3);
}

// Function - Admin Menu User Records
void adminMenuURecords() {
    cout << R"( _                          _      ____          _             
| |                        | |    |  _ \        | |            
| |     _   _  _ __    ___ | |__  | |_) | _   _ | |_  ___  ___ 
| |    | | | || '_ \  / __|| '_ \ |  _ < | | | || __|/ _ \/ __|
| |____| |_| || | | || (__ | | | || |_) || |_| || |_|  __/\__ \
|______|\__,_||_| |_| \___||_| |_||____/  \__, | \__|\___||___/
                                           __/ |               
                                          |___/)";
cout << endl;
setConsoleColor(0 | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << R"(================================================================
=              ADMIN MENU - VIEWING USER RECORDS               =
================================================================
)";
setConsoleColor(1 | 3);
}

// Function - Admin Menu Orders
void adminMenuOrders() {
    cout << R"( _                          _      ____          _             
| |                        | |    |  _ \        | |            
| |     _   _  _ __    ___ | |__  | |_) | _   _ | |_  ___  ___ 
| |    | | | || '_ \  / __|| '_ \ |  _ < | | | || __|/ _ \/ __|
| |____| |_| || | | || (__ | | | || |_) || |_| || |_|  __/\__ \
|______|\__,_||_| |_| \___||_| |_||____/  \__, | \__|\___||___/
                                           __/ |               
                                          |___/)";
    cout << endl;
    setConsoleColor(0 | BACKGROUND_GREEN | BACKGROUND_BLUE);
    cout << R"(================================================================
=              ADMIN MENU - VIEWING ALL ORDERS                 =
================================================================
)";
    setConsoleColor(1 | 3);
}

// Function - Admin Menu User Records
void adminMenuModifyNav() {
    cout << R"( _                          _      ____          _             
| |                        | |    |  _ \        | |            
| |     _   _  _ __    ___ | |__  | |_) | _   _ | |_  ___  ___ 
| |    | | | || '_ \  / __|| '_ \ |  _ < | | | || __|/ _ \/ __|
| |____| |_| || | | || (__ | | | || |_) || |_| || |_|  __/\__ \
|______|\__,_||_| |_| \___||_| |_||____/  \__, | \__|\___||___/
                                           __/ |               
                                          |___/)";
    cout << endl;
    setConsoleColor(0 | BACKGROUND_GREEN | BACKGROUND_BLUE);
    cout << R"(================================================================
=           ADMIN MENU - UPDATE USER INFORMATION               =
================================================================
)";
    setConsoleColor(1 | 3);
}

// Function - Order Menu Nav
void orderMenuNav() {
cout << R"( _                          _      ____          _             
| |                        | |    |  _ \        | |            
| |     _   _  _ __    ___ | |__  | |_) | _   _ | |_  ___  ___ 
| |    | | | || '_ \  / __|| '_ \ |  _ < | | | || __|/ _ \/ __|
| |____| |_| || | | || (__ | | | || |_) || |_| || |_|  __/\__ \
|______|\__,_||_| |_| \___||_| |_||____/  \__, | \__|\___||___/
                                           __/ |               
                                          |___/)";
cout << endl;
setConsoleColor(0 | BACKGROUND_GREEN | BACKGROUND_BLUE);
cout << R"(================================================================
=                          ORDER MENU                          =
================================================================
)";
setConsoleColor(1 | 3);
}