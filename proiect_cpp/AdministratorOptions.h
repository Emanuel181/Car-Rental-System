#pragma once
#include <string>
#include "SystemClass.h"
#include "CompanyBranches.h"
#include <iostream>
#include <fstream>;
#include <vector>
#include <iterator>
#include <windows.h>


void ViewCompanies(SystemClass mainOBJ)
{
	for (const auto& company : mainOBJ.GetCompanyBranches())
	{
		for (const auto& i : company) std::cout << i.GetBranchName() << ' ' << i.GetAdministratorOBS() << '\n';
	}
	system("pause");
}


void DisplayAdminOptions()
{
	std::cout << "\t[1] View registered companies\n";
	std::cout << "\t[2] Change password\n";
	std::cout << "\t[3] Delete a branch\n";
	std::cout << "\t[4] Add observations\n";
	std::cout << "\t[5] Go to main page\n";
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
	std::cout << "\tIEnter password: ";
	std::string newPassword1; std::cin >> newPassword1;
	std::cout << "\tEnter password again: ";
	std::string newPassword2; std::cin >> newPassword2;

	if (newPassword1 == newPassword2)
	{
		std::cout << "\tAre you sure you want to change the password?\n";
		std::cout << "\t[1] Yes\n\t[2] No";
		std::string rez; std::cout << "\tYour option: "; std::cin >> rez;
		
		bool check = CheckRez(rez);

		if (check == 0)
		{
			std::cout << "Option is not valid, reinitiate procces...";
			Sleep(0.2); system("cls");
		}

		else fout << newPassword1;
	}
	else std::cout << "Error: passwords do not match";

	fin.close();
	fout.close();
}


void AdminOptions(SystemClass& mainOBJ, std::vector<std::string>& branchesList)
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

			if (option <= 5)
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
					mainOBJ.DeleteBranch();
				}

				else if (option == 4)
				{
					Sleep(0.016); system("cls");
					mainOBJ.SetAdministratorOBS();
				}
				else if (option == 5)
				{
					Sleep(0.016); system("cls");
					MainMenu(mainOBJ,branchesList);
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