#pragma once


void CreateAnAccount(SystemClass mainOBJ) {
	std::string customerCountry, customerCity, customerPostalCode, customerStreet, customerStreetNumber;
	std::string FirstName, LastName, Email, Telephone, CNP, IDSeries, IDNumber, Mark;
	std::string DrivingStartDay, DrivingStartMonth, DrivingStartYear, DrivingEndDay, DrivingEndMonth, DrivingEndYear;
	std::string Password;
	//std::string AbleToDrive;
	bool valid = false;


	ReadPersonalData(FirstName, LastName, Email, Telephone, CNP, IDSeries, IDNumber);
	std::cout << "Please wait...";
	Sleep(2000);
	system("cls");
	ReadHomeDetails(customerCountry, customerCity, customerPostalCode, customerStreet, customerStreetNumber);
	std::cout << "Please wait...";
	Sleep(2000);
	system("cls");
	ReadDrivingLicenseDetails(DrivingStartDay, DrivingStartMonth, DrivingStartYear, DrivingEndDay, DrivingEndMonth, DrivingEndYear);
	std::cout << "Please wait...";
	Sleep(2000);
	system("cls");
	ReadCustomerPassword(Password);
	std::cout << "\n\tPlease wait...";
	Sleep(2000);
	system("cls");


	std::string personDetails;
	personDetails += FirstName + ";" + LastName + ";" + Email + ";" + Telephone + ";" + CNP + ";" + IDSeries + ";" + IDNumber + ";";
	personDetails += customerCountry + ";" + customerCity + ";" + customerPostalCode + ";" + customerStreet + ";" + customerStreetNumber + ";";
	personDetails += DrivingStartDay + ";" + DrivingStartMonth + ";" + DrivingStartYear + ";" + DrivingEndDay + ";" + DrivingEndMonth + ";" + DrivingEndYear + ";";
	personDetails += Password;
	//ValidateDrivingAbility(AbleToDrive,DrivingStartDay,DrivingStartMonth,DrivingStartYear,);
	DisplayAccountDetails(FirstName,LastName,Email,Telephone,CNP,IDSeries,IDNumber,customerCountry,customerCity,customerPostalCode,customerStreet,
		customerStreetNumber,DrivingStartDay,DrivingStartMonth,DrivingStartYear,DrivingEndDay,DrivingEndMonth,DrivingEndYear,Password);
	ConfirmCreateAccount(valid);
	if (valid == true) {
		std::ofstream fileOutput("Accounts.txt", std::ios_base::app | std::ios_base::out);
		fileOutput << personDetails << "\n";
		fileOutput.close();
	}
}


void ReadCustomerPassword(std::string& Password)
{
	std::string PasswordConfirmation;
	std::cout << "\tPlease enter the password:\n";
	std::cout << "\t";
	std::cin >> Password;
	std::cout << "\n\tPlease enter it again for confirmation:\n";
	while (1)
	{
		std::cout << "\t";
		std::cin >> PasswordConfirmation;
		if (Password != PasswordConfirmation)
		{
			std::cout << "\n\tThe two passwords do not match\n";
			std::cout << "\tTry again to confirm your password.\n\n";
		}
		else
		{
			break;
		}
	}
}