#pragma once
#include <string>



bool InputValid(std::string input)
{
	for (int i = 0; i < input.size(); i++)
	{
		if (strchr("01234567890", input[i]) == 0)
			return false;
	}
	return true;
}

void MainMenu()
{
	std::cout << "\t[1] Administrator\n";
	std::cout << "\t[2] Company registration\n";
	std::cout << "\t[3] Client\n";
	std::cout << "\t[4] Exit the app\n";
	std::cout << "\tYour option:\n";
	std::string input;
	while (1)
	{
		std::cin >> input;
		std::cin.ignore();
		if (InputValid(input))
		{
			int option = stoi(input);
			if (option <= 4) {
				if (option == 1)
				{
					AdminOptions();
					break;
				}
				if (option == 2)
				{
					FirmRegistration();
					break;
				}
				if (option == 3)
				{
					ClientOptions();
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