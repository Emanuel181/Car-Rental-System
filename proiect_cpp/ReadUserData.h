#pragma once


void ReadPersonalData(std::string& FirstName, std::string& LastName, std::string& Email, std::string& Telephone, std::string& CNP, std::string& IDSeries, std::string& IDNumber,SystemClass mainOBJ)
{
	std::cout << "\tPersonal data\n\n";

	std::cout << "\tFirst name: ";
	while (1)
	{
		std::getline(std::cin, FirstName);
		std::cout << "\n\t";
		if (AppearOnce(FirstName,mainOBJ,1) == true)
			break;
		else
		{
			std::cout << "The name introduced already exists.\n";
			std::cout << "\tTry again.\n\n\t";
		}
	}
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
		if (EmailValidation(Email) == true && AppearOnce(Email,mainOBJ,2)==true)
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
	std::cout << "\tRental details - start date:\n\n";
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
		if (RentalHourValidation(StartHour) == true)
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
		if (RentalMinuteValidation(StartMinute) == true)
			break;
		else
		{
			std::cout << "\tThe rental start minute introduced is not valid.\n";
			std::cout << "\tTry again.\n\n\t";
		}
	}

}


void ReadStopRentalDetails(std::string& EndDay, std::string& EndMonth, std::string& EndYear, std::string& EndHour, std::string& EndMinute, std::string StartDay, std::string StartMonth, std::string StartYear)
{


	int startDay = stoi(StartDay);
	int startMonth = stoi(StartMonth);
	int startYear = stoi(StartYear);
	std::cout << "\tRental details - end date:\n\n";
	std::cout << "\tRental End Year: ";
	while (1)
	{
		std::cin >> EndYear;
		std::cout << "\n";
		std::cin.ignore();
		if (InputValid(EndYear) == true) {
			int endYear = stoi(EndYear);
			if (EndYear.length() == 4 && endYear >= startYear)
			{
				break;
			}
			else
			{
				std::cout << "\tThe rental end year introduced is not valid.\n";
				std::cout << "\tTry again.\n\n\t";
			}
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
			if (numar >= 1 && numar <= 12 && numar >= startMonth)
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

	std::cout << "\tRental End Day: ";
	while (1)
	{
		std::cin >> EndDay;
		std::cout << "\n";
		std::cin.ignore();
		if (InputValid(EndDay) == true && (EndDay.length() <= 2 && EndDay.length() >= 1))
		{
			int numar = stoi(EndDay);
			if (numar >= 1 && numar <= 31 && numar > startDay)
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


	int drivingStartDay = stoi(DrivingStartDay);
	int drivingStartMonth = stoi(DrivingStartMonth);
	int drivingStartYear = stoi(DrivingStartYear);
	std::cout << "\tDriving license End Year: ";
	while (1)
	{
		std::cin >> DrivingEndYear;
		std::cout << "\n";
		std::cin.ignore();
		if (InputValid(DrivingEndYear) == true)
		{
			int drivingEndYear = stoi(DrivingEndYear);
			if (DrivingEndYear.length() == 4 && drivingEndYear > drivingStartYear)
			{
				break;
			}
			else
			{
				std::cout << "\tThe driving license end year introduced is not valid.\n";
				std::cout << "\tTry again.\n\n\t";
			}
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
	std::cout << "\t";
}


void ReadHomeDetails(std::string& customerCountry, std::string& customerCity, std::string& customerPostalCode, std::string& customerStreet, std::string& customerStreetNumber)
{
	std::cout << "\tHome address details\n\n";

	std::cout << "\tCountry: ";
	std::getline(std::cin, customerCountry);
	std::cout << "\n";

	std::cout << "\tCity: ";
	std::getline(std::cin, customerCity);
	std::cout << "\n";

	std::cout << "\tPostal code: ";
	while (1)
	{
		std::cin >> customerPostalCode;
		std::cout << "\n\t";
		std::cin.ignore();
		if (InputValid(customerPostalCode) == true)
			break;
		else
		{
			std::cout << "The postal code introduced is not valid.\n";
			std::cout << "\tTry again.\n\n\t";
		}
	}

	std::cout << "Street name: ";
	std::getline(std::cin, customerStreet);
	std::cout << "\n";


	std::cout << "\tCustomer street number: ";
	while (1)
	{
		std::cin >> customerStreetNumber;
		std::cout << "\n\t";
		std::cin.ignore();
		if (InputValid(customerStreetNumber) == true)
			break;
		else
		{
			std::cout << "The street number introduced is not valid.\n";
			std::cout << "\tTry again.\n\n\t";
		}
	}

}


void ReadRentalDetails(std::string& startRent, std::string& stopRent,std::string& companyName,std::vector<std::string>branchesList)
{
	std::cout << "\tRental details\n\n";

	std::cout << "\tIntroduce the city from where you want to rent the car: ";
	std::getline(std::cin, startRent);
	std::cout << "\n";

	std::cout << "\tIntroduce the city from where you are going to leave the car: ";
	std::getline(std::cin, stopRent);
	std::cout << "\n";
}


void RentalPeriod(Customer customerObject,std::vector<std::string>branchesList)
{
	std::string StartDay, StartMonth, StartYear, StartHour, StartMinute;
	std::string EndDay, EndMonth, EndYear, EndHour, EndMinute;
	std::string startRent, stopRent, companyName;

	ReadRentalDetails(startRent,stopRent,companyName,branchesList);
	ReadStartRentalDetails(StartDay, StartMonth, StartYear, StartHour, StartMinute);
	ReadStopRentalDetails(EndDay, EndMonth, EndYear, EndHour, EndMinute, StartDay, StartMonth, StartYear);
	
	std::cout << "\n\tPlease wait...\n";
	Sleep(2000);
	system("cls");
	for (int i = 0; i < branchesList.size(); i++)
	{
		std::cout << "\t" << i + 1 << " - " << branchesList[i] << "\n";
	}
	
	while (1)
	{
		std::cout << "\n";
		std::cout << "\tChoose one of the firms from the above: ";
		std::getline(std::cin, companyName);
		if (FirmExists(branchesList, companyName) == true)
			break;
		else
		{
			std::cout << "\n\tThere is no firm with that name.\n";
			std::cout << "\tTry again.\n";
		}
	}
	
	
	std::string clientDetails;
	std::string clientData;
	IdentificationInfos id = customerObject.GetCustomerIdentificationInfos();
	CustomerHomeAdress homeAd = customerObject.GetCustomerHomeAdress();
	DrivingLicense driving = customerObject.GetCustomerDrivingLicense();

	clientData = id.GetCustomerFirstName() + ";" + id.GetCustomerLastName() + ";" + id.GetCustomerEmail() +
		";" + id.GetCustomerTelephone() + ";" + id.GetCustomerCNP() + ";" + id.GetCustomerIDSeries() + ";" + id.GetCustomerIDCardNumber() + ";"
		+ homeAd.GetCustomerCountry() + ";" + homeAd.GetCustomerCity() + ";" + homeAd.GetCustomerPostalCode() + ";" + homeAd.GetCustomerStreet() + ";" +
		homeAd.GetCustomerStreetNumber() + ";" + driving.GetDrivingLicenseStartDay().GetStartDay()+ ";" + driving.GetDrivingLicenseStartDay().GetStartMonth()+ ";" + driving.GetDrivingLicenseStartDay().GetStartYear()+
		";" + driving.GetDrivingLicenseEndDay().GetEndDay()+ ";" + driving.GetDrivingLicenseEndDay().GetEndMonth()+ ";" + driving.GetDrivingLicenseEndDay().GetEndYear()+ ";" + id.GetCustomerPassword();

	std::ofstream fout;
	fout.open(companyName + ".txt", std::ios::app);
	fout << clientData<<"\n";
	fout.close();

	clientDetails += id.GetCustomerEmail() + ";" + startRent + ";" + stopRent + ";";
	clientDetails += StartDay + ";" + StartMonth + ";" + StartYear + ";" + StartHour + ";" + StartMinute + ";";
	clientDetails += EndDay + ";" + EndMonth + ";" + EndYear + ";" + EndHour + ";" + EndMinute +";" +companyName;

	std::ofstream fileOutput("ClientsDatabase.txt", std::ios_base::app | std::ios_base::out);
	fileOutput << clientDetails << "\n";
	fileOutput.close();
}