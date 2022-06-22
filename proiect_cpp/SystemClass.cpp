#include "SystemClass.h"


std::string SystemClass::m_nameOfHeadCompany;


// Getters

std::string SystemClass::GetNameOfHeadCompany() { return m_nameOfHeadCompany; }


std::vector <std::vector <CompanyBranches>> SystemClass::GetCompanyBranches()const { return (m_companyBranches); }


//-----------------------------------------------------------------------------------------------------------


SystemClass::SystemClass(const static std::string nameOfHeadCompany, std::vector <CompanyBranches> obj)
{

    m_nameOfHeadCompany = nameOfHeadCompany;
    m_companyBranches.push_back(obj);
}


SystemClass::SystemClass()
{
    SetNameOfHeadCompany("\0");
}


void SystemClass::SetNameOfHeadCompany(const std::string Init) { m_nameOfHeadCompany = Init; }

void SystemClass::SetAdministratorOBS()
{
	std::string numeFirma;
	std::cout << "Name of company: "; getline(std::cin, numeFirma);

	bool ok = 0;
	for (auto& it : this->m_companyBranches)
	{
		for (auto& company : it)
		{
			if (company.GetBranchName() == numeFirma)
			{
				std::string OBS;
				std::cout << "Write observation: ";  getline(std::cin, OBS);
				company.SetOBS(OBS);
				ok = 1;
				break;
			}
		}
		if (ok) break;
	}

	if (!ok)
	{
		std::cout << "A company with this name doesn't exist\n";
		Sleep(1000);
	}
}


void SystemClass::Registrate(std::vector<std::string>& branchesList)
{
	std::string firmName = "", country, city = "", review = "", observations = "", street = "", streetNumber = "", postalCode = "",
		phoneNumber = "", emailAdressm = "", managerName = "";

	int numberOfCars;

	double mark = 0.0;


	std::cout << "Enter firm name: "; getline(std::cin, firmName); std::cout << "\n\t";
	std::cout << "\n\tEnter country: "; getline(std::cin, country); std::cout << "\n\t";
	std::cout << "\n\tEnter city: "; getline(std::cin, city); std::cout << "\n\t";
	std::cout << "\n\tEnter number of cars: "; std::cin >> numberOfCars; std::cout << "\n\t"; std::cin.ignore();
	std::cout << "\n\tEnter street: "; getline(std::cin, street); std::cout << "\n\t";
	std::cout << "\n\tEnter street number: "; getline(std::cin, streetNumber); std::cout << "\n\t";
	std::cout << "\n\tEnter postal code: "; getline(std::cin, postalCode); std::cout << "\n\t";
	std::cout << "\n\tEnter phone number: "; getline(std::cin, phoneNumber); std::cout << "\n\t";
	std::cout << "\n\tEnter email adress: "; getline(std::cin, emailAdressm); std::cout << "\n\t";
	std::cout << "\n\tEnter manager name: "; getline(std::cin, managerName); std::cout << "\n\t";

	int cnt = numberOfCars;

	branchesList.push_back(firmName);

	std::cout << "Write specifications for your cars:\n";

	std::string brand = "", color = "", transmission = "", type = "", engineType = "", reviewCar = "";

	int bhp, numberDoors, numberSeats, pricePerDay, deposit, advancePayment;

	double consumption, value, cleanliness, comfort, condition = 0.0, overallMark;

	bool availability = 1;

	while (cnt)
	{
		std::cout << "Brand: "; std::cin >> brand;
		std::cout << "\n\tColor: "; std::cin >> color;
		std::cout << "\n\tTransmission: "; std::cin >> transmission;
		std::cout << "\n\tType: "; std::cin >> type;
		std::cout << "\n\tBhp: "; std::cin >> bhp; std::cin.ignore();
		std::cout << "\n\tEngineType: "; std::cin >> engineType;
		std::cout << "\n\tNumber of Doors: "; std::cin >> numberDoors; std::cin.ignore();
		std::cout << "\n\tNumber of Seats: "; std::cin >> numberSeats; std::cin.ignore();
		std::cout << "\n\tConsumption: "; std::cin >> consumption; std::cin.ignore();
		std::cout << "\n\tPrice Per Day: "; std::cin >> pricePerDay; std::cin.ignore();
		std::cout << "\n\tDeposit: "; std::cin >> deposit; std::cin.ignore();
		std::cout << "\n\tAdvance Payment: "; std::cin >> advancePayment; std::cin.ignore();
		std::cout << "\n\tValue: "; std::cin >> value; std::cin.ignore();
		std::cout << "\n\tCleanliness: "; std::cin >> cleanliness; std::cin.ignore();
		std::cout << "\n\tComfort: "; std::cin >> comfort; std::cin.ignore();
		std::cout << "\n\tOverall Mark: "; std::cin >> overallMark; std::cin.ignore();
		--cnt;
	}

	std::cout << "\n\tCompany added!";
	//Sleep(2000);

	CompanyBranches branch(firmName, country, city, review, observations, numberOfCars, mark, street, streetNumber, postalCode, phoneNumber, emailAdressm, managerName);
	CarReview carReview(value, cleanliness, comfort, condition, overallMark, reviewCar);
	Car car(brand, color, transmission, type, bhp, engineType, numberDoors, numberSeats, consumption, availability, pricePerDay, deposit, advancePayment, carReview);
	std::vector<Car>arrCars; arrCars.push_back(car);

	branch.setCarList(arrCars);

	this->m_companyBranches[0].push_back(branch);
}


void SystemClass::DeleteBranch()
{
	Sleep(0.16); system("cls");
	std::cout << "\tName of company tou want to delete: ";
	std::string numeCompanie; getline(std::cin, numeCompanie);

	bool ok = 0;
	int i = 0;

	for (auto& i : m_companyBranches)
	{
		for (int j = 0; j < i.size(); ++j)
		{
			if (i[j].GetBranchName() == numeCompanie)
			{
				i.erase(i.begin() + j);
				ok = 1;
			}
		}
	}

	if (ok) std::cout << "\tCompany deleted\n";

	else std::cout << "\tA company with this name doesn't exist";
	system("pause");
}
