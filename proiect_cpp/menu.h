#pragma once
#include <string>
#include "SystemClass.h"
#include "AdministratorOptions.h"


void MainMenu(SystemClass mainOBJ)
{
	std::cout << "\t[1] Administrator\n";
	std::cout << "\t[2] Company registration\n";
	std::cout << "\t[3] Client\n";
	std::cout << "\t[4] Exit the app\n";
	std::cout << "\tYour option:\n";
	std::string input;
	while (1)
	{
		std::cout << "\t";
		std::cin >> input;
		std::cin.ignore();
		if (InputValid(input))
		{
			int option = stoi(input);
			if (option <= 4) {
				if (option == 1)
				{
					AdminOptions(mainOBJ);
					break;
				}
				if (option == 2)
				{
					FirmRegistration(mainOBJ);
					break;
				}
				if (option == 3)
				{
					ClientOptions(mainOBJ);
					break;
				}
				if (option == 4)
				{
					Sleep(0.016);
					system("cls");
					std::cout << "You left the app. Have a nice day.\n";
					exit(0);
				}
			}
			else
			{
				std::cout << "\tYour option is invalid\n";
				std::cout << "\tTry again\n";
			}
		}
		else
		{
			std::cout << "\tYour option is invalid\n";
			std::cout << "\tTry again\n";
		}
	}
}