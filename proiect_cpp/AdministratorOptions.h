#pragma once
#include <string>
#include "SystemClass.h"
#include <iostream>
#include <fstream>;
#include <vector>
#include <iterator>


void ViewCompanies(SystemClass mainOBJ)
{
	for (const auto& company : mainOBJ.GetCompanyBranches())
	{
		std::cout << company;
	}
}


void DisplayAdminOptions()
{
	std::cout << "\t[1] View registered companies\n";
	std::cout << "\t[2] Change password\n";
	std::cout << "\t[3] Delete a branch\n";
	std::cout << "\t[4] Go to main page\n";
}


void DeleteBranch(SystemClass mainOBJ)
{
	Sleep(0.16); system("cls");
	std::cout << "\tNumele companiei pe care vrei sa il stergi: ";
	std::string numeCompanie; getline(std::cin, numeCompanie);

	std::vector<CompanyBranches>::iterator it;
	it = mainOBJ.GetCompanyBranches().begin();
	bool ok = 0;

	while(it != mainOBJ.GetCompanyBranches().end())
	{
		if (it->GetBranchName() == numeCompanie)
		{
			it = mainOBJ.GetCompanyBranches().erase(it);
			ok = 1;
		}
	}

	if (ok) std::cout << "\tCompanie eliminata";

	else std::cout << "\tNu am gasit compania cu acest nume";
}


bool CheckRez(std::string rez)
{
	if (rez.size() > 1) return 0;
	if (rez[0] != '1' && rez[0] != '2') return 0;
	return 1;
}


void ChangePassword()
{
	std::ifstream fin("admin.txt");
	std::ofstream fout("admin.txt");

	Sleep(0.16); system("cls");
	std::cout << "\tIntroduceti noua parola: ";
	std::string newPassword1; std::cin >> newPassword1;
	std::cout << "\tIntroduceti din nou parola: ";
	std::string newPassword2; std::cin >> newPassword2;

	if (newPassword1 == newPassword2)
	{
		std::cout << "\tSunteti sigur ca vreti sa schimbati parola?\n";
		std::cout << "\t[1] Da\n\t[2] Nu";
		std::string rez; std::cout << "\tIntroduceti raspunsul: "; std::cin >> rez;
		
		bool check = CheckRez(rez);

		if (check == 0)
		{
			std::cout << "Optiunea nu e valida, reinitiem procesul...";
			Sleep(0.2); system("cls");
		}

		else fout << newPassword1;
	}
	else std::cout << "Eroare: Parolele nu se potrivesc";

	fin.close();
	fout.close();
}


void AdminOptions(SystemClass mainOBJ)
{
	while (1)
	{
		Sleep(0.016); system("cls");
		DisplayAdminOptions();
		std::string input; std::cout << "\tYour option: ";

		std::cout << "\t";
		std::cin >> input; std::cin.ignore();

		if (InputValid(input))
		{
			int option = stoi(input);

			if (option <= 4)
			{
				if (option == 1)
				{
					Sleep(0.016); system("cls");
					ViewCompanies(mainOBJ);
				}
				else if (option == 2)
				{
					Sleep(0.016); system("cls");
					ChangePassword();
				}

				else if (option == 3)
				{
					Sleep(0.016); system("cls");
					DeleteBranch(mainOBJ);
				}

				else if (option == 4)
				{
					Sleep(0.016); system("cls");
					MainMenu(mainOBJ);
				}
			}
			else
			{
				std::cout << "\tYour option is invalid\n";
				std::cout << "\tTry again\n";
			}
		}
		else
		{
			std::cout << "\tYour option is invalid\n";
			std::cout << "\tTry again\n";
		}
	}
}