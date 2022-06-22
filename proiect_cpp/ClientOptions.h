#pragma once
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include "SystemClass.h"
#include "ReadUserData.h"
#include "AccountStuff.h"
#include "RentedCars.h"


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
					return;
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
	std::cout << "\t[2] View rented cars\n";
	std::cout << "\t[3] Go to main page\n";
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
			Customer customer;
			if (option <= 3)
			{
				if (option == 1)
				{
					Sleep(0.016);
					system("cls");
					std::string companyName="";
					bool confirm = false;
					AccountValidation(mainOBJ,branchesList, customer,companyName,confirm);
					if(confirm==true)
						RentalProcess(mainOBJ, customer,companyName);
					system("cls");
					std::cout << "\n\tRedirecting to main page...Please wait...\n";
					Sleep(2000);
					MainMenu(mainOBJ, branchesList);
					break;
				}
				if (option == 2)
				{
					ViewRentedCars(mainOBJ,customer,branchesList);
					break;
				}
				if (option == 3)
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





void AccountValidation(SystemClass mainOBJ,std::vector<std::string>branchesList,Customer& customer,std::string& companyName,bool& confirm) {
	Sleep(0.016);
	system("cls");
	std::cout << "\t[1] Log in\n";
	std::cout << "\t[2] Create an account\n";
	std::cout << "\t[3] Go to main page\n";
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
			if (option <= 3)
			{
				if (option == 1)
				{
					Sleep(0.2);
					system("cls");
					Customer customerObject;
					LoginIntoAccount(mainOBJ,customer,customerObject);
					//email = customerObject.GetCustomerIdentificationInfos().GetCustomerEmail();
					std::cout << "\n\tRedirecting to rental page...";
					Sleep(2000);
					system("cls");
					std::cin.ignore();
					RentalPeriod(customer,branchesList,companyName);
					std::cout << "\n\tPlease wait...";
					Sleep(2000);
					system("cls");
					break; 
				}
				if (option == 2)
				{
					Sleep(0.2);
					system("cls");
					Customer newCustomer=CreateAnAccount(mainOBJ,confirm);
					if (confirm == true) {
						Sleep(0.2);
						system("cls");
						std::cout << "\n\tRedirecting to login page...";
						Sleep(2000);
						system("cls");
						//Customer customerObject;
						LoginIntoAccount(mainOBJ, customer,newCustomer);
						//email = customerObject.GetCustomerIdentificationInfos().GetCustomerEmail();
						std::cout << "\n\tRedirecting to rental page...";
						Sleep(2000);
						system("cls");
						std::cin.ignore();
						RentalPeriod(customer, branchesList, companyName);
						mainOBJ.AddCustomerToBranch(customer, companyName);
						std::cout << "\n\tPlease wait...";
						Sleep(2000);
						system("cls");
					}
					break;
				}
				if (option == 3)
				{
					system("cls");
					std::cout << "\tPlease wait...\n";
					Sleep(1000);
					ClientOptions(mainOBJ, branchesList);
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

void GetEmail(std::string& email)
{
	std::cout << "\tPlease enter the email address:\n\t";
	std::cin >> email;
}


void GetPassword(std::string& password)
{
	std::cout << "\tPlease enter the password:\n\t";
	std::cin >> password;
}


void Error(int& count)
{
	Sleep(0.2); system("cls");
	--count;
	std::cout << "\n\tTry again.Your password is incorrect.\n";
}


void LoginIntoAccount(SystemClass mainOBJ, Customer& customerObject,Customer newCustomer)
{
	std::string email, password; email = password = "null";

	GetEmail(email);

	int count = 3;
	bool valid = false;

	while (1)
	{
		if (count > 0) { std::cout << "\n"; GetPassword(password); std::cout << '\n'; }
		else
		{
			count = 3;
			Sleep(0.2); system("cls");
			email = password = "null";
			GetEmail(email);
			std::cout << "\n"; GetPassword(password);  std::cout << '\n';
		}

		if (password != "null" && email != "null")
		{
			std::vector <std::vector <CompanyBranches>> arr = mainOBJ.GetCompanyBranches();

			for (const auto& it : arr)
			{
				for (const auto& company : it)
				{
					std::vector<Customer>arrCustomers = company.GetBranchCustomers();

					for (const auto& customer : arrCustomers)
					{
						std::string customerEmail = customer.GetCustomerIdentificationInfos().GetCustomerEmail();
						std::string customerPassword = customer.GetCustomerIdentificationInfos().GetCustomerPassword();

						if (email == customerEmail && password == customerPassword) 
						{
							customerObject = customer;
							valid = true;
							std::cout << "\n\tYour credentials are correct.\n\n";
							return;
						}
						else
						{
							if (email == newCustomer.GetCustomerIdentificationInfos().GetCustomerEmail() && password == newCustomer.GetCustomerIdentificationInfos().GetCustomerPassword())
							{
								customerObject = newCustomer;
								valid = true;
								std::cout << "\n\tYour credentials are correct.\n\n";
								return;
							}
						}
					}
				}
			}
		}
		Error(count);
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
	std::cout << "\n\t First name";
	DisplaySpaces(value - strlen("First Name") + maxWord-1);
	std::cout << "| "<<FirstName;
	DisplaySpaces(maxWord - FirstName.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2*maxWord + 1);

	std::cout << "\n\t Last name";
	DisplaySpaces(value - strlen("Last Name") + maxWord - 1);
	std::cout << "| "<<LastName;
	DisplaySpaces(maxWord - LastName.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2 * maxWord + 1);

	std::cout << "\n\t Email";
	DisplaySpaces(value - strlen("Email") + maxWord - 1);
	std::cout << "| "<<Email;
	DisplaySpaces(maxWord - Email.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2 * maxWord + 1);

	std::cout << "\n\t Telephone";
	DisplaySpaces(value - strlen("Telephone") + maxWord - 1);
	std::cout << "| "<<Telephone;
	DisplaySpaces(maxWord - Telephone.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2 * maxWord + 1);

	std::cout << "\n\t CNP";
	DisplaySpaces(value - strlen("CNP") + maxWord - 1);
	std::cout << "| "<<CNP;
	DisplaySpaces(maxWord - CNP.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2 * maxWord + 1);

	std::cout << "\n\t ID Series";
	DisplaySpaces(value - strlen("ID Series") + maxWord - 1);
	std::cout << "| "<<IDSeries;
	DisplaySpaces(maxWord - IDSeries.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2 * maxWord + 1);

	std::cout << "\n\t ID Number";
	DisplaySpaces(value - strlen("ID Number") + maxWord - 1);
	std::cout << "| "<<IDNumber;
	DisplaySpaces(maxWord - IDNumber.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2 * maxWord + 1);

	std::cout << "\n\t City";
	DisplaySpaces(value - strlen("City") + maxWord - 1);
	std::cout << "| "<<customerCity;
	DisplaySpaces(maxWord - customerCity.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2 * maxWord + 1);

	std::cout << "\n\t Country";
	DisplaySpaces(value - strlen("Country") + maxWord - 1);
	std::cout << "| "<<customerCountry;
	DisplaySpaces(maxWord - customerCountry.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2 * maxWord + 1);

	std::cout << "\n\t Postal code";
	DisplaySpaces(value - strlen("Postal Code") + maxWord - 1);
	std::cout << "| "<<customerPostalCode;
	DisplaySpaces(maxWord - customerPostalCode.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2 * maxWord + 1);

	std::cout << "\n\t Street number";
	DisplaySpaces(value - strlen("Street Number") + maxWord - 1);
	std::cout << "| "<<customerStreetNumber;
	DisplaySpaces(maxWord - customerStreetNumber.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2 * maxWord + 1);

	std::cout << "\n\t Driving Start Day";
	DisplaySpaces(value - strlen("Driving Start Day") + maxWord - 1);
	std::cout << "| "<<DrivingStartDay;
	DisplaySpaces(maxWord - DrivingStartDay.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2 * maxWord + 1);

	std::cout << "\n\t Driving Start Month";
	DisplaySpaces(value - strlen("Driving Start Month") + maxWord - 1);
	std::cout << "| "<<DrivingStartMonth;
	DisplaySpaces(maxWord - DrivingStartMonth.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2 * maxWord + 1);

	std::cout << "\n\t Driving Start Year";
	DisplaySpaces(value - strlen("Driving Start Year") + maxWord - 1);
	std::cout << "| "<<DrivingStartYear;
	DisplaySpaces(maxWord - DrivingStartYear.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2 * maxWord + 1);

	std::cout << "\n\t Driving End Day";
	DisplaySpaces(value - strlen("Driving End Day") + maxWord - 1);
	std::cout << "| "<<DrivingEndDay;
	DisplaySpaces(maxWord - DrivingEndDay.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2 * maxWord + 1);

	std::cout << "\n\t Driving End Month";
	DisplaySpaces(value - strlen("Driving End Month") + maxWord - 1);
	std::cout << "| "<<DrivingEndMonth;
	DisplaySpaces(maxWord - DrivingEndMonth.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2 * maxWord + 1);

	std::cout << "\n\t Driving End Year";
	DisplaySpaces(value - strlen("Driving End Year") + maxWord - 1);
	std::cout << "| "<<DrivingEndYear;
	DisplaySpaces(maxWord - DrivingEndYear.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2 * maxWord + 1);

	std::cout << "\n\t Password";
	DisplaySpaces(value - strlen("Password") + maxWord - 1);
	std::cout << "| "<<Password;
	DisplaySpaces(maxWord - Password.length() + 1);
	std::cout << "\n";
	DisplayLine(maxLength + 2 * maxWord + 1);
}


void RentalProcess(SystemClass mainOBJ, Customer customer, std::string companyName)
{
	std::vector<std::vector<CompanyBranches>>arr = mainOBJ.GetCompanyBranches();
	std::vector<Car>arrCars;
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			std::string name = arr[i][j].GetBranchName();
			if (name == companyName)
			{
				arrCars = arr[i][j].GetBranchCars();
				break;
			}
		}
	}

	std::string carName = "";
	std::cout << "\tChose one of the following cars:\n";
	for (int i = 0; i < arrCars.size(); i++)
	{
		std::cout << "\tCar number "<<i+1<<":\n "<<arrCars[i] << "\n\n";
	}
	std::cout << "\tIntroduce the number of the car you would like to rent:\n";
	std::string userInput = "";
	int option = 0;
	while (1)
	{
		std::cout << "\t";
		std::cin >> userInput;
		if (containsOnlyDigits(userInput) == true)
		{
			option = std::stoi(userInput);
			if (option > arrCars.size())
			{
				std::cout << "\n";
				std::cout << "\tThe option introduced is not valid.\n";
				std::cout << "\tTry again.\n";
			}
			else
			{
				break;
			}
		}
		else
		{
			std::cout << "\n";
			std::cout << "\tThe option introduced is not valid.\n";
			std::cout << "\tTry again.\n";
		}
	}
	option--;
	int randomNumber = rand() % 999999 + 1; //random number between 1 and 999999
	arrCars[option].SetCarAvailability(false);
	std::string carDetails = std::to_string(randomNumber) + ";" + customer.GetCustomerIdentificationInfos().GetCustomerFirstName() + ";" + customer.GetCustomerIdentificationInfos().GetCustomerLastName() + ";";
	carDetails += companyName + ";";
	carDetails += arrCars[option].GetCarMake() + ";" + arrCars[option].GetCarColor() + ";" + arrCars[option].GetCarTransmission() + ";" + arrCars[option].GetCarType()
		+ ";" + arrCars[option].GetCarEngineType() + ";" + std::to_string(arrCars[option].GetCarHorsepower()) + ";" + std::to_string(arrCars[option].GetCarNumberOfDoors()) + ";" + std::to_string(arrCars[option].GetCarNumberOfSeats())
		+ ";" + std::to_string(arrCars[option].GetCarConsumption()) + ";" + std::to_string(arrCars[option].GetCarAvailability()) + ";"
		+ std::to_string(arrCars[option].GetCarPrice()) + ";" + std::to_string(arrCars[option].GetCarDeposit()) + ";" + std::to_string(arrCars[option].GetCarAdvancePayment())
		+ ";" + std::to_string(arrCars[option].GetCarReview().GetCarValue()) + ";" + std::to_string(arrCars[option].GetCarReview().GetCarCleanliness()) + ";"
		+ std::to_string(arrCars[option].GetCarReview().GetCarComfort()) + ";" + std::to_string(arrCars[option].GetCarReview().GetCarCondition()) + ";"
		+ std::to_string(arrCars[option].GetCarReview().GetCarOverallMark()) + ";" + arrCars[option].GetCarReview().GetCarReview();

	std::ofstream rentedCarsFile;
	rentedCarsFile.open("RentedCars.txt",std::ios::app);
	rentedCarsFile << carDetails << "\n";
	rentedCarsFile.close();

}