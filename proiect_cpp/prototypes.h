#pragma once


void utility_loadingScreen();


//Menus
void MainMenu();


//Admin stuff
void AdminOptions();
void ViewCompanies();


//Manager stuff
void FirmRegistration();
void Registrate();


//Client stuff
void ClientOptions();
void PersonalDetails();
void ReadPersonalData(std::string& , std::string& , std::string&, std::string&, std::string&, std::string&, std::string&);
void ReadStartRentalDetails(std::string&, std::string&, std::string&, std::string&, std::string&);
void ReadStopRentalDetails(std::string& , std::string& , std::string& , std::string& , std::string& );
void ReadDrivingLicenseDetails(std::string& , std::string& , std::string& , std::string& , std::string& , std::string& );



//Checking
bool EmailValidation(std::string);
bool InputValid(std::string);
bool isChar(char );
bool isDigit(const char);