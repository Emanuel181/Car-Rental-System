#pragma once
#include "SystemClass.h"


void utility_loadingScreen();


//Menus
void MainMenu(SystemClass);


//Admin stuff
void AdminOptions(SystemClass);
void ViewCompanies(SystemClass);


//Manager stuff
void FirmRegistration(SystemClass);
void Registrate();


//Client stuff
void ClientOptions(SystemClass);
void AccountValidation(SystemClass);
void RentalPeriod(std::string);
void ReadCustomerPassword(std::string&);
void ReadRentalDetails(std::string&, std::string&,std::string&);
void DisplayAccountDetails(std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string);
void DisplayLine(int);
void DisplaySpaces(int);
int maxim(int, int);
void ConfirmCreateAccount(bool&);
void ReadHomeDetails(std::string&, std::string&, std::string&, std::string&, std::string&);
void ReadPersonalData(std::string&, std::string&, std::string&, std::string&, std::string&, std::string&, std::string&);
void ReadStartRentalDetails(std::string&, std::string&, std::string&, std::string&, std::string&);
void ReadStopRentalDetails(std::string&, std::string&, std::string&, std::string&, std::string&, std::string, std::string, std::string);
void ReadDrivingLicenseDetails(std::string&, std::string&, std::string&, std::string&, std::string&, std::string&);


//Account stuff
bool AppearOnce(std::string,std::string,int);
void LoginIntoAccount(std::string&,SystemClass);
void CreateAnAccount(SystemClass);


//Checking
bool EmailValidation(std::string);
bool InputValid(std::string);
bool isChar(const char);
bool isDigit(const char);