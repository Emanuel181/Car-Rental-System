#pragma once
//#include "SystemClass.h"


void CompleteFiles(SystemClass mainOBJ)
{
	std::vector<std::vector<CompanyBranches>>arr = mainOBJ.GetCompanyBranches();
	std::vector<Car>arrCars;
	for (int i = 0; i < arr.size(); i++)
	{
		std::ofstream fbranch("Branches.txt");
		std::ofstream fcars("Cars.txt");

		for (int j = 0; j < arr[i].size(); j++)
		{
			std::string branch = "";
			std::string branchName = arr[i][j].GetBranchName();
			std::string branchCountry = arr[i][j].GetCountryName();
			std::string branchCity = arr[i][j].GetCityName();
			std::string branchReview = arr[i][j].GetReviews();
			std::string branchObs = arr[i][j].GetAdministratorOBS();
			std::string branchCars = std::to_string( arr[i][j].GetNumberOfCarsAvaible());
			std::string branchMark = std::to_string(arr[i][j].GetBranchMark());
			std::string branchStreet = arr[i][j].GetLocationAddress().GetStreetName();
			std::string branchStreetNumber = arr[i][j].GetLocationAddress().GetStreetNumber();
			std::string branchPostalCode = arr[i][j].GetLocationAddress().GetStreetPostalCode();
			std::string branchPhoneNumber = arr[i][j].GetContactClass().GetPhoneNumber();
			std::string branchEmail = arr[i][j].GetContactClass().GetEmail();
			std::string branchManagerName = arr[i][j].GetContactClass().GetManagerName();

			branch = branchName + ";" + branchCountry + ";" + branchCity + ";" + branchReview + ";" + branchObs + ";" + branchCars + ";" + branchMark + ";" +
				branchStreet + ";" + branchStreetNumber + ";" + branchPostalCode + ";" + branchPhoneNumber + ";" + branchEmail + ";" + branchManagerName;

			std::vector<Car>arrCars = arr[i][j].GetBranchCars();
			std::vector<Customer>arrCustomer = arr[i][j].GetBranchCustomers();

			std::ofstream carBranch;
			carBranch.open(branchName + "cars.txt", std::ios::out);
			std::ofstream customerBranch;
			customerBranch.open(branchName + "clients.txt", std::ios::out);
			std::ofstream clienstDatabaseFile;
			clienstDatabaseFile.open("ClientsDatabase.txt");

			std::string carDetails = "", customerDetails = "";
			std::string make = "", color = "", transmission = "", type = "", engineType = "", bhp = "";
			std::string numberDoors = "", numberSeats = "", consumption = "", availability = "", pricePerDay = "";
			std::string deposit = "", advancePayment = "", carCondition = "", cleanliness = "", comfort = "", value = "";
			std::string overallMark = "", carReview = "";

			for (int k = 0; k < arrCars.size(); k++)
			{
				make = arrCars[k].GetCarMake();
				color = arrCars[k].GetCarColor();
				transmission = arrCars[k].GetCarTransmission();
				type = arrCars[k].GetCarType();
				engineType = arrCars[k].GetCarEngineType();
				bhp = std::to_string(arrCars[k].GetCarHorsepower());
				numberDoors = std::to_string(arrCars[k].GetCarNumberOfDoors());
				numberSeats = std::to_string(arrCars[k].GetCarNumberOfSeats());
				consumption = std::to_string(arrCars[k].GetCarConsumption());
				if (arrCars[k].GetCarAvailability() == true)
					availability = "1";
				else
					availability = "0";
				pricePerDay = std::to_string(arrCars[k].GetCarPrice());
				deposit = std::to_string(arrCars[k].GetCarDeposit());
				advancePayment = std::to_string(arrCars[k].GetCarAdvancePayment());
				carCondition = std::to_string(arrCars[k].GetCarReview().GetCarCondition());
				cleanliness = std::to_string(arrCars[k].GetCarReview().GetCarCleanliness());
				comfort = std::to_string(arrCars[k].GetCarReview().GetCarComfort());
				overallMark = std::to_string(arrCars[k].GetCarReview().GetCarOverallMark());
				value = std::to_string(arrCars[k].GetCarReview().GetCarValue());
				carReview = arrCars[k].GetCarReview().GetCarReview();

				carDetails = make + ";" + color + ";" + transmission + ";" + type + ";" + bhp + ";" + engineType + ";" + numberDoors + ";" + numberSeats + ";" +
					consumption + ";" + availability + ";" + pricePerDay + ";" + deposit + ";" + advancePayment + ";" + value + ";" + cleanliness + ";" +
					comfort + ";" + carCondition + ";" + overallMark + ";" + carReview;

				carBranch << carDetails << "\n";
				fcars << carDetails << "\n";

			}

			for (int k = 0; k < arrCustomer.size(); k++)
			{
				IdentificationInfos id = arrCustomer[k].GetCustomerIdentificationInfos();
				CustomerHomeAdress homeAd = arrCustomer[k].GetCustomerHomeAdress();
				DrivingLicense driving = arrCustomer[k].GetCustomerDrivingLicense();
				RentalSchedule rental = arrCustomer[k].GetCustomerRentalSchedule();

				customerDetails = id.GetCustomerFirstName() + ";" + id.GetCustomerLastName() + ";" + id.GetCustomerEmail() +
					";" + id.GetCustomerTelephone() + ";" + id.GetCustomerCNP() + ";" + id.GetCustomerIDSeries() + ";" + id.GetCustomerIDCardNumber() + ";"
					+ homeAd.GetCustomerCountry() + ";" + homeAd.GetCustomerCity() + ";" + homeAd.GetCustomerPostalCode() + ";" + homeAd.GetCustomerStreet() + ";" +
					homeAd.GetCustomerStreetNumber() + ";" + driving.GetDrivingLicenseStartDay().GetStartDay() + ";" + driving.GetDrivingLicenseStartDay().GetStartMonth() + ";" + driving.GetDrivingLicenseStartDay().GetStartYear() +
					";" + driving.GetDrivingLicenseEndDay().GetEndDay() + ";" + driving.GetDrivingLicenseEndDay().GetEndMonth() + ";" + driving.GetDrivingLicenseEndDay().GetEndYear() + ";" + id.GetCustomerPassword();

				customerBranch << customerDetails << "\n";
			}

			carBranch.close();
			customerBranch.close();
			
		}

	}
}