#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include "Prototypes.h"
#include "Validation.h"
#include "Menu.h"
#include "AdministratorOptions.h"
#include "ClientOptions.h"
#include "FirmRegistration.h"

void utility_loadingScreen()
{
    std::cout << "\n\n\n\n\n\n\n\n";
    system("color 0A");

    std::cout << "******************************************************************** CAR RENTAL SYSTEM **************************************************************************\n\n\n\n";
    system("color 0A");

    char a = 177, b = 219;

    std::cout << "\n\n\n\t\t\t\t\t\t\t\t\t       Loading...\n\n";
    std::cout << "\t\t\t\t\t";


    for (int i = 0; i < 80; i++)
        std::cout << a;

    std::cout << "\r";
    std::cout << "\t\t\t\t\t";


    for (int i = 0; i < 80; i++) {
        std::cout << b;
        Sleep(170);
    }

    std::cout << "\n\n\n\n";

    std::cout << "*****************************************************************************************************************************************************************\n\n\n";

    std::cout << "Please wait...";
    Sleep(7500);
    std::cout << "\n\n";
}


int main()
{
    utility_loadingScreen();
    MainMenu();

    return 0;
}