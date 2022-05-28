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
void AccountValidation();
void RentalPeriod();
void ReadCustomerPassword(std::string&);
void ReadRentalDetails(std::string&, std::string&);
void ConfirmCreateAccount(bool&);
void ReadHomeDetails(std::string&, std::string&, std::string&, std::string&, std::string&);
void ReadPersonalData(std::string&, std::string&, std::string&, std::string&, std::string&, std::string&, std::string&);
void ReadStartRentalDetails(std::string&, std::string&, std::string&, std::string&, std::string&);
void ReadStopRentalDetails(std::string&, std::string&, std::string&, std::string&, std::string&, std::string, std::string, std::string);
void ReadDrivingLicenseDetails(std::string&, std::string&, std::string&, std::string&, std::string&, std::string&);


//Account stuff
void LoginIntoAccount();
void CreateAnAccount();


//Checking
bool EmailValidation(std::string);
bool InputValid(std::string);
bool isChar(char);
bool isDigit(const char);