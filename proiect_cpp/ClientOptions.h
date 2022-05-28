#pragma once
#include <string>
#include "SystemClass.h"


void ClientOptions(SystemClass mainOBJ)
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
					PersonalDetails();
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


void ReadPersonalData(std::string& FirstName, std::string& LastName, std::string& Email, std::string& Telephone, std::string& CNP, std::string& IDSeries, std::string& IDNumber)
{
	std::cout << "\tPersonal data\n\n";

	std::cout << "\tFirst name: ";
	std::getline(std::cin, FirstName);
	std::cout << "\n";
	
	std::cout << "\tLast name: ";
	std::getline(std::cin, LastName);
	std::cout << "\n";

	std::cout << "\tEmail: ";
	while (1)
	{
		std::cin >> Email;
		std::cout << "\n\t";
		std::cin.ignore();
		if (EmailValidation(Email) == true)
			break;
		else
		{
			std::cout << "The email address introduced is not valid.\n";
			std::cout << "\tTry again.\n\n\t";
		}
	}
	
	//?
	std::cout << "Telephone: ";
	std::cin >> Telephone;
	std::cout << "\n";
	std::cin.ignore();
	
	std::cout << "\tCNP: ";
	while (1)
	{
		std::cin >> CNP;
		std::cout << "\n\t";
		std::cin.ignore();
		if (InputValid(CNP) == true && CNP.length() == 13)
			break;
		else
		{
			std::cout << "The CNP introduced is not valid.\n";
			std::cout << "\tTry again.\n\n\t";
		}
	}
	

	std::cout << "ID Card Series: ";
	while (1)
	{
		std::cin >> IDSeries;
		std::cout << "\n\t";
		std::cin.ignore();
		if (IDCardSeriesValid(IDSeries) == true)
			break;
		else
		{
			std::cout << "The ID Card series introduced is not valid.\n";
			std::cout << "\tTry again.\n\n\t";
		}
	}
	

	std::cout << "ID Card Number: ";
	while (1)
	{
		std::cin >> IDNumber;
		std::cout << "\n\t";
		std::cin.ignore();
		if (InputValid(IDNumber) == true)
			break;
		else
		{
			std::cout << "The ID Card Number introduced is not valid.\n";
			std::cout << "\tTry again.\n\n\t";
		}
	}
	

}


void ReadStartRentalDetails(std::string& StartDay, std::string& StartMonth, std::string& StartYear, std::string& StartHour, std::string& StartMinute)
{
	std::cout << "Rental details - start date:\n\n";
	std::cout << "\tRental Start Day: ";
	while (1)
	{
		std::cin >> StartDay;
		std::cout << "\n";
		std::cin.ignore();
		if (InputValid(StartDay) == true && (StartDay.length() <= 2 && StartDay.length() >= 1))
		{
			int numar = stoi(StartDay);
			if (numar >= 1 && numar <= 31)
				break;
			else
			{
				std::cout << "\tThe rental start day introduced is not valid.\n";
				std::cout << "\tTry again.\n\n\t";
			}
		}
		else
		{
			std::cout << "\tThe rental start day introduced is not valid.\n";
			std::cout << "\tTry again.\n\n\t";
		}
	}

	std::cout << "\tRental Start Month: ";
	while (1)
	{
		std::cin >> StartMonth;
		std::cout << "\n";
		std::cin.ignore();
		if (InputValid(StartMonth) == true && (StartMonth.length() <= 2 && StartMonth.length() >= 1))
		{
			int numar = stoi(StartMonth);
			if (numar >= 1 && numar <= 12)
				break;
			else
			{
				std::cout << "\tThe rental start month introduced is not valid.\n";
				std::cout << "\tTry again.\n\n\t";
			}
		}
		else
		{
			std::cout << "\tThe rental start month introduced is not valid.\n";
			std::cout << "\tTry again.\n\n\t";
		}
	}

	std::cout << "\tRental Start Year: ";
	while (1)
	{
		std::cin >> StartYear;
		std::cout << "\n";
		std::cin.ignore();
		if (InputValid(StartYear) == true && StartYear.length() == 4)
			break;
		else
		{
			std::cout << "\tThe rental start year introduced is not valid.\n";
			std::cout << "\tTry again.\n\n\t";
		}
	}

	std::cout << "\tRental Start Hour (should be between 8 and 17): ";
	while (1)
	{
		std::cin >> StartHour;
		std::cout << "\n";
		std::cin.ignore();
		if (RentalHourValidation(StartHour)==true)
			break;
		else
		{
			std::cout << "\tThe rental start hour introduced is not valid.\n";
			std::cout << "\tTry again.\n\n\t";
		}
	}

	std::cout << "\tRental Start Minute (should be between :00 or :30): ";
	while (1)
	{
		std::cin >> StartMinute;
		std::cout << "\n";
		std::cin.ignore();
		if (RentalMinuteValidation(StartMinute)==true)
			break;
		else
		{
			std::cout << "\tThe rental start minute introduced is not valid.\n";
			std::cout << "\tTry again.\n\n\t";
		}
	}

}


