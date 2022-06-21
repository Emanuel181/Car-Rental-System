#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "SystemClass.h"
#include "AdministratorOptions.h"


bool EnterPassword()
{
	std::ifstream fin("admin.txt");
	Sleep(0.16); system("cls");
	std::cout << "\tIntroduceti parola de admin: ";
	std::string password; std::cin >> password;
	std::string passwordFromDb; fin >> passwordFromDb;

	if (password == passwordFromDb)
	{
		fin.close();
		return 1;
	}

	fin.close();
	return 0;
}


void DisplayOptions()
{
	std::cout << "\t[1] Administrator\n";
	std::cout << "\t[2] Company registration\n";
	std::cout << "\t[3] Client\n";
	std::cout << "\t[4] Exit the app\n";
	std::cout << "\tYour option: ";
}


void MainMenu(SystemClass mainOBJ, std::vector<std::string>branchesList)
{
	while (1)
	{
		DisplayOptions();
		std::string input;

		std::cin >> input;
		std::cin.ignore();
		if (InputValid(input))
		{
			int option = stoi(input);
			if (option <= 4)
			{
				if (option == 1)
				{
					int cnt = 0;
					while (cnt < 3)
					{
						int rez = EnterPassword();
						if (rez == 1) break;
						std::cout << "\tParola gresita, mai aveti " << 3 - cnt - 1 << " incercari. \n\tReinitiam logarea ";
						Sleep(2000);
						++cnt;
					}

					if (cnt < 3) AdminOptions(mainOBJ);
					else
					{
						std::cout << "\n\tPrea multe incercari! Revenim la meniul principal...";
						Sleep(2500); system("cls");
						MainMenu(mainOBJ, branchesList);

						break;
					}
				}
				else if (option == 2)
				{
					FirmRegistration(mainOBJ,branchesList);
					break;
				}
				else if (option == 3)
				{
					ClientOptions(mainOBJ,branchesList);
					break;
				}
				else if (option == 4)
				{
					Sleep(0.016);
					system("cls");
					std::cout << "\tYou left the app. Have a nice day.\n";
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