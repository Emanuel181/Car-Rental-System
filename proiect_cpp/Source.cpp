#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <algorithm>
#include "Prototypes.h"
#include "Validation.h"
#include "Menu.h"
#include <vector>
#include "AdministratorOptions.h"
#include "ClientOptions.h"
#include "FirmRegistration.h"
#include "SystemClass.h"
#include "LocationAddress.h"
#include "StartTime.h"
#include "EndTime.h"


void utility_loadingScreen()
{
    std::cout << "\n\n\n\n\n\n\n\n";
    system("color 0A");

    std::cout << "******************************************************************** CAR RENTAL SYSTEM **************************************************************************\n\n\n\n";
    system("color 0A");

    char a = 177, b = 219;

    std::cout << "\n\n\n\t\t\t\t\t\t\t\t\t       Loading...\n\n";
    std::cout << "\t\t\t\t\t";


    for (int i = 0; i < 80; i++)
        std::cout << a;

    std::cout << "\r";
    std::cout << "\t\t\t\t\t";


    for (int i = 0; i < 80; i++) {
        std::cout << b;
        Sleep(170);
    }

    std::cout << "\n\n\n\n";

    std::cout << "*****************************************************************************************************************************************************************\n\n\n";

    std::cout << "Please wait...";
    Sleep(7500);
    std::cout << "\n\n";
}


int main()
{
    //utility_loadingScreen();
    //system("cls");

    CarReview carReview(10.0, 9.8, 9.9, 10, 9.9, "very good");
    DateOfBirth dateOfBirth("5", "6", "2022");
    CustomerHomeAdress customerHomeAdress("Romania", "Cluj", "123456", "Grivitei", "20");
    DrivingLicenseStartDay drivingLicenseStartDate("10", "10", "2020");
    DrivingLicenseEndDay drivingLicenseEndDate("10", "10", "2030");
    DrivingLicense drivingLicense(drivingLicenseStartDate, drivingLicenseEndDate, "yes");
    StartTime startTime("8", "0");
    EndTime endTime("17", "0");
    RentalStartDate rentalStartDate("10", "10", "2022", startTime);
    RentalEndDate rentalEndDate("14", "10", "2022", endTime);
    RentalSchedule rentalSchedule(rentalStartDate, rentalEndDate);
    IdentificationInfos identificationInfos("George", "Enache", "george@gmail.com", "0786787644", "7654565456545", "ZV", "778764", "parola");


    Customer customer(identificationInfos, customerHomeAdress, drivingLicense, dateOfBirth, rentalSchedule);
    ContactClass contact("0574637475", "email2@gmail.com", "Dorel");
    LocationAddress location("Piata Victoriei", "13", "3456");
    Car car("Audi", "Blue", "Automatic", "SUV", 200, "petrol", 5, 5, 8.8, true, 100, 70, 80, carReview);

    //--------------------------------------------------------------------------------------------------------
    
    std::vector <Customer> arrCustomers;
    arrCustomers.push_back(customer);

    std::vector <Car> arrCars;
    arrCars.push_back(car);

    CompanyBranches companyBranches("Firma 1", "Romania", "Cluj", "veryspatiugood", "OBS-none", 20, 9.5, "Independentei", "22", "345654", "0765676567", "firma1@gmail.com", "Alexandru");
    std::vector <CompanyBranches> arrBranches;
    arrBranches.push_back(companyBranches);

    SystemClass::SetNameOfHeadCompany("Firma principala 1");
    SystemClass mainOBJ(SystemClass::GetNameOfHeadCompany(), arrBranches);

    MainMenu(mainOBJ);

    return 0;
}