void ReadStopRentalDetails(std::string& EndDay, std::string& EndMonth, std::string& EndYear, std::string& EndHour, std::string& EndMinute)
{
	std::cout << "Rental details - end date:\n\n";
	std::cout << "\tRental End Day: ";
	while (1)
	{
		std::cin >> EndDay;
		std::cout << "\n";
		std::cin.ignore();
		if (InputValid(EndDay) == true && (EndDay.length() <= 2 && EndDay.length() >= 1))
		{
			int numar = stoi(EndDay);
			if (numar >= 1 && numar <= 31)
				break;
			else
			{
				std::cout << "\tThe rental end day introduced is not valid.\n";
				std::cout << "\tTry again.\n\n\t";
			}
		}
		else
		{
			std::cout << "\tThe rental end day introduced is not valid.\n";
			std::cout << "\tTry again.\n\n\t";
		}
	}

	std::cout << "\tRental End Month: ";
	while (1)
	{
		std::cin >> EndMonth;
		std::cout << "\n";
		std::cin.ignore();
		if (InputValid(EndMonth) == true && (EndMonth.length() <= 2 && EndMonth.length() >= 1))
		{
			int numar = stoi(EndMonth);
			if (numar >= 1 && numar <= 12)
				break;
			else
			{
				std::cout << "\tThe rental end month introduced is not valid.\n";
				std::cout << "\tTry again.\n\n\t";
			}
		}
		else
		{
			std::cout << "\tThe rental end month introduced is not valid.\n";
			std::cout << "\tTry again.\n\n\t";
		}
	}

	std::cout << "\tRental End Year: ";
	while (1)
	{
		std::cin >> EndYear;
		std::cout << "\n";
		std::cin.ignore();
		if (InputValid(EndYear) == true && EndYear.length() == 4)
			break;
		else
		{
			std::cout << "\tThe rental end year introduced is not valid.\n";
			std::cout << "\tTry again.\n\n\t";
		}
	}

	std::cout << "\tRental End Hour (should be between 8 and 17): ";
	while (1)
	{
		std::cin >> EndHour;
		std::cout << "\n";
		std::cin.ignore();
		if (RentalHourValidation(EndHour) == true)
			break;
		else
		{
			std::cout << "\tThe rental end hour introduced is not valid.\n";
			std::cout << "\tTry again.\n\n\t";
		}
	}

	std::cout << "\tRental End Minute (should be between :00 or :30): ";
	while (1)
	{
		std::cin >> EndMinute;
		std::cout << "\n";
		std::cin.ignore();
		if (RentalMinuteValidation(EndMinute) == true)
			break;
		else
		{
			std::cout << "\tThe rental end minute introduced is not valid.\n";
			std::cout << "\tTry again.\n\n\t";
		}
	}
}


