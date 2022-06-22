#pragma once
#include "SystemClass.h"


void Utility_loadingScreen();
void ReadDataFromFile(SystemClass&, std::vector<std::string>&);
void CompleteFiles(SystemClass);


//Menus
void MainMenu(SystemClass&, std::vector<std::string>&);


//Admin stuff
void AdminOptions(SystemClass&,std::vector<std::string>&);
void ViewCompanies(SystemClass);


//Manager stuff
void FirmRegistration(SystemClass&, std::vector<std::string>&);
void Registrate(SystemClass&, std::vector<std::string>&);


//Client stuff
void ClientOptions(SystemClass,std::vector<std::string>);
void AccountValidation(SystemClass,std::vector<std::string>,Customer&,std::string&,bool&);
void RentalPeriod(Customer);
void ReadCustomerPassword(std::string&);
void ReadRentalDetails(std::string&, std::string&,std::string&);
void DisplayAccountDetails(std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string);
void DisplayLine(int);
void DisplaySpaces(int);
int maxim(int, int);
void ConfirmCreateAccount(bool&);
void ReadHomeDetails(std::string&, std::string&, std::string&, std::string&, std::string&);
void ReadPersonalData(std::string&, std::string&, std::string&, std::string&, std::string&, std::string&, std::string&, SystemClass);
void ReadStartRentalDetails(std::string&, std::string&, std::string&, std::string&, std::string&);
void ReadStopRentalDetails(std::string&, std::string&, std::string&, std::string&, std::string&, std::string, std::string, std::string);
void ReadDrivingLicenseDetails(std::string&, std::string&, std::string&, std::string&, std::string&, std::string&);


//Account stuff
bool AppearOnce(std::string,SystemClass,int);
void LoginIntoAccount(SystemClass,Customer&,Customer);
Customer CreateAnAccount(SystemClass,bool&);


//Rental process
void RentalProcess(SystemClass, Customer,std::string);


//Checking
bool EmailValidation(std::string);
bool InputValid(std::string);
bool isChar(const char);
bool isDigit(const char);
bool FirmExists(std::vector<std::string>, std::string);
bool containsOnlyDigits(std::string);


//Convert
int CreateNumber(char*);


//Drop rented cars
void ViewRentedCars(SystemClass,Customer,std::vector<std::string>);
void DropCar(SystemClass,std::vector<std::string>);
void ViewCars(SystemClass,std::vector<std::string>);
void CollectData(std::string&, std::string&, std::string&);
void GetCarData(std::string&, std::string&, std::string&, std::string&, std::string&);
void ChangeAvailabilityOfCar(char*, SystemClass);