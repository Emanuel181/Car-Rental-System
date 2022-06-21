#pragma once
#include <string>
#include <fstream>


bool InputValid(std::string input)
{
	for (int i = 0; i < input.size(); i++)
	{
		if (strchr("01234567890", input[i]) == 0)
			return false;
	}
	return true;
}


bool isChar(const char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}


bool isDigit(const char c)
{
	return (c >= '0' && c <= '9');
}


bool EmailValidation(std::string input)
{
	if (!isChar(input[0]))
		return false;

	int Posa = -1, PosDot = -1;
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == '@')
			Posa = i;
		else {
			if (input[i] == '.')
				PosDot = i;
		}
	}

	if (Posa == -1 || PosDot == -1)
		return false;
	if (Posa > PosDot)
		return false;
	if (PosDot == input.length() - 1)
		return false;
	return true;
}


bool IDCardSeriesValid(std::string input)
{
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] >= 'a' && input[i] <= 'z')
			return false;
		if (strchr("0123456789", input[i]))
			return false;
	}
	return true;
}


bool RentalHourValidation(std::string input)
{
	for (int i = 0; i < input.size(); i++)
	{
		if (strchr("01234567890", input[i]) == 0)
			return false;
	}
	int numar = stoi(input);
	if (numar < 8 || numar>17)
		return false;
	return true;
}


bool RentalMinuteValidation(std::string input)
{
	for (int i = 0; i < input.size(); i++)
	{
		if (strchr("01234567890", input[i]) == 0)
			return false;
	}
	int numar = stoi(input);
	if (numar != 0 && numar != 30)
		return false;
	return true;
}


bool AppearOnce(std::string word,SystemClass mainOBJ,int value)
{
	std::vector<std::vector<CompanyBranches>>arr = mainOBJ.GetCompanyBranches();
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			std::vector<Customer>arrCustomers = arr[i][j].GetBranchCustomers();
			for (int k = 0; k < arrCustomers.size(); k++)
			{
				std::string variable = "";
				if (value == 1)
					variable = arrCustomers[k].GetCustomerIdentificationInfos().GetCustomerFirstName();
				else
				{
					if(value==2)
						variable = arrCustomers[k].GetCustomerIdentificationInfos().GetCustomerEmail();
				}
				if (variable == word)
					return false;
			}
		}
	}
	return true;
}


bool FirmExists(std::vector<std::string>branchesList, std::string company)
{
	for (int i = 0; i < branchesList.size(); i++)
	{
		if (branchesList[i] == company)
			return true;
	}
	return false;
}


int CreateNumber(char* p)
{
	int nr = 0;
	for (int i = 0; i < strlen(p); i++)
	{
		nr = nr * 10 + p[i] - '0';
	}
	return nr;
}

bool containsOnlyDigits(std::string word)
{
	for (int i = 0; i < word.length(); i++)
	{
		if (word[i] < '0' || word[i]>'9')
			return false;
	}
	return true;
}