#pragma once
#include <string>


void AdminOptions()
{
	Sleep(0.016);
	system("cls");
	std::cout << "\t[1] View registered companies\n";
	std::cout << "\t[2] Go to main page\n";
	std::cout << "\tYour option:\n";
	std::string input;
	while (1)
	{
		std::cin >> input;
		std::cin.ignore();
		if (InputValid(input))
		{
			int option = stoi(input);
			if (option <= 2)
			{
				if (option == 1)
				{
					Sleep(0.016);
					system("cls");
					ViewCompanies();
					break;
				}
				if (option == 2)
				{
					Sleep(0.016);
					system("cls");
					MainMenu();
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

void ViewCompanies()
{

}