void ReadDrivingLicenseDetails(std::string& DrivingStartDay, std::string& DrivingStartMonth, std::string& DrivingStartYear, std::string& DrivingEndDay, std::string& DrivingEndMonth, std::string& DrivingEndYear)
{
	std::cout << "\tDriving license details - start date:\n\n";
	std::cout << "\tDriving License Start Day: ";
	while (1)
	{
		std::cin >> DrivingStartDay;
		std::cout << "\n";
		std::cin.ignore();
		if (InputValid(DrivingStartDay) == true && (DrivingStartDay.length() <= 2 && DrivingStartDay.length() >= 1))
		{
			int numar = stoi(DrivingStartDay);
			if (numar >= 1 && numar <= 31)
				break;
			else
			{
				std::cout << "\tThe driving license start day introduced is not valid.\n";
				std::cout << "\tTry again.\n\n\t";
			}
		}
		else
		{
			std::cout << "\tThe driving license start day introduced is not valid.\n";
			std::cout << "\tTry again.\n\n\t";
		}
	}

	std::cout << "\tDriving license Start Month: ";
	while (1)
	{
		std::cin >> DrivingStartMonth;
		std::cout << "\n";
		std::cin.ignore();
		if (InputValid(DrivingStartMonth) == true && (DrivingStartMonth.length() <= 2 && DrivingStartMonth.length() >= 1))
		{
			int numar = stoi(DrivingStartMonth);
			if (numar >= 1 && numar <= 12)
				break;
			else
			{
				std::cout << "\tThe driving license start month introduced is not valid.\n";
				std::cout << "\tTry again.\n\n\t";
			}
		}
		else
		{
			std::cout << "\tThe driving license start month introduced is not valid.\n";
			std::cout << "\tTry again.\n\n\t";
		}
	}

	std::cout << "\tDriving license Start Year: ";
	while (1)
	{
		std::cin >> DrivingStartYear;
		std::cout << "\n";
		std::cin.ignore();
		if (InputValid(DrivingStartYear) == true && DrivingStartYear.length() == 4)
			break;
		else
		{
			std::cout << "\tThe driving license start year introduced is not valid.\n";
			std::cout << "\tTry again.\n\n\t";
		}
	}

	
	std::cout << "\tDriving License End Day: ";
	while (1)
	{
		std::cin >> DrivingEndDay;
		std::cout << "\n";
		std::cin.ignore();
		if (InputValid(DrivingEndDay) == true && (DrivingEndDay.length() <= 2 && DrivingEndDay.length() >= 1))
		{
			int numar = stoi(DrivingEndDay);
			if (numar >= 1 && numar <= 31)
				break;
			else
			{
				std::cout << "\tThe driving license end day introduced is not valid.\n";
				std::cout << "\tTry again.\n\n\t";
			}
		}
		else
		{
			std::cout << "\tThe driving license end day introduced is not valid.\n";
			std::cout << "\tTry again.\n\n\t";
		}
	}

	std::cout << "\tDriving license End Month: ";
	while (1)
	{
		std::cin >> DrivingEndMonth;
		std::cout << "\n";
		std::cin.ignore();
		if (InputValid(DrivingEndMonth) == true && (DrivingEndMonth.length() <= 2 && DrivingEndMonth.length() >= 1))
		{
			int numar = stoi(DrivingEndMonth);
			if (numar >= 1 && numar <= 12)
				break;
			else
			{
				std::cout << "\tThe driving license end month introduced is not valid.\n";
				std::cout << "\tTry again.\n\n\t";
			}
		}
		else
		{
			std::cout << "\tThe driving license end month introduced is not valid.\n";
			std::cout << "\tTry again.\n\n\t";
		}
	}

	std::cout << "\tDriving license End Year: ";
	while (1)
	{
		std::cin >> DrivingEndYear;
		std::cout << "\n";
		std::cin.ignore();
		if (InputValid(DrivingEndYear) == true && DrivingEndYear.length() == 4)
			break;
		else
		{
			std::cout << "\tThe driving license end year introduced is not valid.\n";
			std::cout << "\tTry again.\n\n\t";
		}
	}

}


void PersonalDetails()
{
	std::string FirstName, LastName, Email, Telephone, CNP, IDSeries, IDNumber, Mark;
	std::string StartDay, StartMonth, StartYear, StartHour, StartMinute;
	std::string EndDay, EndMonth, EndYear, EndHour, EndMinute;
	std::string DrivingStartDay, DrivingStartMonth, DrivingStartYear, DrivingEndDay, DrivingEndMonth, DrivingEndYear;
	std::string AbleToDrive;

	ReadPersonalData(FirstName,LastName,Email,Telephone,CNP,IDSeries,IDNumber);
	ReadStartRentalDetails(StartDay, StartMonth, StartYear, StartHour, StartMinute);
	ReadStopRentalDetails(EndDay,EndMonth,EndYear,EndHour,EndMinute);
	ReadDrivingLicenseDetails(DrivingStartDay, DrivingStartMonth, DrivingStartYear, DrivingEndDay, DrivingEndMonth, DrivingEndYear);


}