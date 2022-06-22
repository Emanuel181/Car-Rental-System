#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <algorithm>
#include <ctime>
#include "SystemClass.h"
#include "Prototypes.h"
#include "Validation.h"
#include "Menu.h"
#include <vector>
#include "AdministratorOptions.h"
#include "ClientOptions.h"
#include "FirmRegistration.h"
#include "LocationAddress.h"
#include "StartTime.h"
#include "EndTime.h"
#include "PasteData.h"


void Utility_loadingScreen()
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

void ReadDataFromFile(SystemClass& mainOBJ,std::vector<std::string>& branchesList)
{
    //std::ifstream fileAccounts("Accounts.txt");
    //std::ifstream fileCars("Cars.txt");
    std::ifstream fileBranches("Branches.txt");

    char* line = new char[500];
    std::vector<CompanyBranches>arrBranches;
    std::string firstname = "", lastname = "", email = "", phonenumber = "", CNP = "", idSeries = "", idNumber = "", password = "";
    std::string country = "", city = "", streetNumber = "", postalCode = "", streetName = "";
    std::string drStartDay = "", drStartMonth = "", drStartYear = "", drEndDay = "", drEndMonth = "", drEndYear = "";

    std::string make = "", color = "", transmission = "", type = "", engineType = "", review="";
    int bhp = 0, numberDoors = 0, numberSeats = 0, pricePerDay=0, deposit=0, advancePayment=0;
    double consumption = 0, value = 0, overallMark = 0, cleanliness = 0, comfort = 0, condition = 0;
    bool availability = false;

    std::string personName = "";

    std::string companyName = "", managerName = "", observations="";
    int numberOfCars = 0;

    while (fileBranches >> line)
    {
        char* p = strtok(line, ";");
        int nr = 0;
        while (p)
        {
            switch (nr)
            {
            case 0:
                companyName = p;
                break;
            case 1:
                country = p;
                break;
            case 2:
                city = p;
                break;
            case 3:
                review = p;
                break;
            case 4:
                observations = p;
                break;
            case 5:
                numberOfCars = CreateNumber(p);
                break;
            case 6:
                overallMark = std::stod(p);
                break;
            case 7:
                streetName = p;
                break;
            case 8:
                streetNumber = p;
                break;
            case 9:
                postalCode = p;
                break;
            case 10:
                phonenumber = p;
                break;
            case 11:
                email = p;
                break;
            case 12:
                managerName = p;
                break;
            }
            nr++;
            p = strtok(NULL, ";");
        }
        CompanyBranches branch(companyName, country, city, review, observations, numberOfCars, overallMark, streetName, streetNumber, postalCode, phonenumber, email, managerName);
        branchesList.push_back(companyName);
        
        std::ifstream fileCustomers(companyName + "clients.txt");
        std::vector<Customer>arrCustomers;
        line[0] = 0;
        while (fileCustomers >>line)
        {
            char* p = strtok(line, ";");
            int nr = 0;
            while (p)
            {
                switch (nr)
                {
                case 0:
                    personName += firstname;
                    firstname = p;
                    break;
                case 1:
                    personName += ";" + lastname;
                    lastname = p;
                    break;
                case 2:
                    email = p;
                    break;
                case 3:
                    phonenumber = p;
                    break;
                case 4:
                    CNP = p;
                    break;
                case 5:
                    idSeries = p;
                    break;
                case 6:
                    idNumber = p;
                    break;
                case 7:
                    country = p;
                    break;
                case 8:
                    city = p;
                    break;
                case 9:
                    postalCode = p;
                    break;
                case 10:
                    streetName = p;
                    break;
                case 11:
                    streetNumber = p;
                    break;
                case 12:
                    drStartDay = p;
                    break;
                case 13:
                    drStartMonth = p;
                    break;
                case 14:
                    drStartYear = p;
                    break;
                case 15:
                    drEndDay = p;
                    break;
                case 16:
                    drEndMonth = p;
                    break;
                case 17:
                    drEndYear = p;
                    break;
                case 18:
                    password = p;
                    break;
                }
                p = strtok(NULL, ";");
                nr++;
            }
            IdentificationInfos identificationInfos(firstname, lastname, email, phonenumber, CNP, idSeries, idNumber, password);
            CustomerHomeAdress customerHomeAddress(country, city, postalCode, streetName, streetNumber);
            DrivingLicenseStartDay drivingLicenseStartDate(drStartDay, drStartMonth, drStartYear);
            DrivingLicenseEndDay drivingLicenseEndDay(drEndDay, drEndMonth, drEndYear);
            DrivingLicense drivingLicense(drivingLicenseStartDate, drivingLicenseEndDay, "yes");
            RentalSchedule rentalSchedule;
            Customer customer(identificationInfos, customerHomeAddress, drivingLicense, rentalSchedule);

            arrCustomers.push_back(customer);
        }

        std::ifstream fileCars(companyName+"cars.txt");
        std::vector<Car>arrCars;
        line[0] = 0;
        while (fileCars >> line)
        {
            char* p = strtok(line, ";");
            int nr = 0;
            while (p)
            {
                switch (nr)
                {
                case 0:
                    make = p;
                    break;
                case 1:
                    color = p;
                    break;
                case 2:
                    transmission = p;
                    break;
                case 3:
                    type = p;
                    break;
                case 4:
                    bhp = CreateNumber(p);
                    break;
                case 5:
                    engineType = p;
                    break;
                case 6:
                    numberDoors = CreateNumber(p);
                    break;
                case 7:
                    numberSeats = CreateNumber(p);
                    break;
                case 8:
                    consumption = std::stod(p);
                    break;
                case 9:
                    if (p[0] == '0')
                        availability = false;
                    else
                        availability = true;
                    break;
                case 10:
                    pricePerDay = CreateNumber(p);
                    break;
                case 11:
                    deposit = CreateNumber(p);
                    break;
                case 12:
                    advancePayment = CreateNumber(p);
                    break;
                case 13:
                    value = std::stod(p);
                    break;
                case 14:
                    cleanliness = std::stod(p);
                    break;
                case 15:
                    comfort = std::stod(p);
                    break;
                case 16:
                    condition = std::stod(p);
                    break;
                case 17:
                    overallMark = std::stod(p);
                    break;
                case 18:
                    review = p;
                    break;
                }
                p = strtok(NULL, ";");
                nr++;
            }
            CarReview carReview(value, cleanliness, comfort, condition, overallMark, review);
            Car car(make, color, transmission, type, bhp, engineType, numberDoors, numberSeats, consumption, availability, pricePerDay, deposit, advancePayment, carReview);
            arrCars.push_back(car);
        }

        branch.setCarList(arrCars);
        branch.setCustomerList(arrCustomers);
        arrBranches.push_back(branch);
    }
    SystemClass object("",arrBranches);
    SystemClass::SetNameOfHeadCompany("Car rental system");
    mainOBJ = object;

    delete[] line;
}


int main()
{
    //Utility_loadingScreen();
    //system("cls");

    srand(time(0));
    std::vector<std::string>branchesList;
    SystemClass mainOBJ;
    SystemClass::SetNameOfHeadCompany("Car rental system");
    //SystemClass mainOBJ(SystemClass::GetNameOfHeadCompany(), arrBranches);

    ReadDataFromFile(mainOBJ,branchesList);

    MainMenu(mainOBJ,branchesList);

    CompleteFiles(mainOBJ);

    return 0;
}