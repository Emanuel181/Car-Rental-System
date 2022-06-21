#pragma once
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include "SystemClass.h"
#include "ReadUserData.h"
#include "AccountStuff.h"


void ConfirmCreateAccount(bool& valid)
{
	Sleep(0.016);
	std::cout << "\n\n";
	std::cout << "\tDo you want to create the account?\n";
	std::cout << "\t[1] Yes\n";
	std::cout << "\t[2] No\n";
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
			if (option <= 2)
			{
				if (option == 1)
				{
					valid = true;
					break;
				}
				if (option == 2)
				{
					valid = false;
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


void ClientOptions(SystemClass mainOBJ,std::vector<std::string>branchesList)
{
	Sleep(0.016);
	system("cls");
	std::cout << "\t[1] Rent a car\n";
	std::cout << "\t[2] Go to main page\n";
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
			if (option <= 2)
			{
				if (option == 1)
				{
					Sleep(0.016);
					system("cls");
					AccountValidation(mainOBJ,branchesList);
					break;
				}
				if (option == 2)
				{
					Sleep(0.016);
					system("cls");
					MainMenu(mainOBJ,branchesList);
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


void AccountValidation(SystemClass mainOBJ,std::vector<std::string>branchesList) {
	Sleep(0.016);
	system("cls");
	std::cout << "\t[1] Log in\n";
	std::cout << "\t[2] Create an account\n";
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
			if (option <= 2)
			{
				if (option == 1)
				{
					Sleep(0.2);
					system("cls");
					Customer customerObject;
					LoginIntoAccount(mainOBJ,customerObject);
					std::cout << "\n\tRedirecting to rental page...";
					Sleep(2000);
					system("cls");
					std::cin.ignore();
					RentalPeriod(customerObject,branchesList);
					break; 
				}
				if (option == 2)
				{
					Sleep(0.2);
					system("cls");
					CreateAnAccount(mainOBJ);
					Sleep(0.2);
					system("cls");
					std::cout << "\n\tRedirecting to login page...";
					Sleep(2000);
					system("cls");
					Customer customerObject;
					LoginIntoAccount(mainOBJ,customerObject);
					std::cout << "\n\tRedirecting to rental page...";
					Sleep(2000);
					system("cls");
					std::cin.ignore();
					RentalPeriod(customerObject,branchesList);
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


void LoginIntoAccount(SystemClass mainOBJ,Customer& customerObject) {
	std::string email = "", password = "";
	std::cout << "\tPlease enter the email address:\n";
	std::cout << "\t";
	std::cin >> email;
	while (1)
	{
		std::cout << "\n\tPlease enter the password:\n";
		std::cout << "\t";
		std::cin >> password;
		std::cout << "\t";

		bool valid = false;

		std::vector<std::vector<CompanyBranches>>arr = mainOBJ.GetCompanyBranches();
		for (int i = 0; i < arr.size(); i++)
		{
			for (int j = 0; j < arr[i].size(); j++)
			{
				std::vector<Customer>arrCustomers = arr[i][j].GetBranchCustomers();
				for (int k = 0; k < arrCustomers.size(); k++)
				{
					std::string customerEmail= arrCustomers[k].GetCustomerIdentificationInfos().GetCustomerEmail();
					std::string customerPassword = arrCustomers[k].GetCustomerIdentificationInfos().GetCustomerPassword();
					if (email == customerEmail && password == customerPassword)
					{
						customerObject = arrCustomers[k];
						valid = true;
						std::cout << "\n\tYour credentials are correct.\n\n";
						break;
					}
				}
			}
		}

		if (valid == true)
			break;
		else 
		{
			Sleep(0.2);
			system("cls");
			std::cout << "\n\tTry again.Your password is incorrect.\n";
		}


		/*std::ifstream fin("Accounts.txt");
		char* line = new char[500];
		customerEmailAddress = "";
		std::string customerPassword = "";
		bool valid = false;
		while (fin >> line)
		{
			char* p = strtok(line, ";");
			int count = 0;
			customerEmailAddress = "";
			customerPassword = "";
			while (p)
			{
				if (count == 2)
				{
					customerEmailAddress = p;
				}
				if (count == 18)
				{
					customerPassword = p;
				}
				if (customerEmailAddress != "" && customerPassword != "") {
					if (customerEmailAddress == email && customerPassword == password)
					{
						valid = true;
						std::cout << "\n\tYour credentials are correct.\n\n";
						break;
					}
				}
				count++;
				p = strtok(NULL, ";");
			}
			line = new char[500];
		}
		if (valid == true)
			break;
		else
		{
			delete[] line;
			Sleep(0.2);
			system("cls");
			std::cout << "\n\tTry again.Your password is incorrect.\n";
		}*/
	}

}

int maxim(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

void DisplayLine(int maxLength)
{
	std::cout << "\t";
	for (int i = 0; i < maxLength; i++)
		std::cout << "-";
}

void DisplaySpaces(int value)
{
	for (int i = 0; i < value; i++)
		std::cout << " ";
}

void DisplayAccountDetails(std::string FirstName, std::string  LastName, std::string  Email, std::string  Telephone, std::string  CNP, std::string  IDSeries, std::string  IDNumber, std::string customerCountry,
	std::string customerCity, std::string  customerPostalCode, std::string  customerStreet, std::string customerStreetNumber,
	std::string DrivingStartDay, std::string  DrivingStartMonth, std::string  DrivingStartYear, std::string  DrivingEndDay,
	std::string DrivingEndMonth, std::string  DrivingEndYear, std::string Password)
{
	int maxLength = INT_MIN;
	int maxWord = INT_MIN;
	maxLength = maxim(maxLength, strlen("FirstName") + FirstName.length());
	maxWord = maxim(maxWord, FirstName.length());

	maxLength = maxim(maxLength, strlen("LastName") + LastName.length());
	maxWord = maxim(maxWord, LastName.length());

	maxLength = maxim(maxLength, strlen("Email") + Email.length());
	maxWord = maxim(maxWord, Email.length());

	maxLength = maxim(maxLength, strlen("Telephone") + Telephone.length());
	maxWord = maxim(maxWord, Telephone.length());

	maxLength = maxim(maxLength, strlen("CNP") + CNP.length());
	maxWord = maxim(maxWord, CNP.length());

	maxLength = maxim(maxLength, strlen("IDSeries") + IDSeries.length());
	maxWord = maxim(maxWord, IDSeries.length());

	maxLength = maxim(maxLength, strlen("IDNumber") + IDNumber.length());
	maxWord = maxim(maxWord, IDNumber.length());

	maxLength = maxim(maxLength, strlen("customerCountry") + customerCountry.length());
	maxWord = maxim(maxWord, customerCountry.length());

	maxLength = maxim(maxLength, strlen("customerCity") + customerCity.length());
	maxWord = maxim(maxWord, customerCity.length());

	maxLength = maxim(maxLength, strlen("customerPostalCode") + customerPostalCode.length());
	maxWord = maxim(maxWord, customerPostalCode.length());

	maxLength = maxim(maxLength, strlen("customerStreetNumber") + customerStreetNumber.length());
	maxWord = maxim(maxWord, customerStreetNumber.length());

	maxLength = maxim(maxLength, strlen("DrivingStartDay") + DrivingStartDay.length());
	maxWord = maxim(maxWord, DrivingStartDay.length());

	maxLength = maxim(maxLength, strlen("DrivingStartMonth") + DrivingStartMonth.length());
	maxWord = maxim(maxWord, DrivingStartMonth.length());

	maxLength = maxim(maxLength, strlen("DrivingStartYear") + DrivingStartYear.length());
	maxWord = maxim(maxWord, DrivingStartYear.length());

	maxLength = maxim(maxLength, strlen("DrivingEndDay") + DrivingEndDay.length());
	maxWord = maxim(maxWord, DrivingEndDay.length());

	maxLength = maxim(maxLength, strlen("DrivingEndMonth") + DrivingEndMonth.length());
	maxWord = maxim(maxWord, DrivingEndMonth.length());

	maxLength = maxim(maxLength, strlen("DrivingEndYear") + DrivingEndYear.length());
	maxWord = maxim(maxWord, DrivingEndYear.length());

	maxLength = maxim(maxLength, strlen("Password") + Password.length());
	maxWord = maxim(maxWord, Password.length());

	int value = strlen("DrivingStartMonth");
	DisplayLine(maxLength+2*maxWord + 1);
	std::cout << "\n\t| First name";
	DisplaySpaces(value - strlen("First Name") + maxWord-1);
	std::cout << FirstName;
	DisplaySpaces(maxWord - FirstName.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2*maxWord + 1);

	std::cout << "\n\t| Last name";
	DisplaySpaces(value - strlen("Last Name") + maxWord - 1);
	std::cout << LastName;
	DisplaySpaces(maxWord - LastName.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2 * maxWord + 1);

	std::cout << "\n\t| Email";
	DisplaySpaces(value - strlen("Email") + maxWord - 1);
	std::cout << Email;
	DisplaySpaces(maxWord - Email.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2 * maxWord + 1);

	std::cout << "\n\t| Telephone";
	DisplaySpaces(value - strlen("Telephone") + maxWord - 1);
	std::cout << Telephone;
	DisplaySpaces(maxWord - Telephone.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2 * maxWord + 1);

	std::cout << "\n\t| CNP";
	DisplaySpaces(value - strlen("CNP") + maxWord - 1);
	std::cout << CNP;
	DisplaySpaces(maxWord - CNP.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2 * maxWord + 1);

	std::cout << "\n\t| ID Series";
	DisplaySpaces(value - strlen("ID Series") + maxWord - 1);
	std::cout << IDSeries;
	DisplaySpaces(maxWord - IDSeries.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2 * maxWord + 1);

	std::cout << "\n\t| ID Number";
	DisplaySpaces(value - strlen("ID Number") + maxWord - 1);
	std::cout << IDNumber;
	DisplaySpaces(maxWord - IDNumber.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2 * maxWord + 1);

	std::cout << "\n\t| City";
	DisplaySpaces(value - strlen("City") + maxWord - 1);
	std::cout << customerCity;
	DisplaySpaces(maxWord - customerCity.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2 * maxWord + 1);

	std::cout << "\n\t| Country";
	DisplaySpaces(value - strlen("Country") + maxWord - 1);
	std::cout << customerCountry;
	DisplaySpaces(maxWord - customerCountry.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2 * maxWord + 1);

	std::cout << "\n\t| Postal code";
	DisplaySpaces(value - strlen("Postal Code") + maxWord - 1);
	std::cout << customerPostalCode;
	DisplaySpaces(maxWord - customerPostalCode.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2 * maxWord + 1);

	std::cout << "\n\t| Street number";
	DisplaySpaces(value - strlen("Street Number") + maxWord - 1);
	std::cout << customerStreetNumber;
	DisplaySpaces(maxWord - customerStreetNumber.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2 * maxWord + 1);

	std::cout << "\n\t| Driving Start Day";
	DisplaySpaces(value - strlen("Driving Start Day") + maxWord - 1);
	std::cout << DrivingStartDay;
	DisplaySpaces(maxWord - DrivingStartDay.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2 * maxWord + 1);

	std::cout << "\n\t| Driving Start Month";
	DisplaySpaces(value - strlen("Driving Start Month") + maxWord - 1);
	std::cout << DrivingStartMonth;
	DisplaySpaces(maxWord - DrivingStartMonth.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2 * maxWord + 1);

	std::cout << "\n\t| Driving Start Year";
	DisplaySpaces(value - strlen("Driving Start Year") + maxWord - 1);
	std::cout << DrivingStartYear;
	DisplaySpaces(maxWord - DrivingStartYear.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2 * maxWord + 1);

	std::cout << "\n\t| Driving End Day";
	DisplaySpaces(value - strlen("Driving End Day") + maxWord - 1);
	std::cout << DrivingEndDay;
	DisplaySpaces(maxWord - DrivingEndDay.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2 * maxWord + 1);

	std::cout << "\n\t| Driving End Month";
	DisplaySpaces(value - strlen("Driving End Month") + maxWord - 1);
	std::cout << DrivingEndMonth;
	DisplaySpaces(maxWord - DrivingEndMonth.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2 * maxWord + 1);

	std::cout << "\n\t| Driving End Year";
	DisplaySpaces(value - strlen("Driving End Year") + maxWord - 1);
	std::cout << DrivingEndYear;
	DisplaySpaces(maxWord - DrivingEndYear.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2 * maxWord + 1);

	std::cout << "\n\t| Password";
	DisplaySpaces(value - strlen("Password") + maxWord - 1);
	std::cout << Password;
	DisplaySpaces(maxWord - Password.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2 * maxWord + 1);
}