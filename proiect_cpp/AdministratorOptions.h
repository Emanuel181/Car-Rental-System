#pragma once
#include <string>
#include "SystemClass.h"
#include <iostream>


void ViewCompanies(SystemClass mainOBJ)
{
	for (auto company : mainOBJ.GetCompanyBranches())
	{
		std::cout << company;
	}
}


void AdminOptions(SystemClass mainOBJ)
{
	Sleep(0.016); system("cls");

	std::cout << "\t[1] View registered companies\n";
	std::cout << "\t[2] Go to main page\n";
	std::cout << "\tYour option:\n";
	std::string input;
	while (1)
	{
		std::cout << "\t";
		std::cin >> input; std::cin.ignore();

		if (InputValid(input))
		{
			int option = stoi(input);
			if (option <= 2)
			{
				if (option == 1)
				{
					Sleep(0.016);
					system("cls");
					ViewCompanies(mainOBJ);
					break;
				}
				if (option == 2)
				{
					Sleep(0.016);
					system("cls");
					MainMenu(mainOBJ);
					break;
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