#pragma once
#include <string>


void ClientOptions()
{
	Sleep(0.016);
	system("cls");
	std::cout << "\t[1] Rent a car\n";
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
					PersonalDetails();
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


void PersonalDetails()
{
	std::string FirstName, LastName, Email, Telephone, CNP, IDSeries, IDNumber, Mark;
	std::string StartDay, StartMonth, StartYear, StartHour, StartMinute;
	std::string EndDay, EndMonth, EndYear, EndHour, EndMinute;
	std::string DrivingStartDay, DrivingStartMonth, DrivingStartYer, DrivingEndDay, DrivingEndMonth, DrivingEndYear;

}